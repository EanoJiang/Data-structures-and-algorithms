#include <stdio.h>

//循环实现
int fibonacci_forLoop(int n) {
    int first = 1, second = 1, result = 0;
    for(int i = 3; i <= n; i++){
        result = first + second;
        second = first;
        first = result;
    }
    return result;
}

//递归实现
int fibonacci(int n) {
    //递到前三项停止，开始归
    if(n == 1 || n == 2){
        return 1;
    }
    else{
        return fibonacci(n-1) + fibonacci(n-2);
    }
}

int main() {
    int n = 3;
    int num = fibonacci(n);
    printf("%d", num);
    return 0;
}