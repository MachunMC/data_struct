/*
 * @Descripttion: 
 * @version: 
 * @Author: machun Michael
 * @Date: 2021-07-31 14:16:43
 * @LastEditors: machun Michael
 * @LastEditTime: 2021-07-31 22:54:28
 */

/**
 * 原理
 * 1. 假设有n个元素，比较相邻的两个元素，如第一个和第二个比较，如果比第二个大，则交换位置；第二个和第三个比较，如果比第三个大，则交换位置；
 *    以此类推，经过第一轮比较后，最大的排到最后一个位置
 * 2. 第二轮，按照前面的方式，比较除最后一个元素外的n-1个元素，可以将第二大的数排到倒数第二个位置
 * 3. 经过n轮，就可以得到从小到大排列的元素
 * 
 * 优化tips:
 * 1. 如果序列本身已经是有序的，或者经过几轮排序后是有序的，就不需要再比较了
 * 2. 所以可以增加一个标志，如果本轮排序没有交换过位置，说明序列已经是有序的，不需要交换位置了
 */

#include <stdio.h>

#define ARRAY_LEN 10

int bubble_sort(int *pArray, int len)
{
    int i = 0;
    int j = 0;
    int temp = 0;
    bool bExchange = false;  // 是否交换过位置的标志，可以提高效率

    for (i = 0; i < len - 1; i++)
    {
        bExchange = false;
        printf("第%d轮比较\n", i);
        
         // 比较的元素个数在递减，5个元素第一轮比较4次，第二轮比较3次，一共需要比较轮次
        for (j = 0; j < len - 1 - i; j++) 
        {
            if (pArray[j] > pArray[j+1])
            {
                temp = pArray[j];
                pArray[j] = pArray[j+1];
                pArray[j+1] = temp;

                bExchange = true; // 交换位置标志置为true
            }
        }

        // 如果一轮下来没有交换过位置，说明当前就是有序的，就可以停止比较了
        if (false == bExchange)
        {
            break;
        }
    }
    
    return 0;
}

int main()
{
    int adwNum[ARRAY_LEN] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    bubble_sort(adwNum, ARRAY_LEN);

    for (int i = 0; i < ARRAY_LEN; i++)
    {
        printf("%d ", adwNum[i]);
    }

    return 0;
}