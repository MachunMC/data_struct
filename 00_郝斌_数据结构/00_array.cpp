/*
 * @Author: machun Michael 
 * @Date: 2021-07-15 22:35:21 
 * @Last Modified by: machun Michael
 * @Last Modified time: 2021-07-15 22:56:16
 */

/**
 * 说明：下面的函数实现，为了方便，没有判断指针是否为空，实际编码一定要判断！！！
 **/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

// 定义一个数据类型
struct Array
{
    int *pBase;  // 数组第一个元素的地址
    int len;     // 数组长度
    int cnt;     // 数组有效元素个数
};

/**
 * 描述：数组初始化
 * 参数：ptArr：结构体指针
 *      len：数组长度
 * 返回值：void
 **/
void init_array(struct Array *ptArr, int len);

/**
 * 描述：判断数组是否为空
 * 参数：ptArr：结构体指针
 * 返回值: 空返回true，非空返回false
 **/
bool if_array_empty(struct Array *ptArr);

/**
 * 描述：判断数组是否满了
 * 参数：ptArr：结构体指针
 * 返回值：满返回true，不满返回false
 **/
bool if_array_full(struct Array *ptArr);

/**
 * 描述：展示数组成员
 * 参数：ptArr：结构体指针
 * 返回值：void
 **/
void show_array(struct Array *ptArr);

/**
 * 描述：追加成员到数组末尾
 * 参数：ptArr：结构体指针
 *      val：要插入的值
 * 返回值：成功返回0，失败返回-1
 **/
int append_to_array(struct Array *ptArr, int val);

/**
 * 描述：追加成员到数组指定位置，比如数组有4个成员，只能往第0个~第3个位置上插入元素
 * 参数：ptArr：结构体指针
 *       pos：要插入的位置，从0开始（在第几个成员前插入一个值）
 *       val：要插入的值
 * 返回值：成功返回0，失败返回-1
 **/
int insert_to_array(struct Array *ptArr, int pos, int val);

/**
 * 描述：删除数组第几个成员，并返回该成员的值
 * 参数：ptArr: 结构体指针
 *       pos：要删除的元素位置（0 ~ 数组有效成员索引下标）
 *       pVal：删除的元素的值
 * 返回值：成功返回0，失败返回-1
 **/
int delete_from_array(struct Array *ptArr, int pos, int *pVal);

/**
 * 描述：反转数组，将第0个元素变成最后一个，将最后一个元素编程第0个
 **/
int inverse_array(struct Array *ptArr);


int main(void)
{
    struct Array tArr;
    int val = 0;

    memset(&tArr, 0, sizeof(tArr));
    
    init_array(&tArr, 20);
    show_array(&tArr);
    printf("\n");

    append_to_array(&tArr, 0);
    append_to_array(&tArr, 1);
    append_to_array(&tArr, 2);
    append_to_array(&tArr, 3);
    append_to_array(&tArr, 4);
    append_to_array(&tArr, 5);
    append_to_array(&tArr, 6);
    printf("after append to array\n");
    show_array(&tArr);
    printf("\n");

    insert_to_array(&tArr, 5, 100);
    insert_to_array(&tArr, 100, 100);
    insert_to_array(&tArr, -11, 100);
    printf("after insert to array\n");
    show_array(&tArr);
    printf("\n");

    delete_from_array(&tArr, 2, &val);
    printf("after delete pos 2 from array\n");
    show_array(&tArr);
    printf("\n");

    inverse_array(&tArr);
    printf("after inverse array\n");
    show_array(&tArr);
    printf("\n");

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
    if (if_array_empty(ptArr))
    {
        printf("array is empty\n");
        return;
    }

    for (int i = 0; i < ptArr->cnt; i++)
    {
        printf("Array[%d]:%d\n", i, ptArr->pBase[i]);
    }

    return;
}

int append_to_array(struct Array *ptArr, int val)
{
    // 判断数组是否已满
    if (if_array_full(ptArr))
    {
        printf("array is full\n");
        return -1;
    }

    int index = ptArr->cnt;
    ptArr->pBase[index] = val;
    ptArr->cnt++;

    return 0;
}

int insert_to_array(struct Array *ptArr, int pos, int val)
{
    if (if_array_full(ptArr))
    {
        printf("array is full\n");
        return 0;
    }

    if (pos < 0 || pos > ptArr->cnt - 1)
    {
        printf("pos:%d invalid, valid pos 0 ~ %d\n", pos, ptArr->cnt-1);
        return -1;
    }

    // 先把插入位置的元素，往后移动一个位置
    for (int i = ptArr->cnt-1; i >= pos; i--)
    {
        ptArr->pBase[i+1] = ptArr->pBase[i]; 
    }
    ptArr->pBase[pos] = val;
    ptArr->cnt++;

    return 0;
}

int delete_from_array(struct Array *ptArr, int pos, int *pVal)
{
    if (if_array_empty(ptArr))
    {
        printf("array empty!!\n");
        return -1;
    }

    if (pos < 0 || pos > ptArr->cnt -1)
    {
        printf("pos:%d invalid, valid pos 0 ~ %d\n", pos, ptArr->cnt-1);
        return 0;
    }

    *pVal = ptArr->pBase[pos];
    for (int i = pos; i < ptArr->cnt-1; i++)
    {
        ptArr->pBase[i] = ptArr->pBase[i+1];
    }
    ptArr->cnt--;

    return 0;
}

int inverse_array(struct Array *ptArr)
{
    int i = 0;
    int j = 0;
    int temp = 0;

    if (if_array_empty(ptArr))
    {
        printf("array is emtpy\n");
    }

    // i指向第0个元素，j指向最后一个元素，一个向前，一个向后，然后借助中间变量temp，互换两个元素的值
    i = 0;
    j = ptArr->cnt -1;
    while (i < j)
    {
        temp = ptArr->pBase[i];
        ptArr->pBase[i] = ptArr->pBase[j];
        ptArr->pBase[j] = temp;

        i++;
        j--;
    }

    return 0;
}