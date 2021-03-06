/**************************************************************
 * File name		: Link_Node.c
 * Description		: 链表
 * Creator			: XU ZAN
 * Creation date	: Thu.	Nov. 20, 2014
 * Copyright(C)		2014	All rights reserved.
 *
 **************************************************************/

#include "Link_Node.h"

#include <stdio.h>
#include <stdlib.h>

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
	pLinkNode->next = NULL;

	L->head = pLinkNode;
	L->tail = pLinkNode->next;	// Actually tail node is NULL.
	L->len = 1;
	return OK;
}

Status	CreateLinkList(LinkList *L, int len)
/* 创建一个长度为len的线性链表, 即:len个结点.
 * 每个结点的数据成员由用户输入.
 */
{
	Link pNode = L->head, pHead = L->head, pTemp = NULL;
	int iCnt = 0;
	printf("Please enter the data for each node to create a link list with %d nodes :\n", len);
	iCnt = 0;	// should start from 1.
	{
		/* Assign the head node, which was initialized and created at
		 * calling InitList(LinkList *L)
		 */
		scanf("%d", &(pNode->data));
		iCnt++;
		// pNode = pNode->next;	// At this moment, DO NOT move to next node, because link list has only 1 node currently
	}
	while (iCnt < len)
	{
		if (pNode->next == NULL)
		{
			pTemp = (Link)calloc(1, sizeof(LNode));
			if (pTemp == NULL)
			{
				printf("Allocating memory failed.\n");
				return OVERFLOW;
			}
			scanf("%d", &(pTemp->data));
			/* Assign current node pointer to L->tail, 
			 * as the tail node.
			 */
			pNode->next = pTemp;
			pNode = pNode->next;	// New node had been already created, So now it can move to next node.
			L->tail = pNode;
			iCnt++;
			L->len = iCnt;	// Length will also increase 1.
		}
		#if 0
		else
		{
			scanf("%d", &(pNode->data));

			iCnt++;
			if (iCnt > L->len)
			{
				L->len = iCnt;
			}
			pNode = pNode->next;
		}
		#endif
	}
	pNode = pHead;
	return OK;
}

Status	InitLinkNode(Link *Node)
/* 初始化一个带头结点的链表，链表只含有1个结点.
 * 返回此链表.
 */
{
	Link pNode = NULL;
	pNode = (Link)calloc(1, sizeof(LNode));
	if (pNode == NULL)
		return OVERFLOW;
	*Node = pNode;
	return OK;
}

Status	CreateLinkNode(Link *Node, int len)
/* 创建一个含有len个结点的链表，每个结点的数据成员由用户输入.
 * 并返回链表的头结点.
 */
{
	Link pNode = *Node, pHead = NULL, pTemp = NULL;
	int n = 0;
	printf("Create a node-linked list with %d nodes, please enter the data :\n", len);
	do
	{
		n++;
		if (pNode == NULL)
		{
			pNode = (Link)calloc(1, sizeof(LNode));
			scanf("%d", &(pNode->data));
			if (n==1)
				pHead = pNode;
		}
		else
		{
			if (n==1)
			{
				pHead = pNode;
				scanf("%d", &(pNode->data));
				n++;
			}
			pNode->next = (Link)calloc(1, sizeof(LNode));
			pNode = pNode->next;
			scanf("%d", &(pNode->data));
		}
	}
	while (n<len);
	*Node = pHead;

	return OK;
}

/**************************************************************/
Status	DestroyList(LinkList *L)
/* 销毁线性链表L，L不再存在
 */
{
	Link pLNode = L->head,	// To get the head node of link-node.
		 pHeadNode = L->head,	// Stage the head node.
		 pTailNode = L->tail;	// Stage the tail node
	void *pTemp = NULL;

	if (pLNode == NULL)
	{
		printf("The link list is already empty.\n");
		return OK;
	}
	
	while (pLNode != NULL)
	{
		pTemp = pLNode->next;
		free(pLNode);
		pLNode = pTemp;
	}
	L->head = pLNode;
	L->tail = pLNode;
	L->len = 0;

	return OK;
}

/**************************************************************/
Status	DestroyLinkNode(Link *Node)
/* 销毁链表,将链表的所有结点均释放,并置为空.
 * 返回链表头指针.
 */
{
	Link pNode = *Node, pTemp = NULL;
	while (pNode != NULL)
	{
		pTemp = pNode->next;
		free(pNode);
		pNode = pTemp;
	}
	pNode = NULL;
	*Node = pNode;
	return OK;
}


/**************************************************************/
Status	MakeNode(Link *p, ElemType e)
/* 分配由p指向的值为e的结点
 * 若分配成功，返回OK; 分配失败，则返回ERROR
 */
{
	Link pNode = (Link)calloc(1, sizeof(LNode));
	if (pNode == NULL)
	{
		printf("Created a new node failed. Allocation error.\n");
		return ERROR;
	}
	pNode->data = e;

	*p = pNode;
	return OK;
}

