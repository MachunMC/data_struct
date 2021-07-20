/*
 * @Author: machun Michael 
 * @Date: 2021-07-20 21:01:28 
 * @Last Modified by: machun Michael
 * @Last Modified time: 2021-07-20 22:18:19
 */
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct Node 
{
    int data;               // 数据域
    struct  Node *pNext;    // 指针域
};

/**
 * 功能：创建一个链表
 * 参数：void
 * 返回值：成功返回链表的首节点，失败返回NULL
 **/
struct Node * create_list(void);

/**
 * 功能：遍历链表
 * 参数：链表头结点
 * 返回值：返回链表长度
 **/
int traverse_list(struct Node *pHead);

/**
 * 功能：判断链表是否为空
 * 参数：链表头结点
 * 返回值：成功返回true，失败返回false
 **/
bool if_list_empty(struct Node *pHead);

/**
 * 功能：将链表的值按照从小到大的顺序重新排列
 * 参数：链表头结点
 * 返回值：成功返回0，失败返回-1
 **/
int sort_list(struct Node *pHead);

/**
 * 功能：插入一个值到链表指定位置
 * 参数：
 *      pHead：链表头结点
 *      pos：插到第几个节点后面（节点从首节点开始，pos从0开始）
 *      val：插入的值
 * 返回值：成功返回0，失败返回-1
 **/
int insert_into_list(struct Node *pHead, int pos, int val);

/**
 * 功能：从链表中删除指定位置的节点
 * 参数：
 *      pHead：链表头结点
 *      pos：要删除第几个节点
 * 返回值：成功返回0，失败返回-1
 **/
int delete_from_list(struct Node *pHead, int pos);

int main(void)
{
    int ret = 0;
    int len = 0;
    struct Node *pHead = NULL;

    pHead = create_list();
    if (NULL == pHead)
    {
        printf("create list failed\n");
        return -1;
    }

    printf("After create list\n");
    traverse_list(pHead);
    printf("\n");

    sort_list(pHead);
    printf("After sort list\n");
    traverse_list(pHead);
    printf("\n");

    insert_into_list(pHead, 2, 88);
    printf("After insert into list, node 2, val 88\n");
    traverse_list(pHead);
    printf("\n");

    delete_from_list(pHead, 3);
    printf("After delete from list, node 3\n");
    traverse_list(pHead);
    printf("\n");
    
    return 0;
}

struct Node * create_list(void)
{
    int len = 0;
    struct Node *pHead = NULL;
    struct Node *pNode = NULL;
    struct Node *pNew = NULL;

    printf("please input list len:");
    scanf("%d", &len);

    pHead = (struct Node *)malloc(sizeof(struct Node));
    if (NULL == pHead)
    {
        printf("malloc list head failed\n");
        return NULL;
    }
    pHead->pNext = NULL;
    pHead->data = 0;

    pNode = pHead;
    for (int i = 0; i < len; i++)
    {
        pNew = (struct Node*)malloc(sizeof(struct Node));
        if(NULL == pNew)
        {
            printf("malloc list node failed\n");
            return NULL;
        }

        pNode->pNext = pNew;
        pNew->pNext = NULL;
        printf("please input node[%d] value:", i);
        scanf("%d", &pNew->data);

        pNode = pNew;
    }

    return pHead;
}

int traverse_list(struct Node *pHead)
{
    int len = 0;
    struct Node *pNode = pHead->pNext;

    while(pNode != NULL)
    {
        printf("node[%d]:%d\n", len++, pNode->data);
        pNode = pNode->pNext;
    }

    return len;
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

int sort_list(struct Node *pHead)
{
    int val = 0;
    struct Node *pNode = pHead->pNext;
    struct Node *pTemp = NULL;

    while(pNode != NULL)
    {
        pTemp = pNode->pNext;
        while(pTemp != NULL)
        {
            if (pNode->data > pTemp->data)
            {
                val = pNode->data;
                pNode->data = pTemp->data;
                pTemp->data = val;
            }
            pTemp = pTemp->pNext;
        }
        pNode = pNode->pNext;
    }

    return 0;
}

int insert_into_list(struct Node *pHead, int pos, int val)
{
    int len = 0;
    struct Node *pNode = pHead;
    struct Node *pNew = NULL;
    
    // 先判断插入位置pos是否合法，pNode指向要插入的那个节点的前一个节点
    while(pNode->pNext != NULL)
    {
        if (++len > pos)
        {
            break;
        }
        pNode = pNode->pNext;
    }

    if (len <= pos)
    {
        printf("list is too short, list len:%d, pos:%d\n", len, pos);
        return -1;
    }

    pNew = (struct Node*)malloc(sizeof(struct Node));
    if (NULL == pNew)
    {
        printf("malloc failed\n");
        return -1;
    }

    pNode = pNode->pNext;
    pNew->pNext = pNode->pNext;
    pNew->data = val;
    pNode->pNext = pNew;

    return 0;
}

int delete_from_list(struct Node *pHead, int pos)
{
    int len = 0;
    struct Node *pNode = pHead;
    struct Node *pTemp = NULL;
    
    // 先判断要删除的位置pos是否合法，pos指向要删除节点的前一个节点
    while(pNode->pNext != NULL)
    {
        if (++len > pos)
        {
            break;
        }

        pNode = pNode->pNext;
    }

    if (len <= pos)
    {
        printf("list is too short, list len:%d, pos:%d\n", len, pos);
        return -1;
    }

    pTemp = pNode->pNext;
    pNode->pNext = pTemp->pNext;
    free(pTemp);

    return 0;
}