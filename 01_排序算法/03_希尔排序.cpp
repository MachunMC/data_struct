/*
 * @Descripttion: 
 * @version: 
 * @Author: machun Michael
 * @Date: 2021-08-02 13:26:42
 * @LastEditors: machun Michael
 * @LastEditTime: 2021-08-02 15:21:08
 */

/**
 * ԭ��
 *      1. ������������У����������ֳ����ɸ������У�Ȼ��ֱ����������ֱ�Ӳ��������������
 *      2. ��С�����ٽ�������ֱ������Ϊ1ʱ����ֱ�Ӳ������������һ������
 * 
 * �������㷽����
 *      ��һ������ = ���鳤�� / 2��
 *      �ڶ������� = ��һ������ / 2��
 *      ���������� = �ڶ������� / 2,
 *      �Դ����ƣ����һ������ = 1
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
 * @description: ������ĳ��λ�õ�Ԫ�أ����뵽ǰ��ָ����λ�ã������ֵ��������Ųһ��λ��
 * @param {int} *pArray������ָ��
 * @param {int} indexToInsert��Ҫ��������������е�λ��
 * @param {int} InsertPos��Ҫ���뵽������ĸ�λ��
 * @param {int} step������
 * @return: �ɹ�����0��ʧ�ܷ���-1
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
 * @description: ��ÿ�������н���ֱ�Ӳ�������
 * @param {int} *pArray������ָ��
 * @param {int} len�����鳤��
 * @param {int} start_index�������е�һ��Ԫ����
 * @param {int} step������
 * @return: �ɹ�����0��ʧ�ܷ���-1
 */
int group_sort(int *pArray, int len, int start_index, int step)
{
    for(int i = start_index + step; i < len; i += step)
    {
        bool bMove = false;  // ѡ�е������Ƿ���Ҫ�ƶ�λ��
        int insertPos = 0;   // Ҫ�����λ��
    
        // �Ӻ���ǰ���ֱ���бȽ�
        for (int j = i - step; j >= 0; j -= step)
        {
            // ֻҪǰ���б�����ģ���ҪŲ��λ�ã���¼��Ҫ�����λ��
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
    int cnt = 0;  // ��������
    int step = 0; // ������������

    // һ��Ҫ���м���������������1ʱΪ���һ������
    for (step = len / 2; step > 0; step /= 2)
    {
        // �����������н�������1 5 4 6 8 2 11 12 13 0����10��������һ������Ϊ10/2=5������һ������Ϊ5��������
        for (int i = 0; i < step; i++)
        {
            group_sort(pArray, len, i, step);
        }
        
        printf("%d�������Ľ��: ", cnt++);
        traverse_array(pArray, len);
    }

    return 0;
}

int main(void)
{
    int array[ARRAY_LEN] = {1, 5, 8, 7, 6, 5, 2, 1, 3, 9};

    printf("����ǰ�����飺");
    traverse_array(array, ARRAY_LEN);
    
    shell_sort(array, ARRAY_LEN);

    printf("���������飺");
    traverse_array(array, ARRAY_LEN);

    return 0;
}