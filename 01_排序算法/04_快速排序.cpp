/*
 * @Descripttion: 
 * @version: 
 * @Author: machun Michael
 * @Date: 2021-08-02 15:26:47
 * @LastEditors: machun Michael
 * @LastEditTime: 2021-08-05 16:03:29
 */

/**
 * ԭ��
 *      ����������ѡһ��Ԫ�أ���Ϊ��׼��pivot��
 *      ������С�ڻ�׼��ֵ�ŵ���ߣ����ڵ��ڻ�׼��ֵ�ŵ��ұߣ��Ϳ��Եõ�����������
 *      �ֱ���������������У�������������������ֱ����������ֻ��һ��Ԫ��
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_LEN 10000

/**
 * @description: �������һϵ��0 ~ 10000���ڵ�����
 * @param {int} *pArray������ָ��
 * @param {int} len�����鳤��
 * @return: �ɹ�����0��ʧ�ܷ���-1
 */
int create_int_array(int *pArray, int len)
{
    srand((unsigned int)time(NULL));  // ���֣����ܷŵ�forѭ�������ÿ�ε����Ӷ�����ͬ�ģ�rand���ɵ���Ҳ����ͬ��
    for (int i = 0; i < len; i++)
    {
        pArray[i] = rand() % 100; // ���������
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
 * @description: ��������
 * @param {int} *pArray������ָ��
 * @param {int} start_index��������ʼ����
 * @param {int} end_index�������������
 * @return: �ɹ�����0��ʧ�ܷ���-1
 */
int quick_sort(int *pArray, int start_index, int end_index)
{
    int pivot = pArray[start_index]; // ѡ���һ������Ϊ��׼
    int left_index = start_index;    // ָ���һ��Ԫ�ص��±�
    int right_index = end_index;     // ָ�����һ��Ԫ�ص��±�

    while (left_index != right_index)
    {
        // ���rightָ���Ԫ��С��pivot�����Ԫ�طŵ���ߣ�leftָ���Ԫ��λ�ã�
        while (right_index > left_index && pArray[right_index] >= pivot)
        {
            right_index--;
        }
                
        if (left_index == right_index)
        {
            break;
        }
        pArray[left_index] = pArray[right_index];

        // ���leftָ���Ԫ�ش��ڵ���pivot�����Ԫ�طŵ��ұߣ�rightָ���Ԫ��λ�ã�
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
        quick_sort(pArray, start_index, left_index-1); // ������������
    }

    if (end_index - left_index - 1 >= 1)
    {
        quick_sort(pArray, left_index+1, end_index);   // ������������
    }
    
    return 0;
}

int main(void)
{
    int array[ARRAY_LEN];
    int len = sizeof(array) / sizeof(int);

    create_int_array(array, len);

    printf("����ǰ������: ");
    traverse_array(array, len);

    quick_sort(array, 0, len - 1);

    printf("����������: ");
    traverse_array(array, len);

    return 0;
}