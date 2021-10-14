/*
 * @Descripttion: 
 * @version: 
 * @Author: machun Michael
 * @Date: 2021-08-01 20:43:57
 * @LastEditors: machun Michael
 * @LastEditTime: 2021-10-14 14:12:41
 */

/**
 * 原理：打牌的时候整理牌
 * 1. 固定第一个数，选择第二个数和第一个比较。如果第二个比第一个小，就插入到第一个数的位置；否则就说明第二个数是前两个中最大的，不用挪动位置
 * 2. 选择第三个数，从第二个数开始，从后往前进行比较。通过挨个比较，找到最终的位置插入，然后后面的数依次往后挪一个位置
 * 3. 选择第四个数，以此类推。。。
 */

#include <stdio.h>
#include <stdlib.h>

#define ARRAY_LEN 10

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
 * @description: 将数组某个位置的元素，插入到前面指定的位置，后面的值依次往后挪一个位置
 * @param {int} *pArray，数组指针
 * @param {int} indexToInsert，要插入的数在数组中的位置
 * @param {int} InsertPos，要插入到数组的哪个位置
 * @return: 成功返回0，失败返回-1
 */
int insert_into_array(int *pArray, int indexToInsert, int InsertPos)
{
    int temp = pArray[indexToInsert];

    for (int k = indexToInsert; k > InsertPos; k--)
    {
        pArray[k] = pArray[k-1];   
    }
    pArray[InsertPos] = temp;

    return 0;
}

int insert_sort(int *pArray, int len)
{
    // 固定第一个数，从第二个数开始和前面的数进行比较
    for (int i = 1; i < len; i++)
    {
        bool bMove = false;  // 选中的数，是否需要移动位置
        int insertPos = 0;   // 要插入的位置
    
        // 从后往前，分别进行比较
        for (int j = i - 1; j >= 0; j--)
        {
            // 只要前面有比它大的，就要挪动位置，记录下要插入的位置
            if (pArray[i] < pArray[j])
            {
                bMove = true;
                insertPos = j;
            }
        }

        if (true == bMove)
        {
            insert_into_array(pArray, i, insertPos);
        }
    }

    return 0;
}

int main(void)
{
    int array[ARRAY_LEN] = {1, 5, 4, 6, 8, 2, 11, 12, 13};

    printf("排序前的数组：");
    traverse_array(array, ARRAY_LEN);
    
    insert_sort(array, ARRAY_LEN);

    printf("排序后的数组：");
    traverse_array(array, ARRAY_LEN);

    return 0;
}