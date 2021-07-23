/*
 * @Descripttion: 
 * @version: 
 * @Author: machun Michael
 * @Date: 2021-07-21 16:31:22
 * @LastEditors: machun Michael
 * @LastEditTime: 2021-07-23 16:16:21
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
 * @description: 判断链表是否为空
 * @param {struct Node} *pHead：链表头节点
 * @return: 空返回true，非空返回false
 */
bool if_list_empty(struct Node *pHead);

/**
 * @description: 遍历链表，不包括头节点
 * @param: {struct Node} *pHead
 * @return {*}
 */
int traverse_list(struct Node *pHead);

/**
 * @description: 追加节点到链表末尾
 * @param：
 *          {struct Node} *pHead：链表头节点
 *          val：节点的值
 * @return {*}
 */
int append_to_list(struct Node *pHead, int val);

/**
 * @description: 插入节点到链表的pos位置后面，pos从0开始
 * @param: pHead：链表头节点
 * @param: pos：位置
 * @param: val：值
 * @return {*}
 */
int insert_to_list(struct Node *pHead, int pos, int val);

/**
 * @description: 删除链表第pos个节点
 * @param {struct Node} *pHead，链表头节点
 * @param {int} pos，位置，从0开始
 * @return：成功返回0，失败返回-1
 */
int delete_from_list(struct Node *pHead, int pos);


int main()
{
    struct Node *pHead = NULL;
    
    pHead = create_list();
    if (NULL == pHead)
    {
        printf("create list failed\n");
        return -1;
    }
    else
    {
        printf("create list succ\n");
    }

    append_to_list(pHead, 10);
    append_to_list(pHead, 2);
    append_to_list(pHead, 3);
    append_to_list(pHead, 5);
    
    traverse_list(pHead);

    return 0;
}

struct Node* create_list(void)
{
    struct Node *pHead = NULL;
    struct Node *pNew = NULL;
    struct Node *pNode = NULL;
    int len = 0;
    int val = 0;
    
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
        
        printf("Please input node[%d] value:", i);
        scanf("%d", &pNew->val);
        pNode->pNext = pNew;
        pNode = pNew;
    }

    return pHead;
}

bool if_list_empty(struct Node *pHead)
{
    if (pHead->pNext == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int append_to_list(struct Node *pHead, int val)
{
    struct Node *pNode = pHead;
    struct Node *pNew = NULL;

    if (NULL == pHead)
    {
        printf("null param\n");
        return -1;
    }

    // 找到链表的尾节点
    while(pNode->pNext != NULL)
    {
        pNode = pNode->pNext;
    }

    pNew = (struct Node*)malloc(sizeof(struct Node));
    if (NULL == pNew)
    {
        printf("malloc failed\n");
        return -1;
    }
    pNew->val = val;
    pNew->pNext = NULL;
    pNode->pNext = pNew;

    printf("append value:%d to list\n", val);
    
    return 0;
}

/**
 * @description: 遍历链表，不包括头节点
 * @param: {struct Node} *pHead
 * @return：成功返回0，失败返回-1
 */
int traverse_list(struct Node *pHead)
{
    int len = 0;
    struct Node *pNode = pHead->pNext;

    while(pNode != NULL)
    {
        printf("Node[%d]: %d\n", len++, pNode->val);
        pNode = pNode->pNext;
    }
    printf("list len:%d", len);
    
    return 0;
}


/**
 * @description: 插入节点到链表的pos位置后面，pos从0开始，不包括头节点
 * @param: pHead：链表头节点
 * @param: pos：位置
 * @param: val：值
 * @return {*}
 */
int insert_to_list(struct Node *pHead, int pos, int val)
{
    struct Node *pNode = pHead;
    struct Node *pNew = NULL;

    // 先找到pos位置
    for (int i = 0; i < pos; i++)
    {
        pNode = pNode->pNext;
    }

    pNew = (struct Node*)malloc(sizeof(struct Node));
    if (NULL == pNew)
    {
        printf("malloc failed\n");
        return -1;
    }
    pNew->val = val;

    pNew->pNext = pNode->pNext;

    

    

    return 0;
}


/**
 * @description: 删除链表第pos个节点
 * @param {struct Node} *pHead，链表头节点
 * @param {int} pos，位置，从0开始
 * @return：成功返回0，失败返回-1
 */
int delete_from_list(struct Node *pHead, int pos)
{

    return 0;
}