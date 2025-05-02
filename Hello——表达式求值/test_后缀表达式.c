#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
#define MAXSIZE 100

typedef struct Stack{
    int top;
    ElemType *data;
}Stack;


// 初始化栈
Stack* initStack(){
    Stack *s = (Stack*)malloc(sizeof(Stack));
    s->data = (ElemType*)malloc(MAXSIZE * sizeof(ElemType));
    s->top = -1;
    return s;
}

int isEmpty(Stack* s){
    return s->top == -1;
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

typedef enum {
    LEFT_PARE,RIGHT_PARE,
    ADD,SUB,MUL,DIV,MOD,
    EOS,NUM
}contentType;

char expr[] = "82/2+56*-";

contentType getToken(char *symbol,int *index){
    //存储当前字符
    *symbol = expr[*index];
    //这句不能写成*index++：指针*index的地址自增
    *index = *index + 1;//指针*index的值自增
    switch(*symbol){
        case '(':
            return LEFT_PARE;
        case ')':
            return RIGHT_PARE;
        case '+':
            return ADD;
        case '-':
            return SUB;
        case '*':
            return MUL;
        case '/':
            return DIV;
        case '%':
            return MOD;
        case '\0':
            return EOS;
        default:
                return NUM;
    }
}

//计算后缀表达式
int eval(Stack *s){
    char symbol;
    int op1,op2;
    int index = 0;
    ElemType result;
    contentType token;
    token = getToken(&symbol,&index);
    //结束条件\0
    while(token!= EOS){
        //遇到数字
        if(token == NUM){
            //将数字(字符相应ASCII码-'0')压入栈中
            push(s,symbol - '0');
        }
        //遇到操作符
        else{
            //出栈，把被操作数存到op2和op1中
            pop(s,&op2);
            pop(s,&op1);
            //计算结果入栈
            switch(token){
                case ADD:
                    push(s,op1 + op2);
                    break;
                case SUB:
                    push(s,op1 - op2); 
                    break;
                case MUL:
                    push(s,op1 * op2);    
                    break;
                case DIV:
                    push(s,op1 / op2);
                    break;
                case MOD:
                    push(s,op1 % op2);
                    break;
                default:
                    printf("非法字符\n");
                    return 0;
            }
        }
        //更新token
        token = getToken(&symbol,&index);
    }
    //循环结束条件\0后，栈中只有一个元素，出栈并打印
    pop(s,&result);
    printf("结果为：%d\n",result);
    return 1;
}


int main(){
    Stack *s = initStack();
    eval(s);
    return 0;

}

