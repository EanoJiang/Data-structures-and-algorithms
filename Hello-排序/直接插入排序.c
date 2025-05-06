/* 插入排序 */
void insertionSort(int nums[], int length) {
    // 外循环：已排序区间为 [0, i-1]
    for (int i = 1; i < length; i++) {
        // 从未排序区间选取一个值作为基准
        int base = nums[i];
        //内循环：比较 base 与已排序区间中的元素
        int j = i - 1;
        //找到正确位置，将该位置后面的元素依次向后移动一位
        for(; j >= 0 && nums[j] > base; j--) {
            nums[j + 1] = nums[j];
        }
        // 将 base 赋值到正确位置
        nums[j + 1] = base;
    }
}