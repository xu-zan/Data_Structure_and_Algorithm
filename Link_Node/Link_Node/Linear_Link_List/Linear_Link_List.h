/*********************************************************************************************
 * File name		: Linear_Link_List.h
 * Description		: Declare the prototype of "Linear link node" structure.
 * Creator			: XU ZAN
 * Creation date	: Tue.	Oct. 28, 2014
 * Copyright(C)		2014	All rights reserved.
 *
 *********************************************************************************************/


#ifndef LINEAR_LINK_LIST_H
#define LINEAR_LINK_LIST_H

	/*******************************************************************************/
	// Includes
	#include "../general.h"
	

	/*******************************************************************************/
	// Structures
	typedef struct LNode
	{
		int data;
		struct LNode *next;
	}
	LNode, *PtrLinkList;


	/*******************************************************************************/
	// Function prototype
	Status	ListGetElem_LinkNode(PtrLinkList L, int i, ElemType *e);
	
	Status	ListInsert_LinkNode(PtrLinkList *L, int i, ElemType e);
	Status	ListInsert_L(PtrLinkList L, int i, ElemType e);
	
	Status	ListDelete_LinkNode(PtrLinkList *L, int i, ElemType *e);
	
	void	ListCreate_LinkNode(PtrLinkList *L, int n);
	void	ListCreate_L(PtrLinkList L, int n);

	void	ListDuplicate_LinkList(PtrLinkList pOriginalNode, PtrLinkList *pCopiedNode);
	void	ListDestroy_LinkNode(PtrLinkList *L);
	
	void	ListDisplay_LinkNode(PtrLinkList L);
	
	void	ListMerge_LinkNode(PtrLinkList La, PtrLinkList Lb, PtrLinkList *Lc);

	ElemType MaxElem_LinkNode(PtrLinkList L, char *sError);
	int GetLength_LinkNode(PtrLinkList L);
	void Bubble_Sort(ElemType Array[], int nSize);

	int ListStatistics_LinkNode(PtrLinkList L, ElemType e);
	void ListMerge_2LinkNodes(PtrLinkList *La, PtrLinkList *Lb, PtrLinkList *Lc);

#endif	/*  LINEAR_LINK_LIST_H  */