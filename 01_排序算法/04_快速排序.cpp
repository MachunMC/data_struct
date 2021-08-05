/*
 * @Descripttion: 
 * @version: 
 * @Author: machun Michael
 * @Date: 2021-08-02 15:26:47
 * @LastEditors: machun Michael
 * @LastEditTime: 2021-08-05 16:03:29
 */

/**
 * 原理：
 *      从序列中挑选一个元素，作为基准（pivot）
 *      将所有小于基准的值放到左边，大于等于基准的值放到右边，就可以得到两个子序列
 *      分别对左右两个子序列，进行上述两个操作，直到各个区间只有一个元素
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_LEN 10000

/**
 * @description: 随机生成一系列0 ~ 10000以内的整数
 * @param {int} *pArray，数组指针
 * @param {int} len，数组长度
 * @return: 成功返回0，失败返回-1
 */
int create_int_array(int *pArray, int len)
{
    srand((unsigned int)time(NULL));  // 播种，不能放到for循环里，否则每次的种子都是相同的，rand生成的数也是相同的
    for (int i = 0; i < len; i++)
    {
        pArray[i] = rand() % 100; // 生成随机数
    }
    
    return 0;
}

int traverse_array(int *pArray, int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%d ", pArray[i]);
    }
    printf("\n");

    return 0;
}

/**
 * @description: 快速排序
 * @param {int} *pArray，数组指针
 * @param {int} start_index，区间起始索引
 * @param {int} end_index，区间结束索引
 * @return: 成功返回0，失败返回-1
 */
int quick_sort(int *pArray, int start_index, int end_index)
{
    int pivot = pArray[start_index]; // 选择第一个数作为基准
    int left_index = start_index;    // 指向第一个元素的下标
    int right_index = end_index;     // 指向最后一个元素的下标

    while (left_index != right_index)
    {
        // 如果right指向的元素小于pivot，则该元素放到左边（left指向的元素位置）
        while (right_index > left_index && pArray[right_index] >= pivot)
        {
            right_index--;
        }
                
        if (left_index == right_index)
        {
            break;
        }
        pArray[left_index] = pArray[right_index];

        // 如果left指向的元素大于等于pivot，则该元素放到右边（right指向的元素位置）
        while (right_index > left_index && pArray[left_index] < pivot)
        {
            left_index++;
        }

        if (left_index == right_index)
        {
            break;
        }
        pArray[right_index] = pArray[left_index];
    }

    pArray[left_index] = pivot;

    if (left_index - 1 - start_index >= 1)
    {
        quick_sort(pArray, start_index, left_index-1); // 左子序列排序
    }

    if (end_index - left_index - 1 >= 1)
    {
        quick_sort(pArray, left_index+1, end_index);   // 右子序列排序
    }
    
    return 0;
}

int main(void)
{
    int array[ARRAY_LEN];
    int len = sizeof(array) / sizeof(int);

    create_int_array(array, len);

    printf("排序前的数组: ");
    traverse_array(array, len);

    quick_sort(array, 0, len - 1);

    printf("排序后的数组: ");
    traverse_array(array, len);

    return 0;
}