/**************************************************************/
void	FreeNode(Link *p)
/* 释放p所指结点
 */
{
	Link pNode = *p;

	pNode->next = NULL;
	free(pNode);
	pNode = NULL;
	*p = pNode;
	return;
}

/**************************************************************/
Status	ClearList(LinkList *L)
/* 将线性链表L重置为空表，并释放原链表的结点空间
 */
{
	Link pNode	= L->head;
	void *pTemp = NULL;

	while (pNode != NULL)
	{
		pTemp = pNode->next;
		free(pNode);
		L->len--;
		pNode = pTemp;
	}
	L->head = NULL;
	L->tail = NULL;

	return OK;
}

void	DisplayList(Link L)
{
	int iCnt = 1;
	printf("Link Nodes :\n");
	printf("	  #	| Current		| Data		| Next\n");
	printf("-------------------------------------------------------------------------------\n");
	while (L != NULL)
	{
		printf("	  %d	| 0x%08X		| %d		| 0x%08X\n",
			   iCnt, L, L->data, L->next);
		printf("-------------------------------------------------------------------------------\n");
		L = L->next;
		iCnt++;
	}
	printf("\n\n");
	return;
}

void	DisplayLinkList(LinkList List)
{
	int iCnt = 1;
	Link pNode = List.head;
	printf("Link List structure :\n");
	printf("Node	| #	| Current		| Data		| Next	\n");
	printf("-------------------------------------------------------------------------------\n");
	while (pNode != NULL)
	{
		if (pNode == List.head)
		{
			printf("Head	| %d	| 0x%08X		| %d		| 0x%08X\n",
				   iCnt, pNode, pNode->data, pNode->next);
		}
		else if (pNode == List.tail)
		{
			printf("Tail	| %d	| 0x%08X		| %d		| 0x%08X\n",
				   iCnt, pNode, pNode->data, pNode->next);
		}
		else
		{
			printf("	| %d	| 0x%08X		| %d		| 0x%08X\n",
				   iCnt, pNode, pNode->data, pNode->next);
		}
		printf("-------------------------------------------------------------------------------\n");
		pNode = pNode->next;
		iCnt++;
	}
	printf("Length	| total %d nodes	\n", List.len);
	printf("-------------------------------------------------------------------------------\n");
	printf("\n\n");
	return;
}

Status	InsFirst(Link *h, Link s)
/* 已知h指向线性链表的头结点, 将s所指结点插入都在第一个结点之前.
 */
{
	Link pHead = *h;
	s->next = pHead;
	pHead = s;
	*h = pHead;

	return OK;
}

Status	DelFirst(Link *h, Link *q)
/* 已知h指向线性链表的头节点, 删除链表中的第一个结点
 * 并以q返回.
 */
{
	Link pNode = (*h)->next,	// point to the next node of head node.
		 pHead = *h,
		 pNode2Copy = NULL;

	/* When you want to free a node, but this node also need to be returned,
	 * It is impossible to free it simply.  
	 * You should allocate a new memory space to save the data of to-be-freed node.
	 */
	pNode2Copy = (Link)calloc(1, sizeof(LNode));
	pNode2Copy->data = pHead->data;
	*q = pNode2Copy;

	free(pHead);
	
	*h = pNode;
	return OK;
}

Status	Append(LinkList *L, Link s)
/* 将指针s所指(彼此以指针相连)的一串结点链接在线性链表L的最后一个结点之后,
 * 并改变链表L的尾指针指向新的尾结点.
 */
{
	int iLen = GetLinkNodeLength(s);
	Link pTailNodeOfLink = NULL, pLinkNode = L->head, pHead = L->head;
	ElemType e = 0;
	
	while (pLinkNode->next != NULL)		// Move to the tail of link node "L->head"
	{
		pLinkNode = pLinkNode->next;
	}
	pLinkNode->next = s;

	GetSpecifiedNode(s, iLen, &pTailNodeOfLink, &e);
	L->tail = pTailNodeOfLink;
	L->len = L->len + iLen;
	return OK;
}

int GetLinkNodeLength(Link s)
/* 获取链表的结点个数,即链表长度
 */
{
	int nCnt = 0;
	while (s != NULL)
	{
		nCnt++;
		s = s->next;
	}
	return nCnt;
}

Status GetSpecifiedNode(Link		s, 
						int			n, 
						Position	*PosOfNode, 
						ElemType	*e)
