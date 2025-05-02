#include <stdio.h>
// 列表结构体
typedef struct
{
    int *arr;        // 数组
    int capacity;    // 列表容量
    int size;        // 列表大小
    int extendRatio; // 列表每次扩容倍数
} Mylist;

// 构造函数
Mylist *newMylist()
{
    Mylist *nums = (int *)malloc(sizeof(Mylist));
    nums->capacity = 10;
    nums->arr = (int *)malloc(sizeof(int) * nums->capacity);
    nums->size = 0;
    nums->extendRatio = 2;
    return nums;
}

// 析构函数
void delMylist(Mylist *nums)
{
    free(nums->arr);
    free(nums);
}

// 获取列表容量
int capacity(Mylist *nums)
{
    return nums->capacity;
}

// 获取列表大小
int size(Mylist *nums)
{
    return nums->size;
}

// 列表转换为数组
int *toArray(Mylist *nums)
{
    return nums->arr;
}

// 访问元素
int get(Mylist *nums, int index)
{
    assert(index >= 0 && index < nums->size);
    return nums->arr[index];
}

// 更新元素
void set(Mylist *nums, int index, int newNum)
{
    assert(index >= 0 && index < nums->size);
    nums->arr[index] = newNum;
}

// 列表扩容
void extendCapacity(Mylist *nums)
{
    // 分配空间
    int newCapacity = capacity(nums) * nums->extendRatio;
    int *extendNums = (int *)malloc(sizeof(int) * newCapacity);
    int *oldArr = nums->arr;
    // 旧数组复制到新数组
    for (int i = 0; i < size(nums); i++)
    {
        extendNums[i] = oldArr[i];
    }
    // 释放旧数据
    free(oldArr);
    // 更新数据到原数组
    nums->arr = extendNums;
    nums->capacity = newCapacity;
}

// 在尾部添加元素
void addLast(Mylist *nums, int newNum)
{
    if (size(nums) == capacity(nums))
    {
        extendCapacity(nums);
    }
    nums->arr[size(nums)] = newNum;
    nums->size++;
}

// 在中间插入元素
void insert(Mylist *nums, int index, int newNum)
{
    assert(index >= 0 && index <= size(nums));

    if (size(nums) == capacity(nums))
    {
        extendCapacity(nums);
    }

    // index后面的元素后移一位
    for (int i = size(nums); i > index; i--)
    {
        nums->arr[i] = nums->arr[i - 1];
    }

    nums->arr[index] = newNum;
    nums->size++;
}

// 删除元素
int removeItem(Mylist *nums, int index)
{
    assert(index >= 0 && index < size(nums));

    int removedNum = nums->arr[index];

    // index以及后面的元素前移一位
    for (int i = index; i < size(nums) - 1; i++)
    {
        nums->arr[i] = nums->arr[i + 1];
    }

    nums->size--;

    return removedNum;
}
