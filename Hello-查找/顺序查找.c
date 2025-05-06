#include <stdio.h>

void search(char *arr, int length, int key) {
    for(int i = 0; i < length; i++) {
        if(arr[i] == key) {
            printf("%d found at index %d\n", key, i);
            return;
        }
    }
    printf("%d not found\n", key);
}

int main(){
    char arr[] = {8,12,5,16,55,24,20,18,36,6,50};
    search(arr,sizeof(arr)/sizeof(arr[0]), 55);
    return 0;
}