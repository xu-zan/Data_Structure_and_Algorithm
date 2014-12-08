/**************************************************************
 * File name		: Link_Node.c
 * Description		: 链表
 * Creator			: XU ZAN
 * Creation date	: Thu.	Nov. 20, 2014
 * Copyright(C)		2014	All rights reserved.
 *
 **************************************************************/

#include "Link_Node.h"

Status	InitList(LinkList *L)
/* 构造一个空的线性链表L
 */
{
	Link pLinkNode = NULL;
	pLinkNode = (Link)calloc(1, sizeof(LNode));		/* If you use calloc() function,
													 * every member of struct will be initialized to 0 (pointer member was assigned NULL).
													 * But if you use malloc() or realloc() function, you should assign the member manually.
													 */
	if (pLinkNode == NULL)	// Allocating memory failed.
		return ERROR;
	L->head = pLinkNode;
	L->tail = pLinkNode->next;	// Actually tail node is NULL.
	L->len = 1;
	return OK;
}

/**************************************************************/
Status	DestroyList(LinkList *L)
/* 销毁线性链表L，L不再存在
 */
{
	return OK;
}

/**************************************************************/
Status	MakeNode(Link *p, ElemType e)
/* 分配由p指向的值为e的结点
 * 若分配成功，返回OK; 分配失败，则返回ERROR
 */
{
	return OK;
}

/**************************************************************/
void	FreeNode(Link *p)
/* 释放p所指结点
 */
{
	return;
}

/**************************************************************/
Status	ClearList(LinkList *L)
/* 将线性链表L重置为空表，并释放原链表的结点空间
 */
{
	return OK;
}