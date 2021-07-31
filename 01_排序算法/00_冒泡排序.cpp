/*
 * @Descripttion: 
 * @version: 
 * @Author: machun Michael
 * @Date: 2021-07-31 14:16:43
 * @LastEditors: machun Michael
 * @LastEditTime: 2021-07-31 22:54:28
 */

/**
 * ԭ��
 * 1. ������n��Ԫ�أ��Ƚ����ڵ�����Ԫ�أ����һ���͵ڶ����Ƚϣ�����ȵڶ������򽻻�λ�ã��ڶ����͵������Ƚϣ�����ȵ��������򽻻�λ�ã�
 *    �Դ����ƣ�������һ�ֱȽϺ������ŵ����һ��λ��
 * 2. �ڶ��֣�����ǰ��ķ�ʽ���Ƚϳ����һ��Ԫ�����n-1��Ԫ�أ����Խ��ڶ�������ŵ������ڶ���λ��
 * 3. ����n�֣��Ϳ��Եõ���С�������е�Ԫ��
 * 
 * �Ż�tips:
 * 1. ������б����Ѿ�������ģ����߾������������������ģ��Ͳ���Ҫ�ٱȽ���
 * 2. ���Կ�������һ����־�������������û�н�����λ�ã�˵�������Ѿ�������ģ�����Ҫ����λ����
 */

#include <stdio.h>

#define ARRAY_LEN 10

int bubble_sort(int *pArray, int len)
{
    int i = 0;
    int j = 0;
    int temp = 0;
    bool bExchange = false;  // �Ƿ񽻻���λ�õı�־���������Ч��

    for (i = 0; i < len - 1; i++)
    {
        bExchange = false;
        printf("��%d�ֱȽ�\n", i);
        
         // �Ƚϵ�Ԫ�ظ����ڵݼ���5��Ԫ�ص�һ�ֱȽ�4�Σ��ڶ��ֱȽ�3�Σ�һ����Ҫ�Ƚ��ִ�
        for (j = 0; j < len - 1 - i; j++) 
        {
            if (pArray[j] > pArray[j+1])
            {
                temp = pArray[j];
                pArray[j] = pArray[j+1];
                pArray[j+1] = temp;

                bExchange = true; // ����λ�ñ�־��Ϊtrue
            }
        }

        // ���һ������û�н�����λ�ã�˵����ǰ��������ģ��Ϳ���ֹͣ�Ƚ���
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