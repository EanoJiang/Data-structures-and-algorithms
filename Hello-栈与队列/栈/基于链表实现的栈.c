#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

// 定义链表节点
typedef struct ListNode{
    int val;
    struct ListNode *next;
}ListNode;

// 定义栈结构
typedef struct{
    ListNode *top;
    int size;
} LinkedListStack;

// 初始化一个空栈
LinkedListStack* newLinkedListStack(){
    LinkedListStack *s = malloc(sizeof(LinkedListStack));
    s->top = NULL;
    s->size = 0;
    return s;
}

// 析构函数：释放栈结构
void delLinkedListStac(LinkedListStack *s){
    while(s->top){
        ListNode *n = s->top ->next;// 指针暂存下一个节点
        free(s->top);// 释放栈顶节点
        s->top = n;//栈顶指向下一个节点
    }
    free(s);// 释放栈结构，头节点可以表示栈
}

// 获取栈的长度
int size(LinkedListStack *s){
    return s->size;
}

//判断栈是否为空
bool isEmpty(LinkedListStack *s){
    return size(s) == 0;
}

//入栈
void push(LinkedListStack *s, int val){
    ListNode *node = (ListNode*)malloc(sizeof(ListNode));
    node->next = s->top;// 新节点指向栈顶
    node->val = val;

    s->top = node;  //更新栈顶
    s->size++;
}

//访问栈顶元素
int peek(LinkedListStack *s){
    if(isEmpty(s)){
        printf("栈为空\n");
        return INT_MAX;
    }
    return s->top ->val;
}

//出栈
int pop(LinkedListStack *s){
    if(isEmpty(s)){
        printf("栈为空\n");
        return INT_MAX;
    }
    int val = peek(s); 

    ListNode *temp = s->top;

    s->top = s->top->next; //删除栈顶节点

    free(temp);
    s->size --;
    return val;
}

