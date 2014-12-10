/*********************************************************************************************
 * File name		: Linear_Link_List.c
 * Description		: Declare the prototype of "Linear link node" structure.
 * Creator			: XU ZAN
 * Creation date	: Tue.	Oct. 28, 2014
 * Copyright(C)		2014	All rights reserved.
 *
 *********************************************************************************************/

#include "Linear_Link_List.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

Status ListGetElem_LinkNode(PtrLinkList L, int i, ElemType *e)
{
	PtrLinkList pNode = NULL;
	int iCnt = 0;

	pNode = L->next;	// 指向L(头指针)的第1个node. 
	iCnt = 1;
	while ((pNode!=NULL) && (iCnt<i-1))
	{
		pNode = pNode->next;
		iCnt++;
	}

	if (!pNode || (iCnt>i))	// 第i个元素不存在
		return ERROR;
	memcpy(e, &(pNode->data), sizeof(ElemType));

	return OK;
}
/*********************************************************************************************************/

Status	ListInsert_LinkNode(PtrLinkList *L, int i, ElemType e)
/* 在带头结点的单链表L中第i个位置之前插入元素e, 
 * 并回传出已更新的单链表L
 */
{
	PtrLinkList *pNode = L, 
				pNewNode = NULL, 
				pHead = *L;		// To stage the head node.
	unsigned int uiCount = 0;

	while (*pNode && (uiCount<(unsigned)i-1))	// 寻找第i-1个结点
	{
		(*pNode) = (*pNode)->next;
		++uiCount;
	}
	if (!(*pNode) || (uiCount > (unsigned)i-1))	// 插入位置i小于１或者大于链表本身长度+1
	{
		return ERROR;
	}
		/* 新结点插入到L中 */
		pNewNode = (PtrLinkList)malloc(sizeof(LNode));
		pNewNode->data = e;
		pNewNode->next = (*pNode)->next;
		(*pNode)->next = pNewNode;

	*L = pHead;	// To restore the head node.
	
	return OK;
}
Status ListInsert_L(PtrLinkList L, int i, ElemType e)
{
	PtrLinkList pNode = L, pNewNode = (PtrLinkList)calloc(1, sizeof(LNode));
	unsigned int uiCount = 0;

	while (pNode && (uiCount<(unsigned)i-1))
	{
		pNode = pNode->next;
		++uiCount;
	}
	if (!pNode || (uiCount>(unsigned)i-1))
		return ERROR;
	{
		pNewNode->data = e;
		pNewNode->next = pNode->next;
		pNode->next = pNewNode;
	}
	return OK;
}
/*********************************************************************************************************/

Status	ListDelete_LinkNode(PtrLinkList *L, int i, ElemType *e)
/* 在带头结点的单链表中L中, 删除第i个结点, 并由返回其值
 * 同时回传出已更新的单链表.
 */
{
	PtrLinkList *pNode = L, 
				pNode2BeDeleted = NULL,
				pHead = *L;
	int iCount = 0;

	while ((*pNode != NULL) && (iCount == i) )	// 找到第i个结点
	{
		(*pNode) = (*pNode)->next;
		++iCount;
	}
	if (!((*pNode)->next) || (iCount>(i-1)))	// 删除位置不合理
		return ERROR;
	{	/* 删除并释放结点 */
		pNode2BeDeleted = (*pNode)->next;
		(*pNode)->next = pNode2BeDeleted->next;
		*e = pNode2BeDeleted->data;
		free(pNode2BeDeleted);
	}

	*L = pHead;
	return OK;
}
/*********************************************************************************************************/

	void	ListCreate_LinkNode(PtrLinkList *L, int n)
	/* 逆位序输入n个元素的值，　建立带表头结点的单链表L,
	 * 并回传出该单链表L
	 */
