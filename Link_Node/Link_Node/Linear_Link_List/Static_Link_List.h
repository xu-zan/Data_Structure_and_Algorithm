/*******************************************************************************************
 * File name		: Static_Link_List.h
 * Description		: 研究静态链表
 * Creator			: XU ZAN
 * Creation date	: Sat.	Nov. 15, 2014
 * Copyright(C)		2014	All rights reserved.
 *
 *******************************************************************************************/

#ifndef STATIC_LINK_LIST_H
#define STATIC_LINK_LIST_H

	#include "../general.h"

	/* 
	 * 线性表的静态单链表存储结构
	 */
	#define MAXSIZE		1000	// 链表的最大长度

	typedef struct
	{
		ElemType data;
		int cur;
	}
	component, SLinkList[MAXSIZE];

	int LocateElem_SL(SLinkList S, ElemType e);

	void InitSpace_SL(SLinkList *space);

	void CreateSpace_SL(SLinkList *space, int iLen);

	int Malloc_SL(SLinkList *space);

	void Free_SL(SLinkList *space, int k);

	void difference(SLinkList *space, int *S);

	void DisplayList_SL(SLinkList S);


#endif	/*  STATIC_LINK_LIST_H */