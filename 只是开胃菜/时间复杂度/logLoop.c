#include <stdio.h>

// 对数阶：复杂度是对数阶
// 这里复杂度是log2(n)
int logLoop(int n){
    int count = 0;
    while(n > 1){
        n /= 2;
        count++;
    }
    return count;
}

int main(){
    int n = 8;
    int count = logLoop(n);
    printf("循环次数log2(n): %d\n", count);
}