/*
 * @Descripttion: 
 * @version: 
 * @Author: machun Michael
 * @Date: 2021-08-02 15:26:47
 * @LastEditors: machun Michael
 * @LastEditTime: 2021-08-03 15:13:26
 */

/**
 * ԭ��
 *      ����������ѡһ��Ԫ�أ���Ϊ��׼��pivot��
 *      ������С�ڻ�׼��ֵ�ŵ���ߣ����ڵ��ڻ�׼��ֵ�ŵ��ұߣ��Ϳ��Եõ�����������
 *      �ֱ���������������У�������������������ֱ����������ֻ��һ��Ԫ��
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
    int left_index = 0;           // ָ���1��Ԫ�ص��±꣬�±������ƶ�
    int right_index = len - 1;    // ָ�����һ��Ԫ�ص��±꣬�±������ƶ�
    int temp = 0;
    bool bleftMove = false;       // leftָ���Ԫ���Ƿ�Ų��λ��
    bool brightMode = false;      // rightָ���Ԫ���Ƿ�Ų��λ��

    while (left_index != right_index)
    {
        // ���rightָ���Ԫ��С��pivot�����Ԫ�طŵ�leftָ���Ԫ��λ��
        if (pArray[right_index] < pivot)
        {
            temp = pArray[right_index];
            pArray[right_index] = pArray[left_index];
            pArray[left_index] = temp;
            brightMode = true;
        }

        // ���leftָ���Ԫ�ش���pivot�����Ԫ�طŵ�rightָ���Ԫ��λ��
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

    // ���ˣ�array���ֳ����������У���pivotΪ�ֽ�
    quick_sort(pArray, left_index - 1);
    quick_sort(pArray+left_index+1, len-left_index-1);

    return 0;
}

int main(void)
{
    int array[ARRAY_LEN] = {2, 1, 3, 5, 4, 9, 6, 8, 0, 6};

    traverse_array(array, ARRAY_LEN);
    printf("����ǰ������: ");

    quick_sort(array, ARRAY_LEN);

    printf("����������: ");
    traverse_array(array, ARRAY_LEN);

    return 0;
}