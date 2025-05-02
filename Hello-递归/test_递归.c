#include <stdio.h>

int sum(int n){
    if(n == 1){
        return 1;
    }
    else{
        return sum(n-1)+n;
    }
}

int main(){
    int n = sum(5);
    printf("%d\n", n);
    return 0;
}