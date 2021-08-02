/*
 * @Descripttion: 
 * @version: 
 * @Author: machun Michael
 * @Date: 2021-08-02 13:26:42
 * @LastEditors: machun Michael
 * @LastEditTime: 2021-08-02 15:21:08
 */

/**
 * 原理：
 *      1. 将待排序的序列，按照增量分成若干个子序列，然后分别对子序列用直接插入排序进行排序
 *      2. 减小增量再进行排序，直到增量为1时，用直接插入排序做最后一次排序
 * 
 * 增量计算方法：
 *      第一个增量 = 数组长度 / 2，
 *      第二个增量 = 第一个增量 / 2，
 *      第三个增量 = 第二个增量 / 2,
 *      以此类推，最后一个增量 = 1
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

/**
 * @description: 将数组某个位置的元素，插入到前面指定的位置，后面的值依次往后挪一个位置
 * @param {int} *pArray，数组指针
 * @param {int} indexToInsert，要插入的数在数组中的位置
 * @param {int} InsertPos，要插入到数组的哪个位置
 * @param {int} step，步长
 * @return: 成功返回0，失败返回-1
 */
int insert_into_array(int *pArray, int indexToInsert, int InsertPos, int step)
{
    int temp = pArray[indexToInsert];

    for (int k = indexToInsert; k > InsertPos; k -= step)
    {
        pArray[k] = pArray[k-step];   
    }
    pArray[InsertPos] = temp;

    return 0;
}

/**
 * @description: 对每个子序列进行直接插入排序
 * @param {int} *pArray，数组指针
 * @param {int} len，数组长度
 * @param {int} start_index，子序列第一个元素在
 * @param {int} step，步长
 * @return: 成功返回0，失败返回-1
 */
int group_sort(int *pArray, int len, int start_index, int step)
{
    for(int i = start_index + step; i < len; i += step)
    {
        bool bMove = false;  // 选中的数，是否需要移动位置
        int insertPos = 0;   // 要插入的位置
    
        // 从后往前，分别进行比较
        for (int j = i - step; j >= 0; j -= step)
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
            insert_into_array(pArray, i, insertPos, step);
        }
    }

    return 0;
}

int shell_sort(int *pArray, int len)
{
    int cnt = 0;  // 排序轮数
    int step = 0; // 步长（增量）

    // 一共要进行几轮排序，增量等于1时为最后一次排序
    for (step = len / 2; step > 0; step /= 2)
    {
        // 对所有子序列进行排序：1 5 4 6 8 2 11 12 13 0，共10个数，第一个增量为10/2=5，序列一共被分为5个子序列
        for (int i = 0; i < step; i++)
        {
            group_sort(pArray, len, i, step);
        }
        
        printf("%d次排序后的结果: ", cnt++);
        traverse_array(pArray, len);
    }

    return 0;
}

int main(void)
{
    int array[ARRAY_LEN] = {1, 5, 8, 7, 6, 5, 2, 1, 3, 9};

    printf("排序前的数组：");
    traverse_array(array, ARRAY_LEN);
    
    shell_sort(array, ARRAY_LEN);

    printf("排序后的数组：");
    traverse_array(array, ARRAY_LEN);

    return 0;
}