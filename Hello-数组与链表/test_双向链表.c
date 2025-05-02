#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct node{
    ElemType data;
    struct node *prev, *next;
}Node;

//初始化和单链表一样
/*单链表——初始化*/
Node* initList(){
    Node *head = (Node*)malloc(sizeof(Node));
    head->data = 0;
    head->next = NULL;
    return head;//返回头节点指针，头节点可以代表整个链表
}

//遍历和单链表一样
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

//获取链表长度和单链表一样
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

//释放内存和单链表一样
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

/*双向链表——头插法*/
int insertHead(Node *L,ElemType elem){
    Node *tmp = (Node*)malloc(sizeof(Node));
    //新节点的前驱 是 头节点，后驱 是 头节点的后继节点
    tmp->data = elem;
    tmp->prev = L;
    tmp->next = L->next;
    //头节点的后继节点的前驱 是 新节点
    if(L->next != NULL){
        L->next->prev = tmp;
    }
    //头节点的新后继节点 是 新节点
    L->next = tmp;
    return 1;
}

/*双向链表——尾插法*/
//获取尾节点的方法和单链表一样
Node* getTail(Node *L){
    Node *tmp = L;
    while(tmp->next != NULL){
        tmp = tmp->next;
    }
    return tmp;
}
Node* insertTail(Node *tail,ElemType elem){
    Node* tmp = (Node*)malloc(sizeof(Node));
    tmp->data = elem;
    tmp->prev = tail;
    tail->next = tmp;
    //更新尾节点指针
    tmp->next = NULL;
    return tmp;
}

/*双向链表——指定位置插入节点*/
int insertPos(Node *L,int targetIndex,ElemType elem){
    //获取目标位置的前驱节点
    Node *p = L;
    //如果定义的是L->next，下面获取的就是指定位置的后驱节点
    for(int i = 0;i < targetIndex;i++){
        p = p->next;
    }
    Node *tmp = (Node*)malloc(sizeof(Node));
    tmp->data = elem;
    tmp->prev = p;
    tmp->next = p->next;
    
    p->next->prev = tmp;
    p->next = tmp;
    return 1;
}

/*双向链表——删除指定位置的节点*/
Node* delNode(Node *L,int targetIndex){
    //获取前驱节点
    Node *p = L;
    for(int i = 0;i < targetIndex;i++){
        p = p->next;
        if(p == NULL){
            return 0;
        }
    }
    //记录要删除的节点
    Node *del = p->next;
    //如果要删除的节点不存在
    if(del == NULL){
        printf("要删除的节点不存在\n");
        return 0;
    }
    //如果要删除的是尾节点，则直接更新尾节点指针为前驱节点
    else if(del->next == NULL) {
        p->next = NULL; 
        return L;
    } 

    p->next = del->next;
    del->next->prev = p;
    free(del);
    return L;
}

int main(){
    Node *list = initList();
    Node *tail = getTail(list);
    tail = insertTail(tail,1);
    tail = insertTail(tail,2);
    tail = insertTail(tail,3);
    listNode(list);
    insertPos(list,1,99);
    listNode(list);
    delNode(list,1);
    listNode(list);
    return 0;
}

