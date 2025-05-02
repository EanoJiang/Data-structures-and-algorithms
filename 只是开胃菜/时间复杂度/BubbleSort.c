#include <stdio.h>
//冒泡排序
int BubbleSort(int *nums,int n){
    int count = 0;
    for (int i = n - 1; i >= 0; i--){
        for (int j = 0; j < i; j++){
            if (nums[j] > nums[j+1]){
                int temp = nums[j];
                nums[j] = nums[j+1];
                nums[j+1] = temp;
                //单层操作数为3
                count += 3;
            }
        }
    }
    return count;
}

int main(){
    int nums[] = {1, 3, 2, 5, 4, 7, 6, 9};
    int n = sizeof(nums)/sizeof(nums[0]);
    int count = bubbleSort(nums,n);
    printf("冒泡排序共进行%d次操作\n", count);
    return 0;
}