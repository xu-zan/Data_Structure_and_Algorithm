/**********************************************************************************
 * File name		: Test_Stack.c
 * Description		: Design some test cases to perform and validate the algorithm
 *					  of "Stack" structure.
 * Creator			: XU ZAN
 * Creation date	: Sun.	Nov. 23, 2014
 * Copyright(C)		2014	All rights reserved.
 *
 **********************************************************************************/

#include "Test_Stack.h"

#include "Stack.h"

#include <stdlib.h>

void Test_Stack_Operations(void)
{
	SElemType elem = 0;
	SqStack S = {0};
	
	InitStack(&S);		// 初始化一個棧
	CreateStack(&S);	// 實例化一個棧，為棧中的每一個元素賦值
	
	DisplayStack(S);	// 打印出棧中所有的元素
	
	// 压栈
	Push(&S, 21);
	DisplayStack(S);	// 確認壓棧後的效果
	
	// 退棧
	Pop(&S, &elem);
	DisplayStack(S);	// 確認退棧的效果
	
	// 压栈
	Push(&S, 99);
	DisplayStack(S);	// 確認壓棧後的效果
	
	DestroyStack(&S);	// 銷毀棧
	DisplayStack(S);	// 確認是否銷毀棧
}


/*
 * END OF FILE <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
 */