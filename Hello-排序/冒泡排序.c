/* 冒泡排序 */
void bubbleSort(int nums[], int length) {
    // 外循环：数组几个数就需要进行i轮冒泡
    for (int i = 0; i < length; i++) {
        // 内循环：
        // 每轮冒泡
        // 数组长度减去第i轮，因为每轮冒泡都会将最大的数冒泡到最后面，所以不需要再比较后面的数
        // length - 1是因为要防止数组越界，因为要比较 nums[j] > nums[j + 1]
        for (int j = 0; j < length- 1 - i; j++) {
            if (nums[j] > nums[j + 1]) {
                int temp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = temp;
            }
        }
    }
}

#include <stdbool.h>

/*优化后的冒泡排序*/
void bubbleSort2(int nums[], int length) {
    // 外循环：数组几个数就需要进行i轮冒泡
    for (int i = 0; i < length; i++) {
        //每轮冒泡开始前，标志位isSwap置为false
        bool isSwap = false;
        // 内循环：
        // 每轮冒泡
        // 数组长度减去第i轮，因为每轮冒泡都会将最大的数冒泡到最后面，所以不需要再比较后面的数
        // length - 1是因为要防止数组越界，因为要比较 nums[j] > nums[j + 1]
        for (int j = 0; j < length- 1 - i; j++) {
            if (nums[j] > nums[j + 1]) {
                int temp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = temp;
                //每次交换后，isSwap置为true
                isSwap = true;
            }
        }
        //如果本轮没有发生交换，说明已经排序好了，即刻退出循环
        if(!isSwap)break;
    }
}

#include <stdio.h>

int main() {
    int nums[] = {5, 3, 8, 6, 2, 7, 1, 4};
    int length = sizeof(nums) / sizeof(nums[0]);
    bubbleSort2(nums, length);
    for (int i = 0; i < length; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
    return 0;
}
