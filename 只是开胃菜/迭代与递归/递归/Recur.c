#include <stdio.h>

// 递归
int recur(int n){
    if (n == 1) 
        return 1;
    int fn = recur(n-1) + n;
    return fn;
}

int main(){
    printf("%d\n", recur(5));
    return 0;
}