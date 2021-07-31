/*
 * @Descripttion: 
 * @version: 
 * @Author: machun Michael
 * @Date: 2021-07-31 22:46:43
 * @LastEditors: machun Michael
 * @LastEditTime: 2021-07-31 22:58:39
 */

/**
 * 原理
 * 1. 选择第一个元素，遍历后面所有元素，找比第一个元素小的。如果找到，就和第一个元素交换位置；如果没找到，就说明第一个元素就是最小的
 * 2. 选择第二个元素，按照上面的方法，找到第二小的元素，放到第二个位置
 * 3. 以此类推，最终可以得到从小到大排列的元素 
 */

#include <stdio.h>
#include <stdlib.h>

#define ARRAY_LEN 10

int select_sort(int *pArrar, int len)
{
    int temp = 0;

    for (int i = 0; i < len - 1 ; i++)
    {
        // printf("第%d次比较\n", i);
        for (int j = i+1; j < len; j++)
        {
            if (pArrar[i] > pArrar[j])
            {
                temp = pArrar[i];
                pArrar[i] = pArrar[j];
                pArrar[j] = temp;
            }
        }        
    }

    return 0;
}

int main(void)
{
    int array[ARRAY_LEN] = {1, 5, 4, 6, 8, 2, 9, 3, 4, 10};

    printf("排序前的数组：");
    for (int i = 0; i < ARRAY_LEN; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
    
    select_sort(array, ARRAY_LEN);

    printf("排序后的数组：");
    for (int i = 0; i < ARRAY_LEN; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}