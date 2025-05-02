#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 最大容量
typedef int ElemType;

// 队列节点
typedef struct QueueNode
{
    ElemType data;
    struct QueueNode *next;
} QueueNode;

// 队列
typedef struct{
    QueueNode *front;
    QueueNode *rear;
}Queue;

Queue* initQueue()
{
    QueueNode *qNode = (QueueNode *)malloc(sizeof(QueueNode));
    qNode->data = 0;
    qNode->next = NULL;
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->front = qNode;
    q->rear = qNode;

    return q;
}

// 队列是否为空
bool isEmpty(Queue *q)
{
    return q->rear == q->front;
}

// 入队
// 从队尾入队
// 尾插法
int push(Queue *q, ElemType e)
{
    QueueNode *qNode = (QueueNode *)malloc(sizeof(QueueNode));
    qNode->data = e;
    qNode->next = NULL;
    //插在尾节点的next
    q->rear->next = qNode;
    q->rear = qNode;
    return 1;
}

// 出队
// 从队首出队
ElemType pop(Queue *q, ElemType *e)
{
    QueueNode *qnode = q->front->next;
    *e = qnode->data;
    q->front->next = qnode->next;
    if(q->rear == qnode){
        q->rear = q->front;
    }
    free(qnode);
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
    return q->front->next->data;
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