#if 0
	{
		int i = 0;
		PtrLinkList pNode = NULL;
		*L = (PtrLinkList)calloc(1, sizeof(LNode));
		(*L)->next = NULL;
		printf("Please input the element data of each node, and enter.\n");
		for (i=n; i>0; --i)
		{
			pNode = (PtrLinkList)malloc(sizeof(LNode));
			scanf("%d", &(pNode->data));
			pNode->next = (*L)->next;
			(*L)->next = pNode;
		}
		return;
	}
#else
	/* 按顺序依次输入n个元素的值, 创建一个带表头和表尾的单链表L.
	 * 并回传出该单链表L.
	 */
	{
		int i = 0;
	#if 0
		PtrLinkList pNode = (PtrLinkList)calloc(1, sizeof(LNode)), 
					pHead = NULL;
		pHead = pNode;
		printf("Please input the element data of each node, and enter.\n");
		for (i=0; i<n; i++)
		{
			scanf("%d", &(pNode->data));
			pNode->next = (PtrLinkList)calloc(1, sizeof(LNode));
			pNode = pNode->next;
		}
		pNode = NULL;
		*L = pHead;
	#else
		PtrLinkList pNode = (PtrLinkList)calloc(1, sizeof(LNode)), 
					pHead = NULL;
		pHead = pNode;		// Keep the head node.	It is a must.

		printf("Please input the element data of each node, and enter.\n");		
		scanf("%d", &(pNode->data));
		// pNode = pNode->next;	// Move to next node.  Actually this statement will bring a broken link node.
		for (i=0; i<n-1; i++)
		{
			pNode->next = (PtrLinkList)calloc(1, sizeof(LNode));
			pNode = pNode->next;	// 移动到下一个结点
			scanf("%d", &(pNode->data));
		}
		pNode = NULL;
		*L = pHead;
	#endif
		return;
	}
#endif


void	ListCreate_L(PtrLinkList L, int n)
{
	int i = 0;
	PtrLinkList pNode = NULL;
	L = (PtrLinkList)malloc(sizeof(LNode));
	L->next = NULL;
	printf("Please input the element data of each node, and enter.\n");
	for (i=n; i>0; --i)
	{
		pNode = (PtrLinkList)malloc(sizeof(LNode));
		scanf("%d", &(pNode->data));
		pNode->next = L->next;
		L->next = pNode;
	}
	return;
}
/*********************************************************************************************************/

void	ListDestroy_LinkNode(PtrLinkList *L)
{
	void *pNextNodeTempAddr = (*L)->next;

	while ((*L) != NULL)
	{
		free(*L);
		(*L) = pNextNodeTempAddr;
		if (NULL == (*L))
		{
			break;
		}
		pNextNodeTempAddr = (*L)->next;
	}
	(*L) = NULL;
	return;
}

/*********************************************************************************************************/
void	ListDisplay_LinkNode(PtrLinkList L)
{
	PtrLinkList pNode = L;

	printf("Current link node list :\n");
	printf("----------------------------------------------------------------------------\n");
	printf("Current node address	| current node data	| Next node address    \n");
	printf("----------------------------------------------------------------------------\n");
	while (pNode != NULL)
	{
		printf("0x%08X		| %d			| 0x%08X	\n", pNode, pNode->data, pNode->next);
		printf("----------------------------------------------------------------------------\n");
		pNode = pNode->next;
	}
	printf("\n\n");
	return;
}


