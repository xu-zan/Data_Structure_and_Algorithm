/********************************************************************************************
 * File name	: Linear_List.cpp
 * Description	: To implement the structure of Linear_List and its algorithm.
 * Creator		: XU ZAN
 * Creation date: Thur.	Nov. 28, 2013
 * Copyright(C)		2013	All rights reserved.
 *
 ********************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "Linear_List.h"

Status InitList_Sq(SqList &L)
{
	// 構造一個空的綫性表L
	L.elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if (!L.elem)
		exit(OVERFLOW);		// 存儲分配失敗
	L.length = 0;					// 空表長度為0
	L.listsize = LIST_INIT_SIZE;	// 初始存儲容量
	return OK;
}

Status ListInsert_Sq(SqList &L, int i, ElemType e)
/* 在順序綫性表L中第i個位置之前插入新的元素e
 * i的合法值為 1<=i<=ListLength_Sq(L)+1
 */
{
	ElemType *newbase = NULL;
	ElemType *q = NULL,
			 *p = NULL;

	if ((i<1) ||(i>L.length+1))
		return ERROR;
	if (L.length >= L.listsize)
	{
		/*
		 * 當前存儲空間已滿,增加分配
		 */
		newbase = (ElemType *)realloc(L.elem, sizeof(ElemType)*(L.listsize + LISTINCREMENT));
		if (!newbase)
			exit(OVERFLOW);
		L.elem = newbase;	// 賦予新的基地址
		L.listsize += LISTINCREMENT;	// 增加存儲容量
	}

	q = &(L.elem[i-1]);		// q為插入位置
	for (p=&(L.elem[L.length-1]); p>=q; --p)
	{
		// 插入位置及之後的元素右移
		*(p+1) = *p;
	}
	*q = e;			// 插入e
	++L.length;		// 表長增1
	return OK;
}

Status ListDelete_Sq(SqList &L, int i, ElemType &e)
/* 在順序綫性表L中刪除第i個元素, 並用e返回其值
 * i的合法值為 1<=i<=ListLength_Sq(L)
 */
{
	ElemType *p = NULL, *q = NULL;

	if ((i<1) || (i>L.length))
		return ERROR;

	p = &(L.elem[i-1]);		// p為被刪除元素的位置
	e = *p;					// 被刪除元素的值賦給e
	q = L.elem + L.length - 1;	// 表尾元素的位置
	for (p++; p<=q; ++p)
	{
		*(p-1) = *p;	// 被刪除元素之後的元素左移
	}
	--L.length;		// 表長減1

	return OK;
}

void ListDisplay_Sq(SqList L)
/* 列印出順序表中所有的元素, 
 * 依次列印出來, 並顯示每個元素在内存中的地址
 */
{
	ElemType *p = NULL;
	int i = 0;

	printf("The Seq_List is shown as below :\n");
	printf("Value\t\tAddress\n");

	for (i=0; i<L.length; i++)
	{
		p = &(L.elem[i]);
		printf("%d\t\t0x%08X\n", *p, p);
	}
	printf("\n");

	return;
}

int ListLength(SqList L)
{
	int iLen = 0;

	iLen = sizeof(L.elem) / sizeof(ElemType); 

	return iLen;
}

void GetElem_ListSq(SqList L, int i, ElemType &e)
{
}

int LocateElem_Sq(SqList L, ElemType e, Status (*compare)(ElemType, ElemType))
/* 在順序表L中查找第一個值與e滿足compare()的元素的位序
 * 若找到，則返回其在L中的位序， 否則返回0
 */
{
	int i = 1;				// i的初值為第1個元素的位序
	ElemType *p = L.elem;	// p的初值為第1個元素的存儲位置

	while ( (i<=L.length) && !((*compare)(*(p++), e)) )
	{
		++i;
	}
	if (i<=L.length)
		return i;
	else
		return 0;

	return OK;
}

Status compare(ElemType e1, ElemType e2)
{
#if 0
	if (e1 == e2)
		return 0;
	else if (e1 > e2)
		return 1;
	else if (e1 < e2)
		return -1;
#endif
	if (e1 == e2)
		return 0;
	else
		return !0;
}

Status equal(ElemType e1, ElemType e2)
{
	if (e1 == e2)
		return OK;
	else
		return ERROR;
}

void MergeList_Sq(SqList La, SqList Lb, SqList &Lc)
/* 已知順序表La和Lb的元素按值非遞減排列
 * 歸併La和Lb得到新的順序表Lc, Lc的元素也按值非遞減排列
 */
{
	ElemType *pa = La.elem, *pb = Lb.elem, *pc = NULL;
	ElemType *pa_last = NULL, *pb_last = NULL;

	Lc.length = La.length + Lb.length;
	Lc.listsize = Lc.length;
	Lc.elem = (ElemType *)malloc(Lc.listsize * sizeof(ElemType));
	if (!Lc.elem)
		exit(OVERFLOW);
	pc = Lc.elem;

	pa_last = La.elem + La.length - 1;	// La的最後一個元素
	pb_last = Lb.elem + Lb.length - 1;	// Lb的最後一個元素

	while ( (pa <= pa_last) && (pb <= pb_last) )	// 歸併
	{
		if (*pa <= *pb)
			*pc++ = *pa++;
		else
			*pc++ = *pb++;
	}
	while (pa <= pa_last)	// 插入La的剩餘元素
	{
		*pc++ = *pa++;
	}
	while (pb <= pb_last)	// 插入Lb的剩餘元素
	{
		*pc++ = *pb++;
	}
}

void UnionList_Sq(SqList &La, SqList Lb)
/* 將所有在順序表Lb中,但不在La的數據元素
 * 插入到La中.
 */
{
	int iLa_len = ListLength(La),
		iLb_len = ListLength(Lb);
	int i = 0;
	ElemType e;

	for (i=0; i<iLb_len; i++)
	{
		GetElem_ListSq(Lb, i, e);	// 取Lb中的第i个数据元素赋给e
		if (!LocateElem_Sq(La, e, equal))
		{
			ListInsert_Sq(La, ++iLa_len, e);
		}
	}
}