#include <stdio.h>

// 指数阶 循环实现
int Exponential(int n) {
    int count = 0;
    int bas = 1;
    // 每轮count=2^n，共n-1轮相加
    // 也就是2^0+2^1+2^2+...+2^(n-1)
    for (int i = 0; i < n; i ++){
        for (int j = 0; j < bas; j ++){
            count ++;
        }
        bas *= 2;     
    }
    return count;
}

int main() {
    int n = 5;
    int result = Exponential(n);
    printf("Exponential(%d) = %d\n", n, result);
    return 0;
}