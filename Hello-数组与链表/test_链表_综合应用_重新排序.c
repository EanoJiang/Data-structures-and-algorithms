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


/*综合应用——重新排序*/
Node* reOrder(Node *L){
    Node *fast = L;
    Node *slow = L;
    while(fast!= NULL){  
        fast = fast->next->next;
        slow = slow->next;
    }
    //这时候slow就是中间节点

    //把链表分成两部分
    Node *L1 = L;
    Node *L2 = slow->next;
    slow->next = NULL;

    //反转L2
    //注意上面分好后，L2没有头节点，second = head->next = L2，所以second = L2
    Node *first = NULL;
    Node *second = L2;
    Node *third = NULL;

    while(second!= NULL){
        third = second->next;
        second->next = first;
        first = second;
        second = third;
    }
    
    //插入
    Node *p1 = L1->next;
    Node *q1 = first;
    Node *p2 = NULL;
    Node *q2 = NULL;
    while(p1!= NULL && q1!= NULL){
        p2 = p1->next;
        q2 = q1->next;
        //交替插入
        p1->next = q1;
        q1->next = p2;
        //向后更新指针
        p1 = p2;
        q1 = q2;
    }

    return L;
}

int main(){
    Node *list = initList();
    Node *tail = getTail(list);
    tail = insertTail(tail,1);
    tail = insertTail(tail,2);
    tail = insertTail(tail,3);
    tail = insertTail(tail,4);
    tail = insertTail(tail,5);
    tail = insertTail(tail,6);
    tail = insertTail(tail,7);

    listNode(list);
    Node *reOrderedList = reOrder(list);
    listNode(reOrderedList);
    
    return 0;

}

