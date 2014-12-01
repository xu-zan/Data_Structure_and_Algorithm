/*****************************************************************************************
 * File name		: Dual_Link_Node.h
 * Description		: Study the "dual-direction link node" structure.
 * Creator			: XU ZAN
 * Creation date	: Mon.	Nov. 17, 2014
 * Copyright(C)		2014	All rights reserved.
 *
 *****************************************************************************************/

#ifndef DUAL_LINK_NODE_H
#define DUAL_LINK_NODE_H

	#include "../general.h"

	typedef struct DuLNode
	{
		ElemType data;
		struct DuLNode *prior;
		struct DuLNode *next;
	}
	DuLNode, *PtrDuLNode;

	Status ListInsert_DuLN(PtrDuLNode *L, int i, ElemType e);
	Status ListDelete_DuLN(PtrDuLNode *L, int i, ElemType *e);

	int GetLength_DuLN(PtrDuLNode L);
	PtrDuLNode GetElemPtr_DuLN(PtrDuLNode L, unsigned int n);

	Status ListCreate_DuLN(PtrDuLNode *L, int n);
	void ListDisplay_DuLN(PtrDuLNode L);
	void ListDestroy_DuLN(PtrDuLNode *L);

#endif	/*  DUAL_LINK_NODE_H  */