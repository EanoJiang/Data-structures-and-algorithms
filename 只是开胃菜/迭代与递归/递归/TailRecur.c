#include <stdio.h>

// 尾递归函数
int TailRecur(int n, int res){
    if (n == 0)
        return res;
    return TailRecur(n - 1, n + res);
}

int main(){
    int res = TailRecur(5, 0);
    printf("%d\n", res);
    return 0;
}