#include <stdio.h>
#include <stdlib.h>
/* 平方阶 */
void quadratic(int n) {
    // 二维列表占用 O(n^2) 空间
    int **numMatrix = malloc(sizeof(int *) * n);
    for (int i = 0; i < n; i++) {
        int *tmp = malloc(sizeof(int) * n);
        for (int j = 0; j < n; j++) {
            tmp[j] = 0;
        }
        numMatrix[i] = tmp;
    }

    // 内存释放
    for (int i = 0; i < n; i++) {
        free(numMatrix[i]);
    }
    free(numMatrix);
}

int main() {
    int n = 10;
    quadratic(n);
    printf("quadratic(%d) done.\n", n);
    return 0;
}