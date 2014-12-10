/*******************************************************************************
 * File name		: Stack.c
 * Description		: Implement the algorithm of "Stack" structure.
 * Creator			: XU ZAN
 * Creation date	: Sun.	Nov. 23, 2014
 * Copyright(C)		2014	All rights reserved.
 *
 *******************************************************************************/

#include "Stack.h"

#include <stdlib.h>
#include <stdio.h>

Status InitStack(SqStack *S)
/* 構造一個空棧S
 */
{
	S->base = (SElemType *)calloc(STACK_INIT_SIZE, sizeof(SElemType));
	if (S->base == NULL)
	{
		exit(OVERFLOW);
	}
	S->top = S->base;	// 棧底等於棧頂，即為空棧
	S->stacksize = STACK_INIT_SIZE;
	
	return OK;
}

/*******************************************************************************/

Status CreateStack(SqStack *S)
/* 創建一個具體的棧，棧內填滿用戶輸入的數據。
 */
{
	int i = 0;
	printf("Create a new stack, please enter the data :\n");
	for (i=0; i<S->stacksize; i++)
	{
		scanf("%d", (S->base+i));
		S->top = S->base+i;		// 棧頂的指針移動，隨著棧中元素不斷增長。
	}
	return OK;
}

/*******************************************************************************/

Status DestroyStack(SqStack *S)
/* 銷毀棧S，S不存在.
 */
{
	free(S->base);
	// free(S->top);	// S->top was not allocated a memory space, so forbid calling free().
						// S->top is just a pointer, pointing to the stack top.
	S->base = NULL;
	S->top = NULL;
	S->stacksize = 0;
	
	return OK;
}

/*******************************************************************************/

Status ClearStack(SqStack *S)
/* 把S置為空棧
 */
{
	free(S->base);		// 清空棧底
	S->top = S->base;	// 棧頂的指針等於棧底的元素，則說明該棧為空棧
	return OK;
}

/*******************************************************************************/

void DisplayStack(SqStack S)
/* 打印出棧的內容與地址空間
 */
{
	int i = 0;
	printf("\n\n");
	printf("Address			| Data		\n");
	printf("--------------------------------------\n");
	for (i=0; i<S.stacksize; i++)
	{
		printf("0x%08X		| %d		\n", S.top-i, *(S.top-i));
		printf("--------------------------------------\n");
		if (S.top == S.base)
		{
			printf("Stack over.\n");
			break;	
		}
	}
	return;
}


/*******************************************************************************/

int StackEmpty(SqStack S)
/* 若棧S為空棧，則返回TRUE, 否則返回FLASE.
 */
{
	int iValue = FALSE;
	
	if (S.top == S.base)
	{
		iValue = TRUE;
	}
	else
	{
		iValue = FALSE;
	}
	
	return iValue;
}

/*******************************************************************************/

int StackLength(SqStack S)
{
	int iStackLen = 0;
	SElemType *pStart = S.base;
	while (pStart != S.top)
	{
		iStackLen++;
		pStart = pStart+1;
	}
	
	return iStackLen;
}


/*******************************************************************************/

Status GetTop(SqStack S, SElemType *e)
/* 若棧不為空，則用e返回S的棧頂元素，並返回OK, 否則返回ERROR.
 */
{
	if (S.top == S.base)
	{
		return ERROR;
	}
	*e = *(S.top-1);
	return OK;
}


/*******************************************************************************/

Status Push(SqStack *S, SElemType e)
/* 插入元素e為新的棧頂元素
 */
{
	int iCurrentLen = 0;
	iCurrentLen = (S->top) - (S->base) + 1;
	if (iCurrentLen >= (S->stacksize))		// 棧滿，追加存儲空間
	{
		S->base = (SElemType *)realloc(S->base,
									   sizeof(SElemType)*(S->stacksize+STACK_INCREMENT));
		if (!(S->base))		// 存儲空間分配失敗
		{
			exit(OVERFLOW);
		}
		
		S->top = S->base + S->stacksize;	// 棧頂的指針指向新分配的空間地址
		S->stacksize = S->stacksize + STACK_INCREMENT;		// 更新存儲空間的size.
	}
	*(S->top) = e;
	return OK;
}


/*******************************************************************************/

Status Pop(SqStack *S, SElemType *e)
/* 若棧不為空， 則刪除S的棧頂元素。
 * 用e返回其值，並返回OK, 否則就返回ERROR.
 */
{
	// SElemType *pSpace2BeFreed = NULL;
	if (S->top == S->base)
	{
		return ERROR;
	}
	*e = *(S->top);
	S->top--;	// 栈顶指针后退一个单位
	
	// 退棧需要銷毀棧頂指針所指向的空間 ===> 如何销毁？
	// pSpace2BeFreed = (S->base) + (S->stacksize)-1;
	// free(pSpace2BeFreed);
	// free((S->base) + (S->stacksize)-1);
	
	(S->stacksize)--;
	
	return OK;
}


/*******************************************************************************/

Status StackTraverse(SqStack S, Status (*visit)(void *p))
/* 從棧底到棧頂依次對棧中的每個元素調用visit()函數， 一旦visit()失敗，則操作失敗。
 */
{
	return OK;
}
/*
 * END OF FILE <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
 */