/*
 * @Descripttion: 
 * @version: 
 * @Author: machun Michael
 * @Date: 2021-07-21 16:31:22
 * @LastEditors: machun Michael
 * @LastEditTime: 2021-07-21 17:44:42
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
 * @param: {struct Node} *pHead
 * @return: 成功返回0，失败返回-1
 */
int create_list(struct Node *pHead);

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
    



    return 0;
}