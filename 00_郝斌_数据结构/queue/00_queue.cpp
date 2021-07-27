/*
 * @Descripttion:用数组实现一个循环队列（环形队列）
 * @version: 
 * @Author: machun Michael
 * @Date: 2021-07-27 19:08:05
 * @LastEditors: machun Michael
 * @LastEditTime: 2021-07-27 19:55:22
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

#define QUEUE_LEN 10

struct Queue
{
    int *pBase;  // 用于实现队列的数组的首地址
    int len;     // 队列长度，即数组长度
    int front;   // 指向队首元素的索引
    int rear;    // 指向队尾下一个元素的索引
};


// 函数声明
int create_queue(struct Queue *pQueue, int len);
bool if_queue_empty(struct Queue *pQueue);
bool if_queue_full(struct Queue *pQueue);
int in_queue(struct Queue *pQueue, int val);
int out_queue(struct Queue *pQueue, int *pVal);
int traverse_queue(struct Queue *pQueue);

int main(void)
{
    int val = 0;
    struct Queue tQueue;

    if (0 == create_queue(&tQueue, QUEUE_LEN))
    {
        printf("create queue succ\n");
    }
    else
    {
        printf("create queue failed\n");
        return -1;
    }

    in_queue(&tQueue, 1);
    in_queue(&tQueue, 2);
    in_queue(&tQueue, 3);
    in_queue(&tQueue, 4);
    in_queue(&tQueue, 5);
    in_queue(&tQueue, 6);
    in_queue(&tQueue, 7);
    in_queue(&tQueue, 8);
    in_queue(&tQueue, 9);
    in_queue(&tQueue, 10);
    in_queue(&tQueue, 11);
    in_queue(&tQueue, 12);
    in_queue(&tQueue, 13);
    in_queue(&tQueue, 14);
    in_queue(&tQueue, 15);
    traverse_queue(&tQueue);

    out_queue(&tQueue, &val);
    out_queue(&tQueue, &val);
    out_queue(&tQueue, &val);
    out_queue(&tQueue, &val);
    out_queue(&tQueue, &val);
    out_queue(&tQueue, &val);
    out_queue(&tQueue, &val);
    out_queue(&tQueue, &val);
    out_queue(&tQueue, &val);
    out_queue(&tQueue, &val);
    out_queue(&tQueue, &val);
    out_queue(&tQueue, &val);
    traverse_queue(&tQueue);

    return 0;
}


/**
 * @description: 创建一个环形队列
 * @param {struct Queue} *pQueue，队列指针
 * @param {int} len，队列长度
 * @return: 成功返回0，失败返回-1
 */
int create_queue(struct Queue *pQueue, int len)
{
    pQueue->len = len;
    pQueue->front = 0;
    pQueue->rear = 0;

    pQueue->pBase = (int *)malloc(sizeof(int) * len);
    if (NULL == pQueue->pBase)
    {
        printf("malloc failed\n");
        return -1;
    }
    memset(pQueue->pBase, 0, sizeof(sizeof(int) * len));

    return 0;
}

/**
 * @description: 判断队列是否为空
 * @param {struct Queue} *pQueue，队列指针
 * @return：空返回true，非空返回false
 */
bool if_queue_empty(struct Queue *pQueue)
{
    if (pQueue->rear == pQueue->front)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/**
 * @description: 判断队列是否满
 * @param {struct Queue} *pQueue，队列指针
 * @return：满返回true，不满返回false
 */
bool if_queue_full(struct Queue *pQueue)
{
    if (pQueue->front == (pQueue->rear + 1) % pQueue->len)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/**
 * @description: 入队
 * @param {struct Queue} *pQueue，队列指针
 * @param {int} val，要入队的值
 * @return: 成功返回0，失败返回-1
 */
int in_queue(struct Queue *pQueue, int val)
{
    if (if_queue_full(pQueue))
    {
        printf("queue full\n");
        return -1;
    }

    pQueue->pBase[pQueue->rear] = val;
    pQueue->rear = (pQueue->rear + 1) % pQueue->len;

    printf("in queue succ, val:%d\n", val);
    return 0;
}

/**
 * @description: 出队
 * @param {struct Queue} *pQueue，队列指针
 * @param {int} *pVal，保存出队的值
 * @return: 成功返回0，失败返回-1
 */
int out_queue(struct Queue *pQueue, int *pVal)
{
    if (if_queue_empty(pQueue))
    {
        printf("queue empty\n");
        return -1;
    }

    *pVal = pQueue->pBase[pQueue->front];
    pQueue->pBase[pQueue->front] = 0;
    pQueue->front = (pQueue->front + 1) % pQueue->len;

    printf("out queue succ, val:%d\n", *pVal);
    return 0;
}

/**
 * @description: 遍历队列
 * @param {struct Queue} *pQueue，队列指针
 * @return: 成功返回0，失败返回-1
 */
int traverse_queue(struct Queue *pQueue)
{
    int temp = pQueue->front;

    if (if_queue_empty(pQueue))
    {
        printf("queue empty\n");
        return -1;
    }
    
    while(temp != pQueue->rear)
    {
        printf("%d ", pQueue->pBase[temp]);
        temp = (temp + 1) % pQueue->len;
    }
    printf("\n");

    return 0;
}