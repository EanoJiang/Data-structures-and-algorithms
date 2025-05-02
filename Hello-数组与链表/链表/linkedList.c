#include <stdio.h>
#include <stdlib.h>
//链表结构体
typedef struct ListNode{
    int val;
    struct ListNode *next;
}ListNode;

//节点创建函数
ListNode *newListNode(int val){
    ListNode *node;
    node = (ListNode *)malloc(sizeof(ListNode));
    node -> val = val;
    node -> next = NULL;
    return node;
}


//遍历链表
void traverse(ListNode* head){
    for (ListNode* i = head; i != NULL; i = i -> next){
        printf("%d", i -> val);
        if(i -> next!= NULL)
            printf(" -> ");
    }
    printf("\n");
}

//插入节点
//  node1 和 node2 之间插入 p
void insert(ListNode* node1, ListNode* node2, ListNode* p){
    node1 -> next = p;
    p -> next = node2;
}

//删除节点
// 删除node1 后的 第一个节点
void removeNode(ListNode* node1){
    if(! node1 -> next){
        return;
    }
    //node1 -> p -> node2
    ListNode* p = node1 -> next; //把node1 后的第一个节点记作p
    ListNode* node2 = p -> next; //把p 后的第一个节点记作node2

    //node1 -> node2
    node1 -> next = node2;
    free(p);
}

//访问节点
ListNode* searchNode(ListNode* head,int index){
    for(int i = 0; i < index; i++){
        if(head == NULL)
            return NULL;
        head = head -> next;    //更新head为下一个节点
    }
    return head;
}

//查找节点(的索引)
int search(ListNode* head,int target){
    for(int index = 0; head != NULL; index++){
        if(head ->val == target){
            return index;
        }
        head = head -> next;    //更新head为下一个节点
    }
    return -1; //未找到，返回一个不可能存在的索引
}

int main(){
    //初始化链表
    ListNode* n0 = newListNode(3);
    ListNode* n1 = newListNode(9);
    ListNode* n2 = newListNode(7);
    ListNode* n3 = newListNode(2);

    n0 -> next = n1;
    n1 -> next = n2;
    n2 -> next = n3;
    n3 -> next = NULL;
    
    //遍历链表
    traverse(n0);
    
    //插入节点
    ListNode* p = newListNode(4);
    insert(n0, n1, p);
    //遍历链表
    traverse(n0);

    //删除节点
    removeNode(n0);
    //遍历链表
    traverse(n0);

    //访问节点
    printf("%d\n",searchNode(n0,2)->val);

    //查找节点(的索引)
    printf("%d\n",search(n0,7));

    return 0;
}


