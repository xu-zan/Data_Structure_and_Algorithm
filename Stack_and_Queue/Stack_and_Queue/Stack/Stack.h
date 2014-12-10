/*******************************************************************************
 * File name		: Stack.h
 * Description		: Declare the "Stack" structure.
 * Creator			: XU ZAN
 * Creation date	: Sun.	Nov. 23, 2014
 * Copyright(C)		2014	All rights reserved.
 *
 *******************************************************************************/


#ifndef STACK_H
#define STACK_H

	#include "../general.h"

	// ==== 抽象數據結構 Stack 的表示和實現 ====

	// －－－棧的順序存儲表示－－－

	typedef int	SElemType;

	#define STACK_INIT_SIZE	10		// 存空間初始分配量
	#define STACK_INCREMENT	1		// 存儲空間分配增量

	typedef struct SqStack
	{
		SElemType	*top;		// 棧頂指針
		SElemType	*base;		// 棧底指針，在棧構造之前和銷毀之後，base的值均為NULL
		int			stacksize;	// 當前已分配的存儲空間，以元素為單位
	}
	SqStack,	*PtrSqStack;

	/**********************************************************************/
	Status InitStack(SqStack *S);
	Status CreateStack(SqStack *S);

	Status DestroyStack(SqStack *S);

	Status ClearStack(SqStack *S);

	void DisplayStack(SqStack S);

	int StackEmpty(SqStack S);
	int StackLength(SqStack S);

	Status GetTop(SqStack S, SElemType *e);

	Status Push(SqStack *S, SElemType e);

	Status Pop(SqStack *S, SElemType *e);

	Status StackTraverse(SqStack S, Status (*visit)(void *p));

#endif	/*  STACK_H  */