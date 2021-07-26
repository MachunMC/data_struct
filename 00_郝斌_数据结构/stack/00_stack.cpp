/*
 * @Descripttion: 用链表来实现一个栈（先进后出）
 * @version: 
 * @Author: machun Michael
 * @Date: 2021-07-21 18:58:12
 * @LastEditors: machun Michael
 * @LastEditTime: 2021-07-26 15:20:59
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

// 定义链表的节点
struct Node
{
    int val; // 数据域
    struct Node *pNext; // 指针域
};

// 定义一个栈的结构体
struct Stack
{
    struct Node *pBottom; // 指向栈底，为了便于链表操作，pBottom指向链表最后一个有效元素后的一个空元素（不含有效数据）
    struct Node *pTop;    // 指向栈顶
};

int init_stack(struct Stack *pStack);
int push_stack(struct Stack *pStack, int val);
int pop_stack(struct Stack *pStack, int *pVal);
int traverse_stack(struct Stack *pStack);
int clear_stack(struct Stack *pStack);
int destroy_stack(struct Stack *pStack);


int main(void)
{
    int val = 0;
    struct Stack tStack;
    memset(&tStack, 0, sizeof(struct Stack));

    if (0 == init_stack(&tStack))
    {
        printf("init stack succ\n");
    }
    else
    {
        printf("init stack failed\n");
    }

    push_stack(&tStack, 1);
    push_stack(&tStack, 2);
    push_stack(&tStack, 3);
    push_stack(&tStack, 4);
    push_stack(&tStack, 5);
    push_stack(&tStack, 6);
    traverse_stack(&tStack);

    pop_stack(&tStack, &val);
    pop_stack(&tStack, &val);
    pop_stack(&tStack, &val);
    pop_stack(&tStack, &val);
    pop_stack(&tStack, &val);
    traverse_stack(&tStack);

    clear_stack(&tStack);
    traverse_stack(&tStack);

    destroy_stack(&tStack);

    return 0;
}

/**
 * @description: 初始化栈
 * @param：{struct Stack} *pStack：指向栈的指针
 * @return：成功返回0，失败返回-1
 */
int init_stack(struct Stack *pStack)
{
    // 0. 申请一个头结点
    pStack->pBottom = (struct Node*)malloc(sizeof(struct Node));
    if (NULL == pStack)
    {
        printf("malloc failed\n");
        return -1;
    }

    // 1. 头结点的指针域置为NULL，数据域置为0
    pStack->pBottom->pNext = NULL;
    pStack->pBottom->val = 0;

    // 2. pTop指向pBottom
    pStack->pTop = pStack->pBottom;

    return 0;
}

/**
 * @description: 入栈（往栈中添加一个元素）
 * @param {struct Stack} *pStack，指向栈的指针
 * @param {int} val，入栈的值
 * @return：成功返回0，失败返回-1
 */
int push_stack(struct Stack *pStack, int val)
{
    // 0. 申请一个节点
    struct Node *pNew = (struct Node*)malloc(sizeof(struct Node));
    if (NULL == pNew)
    {
        printf("malloc failed\n");
        return -1;
    }
    pNew->pNext = pStack->pTop;
    pNew->val = val;

    // 1. pTom指向新节点
    pStack->pTop = pNew;

    return 0;
}

/**
 * @description: 出栈（从栈中取出一个元素）
 * @param {struct Stack} *pStack，指向栈的指针
 * @param {int} *pVal，保存出栈元素的值
 * @return：成功返回0，失败返回-1
 */
int pop_stack(struct Stack *pStack, int *pVal)
{
    // 需要判断栈是否为空
    if (pStack->pTop == pStack->pBottom)
    {
        printf("%s:%d stack empty\n", __func__, __LINE__);
    }
    else
    {
        // 0. 定义一个指针指向pTop
        struct Node *pNode = pStack->pTop;

        // 1. pTop指向pTop->pNext
        pStack->pTop = pStack->pTop->pNext;

        // 2. 销毁pNode
        printf("pop stack succ, val:%d\n", pNode->val);
        free(pNode);
    }

    return 0;
}

/**
 * @description: 遍历栈
 * @param {struct Stack} *pStack，指向栈的指针
 * @return：成功返回0，失败返回-1
 */
int traverse_stack(struct Stack *pStack)
{
    if (pStack->pTop == pStack->pBottom)
    {
        printf("%s:%d stack empty\n", __func__, __LINE__);
        return 0;
    }
    else
    {
        struct Node *pNode = pStack->pTop;
        printf("traverse stack:");
        while(pNode != pStack->pBottom)
        {
            printf("%d ", pNode->val);
            pNode = pNode->pNext;
        }
        printf("\n");

        return 0;
    }
}

/**
 * @description: 清空栈：释放头结点外的所有有效节点，只保留头结点，使pTom等于pBottom
 * @param {struct Stack} *pStack，指向栈的指针
 * @return：成功返回0，失败返回-1
 */
int clear_stack(struct Stack *pStack)
{
    if (pStack->pTop == pStack->pBottom)
    {
        printf("%s:%d stack empty\n", __func__, __LINE__);
    }
    else
    {
        printf("clear stack\n");
        struct Node *pNode = pStack->pTop;

        while(pNode != pStack->pBottom)
        {
            pStack->pTop = pNode->pNext;
            free(pNode);
            pNode = pStack->pTop;
        }
    }

    return 0;
}

/**
 * @description: 销毁栈：清空栈，并销毁头结点
 * @param {struct Stack} *pStack，指向栈的元素
 * @return：成功返回0，失败返回-1
 */
int destroy_stack(struct Stack *pStack)
{
    // 0. 清空栈
    clear_stack(pStack);

    // 1. 释放头结点
    free(pStack->pBottom);
    pStack->pTop = NULL;
    pStack->pBottom = NULL;
    
    return 0;
}