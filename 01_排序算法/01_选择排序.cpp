/*
 * @Descripttion: 
 * @version: 
 * @Author: machun Michael
 * @Date: 2021-07-31 22:46:43
 * @LastEditors: machun Michael
 * @LastEditTime: 2021-07-31 22:58:39
 */

/**
 * ԭ��
 * 1. ѡ���һ��Ԫ�أ�������������Ԫ�أ��ұȵ�һ��Ԫ��С�ġ�����ҵ����ͺ͵�һ��Ԫ�ؽ���λ�ã����û�ҵ�����˵����һ��Ԫ�ؾ�����С��
 * 2. ѡ��ڶ���Ԫ�أ���������ķ������ҵ��ڶ�С��Ԫ�أ��ŵ��ڶ���λ��
 * 3. �Դ����ƣ����տ��Եõ���С�������е�Ԫ�� 
 */

#include <stdio.h>
#include <stdlib.h>

#define ARRAY_LEN 10

int select_sort(int *pArrar, int len)
{
    int temp = 0;

    for (int i = 0; i < len - 1 ; i++)
    {
        // printf("��%d�αȽ�\n", i);
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

    printf("����ǰ�����飺");
    for (int i = 0; i < ARRAY_LEN; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
    
    select_sort(array, ARRAY_LEN);

    printf("���������飺");
    for (int i = 0; i < ARRAY_LEN; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}