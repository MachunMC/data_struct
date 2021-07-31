/*
 * @Descripttion: 用链表实现链式二叉树
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

// 定义二叉树节点, binary tree
struct BTNode
{
    char chVal;
    struct BTNode *pLChild; // 左子节点
    struct BTNode *pRChild; // 右子节点
};

// 函数声明
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

    printf("二叉树前序遍历\n");
    preorder_traverse_binary_tree(ptRoot);

    printf("\n二叉树中序遍历\n");
    inorder_traverse_binary_tree(ptRoot);

    printf("\n二叉树后序遍历\n");
    postorder_traverse_binary_tree(ptRoot);

    return 0;
}

/**
 * @description: 创建一个二叉树，创建的二叉树为笔记1.5节中的二叉树
 * @param {struct BTNode} *pRoot，二叉树根节点
 * @return: 成功返回0，失败返回-1
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
    
    // 先创建左子树
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

    // 再创建右子树
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
 * @description: 前序遍历二叉树
 * @param {struct BTNode} *pRoot，二叉树根节点
 * @return: 成功返回0，失败返回-1
 */
int preorder_traverse_binary_tree(struct BTNode *ptRoot)
{
    // 根左右
    printf("%c\n", ptRoot->chVal);
    
    // 遍历左子树
    // 这里需要用到递归的思想，左子树也是一棵二叉树，左子节点是根节点
    if (NULL != ptRoot->pLChild)
    {
        preorder_traverse_binary_tree(ptRoot->pLChild);
    }

    // 遍历右子树
    if (NULL != ptRoot->pRChild)
    {
        preorder_traverse_binary_tree(ptRoot->pRChild);
    }

    return 0;
}

/**
 * @description: 中序遍历二叉树
 * @param {struct BTNode} *pRoot，二叉树根节点
 * @return: 成功返回0，失败返回-1
 */
int inorder_traverse_binary_tree(struct BTNode *ptRoot)
{
    // 左根右
    // 遍历左子树
    if (NULL != ptRoot->pLChild)
    {
        inorder_traverse_binary_tree(ptRoot->pLChild);
    }

    // 根节点
    printf("%c\n", ptRoot->chVal);

    // 遍历左子树
    if (NULL != ptRoot->pRChild)
    {
        inorder_traverse_binary_tree(ptRoot->pRChild);
    }

    return 0;
}

/**
 * @description: 后续遍历二叉树
 * @param {struct BTNode} *pRoot，二叉树根节点
 * @return: 成功返回0，失败返回-1
 */
int postorder_traverse_binary_tree(struct BTNode *ptRoot)
{
    // 左右根

    // 遍历左子树
    if (NULL != ptRoot->pLChild)
    {
        postorder_traverse_binary_tree(ptRoot->pLChild);
    }

    // 遍历右子树
    if (NULL != ptRoot->pRChild)
    {
        postorder_traverse_binary_tree(ptRoot->pRChild);
    }

    printf("%c\n", ptRoot->chVal);

    return 0;
}