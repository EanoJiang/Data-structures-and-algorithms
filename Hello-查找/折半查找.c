#include <stdio.h>
//非递归实现
int binarySearch(int *arr, int length, int target) {
    //初始化左右边界
    int i = 0, j = length - 1, mid;
    //区间[i,j]存在
    while(i <= j){
        mid = i + (j - i) / 2;
        //目标在右半部分，也就是[mid+1,j]
        if(arr[mid] < target){
            i = mid+1;
        }
        //目标在左半部分，也就是[i,mid-1]
        else if(arr[mid] > target){
            j = mid-1;
        }
        //找到目标元素,arr[mid] == target
        else{
            return mid;
        }
    }
    //没找到目标元素
    return -1;
}

//递归实现
int binarySearch_Recursive(int *arr, int target, int low, int high) {
    //递归结束条件    
    if(low > high) return -1;
    int mid = low + (high - low) / 2;

    //目标在右半部分，也就是[mid+1,high]
    if(arr[mid] < target){
        return binarySearch_Recursive(arr, target, mid+1, high);
    }
    //目标在左半部分，也就是[low,mid-1]
    else if(arr[mid] > target){
        return binarySearch_Recursive(arr, target, low, mid-1);
    }
    //找到目标元素,arr[mid] == target
    else{
        return mid;
    }
}

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int length = sizeof(arr) / sizeof(arr[0]);
    int target = 15;
    int index = binarySearch(arr, length, target);
    if(index == -1)printf("Not found %d\n", target);
    else printf("Found %d at index %d\n", target, index);
    return 0;
}
