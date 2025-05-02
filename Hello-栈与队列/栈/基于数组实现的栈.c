#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#define MAX_SIZE 100

typedef struct ArrayStack {
    int *data;
    int size;
}ArrayStack;

//初始化一个空栈
ArrayStack *newArrayStack() {
    ArrayStack *stack =(ArrayStack *)malloc(sizeof(ArrayStack));
    stack->data = malloc(sizeof(int*)*MAX_SIZE);
    stack->size = 0;
    return stack;
}

//析构函数
void delArrayStack(ArrayStack *stack){
    free(stack->data);
    free(stack);
}

//获取栈的大小
int size(ArrayStack *stack){
    return stack->size;
}

//判断栈是否为空
bool isEmpty(ArrayStack *stack){
    return stack->size == 0;
}

//入栈
void push(ArrayStack *stack, int val){
    if(size(stack) == MAX_SIZE){
        printf("栈满\n");
        return;
    }
    stack->data[stack->size] = val;//更新栈顶：数组尾部的后面添加元素
    stack->size++;
}

int peek(ArrayStack *stack){
    if(isEmpty(stack)){
        printf("栈空\n");
        return INT_MIN;
    }
    return stack->data[stack->size-1];//返回栈顶元素
}

//出栈
int pop(ArrayStack *stack){
    if(isEmpty(stack)){
        printf("栈空\n");
        return INT_MIN;
    }
    int val = peek(stack);//栈顶元素
    stack->size--;
    return val;
}

