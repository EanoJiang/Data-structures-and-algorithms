#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct node {
    ElemType data;
    struct node *next;
}Node;

/*单链表——初始化*/
Node* initList(){
    Node *head = (Node*)malloc(sizeof(Node));
    head->data = 0;
    head->next = NULL;
    return head;//返回头节点指针，头节点可以代表整个链表
}

/*单链表——头插法 插入元素*/
//L: 链表头节点 ，elem: 插入元素
void insertHead(Node *L,ElemType elem){
    Node *tmp = (Node*)malloc(sizeof(Node));
    tmp->data = elem;
    tmp->next = L->next;
    L->next = tmp;
}

/*单链表——遍历*/
void listNode(Node *L){
    Node *tmp = L->next;
    while(tmp!= NULL){
        printf("%d ",tmp->data);
        //更新为下一个节点
        tmp = tmp->next;
    }
    printf("\n");
}

/*单链表——尾插法*/
Node* getTail(Node *L){
    Node *tmp = L;
    while(tmp->next!= NULL){
        tmp = tmp->next;
    }
    return tmp;
}
Node* insertTail(Node *tail,ElemType elem){
    Node *tmp = (Node*)malloc(sizeof(Node));
    tmp->data = elem;
    //尾节点的next指向新节点，新节点的next指向NULL(这时候的尾节点就是新节点)
    tail->next = tmp;
    tmp->next = NULL;

    //返回新的尾节点
    return tmp;
}

/*单链表——在指定位置插入元素*/
int insertNode(Node *L,int target_index,ElemType elem){
    //找到索引为target_index-1的节点
    Node *tmp = L;
    for(int i = 0; i <= target_index-1; i++){
        tmp = tmp->next;
        if(tmp == NULL){
            return 0;
        }
    }
    //这时tmp就是索引为target_index-1的节点
    //下面用头插法让新节点插到tmp的后面

    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = elem;
    newNode->next = tmp->next;
    tmp->next = newNode;

    return 1;  
}

/*单链表——删除指定元素*/
int deleteNode(Node *L,int target_index){
    //遍历找到要删除节点的前驱节点tmp
    Node *tmp = L;
    for(int i = 0;i <= target_index-1;i++){
        tmp = tmp->next;
        if(tmp == NULL){
            printf("要删除的节点不存在\n");
            return 0;
        }
    }

    if(target_index < 0 || 
        tmp->next == NULL){
        printf("要删除的节点索引不合法\n");
        return 0;
    }

    //delNode用来存放要删除的节点
    Node *delNode = tmp->next;

    //直接让tmp的next指向delNode的next
    tmp->next = delNode->next;
    free(delNode);
    return 1;
}

/*单链表——获取链表长度*/
int listLength(Node *L){
    Node *tmp = L;
    int len = 0;
    while(tmp != NULL){
        tmp = tmp->next;
        len++; 
    }
    return len;

}

int listRealse(Node *L){
    Node *tmp = L->next;
    Node *q;

    if(tmp == NULL){
        printf("这个链表只有头节点，不用释放\n");
        return 0;
    }
    while(tmp != NULL){
        q = tmp->next;
        free(tmp);
        //向后更新tmp
        tmp = q;
    }
    L->next = NULL;
    return 0;
}


/*题1：查找链表中倒数第k个位置的节点*/
//L:链表，k:倒数第k个位置
//单指针法
// ElemType listFind_1p(Node *L,int k){
//     Node *tmp = L;
//     int count = 0;
//     for(int i = 0;i <= listLength(L)-k-1;i++){
//         tmp = tmp->next;
//         count++;
//     }
//     printf("单指针法查找循环了%d次,但是计算链表总长度是遍历得到的,这部分循环次数没算进来\n",count);
//     return tmp->data;
// }

//双指针法
ElemType listFind_2p(Node *L,int k){
    Node *fast = L->next;
    Node *slow = L->next;
    int count = 0;
    //快指针先走k步
    for(int i = 0;i < k;i++){
        fast = fast->next;
    }
    //当快指针走到尾指针的时候，慢指针的位置就是倒数第k个
    while(fast != NULL){
        fast = fast->next;
        slow = slow->next;
        count++;
    }
    printf("双指针法查找循环了%d次\n",count);
    return slow->data;
}


int main(){
    Node *list = initList();
    insertHead(list,1);
    insertHead(list,2);
    insertHead(list,3);
    listNode(list);

    //这样写只在第一次得到尾指针时调用一次getTail()
    //后面的尾指针均由insertTail()返回值传递
    Node *tail = getTail(list);
    tail = insertTail(tail,4);
    tail = insertTail(tail,5);
    tail = insertTail(tail,6);
    listNode(list);

    insertNode(list,2,99);
    listNode(list);

    deleteNode(list,100);
    listNode(list);
    deleteNode(list,-1);
    listNode(list);
    deleteNode(list,2);
    listNode(list);
    printf("当前链表长度%d\n",listLength(list));

    // listRealse(list);
    // printf("当前链表长度%d\n",listLength(list));
    // listRealse(list);
    // printf("当前链表长度%d\n",listLength(list));
    for(int i = 1;i <= 10;i++){
        tail = insertTail(tail,1);
    }
    listNode(list);
    int k = 3;
    //printf("倒数第%d个节点的data是%d\n",k,listFind_1p(list,k));
    printf("倒数第%d个节点的data是%d\n",k,listFind_2p(list,k));
    return 0;
}


