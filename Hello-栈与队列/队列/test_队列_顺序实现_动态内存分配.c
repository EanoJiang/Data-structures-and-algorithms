#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXSIZE 100
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

bool isEmpty(Queue *q)
{
    return q->front == q->rear;
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
    q->front++;
    return *e;
}

bool frontIsEmpty(Queue *q)
{
    if (q->front == 0)
    {
        printf("队首不空\n");
        return 0;
    }
    // 队首索引不为0,说明前面有空的位置，需要挪过去
    else
    {
        int step = q->front;
        for (int i = q->front; i <= q->rear; i++)
        {
            q->data[i - step] = q->data[i];
        }
        q->front = 0;
        q->rear = q->rear - step;
        return 1;
    }
}

// 入队
// 从队尾入队
int push(Queue *q, ElemType e)
{
    // 队尾到头的情况下，队首不空，说明队列已满
    if (q->rear == MAXSIZE - 1 && !frontIsEmpty(q))
    {
        printf("队列已满！\n");
        return 0;
    }
    q->data[q->rear] = e;
    q->rear++;
    return 1;
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