#include <stdio.h>

//双向链表的结构体
typedef struct DoubleLinkedList{
    int val; //节点值
    struct DoubleLinkedList* prev;
    struct DoubleLinkedList* next;
}DoubleLinkedList; 

//节点创建函数
DoubleLinkedList* newDoubleLinkedList(int val){
    DoubleLinkedList* node = (DoubleLinkedList*)malloc(sizeof(DoubleLinkedList));
    node -> val = val;
    node -> prev = NULL;
    node -> next = NULL;
    return node;
}
