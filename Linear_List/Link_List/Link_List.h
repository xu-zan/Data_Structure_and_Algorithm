/**********************************************************************************
 * File name	: Link_List.h
 * Description	: Define the data structure of link list, declare the function 
 *				  prototypes of its algorithm.
 * Creator		: XU ZAN
 * Creation date: Mon.	Dec. 16, 2013
 * Copyright(C)		2013	All rights reserved.
 *
 **********************************************************************************/

#ifndef LINK_LIST_H
#define LINK_LIST_H

	#include "../pre_definition.h"

	typedef int ElemType;

	typedef struct LNode
	{
		ElemType data;
		struct LNode *next;
	}
	LNode, *LinkList;

	Status GetElem_LinkList(LinkList L, int i, ElemType &e);

	void Display_LinkList(LinkList L);

	Status ListInsert_LinkList(LinkList &L, int iPos, ElemType e);

#endif	/*  LINK_LIST_H  */