/*********************************************************************************************************/
void	ListMerge_LinkNode(PtrLinkList La, PtrLinkList Lb, PtrLinkList *Lc)
/* 已知单链表La和Lb的元素按值非递减排列
 * 归并La和Lb得到新的单链表Lc, Lc的元素也按值非递减排列.
 */
{
	PtrLinkList pNode_La = La->next,  pHead_La = La,
				pNode_Lb = Lb,  pHead_Lb = Lb,
				pNode_Lc = *Lc, pHead_Lc;

	pNode_Lc = La;			// 用La的头结点作为Lc的头结点
	pHead_Lc = pNode_Lc;	// Keep the head node of Lc
	while ( pNode_La && pNode_Lb )
	{
		if ( (pNode_La->data) <= (pNode_Lb->data) )
		{
			pNode_Lc->next = pNode_La;
			pNode_Lc = pNode_Lc->next;	// Lc移动到下一个结点
			pNode_La = pNode_La->next;	// La移动到下一个结点
		}
		else
		{
			pNode_Lc->next = pNode_Lb;
			pNode_Lc = pNode_Lc->next;	// Lc移动到下一个结点
			pNode_Lb = pNode_Lb->next;	// Lb移动到下一个结点
		}
	}
	pNode_Lc->next = pNode_La ? pNode_La : pNode_Lb;	// 插入剩余段

	*Lc = pHead_Lc;		// Restore the head node of Lc.
	La =  pHead_La;
	Lb = pHead_Lb;
	return;
}


void ListMerge_2LinkNodes(PtrLinkList *La, PtrLinkList *Lb, PtrLinkList *Lc)
/* 合并La和Lb两个链表得到链表Lc, 回传出链表Lc
 * 同时摧毁La和Lb.
 */
{
	PtrLinkList pNode_La = (*La)->next, pHead_La = *La,
				pNode_Lb = (*Lb),		pHead_Lb = *Lb,
				pNode_Lc = NULL,		pHead_Lc = NULL,
				pTargetNode_Lc = NULL;

	pNode_Lc = (*La);	// Assign La head node to Lc, as the head node
	pHead_Lc = pNode_Lc;	// Stage the head node of Lc.
	while (pNode_La && pNode_Lb)
	{
		if ((pNode_La->data) <= (pNode_Lb->data))
		{
			pNode_Lc->next = pNode_La;	// Assign La current node to Lc successor node.
			pNode_Lc = pNode_Lc->next;	// Lc move to next node
			pNode_La = pNode_La->next;	// La move to next node
		}
		else
		{
			pNode_Lc->next = pNode_Lb;	// Assign Lb current node to Lc successor node
			pNode_Lc = pNode_Lc->next;	// Lc move to next node
			pNode_Lb = pNode_Lb->next;	// Lb move to next node
		}
	}
	pNode_Lc->next = pNode_La ? pNode_La : pNode_Lb;	// Append the remained nodes.
	pNode_Lc = pHead_Lc;		// Restore the Lc head node.

	/* Duplicate the pNode_LC, to obtain another link node
	 */
	ListDuplicate_LinkList(pNode_Lc, &pTargetNode_Lc);
	*Lc = pTargetNode_Lc;	// At last output(assign) pTargetNode_Lc to (*Lc) argument.

	/* Destroy intermediate Lc(namely pNode_Lc) and argument *La, *Lb
	 */
	ListDestroy_LinkNode(&pNode_Lc);	// In fact, destroying pNode_Lc means that both Lb and La had been destroyed simultaneously.
	
	/* Notice : 
	 * After destroying pNode_Lc, pNode_Lc has become an arbitrary pointer.
	 * You must set it as a NULL pointer.
	 */
	pNode_Lc = NULL;
	*La = NULL;
	*Lb = NULL;

	return;
}


/*********************************************************************************************************/
void	ListDuplicate_LinkList(PtrLinkList pOriginalNode, PtrLinkList *pCopiedNode)
{
	PtrLinkList pNode = NULL, pHead = NULL;

	pNode = (PtrLinkList)malloc(sizeof(LNode));
	pHead = pNode;	// Stage the head-node's pointer.

	pNode->data = pOriginalNode->data;
	while (pOriginalNode != NULL)
	{
		pOriginalNode = pOriginalNode->next;
		if (pOriginalNode == NULL)		// This if-judgement is used to prevent from moving to the next pointer of tail node.
		{
			break;
		}
		pNode->next = (PtrLinkList)calloc(1, sizeof(LNode));
		pNode = pNode->next;
		pNode->data = pOriginalNode->data;
	}
	pNode = pHead;	// Restore the head node
	*pCopiedNode = pNode;
	
	return;
}