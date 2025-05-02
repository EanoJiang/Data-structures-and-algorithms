#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//链表结构体
typedef struct ListNode{
    int val;
    struct ListNode *next;
}ListNode;

//创建一个新节点
ListNode *newListNode(int val){
    ListNode *node = (ListNode*)malloc(sizeof(ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

//队列结构体
typedef struct LinkedListQueue{
    ListNode *front;
    ListNode *rear;
    int queueSize;
}LinkedListQueue;

//创建一个空队列
LinkedListQueue *newLinkedListQueue(){
    LinkedListQueue *queue = (LinkedListQueue*)malloc(sizeof(LinkedListQueue));
    queue->front = NULL;
    queue->rear = NULL;
    queue->queueSize = 0;
    return queue;
}

//析构函数（构造函数的相反操作，相当于删除原来的构造）
void delLinkedListQueue(LinkedListQueue *queue){
    while(queue->front!= NULL){
        ListNode *temp = queue->front;
        queue->front = queue->front->next;//从头节点开始删除
        free(temp);//释放头节点
    }
    free(queue);//释放最后的链表
}

//获取队列长度
int size(LinkedListQueue *queue){
    return queue->queueSize;
}

//判断队列是否为空
bool isEmpty(LinkedListQueue *queue){
    return size(queue) == 0;
}

//入队
void pop(LinkedListQueue *queue,int val){
    //入队：队尾入队

    ListNode *node = newListNode(val); //创建新节点node
    //如果队列空的话，则头节点和尾节点指向同一个节点
    if(isEmpty(queue)){
        queue->front = node;
        queue->rear = node;  
    }
    //不为空
    queue->rear->next = node;//队尾入队
    queue->rear = node;//更新队尾
    queue->queueSize++;
}

//访问队首元素
int peek(LinkedListQueue *queue){
    return queue->front->val;   
}

//出队
int pop(LinkedListQueue *queue){
    //出队：队首出队

    int val = peek(queue);
    
    ListNode *temp = queue->front;//保存原来的队首
    queue->front = queue->front->next; //队首出队
    free(temp);//释放原来的队首

    return val;
}

void printArray(int *arr,int size){
    for (int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
//打印队列
void printQueue(LinkedListQueue *queue){
    int *arr = (int*)malloc(sizeof(int)*size(queue));//定义一个数组用来存放后面的每个队列元素
    ListNode *node = queue->front;
    for(int i = 0; i < size(queue); i++){
        arr[i] = node->val;
        node = node->next;
    }
    printArray(arr,size(queue));
    free(arr);
}




