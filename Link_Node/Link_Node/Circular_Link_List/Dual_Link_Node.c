/*****************************************************************************************
 * File name		: Dual_Link_Node.c
 * Description		: Study the "dual-direction link node" structure.
 * Creator			: XU ZAN
 * Creation date	: Mon.	Nov. 17, 2014
 * Copyright(C)		2014	All rights reserved.
 *
 *****************************************************************************************/

#include "Dual_Link_Node.h"

#include <stdio.h>
#include <stdlib.h>

Status ListCreate_DuLN(PtrDuLNode *L, int n)
/* 创建一个有n个结点的双向链表， 并回传出该双向链表
 */
{
	int i = 0;
	void *pTemp = NULL;
	PtrDuLNode pDuLNode	 = *L,
			   pHeadNode = NULL, 
			   pTailNode = NULL;
	pDuLNode = (PtrDuLNode)calloc(1, sizeof(DuLNode));
	// pDuLNode = (PtrDuLNode)malloc(sizeof(DuLNode));
	pHeadNode = pDuLNode;	// Save the head node's address.
	pTemp = pDuLNode;	// Stage current node's address

	printf("Create the dual-direction link node, please enter the element :\n");
	scanf("%d", &(pDuLNode->data));
	for (i=0; i<n-1; i++)
	{
		pDuLNode->next = (PtrDuLNode)calloc(1, sizeof(DuLNode));
		pDuLNode = pDuLNode->next;	// Move to next node
		scanf("%d", &(pDuLNode->data));
		pDuLNode->prior = pTemp;
		pTemp = pDuLNode;
	}
	pTailNode = pDuLNode;	// Save the tail node's address
	pDuLNode->next = pHeadNode;
	pHeadNode->prior = pTailNode;

	*L = pHeadNode;
	return OK;
}

void ListDisplay_DuLN(PtrDuLNode L)
{
	PtrDuLNode pNode = L, pHead = L;
	if (pNode == NULL)
	{
		printf("Empty dual link node.\n");
		return;
	}
	printf("\n\n");
	printf("Prior		| Current		| Element		| Next	\n");
	printf("-------------------------------------------------------------------------------\n");
	do
	{
		printf("0x%08X	| 0x%08X		| %d			| 0x%08X\n", 
			   pNode->prior,
			   pNode,
			   pNode->data,
			   pNode->next);
		printf("-------------------------------------------------------------------------------\n");
		pNode = pNode->next;
	}
	while (pHead != pNode);
	printf("\n\n");
	return;
}

void ListDestroy_DuLN(PtrDuLNode *L)
{
	PtrDuLNode pNode = *L, pHead = *L, pTemp = NULL;
	do
	{
		pTemp = pNode->next;	// Stage the next node address.
		free(pNode);
		pNode = pTemp;	// Move to next node
	}
	while (pNode != pHead);
	pNode = NULL;
	*L = NULL;
	return;
}


Status ListInsert_DuLN(PtrDuLNode *L, int i, ElemType e)
/* 在带头结点的双向链表L的第i个位置之前插入元素e, 并回传出更新后的链表L
 * i的合法值为 1<=i<=(表长+1)
 */
{
	int n = 0, iLen = GetLength_DuLN(*L);
	PtrDuLNode pNode = *L, pHead = *L, pNewNode = NULL;
	if ( (i<1) || (i>(iLen+1)) )
	{
		return ERROR;
	}
	for (n=1; n<i-1; n++)		// Move to the ith node
	{
		pNode = pNode->next;
	}
	pNewNode = (PtrDuLNode)calloc(1, sizeof(DuLNode));
	if (pNewNode == NULL)
	{
		return ERROR;
	}
	pNewNode->data = e;

	pNewNode->next = pNode->next;
	pNewNode->prior = pNode;
	(pNode->next)->prior = pNewNode;
	pNode->next = pNewNode;

	*L = pHead;
	return OK;
}

Status ListDelete_DuLN(PtrDuLNode *L, int i, ElemType *e)
/* 删除带头结点的双向链表L的第i个元素， 并回传出更新后的链表L.
 * i的合法值为 1<=i<=表长
 */
{
	int nCnt = 0, iLen = GetLength_DuLN(*L);
	PtrDuLNode pNode = *L, pHead = *L;

	if ((i<1) || (i>iLen))
	{
		return ERROR;
	}
	for (nCnt=1; nCnt<i; nCnt++)
	{
		pNode = pNode->next;	// Move to next node, till the ith node.
	}
	(pNode->prior)->next = pNode->next;
	(pNode->next)->prior = pNode->prior;

	*e = pNode->data;
	free(pNode);

	*L = pHead;
	return OK;
}

int GetLength_DuLN(PtrDuLNode L)
/* 算出带头结点的双向链表L的结点个数
 */
{
	int nCnt = 0;
	PtrDuLNode pHead = L, pNode = L;
	do
	{
		++nCnt;			// nCnt的值比++nCnt的值少1
		// nCnt++;		// nCnt的值与nCnt++的值相等
		pNode = pNode->next;
	}
	while (pHead != pNode);
	return nCnt;
}

PtrDuLNode GetElemPtr_DuLN(PtrDuLNode L, unsigned int n)
/* 返回第n个结点的指针
 */
{
	PtrDuLNode pNode = L;
	unsigned int ui = 0, uiLen = GetLength_DuLN(L);
	if ( (n<0) || (n>uiLen) )
	{
		return NULL;
	}

	for (ui=1; ui<n; ui++)
	{
		pNode = pNode->next;
	}
	return pNode;
}