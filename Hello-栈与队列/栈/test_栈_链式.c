#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int ElemType;

typedef struct Stack{
    ElemType data;
    struct Stack *next;
}Stack;

Stack* initStack(){
    Stack *s = (Stack*)malloc(sizeof(Stack));
    s->next = NULL;
    return s;
}

//判断栈是否为空
bool isEmpty(Stack *s){
    return s->next == NULL;
}
//入栈
//头插法
int push(Stack *s, ElemType e){
    Stack *p = (Stack*)malloc(sizeof(Stack));
    p->data = e;
    p->next = s->next;
    s->next = p;
    return 1;
}

//出栈
//删去头结点的next
ElemType pop(Stack *s, ElemType *e){
    if(s->next == NULL){
        printf("栈为空！\n");
        return 0;
    }
    *e = s->next->data;

    Stack *p = s->next;
    s->next = p->next;
    free(p);

    return *e;
}

//获取栈顶元素
ElemType getTop(Stack *s){
    if(s->next == NULL){
        printf("栈为空！\n");
        return 0;
    }
    
    return s->next->data;
}

int main(){
    Stack *s = initStack();
    push(s,1);
    push(s,2);
    push(s,3);
    printf("栈顶元素:%d\n",getTop(s));
    ElemType elem;
    pop(s,&elem);
    printf("出栈元素:%d\n",elem);
    printf("栈顶元素:%d\n",getTop(s));
    free(s);
    return 0;
    
}