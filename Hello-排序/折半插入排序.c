void BInsertSort(int L[], int length)
{
    for (int i = 2; i <= length; ++i)
    {
        //折半查找找到要插入的正确位置区间[low,high]
        int base = L[i];
        int low = 1;
        int high = i - 1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (base < L[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
        //从high+1开始，后面的元素向后移动一位
        for (int j = i - 1; j >= high + 1; j--)
        {
            L[j + 1] = L[j];
        }
        //基准元素base赋值给正确位置arr[ high+1 ]
        L[high + 1] = base;
    }
}
