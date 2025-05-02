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

/*单链表——释放内存*/
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


/*题3：删除绝对值相同的其余节点*/
//L: 链表头节点 n: |data|的最大值（和题目给的n没关系）
void removeNode_withAbsSame(Node* L,int n){
    Node *tmp = L;
    //数组下标
    int index;
    //数组
    int *arr = (int*)malloc(sizeof(int)*(n+1));
    //初始化全0数组
    for(int i = 0; i < n+1; i++){
        arr[i] = 0;
    }
    //遍历链表，和数组下标index比对
    //tmp是待比对节点的前驱节点
    //tmp->next是待比对节点
    while(tmp->next != NULL){
        index = abs(tmp->next->data);
        //待比对节点的data在数组下标中第一次出现为0
        if(arr[index] == 0){
            arr[index] = 1;
            tmp = tmp->next;
        } 
        //否则为1，已经出现过，就删除待比对节点
        else{
            Node *delNode = tmp->next;
            tmp->next = delNode->next;
            free(delNode);
        }
    }

}


int main(){
    Node *list = initList();
    Node *tail = getTail(list);
    tail = insertTail(tail,21);
    tail = insertTail(tail,-15);
    tail = insertTail(tail,-15);
    tail = insertTail(tail,7);
    tail = insertTail(tail,15);

    listNode(list);
    removeNode_withAbsSame(list,21);
    listNode(list);
    
    return 0;
}

