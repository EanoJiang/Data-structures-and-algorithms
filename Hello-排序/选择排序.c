/* 选择排序 */
void selectionSort(int nums[], int length) {
    // 外循环：n轮
    for (int n = 0; n < length - 1; n++) {
        // 内循环：找到未排序区间内的最小元素
        int minIndex = n;
        for (int j = n + 1; j < length; j++) {
            if (nums[j] < nums[minIndex])
                minIndex = j; // 记录最小元素的索引
        }
        // 将该最小元素与未排序区间的首个元素交换
        int temp = nums[minIndex];
        nums[minIndex] = nums[n];
        nums[n] = temp;
    }
}

#include <stdio.h>
// 测试
int main() {
    int nums[] = {5, 2, 8, 3, 9, 1};
    int length = sizeof(nums) / sizeof(nums[0]);
    selectionSort(nums, length);
    for (int i = 0; i < length; i++) {
        printf("%d ", nums[i]);
    }
    return 0;
}
