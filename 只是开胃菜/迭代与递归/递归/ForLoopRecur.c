#include <stdio.h>

/* 使用迭代模拟递归 */
int forLoopRecur(int n) {
    //栈
    int stack[100];
    //栈顶索引
    int topStack = -1;
    //入栈:索引从栈顶向上
    for(int i = n; i > 0; i--){
        stack[1 + topStack++] = i;
    }
    //入栈操作全部完成后，栈顶在最上面
    //出栈：索引从栈顶向下
    int res = 0;
    while(topStack >= 0){
        res += stack[topStack--];
    }

    return res;
}

int main(){
    int res = forLoopRecur(5);
    printf("%d\n", res);    
    return 0;
}