/* 获取第n个结点的指针, 并返回其数据成员.
 */
{
	Position pNodePos = s;
	int iLen = GetLinkNodeLength(s), iCnt = 0;

	if ((n<=0) || (n>=(iLen+1)))
	{
		return ERROR;
	}
	iCnt = 1;	// The count should start from 1.
	while ((iCnt<n) && (pNodePos))
	{
		iCnt++;
		pNodePos = pNodePos->next;
	}
	*PosOfNode = pNodePos;
	*e = pNodePos->data;

	return OK;
}

Status	Remove(LinkList *L, ElemType *q)
/* 删除线性链表L中的尾结点并以q返回,
 * 改变链表L的尾指针指向新的尾结点.
 */
{
	Link pNode = L->head, pTemp = NULL;
	while (pNode->next != L->tail)		// Move to the previous node of tail node
	{
		pNode = pNode->next;
	}
	// *q = pNode->next;		// Current pNode->next is exactly the tail node.
	/* Stage the tail node, 
	 * but currently pNode is still remained the previous node of tail node
	 */
	pTemp = pNode->next;
	*q = pTemp->data;
	free(pTemp);			// Then free the tail node.
	/* At this moment, pNode was changed-over as the tail node.
	 */
	L->tail = pNode;	// Assign the tail node pointer to L's tail member.
	pNode->next = NULL;	// Meanwhile must assign the next of tail node to be NULL.
	L->len--;

	return OK;
}

Status	InsBefore(LinkList *L, Link *p, Link s)
/* 已知p指向线性链表L中的一个结点, 将s所指结点插入在p所指接点之前,
 * 并修改指针p指向新插入的结点.
 */
{
	Link posOfSpecifiedNode = *p,
		 pNode = L->head, 
		 pHead = L->head;
	if (pNode == posOfSpecifiedNode)	// The *p node points to the head node of link-list L
	{
		/* It means to insert a new node as the head node.
		 */
		s->next = pNode;
		pHead = s;
	}
	else
	{
		while (pNode->next != posOfSpecifiedNode)	// Move to the previous node of specified node.
		{
			pNode = pNode->next;
		}
		/* Insert the node "s" before "posOfSpecifiedNode" node.
		 */
		s->next = posOfSpecifiedNode;
		pNode->next = s;
	}

	/* Restore the head node pointer. */
	pNode = pHead;
	L->head = pHead;
	L->len++;
	/* Let *p point to s node position */
	*p = s;

	return OK;
}

Status	InsAfter(LinkList *L, Link *p, Link s)
/* 已知p指向线性链表L中的一个结点, 将s所指结点插入在p所指接点之后,
 * 并修改指针p指向新插入的结点.
 */
{
	Link posOfSpecifiedNode = *p,
		pNode = L->head,
		pHead = L->head;
	if (pNode == posOfSpecifiedNode)
	{
		/* Insert a new node after the head node
		 */
		s->next = pNode->next;
		pNode->next = s;
	}
	else
	{
		while (pNode != posOfSpecifiedNode)		// Move to the specified node
		{
			pNode = pNode->next;
		}
		/* Insert a new node after the specified node.
		 */
		s->next = pNode->next;
		pNode->next = s;
	}
	/* Restore the head node pointer. */
	pNode = pHead;
	L->head = pHead;
	L->len++;
	/* Let *p point to s node position */
	*p = s;

	return OK;
}

Status	SetCurElem(Link *p, ElemType e)
/* 已知p指向线性链表中的一个结点, 用e更新p所指结点中数据元素的值
 */
{
	Link pNode = *p;
	pNode->data = e;

	return OK;
}

ElemType	GetCurElem(Link p)
/* 已知p指向线性链表中的一个结点, 返回p所指结点中数据元素的值. 
 */
{
	return p->data;
}

