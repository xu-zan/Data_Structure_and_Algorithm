/********************************************************************************************
 * File name	: Linear_List.h
 * Description	: To describe the structure of Linear_List
 * Creator		: XU ZAN
 * Creation date: Fri.	Nov. 22, 2013
 * Copyright(C)		2013	All rights reserved.
 *
 ********************************************************************************************/

#ifndef LINEAR_LIST_H
#define LINEAR_LIST_H

	/* "綫性表"抽象數據類型表述
	 * 
	 * ADT List
	 * {
	 *		數據對象 : D = {a[i], i = 1, 2, ..., n}
	 *		數據關係 : R1 = {<a[i-1], a[i]>}
	 *		基本操作 :
	 *			InitList(&L);
	 *			DestroyList(&L);
	 *			ClearList(&L);
	 *			ListEmpty(L);
	 *			ListLength(L);
	 *			GetElem(L, i, &e);
	 *			LocateElem(L, e, compare());
	 *			PriorElem(L, cur_e, &pre_e);
	 *			NextElem(L,  cur_e, &next_e);
	 *			ListInsrt(&L, i, e);
	 *			ListDelete(&L, i, &e);
	 *			ListTraverse(L, visit());
	 *			union(List &La, List Lb);
	 *			MergeList(List La, List Lb, List &Lc);
	 * }
	 */

	#include "../pre_definition.h"

	// ----- 綫性表的動態分配順序存儲結構 -----
	#define LIST_INIT_SIZE	100	// 綫性表存儲空間的初始分配量
	#define LISTINCREMENT	10	// 綫性表存儲空間的分配增量

	typedef int	ElemType;

	typedef struct
	{
		ElemType	*elem;		// 存儲空間基地址
		int			length;		// 當前長度
		int			listsize;	// 當前分配的存儲容量（以sizeof(ElemType)為單位）
	} SqList;

	Status InitList_Sq(SqList &L);
	Status ListInsert_Sq(SqList &L, int i, ElemType e);			// 時間複雜度 ：
	Status ListDelete_Sq(SqList &L, int i, ElemType &e);		// 順序表中刪除/插入元素的時間複雜度 = O(n)
	void ListDisplay_Sq(SqList L);
	int ListLength(SqList L);
	void GetElem_ListSq(SqList L, int i, ElemType &e);

	int LocateElem_Sq(SqList L, ElemType e, Status (*compare)(ElemType, ElemType));
	Status compare(ElemType e1, ElemType e2);
	Status equal(ElemType e1, ElemType e2);

	void MergeList_Sq(SqList La, SqList Lb, SqList &Lc);	// 順序表的合併
	void UnionList_Sq(SqList &La, SqList Lb);

#endif	/*  LINEAR_LIST_H  */