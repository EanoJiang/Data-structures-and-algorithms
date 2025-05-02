#include <stdio.h>
#include <stdlib.h>

//访问元素
//  随机访问
int randomAccess(int *nums, int size){
    int randomIndex = rand() % size;
    // size = sizeof(nums) / sizeof(nums[0]);
    int randomNumd = nums[randomIndex];
    return randomNumd;
}

// 插入元素(在index位置插入num)
void insert(int *nums, int size, int num, int index){
    for(int i = size - 1; i > index; i--){
        nums[i] = nums[i - 1];
    }
    nums[index] = num;
}

// 删除元素(删除index位置的元素)
//  注意：stdio.h 占用了 remove 关键词
void removeItem(int *nums, int size, int index){
    for(int i = size - 1; i < index; i++){
        nums[i] = nums[i + 1];
    }
}

// 遍历数组
void traverse(int *nums, int size){
    int temp = 0;
    for (int i = 0; i < size; i++){
        temp = nums[i];
        printf("num = %d\n", temp);
    }
}

// 查找元素
int search(int *nums, int size, int target){
    for (int i = 0; i < size; i++){
        if (nums[i] == target){
            return i;
        }
    }  
    return -1; // 未找到元素，返回一个不可能出现的索引值
}

// 扩展数组
int *extendArray(int *nums, int size, int newSize){
    // 新数组的动态内存分配
    int *newNums = (int *)malloc(newSize * sizeof(int));
    // 把原数组的元素依次添加到新数组中
    for (int i = 0; i< size; i++){
        newNums[i] = nums[i];
    }
    // 初始化新数组中剩余的元素
    for (int i = size; i < newSize; i++){
        newNums[i] = 0;
    }
    return newNums;
}



//数组初始化
int main(){
    int arr[5] = {0};
    int nums[5] = {1, 2, 3, 4, 5};
    //traverse(nums, 5);
    int temp = search(nums, 5, 0);
    printf("index = %d\n", temp);

}