Status	ListEmpty(LinkList L)
/* 若线性链表为空表,则返回TRUE, 否则返回FALSE
 */
{
	Link pNode = L.head, 
		pTailNode = L.tail,
		pHeadNode = L.head;
	int n = 0;
	while (pNode != NULL)
	{
		n++;
		pNode = pNode->next;
	}
	if (n != 0)
	{
		return FALSE;
	}
	if ( (L.len == 0) && (pTailNode == NULL) && (pHeadNode == NULL)  )
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

int		ListLength(LinkList L)
/* 返回线性链表L中的元素个数
 */
{
	int nLen = 0;
	Link pNode = L.head;
	while (pNode != NULL)
	{
		nLen++;
		pNode = pNode->next;
	}
	if (nLen != L.len)
	{
		printf("The node count of Link-list is wrong.\n");
		return ERROR;
	}

	return nLen;
}

Position	GetHead(LinkList L)
/* 返回线性链表L中头接点的位置
 */
{
	return L.head;
}

Position	GetLast(LinkList L)
/* 返回线性链表L中最后一个结点的位置
 */
{
	return L.tail;
}

Position	PriorPos(LinkList L, Link p)
/* 已知p指向线性链表L中的一个结点, 返回p所指结点的直接前驱的位置,
 * 若无前驱, 则返回NULL.
 */
{
	Link pNode = L.head;
	int n = 0;
	if (L.head == p)
	{
		return NULL;
	}
	else
	{
		while (pNode->next != p)
		{
			n++;
			if (n>L.len)	// To prevent pNode had moved beyond the length limitation
			{				// Because p could perhaps not point to any node of this link-list.
				return NULL;
			}
			pNode = pNode->next;
		}
		return pNode;
	}
}

Position	NextPos(LinkList L, Link p)
/* 已知p指向线性链表L中的一个结点, 返回p所指结点的直接后缀的位置,
 * 若无后缀, 则返回NULL.
 */
{
	Link pNode = L.head;
	int n = 0;
	if (p == L.tail)
	{
		return NULL;
	}
	else
	{
		while (pNode != p)
		{
			n++;
			if (n > L.len-1)
			{
				return NULL;
			}
			pNode = pNode->next;
		}
		return pNode->next;
	}
}

Status	LocatePos(LinkList L, int i, Link *p)
/* 返回p指向线性链表L中第i个结点的位置并返回OK.
 * i值不合法时则返回ERROR.
 */
{
	int nLen = ListLength(L), n = 0;
	Link pNode = L.head;

	if ((i<=0) || (i>nLen))
	{
		printf("The node position you entered is wrong.\n");
		return ERROR;
	}
	do
	{
		n++;
		pNode = pNode->next;
	}
	while (pNode && (n<i-1));		// Move to the ith node you desired.
	*p = pNode;

	return OK;
}

Position	LocateElem(LinkList L, 
					   ElemType e, 
					   Status	(*compare)(ElemType, ElemType))
/* 返回线性链表L中第1个与e满足函数compare()判定关系的元素的位置,
 * 若不存在这样的元素,则返回NULL.
 */
{
	Position posNode = L.head;
	while (posNode != NULL)
	{
		if (OK == (*compare)(posNode->data, e))
		{
			break;
		}
		posNode = posNode->next;
	}
	return posNode;
}

Status	ListTraverse(LinkList L, Status (*visit)(void *))
/* 依次对L的每个元素都调用函数visit().
 * 一旦visit()失败, 则操作失败.
 */
{
	Link pNode = L.head;
	Status iResult = 0;

	while (pNode != NULL)
	{
		if (FALSE == (*visit)(pNode))
		{
			return FALSE;
		}
		else
		{
			iResult = TRUE;
		}
		pNode = pNode->next;
	}
	return iResult;
}

Status	LinkListInsert(LinkList *L, int i, ElemType e)
/* 在带头结点的单链表L的第i个元素之前插入元素e
 */
{
	int iLen = ListLength(*L), nCnt = 0;
	Link pNode = L->head,
		pHead = L->head,
		pNewNode = NULL;

	if ((i <= 0) || (i > iLen) )	// i值不合法
	{
		return ERROR;
	}
	pNewNode = (Link)calloc(1, sizeof(LNode));
	if (pNewNode == NULL)
		return ERROR;
	pNewNode->data = e;

	while (pNode && (nCnt<i-2))
	{
		nCnt++;
		pNode = pNode->next;
	}
	pNewNode->next = pNode->next;
	pNode->next = pNewNode;

	/* Restore the head link L
	 */
	L->head = pHead;
	L->len++;

	return OK;
}

Status	MergeLinkList(LinkList	*La,
					  LinkList	*Lb,
					  LinkList	*Lc,
					  int		(*compare)(ElemType, ElemType))
/* 已知单链表La和Lb的元素按值非递减排列
 * 归并La和Lb得到新的单链表Lc, Lc的元素也按值非递减排列.
 */
{
	Link pNode_La = La->head, ha = GetHead(*La),
		 pNode_Lb = Lb->head, hb = GetHead(*Lb);
	int  iLen_La  = La->len,  iLen_Lb  = Lb->len;
	ElemType a = 0, b = 0;
	Link pTemp = NULL;

	if (!InitList(Lc))	// Initialize link list Lc.
		return ERROR;
	while (pNode_La && pNode_Lb)
	{
		a = GetCurElem(pNode_La);
		b = GetCurElem(pNode_Lb);
		if (0 >= (*compare)(a, b))
		{
			DelFirst(&ha, &pTemp);
			Append(Lc, pTemp);
			pNode_La = NextPos(*La, ha);
		}
		else
		{
			DelFirst(&hb, &pTemp);
			Append(Lc, pTemp);
			pNode_Lb = NextPos(*Lb, hb);
		}
	}
	if (pNode_La)
		Append(Lc, pNode_La);
	else
		Append(Lc, pNode_Lb);

	FreeNode(&ha);
	FreeNode(&hb);
	return OK;
}