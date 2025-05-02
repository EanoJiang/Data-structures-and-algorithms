#include <stdio.h>
#include <stdlib.h> // 添加stdlib.h头文件以使用malloc

#define MAXSIZE 100
typedef int ElemType;

/*顺序表——动态分配内存地址初始化*/
typedef struct {
    ElemType *data;
    int length;
}SeqList;

SeqList *initList(SeqList *L){
    L = (SeqList *)malloc(sizeof(SeqList));
    L->data = (ElemType *)malloc(sizeof(ElemType)*MAXSIZE); // 为L分配内存
    L->length = 0;
    return L;
}

/*顺序表——添加元素到末尾*/
int appendElem(SeqList *L, ElemType new){
    if(L->length >= MAXSIZE){
        printf("列表已满\n");
        return -1;
    }
    //将元素添加到末尾
    L->data[L->length] = new;
    //更新length
    L->length++;
    return 1;
}

/*顺序表——遍历打印*/
void listElem(SeqList *L){
    for(int i = 0; i < L->length; i++){
        printf("%d ",L->data[i]);
    }
    printf("\n");
}

/*顺序表——插入元素*/
//头插法，后面的元素都向后移动一位
void insertElem(SeqList *L, int target_index, ElemType new){
    if(L->length >= MAXSIZE){
        printf("列表已满\n");
        return;
    }
    if(target_index < 0 || target_index > L->length){
        printf("插入位置不合法\n");
        return;
    }

    if(target_index <= L->length){
        for(int i = L->length - 1; i >= target_index; i--){
            L->data[i+1] = L->data[i];
        }
        L->data[target_index] = new;
        L->length++;
    }
}

/*顺序表——删除元素*/
//后面的元素都向前移动一位
int deleteElem(SeqList *L, int target_index,ElemType *del){
    //是否合法省略...

    //指针写入删除的元素
    *del = L->data[target_index];

    if(target_index <= L->length){
        for(int i = target_index; i < L->length; i++){
            L->data[i] = L->data[i+1];
        }
        L->length--;
    }
    return 1;
}

/*顺序表——查找*/
int findElem(SeqList *L, ElemType target){
    for(int i = 0; i < L->length; i++){
        if(L->data[i] == target){
            return i;
        }
    }
    return 0;
}

int main(){
    //创建的是一个指针，需要在声明的时候立刻分配内存
    SeqList *list = initList(list);
    
    printf("初始化成功\n");
    printf("length = %d\n", list->length);
    printf("占用字节数 %zu\n", sizeof(list->data));
    printf("\n");

    appendElem(list, 1);
    appendElem(list, 2);
    appendElem(list, 3);
    
    listElem(list);

    insertElem(list, 2, 99);
    listElem(list);

    ElemType delData;
    deleteElem(list, 2, &delData);
    printf("删除元素:%d\n", delData);
    listElem(list);

    printf("查找元素的index: %d\n",findElem(list, 2));

    //记得释放内存
    free(list->data);
    free(list);
    
    return 0;
}
