#include <stdio.h>

// 递归树，斐波那契数列
int fib(int n){
    // 递归终止条件:前两项
    if(n == 1 || n == 2)
        return n-1;
    int fn = fib(n-1) + fib(n-2);
    return fn;
}

int main(){
    int n = 10;
    printf("斐波那契数列的第%d项为: %d\n", n, fib(n));
    return 0;
}