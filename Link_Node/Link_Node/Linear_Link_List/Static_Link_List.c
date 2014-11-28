/*******************************************************************************************
 * File name		: Static_Link_List.c
 * Description		: 研究静态链表
 * Creator			: XU ZAN
 * Creation date	: Sat.	Nov. 15, 2014
 * Copyright(C)		2014	All rights reserved.
 *
 *******************************************************************************************/


#include "Static_Link_List.h"

#include <stdio.h>

int LocateElem_SL(SLinkList S, ElemType e)
/* 在静态单链表L中查找第一个值为e的元素。
 * 若找到，则返回它在L中的位序， 否则返回0.
 */
{
	int index = 0;
	index = S[0].cur;	// index指示表L中的第一个结点
	while (index && (S[index].data != e))
	{
		index = S[index].cur;
	}
	return index;
}


void InitSpace_SL(SLinkList *space)
/* 将一维数组space中各分量链接成一个备用链表。
 * space[0].cur 为头指针, 0表示空指针
 */
{
	int iCnt = 0;
	for (iCnt=0; iCnt<MAXSIZE-1; iCnt++)
	{
		(*space)[iCnt].cur = iCnt+1;
	}
	(*space)[MAXSIZE-1].cur = 0;

	return;
}


void CreateSpace_SL(SLinkList *space, int iLen)
{
}


int Malloc_SL(SLinkList *space)
/* 给静态链表分配备用空间space.
 * 若备用空间链表为空， 则返回分配的结点下标， 否则返回0.
 */
{
	int idx = 0;
	
	idx = (*space)[0].cur;
	if ((*space)[0].cur)
	{
		(*space)[0].cur = (*space)[idx].cur;
	}
	
	return idx;
}


void Free_SL(SLinkList *space, int k)
/* 将下标为k的空闲结点回收到备用链表
 */
{
	(*space)[k].cur = (*space)[0].cur;
	(*space)[0].cur = k;
}


void difference(SLinkList *space, int *S)
{
}


void DisplayList_SL(SLinkList S)
{
	int index = 0;
	printf("Current static link list is :\n");
	printf("Node #		| Data			| Cursor			\n");
	
	for (index=0; index<(MAXSIZE-1); index++)
	{
		printf("%d		| %d			| %d			\n", index, S[index].data, S[index].cur);
	}
	printf("\n\n");
	return;
}


/*
 * END OF FILE <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
 */