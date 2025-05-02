#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100
typedef int ElemType;

typedef struct {
    ElemType *data;
    int top;
} Stack;

// 初始化栈
Stack* initStack() {
    Stack *s = (Stack*)malloc(sizeof(Stack));
    s->data = (ElemType*)malloc(MAXSIZE * sizeof(ElemType));
    s->top = -1;
    return s;
}

//入栈
int push(Stack *s, ElemType e){
    if(s->top == MAXSIZE-1){
        printf("栈满\n");
        return 0;
    }
    s->top++;
    //从栈顶入栈
    s->data[s->top] = e;
    return 1;
}

//出栈
ElemType pop(Stack *s,ElemType *e){
    if(s->top == -1){
        printf("栈空\n");
        return 0;
    }
    *e = s->data[s->top];
    s->top--;
    return *e;
}

//查看栈顶元素
ElemType getTop(Stack *s,ElemType *e){
    if(s->top == -1){
        printf("栈空\n");
        return 0;
    }
    *e = s->data[s->top];
    return *e;
}

int main(){
    Stack *s = initStack();
    push(s,1);
    push(s,2);
    push(s,3);
    ElemType elem;
    getTop(s,&elem);
    printf("栈顶元素:%d\n",elem);
    pop(s,&elem);
    printf("出栈元素:%d\n",elem);
    printf("栈顶元素:%d\n",getTop(s,&elem));
    free(s->data);
    free(s);
    return 0;

}

