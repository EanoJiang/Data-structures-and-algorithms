/* 线性对数阶 */

int linearLogRecur(int n) {
    if (n <= 1)
        return 1;
    //n + n/2 + n/4 +... + 1
    // 把第一次n 分解成两个子任务（二叉树），即为两个n/2开始的线性对数阶
    int count = linearLogRecur(n / 2) + linearLogRecur(n / 2);
    for (int i = 0; i < n; i++) {
        count++;
    }
    return count;
}