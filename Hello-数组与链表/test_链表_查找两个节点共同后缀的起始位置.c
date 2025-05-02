#include <stdio.h>
#include <stdlib.h>

/*题2：单词后缀*/
typedef char ElemType;

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
        printf("%c ",tmp->data);
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


/*题2：查找两个节点共同后缀的起始位置*/
Node* findNodeWithSuffix(Node *L1,Node *L2){
    if(L1 == NULL || L2 == NULL) return NULL;
    //获取两个链表的长度
    int len1 =  listLength(L1);
    int len2 =  listLength(L2);

    Node *fast;//快指针
    Node *slow;//慢指针
    int step; //步长：长度差值

    //让快指针指向较长链表的next
    if(len1 > len2){
        step = len1 - len2;
        fast = L1->next;
        slow = L2->next;
    }
    else{
        step = len2 - len1;
        fast = L2->next;
        slow = L1->next;
    }
    //先让快指针走step步
    for(int i = 0; i < step; i++){
        fast = fast->next;
    }
    //然后两个指针一起走，直到找到快慢指针走到同一个节点(同一个后缀的第一个字母)
    while(fast != slow){
        fast = fast->next;
        slow = slow->next;
    }
    return fast;
}

int main(){
    Node *str1 = initList();
    Node *str2 = initList();

    Node *tail1 = getTail(str1);
    Node *tail2 = getTail(str2);
    //str1的前缀是load
    tail1 = insertTail(tail1,'l');
    tail1 = insertTail(tail1,'o');
    tail1 = insertTail(tail1,'a');
    tail1 = insertTail(tail1,'d');
    //str2的前缀是be
    tail2 = insertTail(tail2,'b');
    tail2 = insertTail(tail2,'e');

    Node *suffix = initList();
    Node *tail_suffix = getTail(suffix);
    //suffix是ing
    tail_suffix = insertTail(tail_suffix,'i');
    tail_suffix = insertTail(tail_suffix,'n');
    tail_suffix = insertTail(tail_suffix,'g');

    //str1和suffix相连,也就是str1的尾节点的next指向suffix的头节点的next
    tail1->next = suffix->next;
    //str2和suffix相连
    tail2->next = suffix->next;

    listNode(str1);
    listNode(str2);
    
    printf("共同后缀的起始位置：%c\n",findNodeWithSuffix(str1,str2)->data);

    return 0;
}