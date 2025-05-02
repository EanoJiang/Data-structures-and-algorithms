#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 嵌套循环
char *NestedForLoop(int n) {
    // n * n 为对应点数量，"(i, j), " 对应字符串长最大为 6+1*2，加上最后一个空字符 \0 的额外空间
    //6 是固定部分的长度，包括 "("、", " 和 "), " 这些字符
    //假设i和j都是一位数字
    int size = n * n * 8 + 1;
    char *res = malloc(size*sizeof(char));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            char tmp[8];
            snprintf(tmp, 8, "(%d, %d), ", i, j);
            strncat(res, tmp, size-strlen(res)-1);
        }
    }
    return res;
}

int main(){
    int n = 5;
    char *res = nestedForLoop(n);
    printf("%s\n", res);
    free(res);
    return 0;
}
