/**********************************************************************************
 * File name	: Link_List.c
 * Description	: Implement the data structure of link list and the function 
 *				  definition of its algorithm.
 * Creator		: XU ZAN
 * Creation date: Mon.	Dec. 16, 2013
 * Copyright(C)		2013	All rights reserved.
 *
 **********************************************************************************/

#include <stdio.h>
#include "Link_List.h"

Status GetElem_LinkList(LinkList L, int i, ElemType &e)
/* L为带头结点的单链表的头指针.
 * 当第i个元素存在时, 其值赋给e并返回OK, 否则返回ERROR
 */
{
	LinkList p = L->next;		// 初始化, p指向第一个结点
	int j = 1;					// j为计数器

	while (p && (j<i))			// 顺着指针向后查找，直到p指向第i个元素或p为空
	{
		p = p->next;
		++j;
	}

	if (!p || (j>i))	// 第i个元素不存在
		return ERROR;
	e = p->data;		// 取第i个元素

	return OK;
}

void Display_LinkList(LinkList L)
{
	int i = 0;

	printf("Node #\t\tNode Address\t\tNode Element\t\tNext Node");
	while (L != NULL)
	{
		printf("%d\t\t0x%08X\t\t%d\t\t0x%08X",
			    ++i,
				L,
				L->data,
				L->next);
		L = L->next;
	}
	return;
}

Status ListInsert_LinkList(LinkList &L, int iPos, ElemType e)
{
	int iResult = 0;
	return iResult;
}