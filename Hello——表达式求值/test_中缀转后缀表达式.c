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

char expr[] = "x/(i-j)*y";

contentType getToken(char *symbol,int *index){
    //当前字符存到指针symbol中
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

//打印token
int print_token(contentType token)
{
	switch(token)
	{
		case ADD:
			printf("+");
			break;
		case SUB:
			printf("-");
			break;
		case MUL:
			printf("*");
			break;
		case DIV:
			printf("/");
			break;
		case MOD:
			printf("%%");
			break;
		default:
			return 0;
	}
	return 1;
}

//中缀转后缀表达式,打印
void postfix(Stack *s){
    //运算符优先级
    //LEFT_PARE,RIGHT_PARE,ADD,SUB,MUL,DIV,MOD,EOS
    int in_stack[] = {0,19,12,12,13,13,13,0};//栈内运算符(左括号在栈里面的时候优先级是0)
	int out_stack[] = {20, 19, 12, 12, 13, 13, 13, 0};//栈外运算符
    contentType token;
    int index = 0;
    //栈顶先放一个\0，作为优先级最低的token
    s->top = 0;
    s->data[0] = EOS;
    char symbol;
    ElemType e;
    
    token = getToken(&symbol,&index);
    //结束条件\0，就不再获取新的token了
    while(token!= EOS){
        //遇到数字
        if(token == NUM)
        {
            printf("%c",symbol);
        }
        //遇到右括号
        else if(token == RIGHT_PARE){
            //出栈并打印，结束条件：遇到左括号
            while(s->data[s->top] != LEFT_PARE){
                pop(s,&e);
                print_token(e);
            }
            //出栈左括号
            pop(s,&e);
        }
        //遇到其他操作符
        else{
            //优先级越小越优先
            //优先级：当前元素(优先)<=栈顶元素，出栈并打印
            while(out_stack[token] <= in_stack[s->data[s->top]]){
                pop(s,&e);
                print_token(e);
            }
            //优先级：当前元素>栈顶元素(优先)，入栈
            push(s,token);
        }
        //更新token
        token = getToken(&symbol,&index);
    }
    //出栈剩余的元素
    pop(s, &e);
    //打印剩余的元素
	token = e;
	while(token != EOS)
	{
		print_token(token);
		pop(s, &e);
		token = e;
	}
	printf("\n");
}

int main(){
    Stack *s = initStack();
    printf("中缀表达式：%s\n",expr);
    postfix(s);
    return 0;
}