/*
 * @Descripttion: 
 * @version: 
 * @Author: machun Michael
 * @Date: 2021-08-02 15:26:47
 * @LastEditors: machun Michael
 * @LastEditTime: 2021-08-03 15:13:26
 */

/**
 * 原理：
 *      从序列中挑选一个元素，作为基准（pivot）
 *      将所有小于基准的值放到左边，大于等于基准的值放到右边，就可以得到两个子序列
 *      分别对左右两个子序列，进行上述两个操作，直到各个区间只有一个元素
 */

#include <stdio.h>
#include <stdlib.h>

#define ARRAY_LEN 10

int traverse_array(int *pArray, int len)
{
    for (int i = 0; i < ARRAY_LEN; i++)
    {
        printf("%d ", pArray[i]);
    }
    printf("\n");

    return 0;
}

int quick_sort(int *pArray, int len)
{
    int pivot = pArray[0];
    int left_index = 0;           // 指向第1个元素的下标，下标向右移动
    int right_index = len - 1;    // 指向最后一个元素的下标，下标向左移动
    int temp = 0;
    bool bleftMove = false;       // left指向的元素是否挪动位置
    bool brightMode = false;      // right指向的元素是否挪动位置

    while (left_index != right_index)
    {
        // 如果right指向的元素小于pivot，则该元素放到left指向的元素位置
        if (pArray[right_index] < pivot)
        {
            temp = pArray[right_index];
            pArray[right_index] = pArray[left_index];
            pArray[left_index] = temp;
            brightMode = true;
        }

        // 如果left指向的元素大于pivot，则该元素放到right指向的元素位置
        if (pArray[left_index] >= pivot)
        {
            temp = pArray[left_index];
            pArray[left_index] = pArray[right_index];
            pArray[right_index] = temp;
            bleftMove = true;
        }

        if (true == bleftMove)
        {
            left_index++;
        }

        if (true == brightMode)
        {
            right_index--;
        }
    }

    pArray[left_index] = pivot;

    // 至此，array被分成两个子序列，以pivot为分界
    quick_sort(pArray, left_index - 1);
    quick_sort(pArray+left_index+1, len-left_index-1);

    return 0;
}

int main(void)
{
    int array[ARRAY_LEN] = {2, 1, 3, 5, 4, 9, 6, 8, 0, 6};

    traverse_array(array, ARRAY_LEN);
    printf("排序前的数组: ");

    quick_sort(array, ARRAY_LEN);

    printf("排序后的数组: ");
    traverse_array(array, ARRAY_LEN);

    return 0;
}