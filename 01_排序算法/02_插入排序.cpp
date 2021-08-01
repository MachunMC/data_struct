/*
 * @Descripttion: 
 * @version: 
 * @Author: machun Michael
 * @Date: 2021-08-01 20:43:57
 * @LastEditors: machun Michael
 * @LastEditTime: 2021-08-01 22:07:05
 */

/**
 * 原理：
 * 1. 固定第一个数，选择第二个数和第一个比较。如果第二个比第一个小，就插入到第一个数的位置；否则就说明第二个数是前两个中最大的，不用挪动位置
 * 2. 选择第三个数，从第二个数开始，从后往前进行比较。通过挨个比较，找到最终的位置插入，然后后面的数依次往后挪一个位置
 * 3. 选择第四个数，以此类推。。。
 */

#include <stdio.h>
#include <stdlib.h>

#define ARRAY_LEN 10

/**
 * @description: 遍历数组
 * @param {int} *pArray，数组指针
 * @param {int} len，数组长度
 * @return: 成功返回0，失败返回-1
 */
int traverse_array(int *pArray, int len)
{
    for (int i = 0; i < ARRAY_LEN; i++)
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
int insert_array(int *pArray, int indexToInsert, int InsertPos)
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
    // 示例：1, 5, 4, 6, 8, 2, 9, 3, 4, 10
    for (int i = 1; i < len; i++)
    {
        // 从后往前，分别进行比较
        for (int j = i - 1; j >= 0; j--)
        {
            // 选中的数比前面的大，就进行插入或者进行下一轮比较
            if (pArray[i] > pArray[j])
            {
                // 选中的数刚好比前一个数大，本次就不用再进行比较了
                if (j == i -1)
                {
                    break;
                }
                else // 插入到后面一个位置，后面的数往后挪一个位置
                {
                    insert_array(pArray, i, j+1);
                }
            }
            else
            {
                // 如果选中的数是最小的，前面的数都比它大，就需要将它插入到第0个位置
                if (j == 0)
                {
                    insert_array(pArray, i, 0);
                }
            }
        }

        printf("第%d次比较后的结果，选中的数是Arr[%d]\n", i, i);
        traverse_array(pArray, len);
    }

    return 0;
}

int main(void)
{
    int array[ARRAY_LEN] = {1, 5, 4, 6, 8, 2, 9, 3, 4, 10};

    printf("排序前的数组：");
    traverse_array(array, ARRAY_LEN);
    
    insert_sort(array, ARRAY_LEN);

    // printf("排序后的数组：");
    // traverse_array(array, ARRAY_LEN);    

    return 0;
}