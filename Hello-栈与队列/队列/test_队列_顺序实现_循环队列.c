#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 最大容量
#define MAXSIZE 4

typedef int ElemType;

typedef struct
{
    ElemType *data;
    ElemType front, rear;
} Queue;

Queue *initQueue()
{
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->data = (ElemType *)malloc(MAXSIZE * sizeof(ElemType));
    q->front = 0;
    q->rear = 0;
    return q;
}

int count = 0;

bool isEmpty(Queue *q)
{
    return count == 0 && q->rear == q->front;
}

// 入队
// 从队尾入队
int push(Queue *q, ElemType e)
{
    // 队列满的时候，rear+1 == MAXSIZE，因为rear和front都是从0开始计数的
    if (count == MAXSIZE && (q->rear + 1) % MAXSIZE == q->front)
    {
        printf("队列已满！\n");
        return -1;
    }
    q->data[q->rear] = e;
    //更新rear索引
    q->rear = (q->rear + 1) % MAXSIZE;
    count++;
    printf("当前的元素个数为:%d\n",count);
    return 1;
}

// 出队
// 从队首出队
ElemType pop(Queue *q, ElemType *e)
{
    if (isEmpty(q))
    {
        printf("队列为空！\n");
        return -1;
    }
    *e = q->data[q->front];
    //更新front索引
    q->front = (q->front + 1) % MAXSIZE;
    count--;
    printf("当前的元素个数为:%d\n",count);
    return *e;
}

// 获取队首元素
ElemType getFront(Queue *q)
{
    if (isEmpty(q))
    {
        printf("队列为空！\n");
        return -1;
    }
    return q->data[q->front];
}

int main()
{
    Queue *q = initQueue();
    push(q, 1);
    push(q, 2);
    push(q, 3);
    push(q, 4);

    printf("队首元素为：%d\n", getFront(q));

    ElemType e;
    pop(q, &e);
    printf("出队元素为：%d\n", e);
    pop(q, &e);
    printf("出队元素为：%d\n", e);
    return 0;
}