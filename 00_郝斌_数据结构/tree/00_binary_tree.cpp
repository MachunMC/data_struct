/*
 * @Descripttion: ������ʵ����ʽ������
 * @version: 
 * @Author: machun Michael
 * @Date: 2021-07-31 13:19:03
 * @LastEditors: machun Michael
 * @LastEditTime: 2021-07-31 14:15:02
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

// ����������ڵ�, binary tree
struct BTNode
{
    char chVal;
    struct BTNode *pLChild; // ���ӽڵ�
    struct BTNode *pRChild; // ���ӽڵ�
};

// ��������
int create_binary_tree(struct BTNode **ptRoot);
int preorder_traverse_binary_tree(struct BTNode *ptRoot);
int inorder_traverse_binary_tree(struct BTNode *ptRoot);
int postorder_traverse_binary_tree(struct BTNode *ptRoot);

int main(void)
{
    int nRet = 0;
    struct BTNode *ptRoot = NULL;

    nRet = create_binary_tree(&ptRoot);
    if (0 != nRet)
    {
        printf("create binary tree failed\n");
        return -1;
    }
    else
    {
        printf("create binary tree succ\n");
    }

    printf("������ǰ�����\n");
    preorder_traverse_binary_tree(ptRoot);

    printf("\n�������������\n");
    inorder_traverse_binary_tree(ptRoot);

    printf("\n�������������\n");
    postorder_traverse_binary_tree(ptRoot);

    return 0;
}

/**
 * @description: ����һ���������������Ķ�����Ϊ�ʼ�1.5���еĶ�����
 * @param {struct BTNode} *pRoot�����������ڵ�
 * @return: �ɹ�����0��ʧ�ܷ���-1
 */
int create_binary_tree(struct BTNode **ptRoot)
{
    struct BTNode *ptNodeA = (struct BTNode *)malloc(sizeof(struct BTNode));
    struct BTNode *ptNodeB = (struct BTNode *)malloc(sizeof(struct BTNode));
    struct BTNode *ptNodeC = (struct BTNode *)malloc(sizeof(struct BTNode));
    struct BTNode *ptNodeD = (struct BTNode *)malloc(sizeof(struct BTNode));
    struct BTNode *ptNodeE = (struct BTNode *)malloc(sizeof(struct BTNode));
    struct BTNode *ptNodeF = (struct BTNode *)malloc(sizeof(struct BTNode));
    struct BTNode *ptNodeG = (struct BTNode *)malloc(sizeof(struct BTNode));

    ptNodeA->chVal = 'A';
    
    // �ȴ���������
    ptNodeA->pLChild = ptNodeB;
    ptNodeB->chVal = 'B';
    ptNodeB->pLChild = ptNodeD;
    ptNodeB->pRChild = ptNodeE;
    ptNodeD->chVal = 'D';
    ptNodeD->pLChild = NULL;
    ptNodeD->pRChild = NULL;
    ptNodeE->chVal = 'E';
    ptNodeE->pLChild = NULL;
    ptNodeE->pRChild = NULL;

    // �ٴ���������
    ptNodeA->pRChild = ptNodeC;
    ptNodeC->chVal = 'C';
    ptNodeC->pLChild = ptNodeF;
    ptNodeC->pRChild = ptNodeG;
    ptNodeF->chVal = 'F';
    ptNodeF->pLChild = NULL;
    ptNodeF->pRChild = NULL;
    ptNodeG->chVal = 'G';
    ptNodeG->pLChild = NULL;
    ptNodeG->pRChild = NULL;

    *ptRoot = ptNodeA;
    return 0;
}

/**
 * @description: ǰ�����������
 * @param {struct BTNode} *pRoot�����������ڵ�
 * @return: �ɹ�����0��ʧ�ܷ���-1
 */
int preorder_traverse_binary_tree(struct BTNode *ptRoot)
{
    // ������
    printf("%c\n", ptRoot->chVal);
    
    // ����������
    // ������Ҫ�õ��ݹ��˼�룬������Ҳ��һ�ö����������ӽڵ��Ǹ��ڵ�
    if (NULL != ptRoot->pLChild)
    {
        preorder_traverse_binary_tree(ptRoot->pLChild);
    }

    // ����������
    if (NULL != ptRoot->pRChild)
    {
        preorder_traverse_binary_tree(ptRoot->pRChild);
    }

    return 0;
}

/**
 * @description: �������������
 * @param {struct BTNode} *pRoot�����������ڵ�
 * @return: �ɹ�����0��ʧ�ܷ���-1
 */
int inorder_traverse_binary_tree(struct BTNode *ptRoot)
{
    // �����
    // ����������
    if (NULL != ptRoot->pLChild)
    {
        inorder_traverse_binary_tree(ptRoot->pLChild);
    }

    // ���ڵ�
    printf("%c\n", ptRoot->chVal);

    // ����������
    if (NULL != ptRoot->pRChild)
    {
        inorder_traverse_binary_tree(ptRoot->pRChild);
    }

    return 0;
}

/**
 * @description: ��������������
 * @param {struct BTNode} *pRoot�����������ڵ�
 * @return: �ɹ�����0��ʧ�ܷ���-1
 */
int postorder_traverse_binary_tree(struct BTNode *ptRoot)
{
    // ���Ҹ�

    // ����������
    if (NULL != ptRoot->pLChild)
    {
        postorder_traverse_binary_tree(ptRoot->pLChild);
    }

    // ����������
    if (NULL != ptRoot->pRChild)
    {
        postorder_traverse_binary_tree(ptRoot->pRChild);
    }

    printf("%c\n", ptRoot->chVal);

    return 0;
}