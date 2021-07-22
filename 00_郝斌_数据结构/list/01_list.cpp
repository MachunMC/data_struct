/*
 * @Descripttion: 
 * @version: 
 * @Author: machun Michael
 * @Date: 2021-07-21 16:31:22
 * @LastEditors: machun Michael
 * @LastEditTime: 2021-07-22 19:51:48
 */
/*
 * @Author: machun Michael 
 * @Date: 2021-07-21 16:31:27 
 * @Last Modified by: machun Michael
 * @Last Modified time: 2021-07-We 04:40:57
 */

// 复习代码
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct Node 
{
    int val;             // 数据部分
    struct Node *pNext;  // 指针部分
};

/**
 * @description: 创建链表
 * @param: void
 * @return: 成功返回0，失败返回-1
 */
struct Node* create_list(void);

/**
 * @description: 追加节点到链表末尾
 * @param {struct Node} *pHead
 * @return {*}
 */
int append_to_list(struct Node *pHead);

/**
 * @description: 遍历链表
 * @param: {struct Node} *pHead
 * @return {*}
 */
int traverse_list(struct Node *pHead);


int main()
{
    struct Node *pHead = NULL;
    
    pHead = create_list();


    return 0;
}


struct Node* create_list(void)
{
    struct Node *pHead = NULL;
    struct Node *pNew = NULL;
    struct Node *pNode = NULL;
    int len = 0;
    
    printf("please input len of list:");
    scanf("%d", &len);

    // 先创建一个头节点，不包含数据域
    pHead = (struct Node*)malloc(sizeof(struct Node));
    if (NULL == pHead)
    {
        printf("malloc failed\n");
        return NULL;
    }
    pHead->pNext = NULL;
    pHead->val = 0;

    pNode = pHead;
    for (int i = 0; i < len; i++)
    {
        pNew = (struct Node*)malloc(sizeof(struct Node));
        pNew->pNext = NULL;
        scanf("%d", &pNew->val);

        pNode->pNext = pNew;
        pNode = pNew;
    }

    return 0;
}