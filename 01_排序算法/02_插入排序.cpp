/*
 * @Descripttion: 
 * @version: 
 * @Author: machun Michael
 * @Date: 2021-08-01 20:43:57
 * @LastEditors: machun Michael
 * @LastEditTime: 2021-08-01 22:07:05
 */

/**
 * ԭ��
 * 1. �̶���һ������ѡ��ڶ������͵�һ���Ƚϡ�����ڶ����ȵ�һ��С���Ͳ��뵽��һ������λ�ã������˵���ڶ�������ǰ���������ģ�����Ų��λ��
 * 2. ѡ������������ӵڶ�������ʼ���Ӻ���ǰ���бȽϡ�ͨ�������Ƚϣ��ҵ����յ�λ�ò��룬Ȼ����������������Ųһ��λ��
 * 3. ѡ����ĸ������Դ����ơ�����
 */

#include <stdio.h>
#include <stdlib.h>

#define ARRAY_LEN 10

/**
 * @description: ��������
 * @param {int} *pArray������ָ��
 * @param {int} len�����鳤��
 * @return: �ɹ�����0��ʧ�ܷ���-1
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
 * @description: ������ĳ��λ�õ�Ԫ�أ����뵽ǰ��ָ����λ�ã������ֵ��������Ųһ��λ��
 * @param {int} *pArray������ָ��
 * @param {int} indexToInsert��Ҫ��������������е�λ��
 * @param {int} InsertPos��Ҫ���뵽������ĸ�λ��
 * @return: �ɹ�����0��ʧ�ܷ���-1
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
    // �̶���һ�������ӵڶ�������ʼ��ǰ��������бȽ�
    // ʾ����1, 5, 4, 6, 8, 2, 9, 3, 4, 10
    for (int i = 1; i < len; i++)
    {
        // �Ӻ���ǰ���ֱ���бȽ�
        for (int j = i - 1; j >= 0; j--)
        {
            // ѡ�е�����ǰ��Ĵ󣬾ͽ��в�����߽�����һ�ֱȽ�
            if (pArray[i] > pArray[j])
            {
                // ѡ�е����պñ�ǰһ�����󣬱��ξͲ����ٽ��бȽ���
                if (j == i -1)
                {
                    break;
                }
                else // ���뵽����һ��λ�ã������������Ųһ��λ��
                {
                    insert_array(pArray, i, j+1);
                }
            }
            else
            {
                // ���ѡ�е�������С�ģ�ǰ������������󣬾���Ҫ�������뵽��0��λ��
                if (j == 0)
                {
                    insert_array(pArray, i, 0);
                }
            }
        }

        printf("��%d�αȽϺ�Ľ����ѡ�е�����Arr[%d]\n", i, i);
        traverse_array(pArray, len);
    }

    return 0;
}

int main(void)
{
    int array[ARRAY_LEN] = {1, 5, 4, 6, 8, 2, 9, 3, 4, 10};

    printf("����ǰ�����飺");
    traverse_array(array, ARRAY_LEN);
    
    insert_sort(array, ARRAY_LEN);

    // printf("���������飺");
    // traverse_array(array, ARRAY_LEN);    

    return 0;
}