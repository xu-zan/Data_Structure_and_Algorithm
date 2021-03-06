/**************************************************************
 * File name		: Link_Node.h
 * Description		: 链表
 * Creator			: XU ZAN
 * Creation date	: Thu.	Nov. 20, 2014
 * Copyright(C)		2014	All rights reserved.
 *
 **************************************************************/

#ifndef LINK_NODE_H
#define LINK_NODE_H

	#include "../general.h"


	typedef struct LNode		// 结点类型
	{
		ElemType		data;
		struct LNode	*next;
	}
	LNode, *Link, *Position;

	typedef struct		// 链表类型
	{
		Link head;		// 链表的头结点
		Link tail;		// 链表的尾结点
		int len;		// 链表的长度
	}
	LinkList;


	Status	InitList(LinkList *L);

	Status	InitLinkNode(Link *Node);
	Status	CreateLinkNode(Link *Node, int len);
	Status	CreateLinkList(LinkList *L, int len);
	
	Status	DestroyLinkNode(Link *Node);
	Status	DestroyList(LinkList *L);
	
	Status	MakeNode(Link *p, ElemType e);
	
	void	FreeNode(Link *p);
	
	Status	ClearList(LinkList *L);

	void	DisplayList(Link L);
	void	DisplayLinkList(LinkList List);

	int GetLinkNodeLength(Link s);
	Status GetSpecifiedNode(Link		s, 
							int			n, 
							Position	*PosOfNode, 
							ElemType	*e);
	
	Status	InsFirst(Link *h, Link s);
	
	Status	DelFirst(Link *h, Link *q);
	
	Status	Append(LinkList *L, Link s);
	
	Status	Remove(LinkList *L, ElemType *q);
	
	Status	InsBefore(LinkList *L, Link *p, Link s);
	
	Status	InsAfter(LinkList *L, Link *p, Link s);
	
	Status	SetCurElem(Link *p, ElemType e);
	
	ElemType	GetCurElem(Link p);
	
	Status	ListEmpty(LinkList L);
	
	int		ListLength(LinkList L);
	
	Position	GetHead(LinkList L);
	
	Position	GetLast(LinkList L);
	
	Position	PriorPos(LinkList L, Link p);
	
	Position	NextPos(LinkList L, Link p);
	
	Status	LocatePos(LinkList L, int i, Link *p);
	
	Position	LocateElem(LinkList L, 
						   ElemType e, 
						   Status	(*compare)(ElemType, ElemType));
	
	Status	ListTraverse(LinkList L, Status (*visit)(void *));

	Status	LinkListInsert(LinkList *L, int i, ElemType e);

	Status	MergeLinkList(LinkList	*La,
						LinkList	*Lb,
						LinkList	*Lc,
						int			(*compare)(ElemType, ElemType));

#endif	/*  LINK_NODE_H  */