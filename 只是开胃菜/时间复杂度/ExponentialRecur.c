#include <stdio.h>

// f(n) = 1 + 2^1 + 2^2 + ...+ 2^(n-1)
// 每次递归（子任务）：f(n) = 1 + 2f(n-1)       后面这些项每一项都是前一项的2倍
// 指数阶 递归实现
int ExponentialRecur(int n) {
    if (n == 1)
        return 1;
    int fn = 1 + 2 * ExponentialRecur(n - 1);
    return fn;
}

int main() {
    int n = 5;
    int result = ExponentialRecur(n);
    printf("ExponentialRecur(%d) = %d\n", n, result);
    return 0;
}