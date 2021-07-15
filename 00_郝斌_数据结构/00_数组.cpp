/*
 * @Author: machun Michael 
 * @Date: 2021-07-15 22:35:21 
 * @Last Modified by: machun Michael
 * @Last Modified time: 2021-07-15 22:56:16
 */
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

// 定义一个数据类型
struct Array
{
    int *pBase;  // 存储的是数组第一个元素的地址
    int len;     // 存储的是数组的长度
    int cnt;     // 存储的是数组有效元素的个数
};

/**
 * 描述：数组初始化
 * 参数：ptArr：结构体指针
 *      len：数组长度
 **/
void init_array(struct Array *ptArr, int len);

/**
 * 描述：判断数组是否为空
 * 参数：ptArr：结构体指针
 **/
bool if_array_empty(struct Array *ptArr);

/**
 * 描述：判断数组是否满了
 **/
bool if_array_full(struct Array *ptArr);

/**
 * 描述：展示数组成员
 * 参数：ptArr：结构体指针
 **/
void show_array(struct Array *ptArr);

/**
 * 描述：追加成员到数组末尾
 **/
void append_to_array();

/**
 * 描述：追加成员到数组指定位置
 **/
void insert_to_array();

/**
 * 描述：删除数组成员
 **/
void delete_array();

/**
 * 描述：获取数组成员
 **/
int get_member();


int main(void)
{
    struct Array tArr;
    
    init_array(&tArr, 10);

    return 0;
}

void init_array(struct Array *ptArr, int len)
{
    ptArr->pBase = (int*)malloc(sizeof(int) * len);
    if (NULL == ptArr->pBase)
    {
        printf("malloc %d bytes failed\n", sizeof(int) * len);
        exit(-1);
    }

    ptArr->len = len;
    ptArr->cnt = 0;

    return;
}

bool if_array_empty(struct Array *ptArr)
{
    if (NULL == ptArr)
    {
        return false;
    }

    if (ptArr->cnt == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool if_array_full(struct Array *ptArr)
{
    if (NULL == ptArr)
    {
        return false;
    }

    if (ptArr->cnt == ptArr->len)
    {
        return true;
    }
    else
    {
        return false;
    }
}


void show_array(struct Array *ptArr)
{
    if_array_empty(ptArr);

    for (int i = 0; i < ptArr->cnt; i++)
    {
        printf("%d ", ptArr->pBase[i]);
    }
    printf("\n");

    return;
}