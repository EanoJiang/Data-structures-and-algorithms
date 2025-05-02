#include <stdio.h>

// 对数阶 递归实现

// f(n) = n/2 + n/4 + ... + 1
// 每次递归（子任务）：f(n) = n/2 + 1
int logRecur(int n)
{
    if (n <= 1){
        return 0;
    }
    return logRecur(n / 2) + 1;
}

int main(){
    int n = 10;
    printf("循环次数log2(n): %d\n", n, logRecur(n));
    return 0;
}