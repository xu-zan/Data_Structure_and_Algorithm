/******************************************************************************************************
 * File name		: Stack.h
 * Description		: Define the data structure of Stack.
 * Creator			: XU ZAN
 * Creation date	: Thur.	April 24, 2014
 * Copyright(C)		2014	All rights reserved.
 *
 ******************************************************************************************************/


#ifndef STACK_H
#define STACK_H

    #include "pre_definition.h"

    #define STACK_INIT_SZIE     100		// 存储空间初始分配量
    #define STACKINCREMENT      10		// 存储空间分配增量

    typedef struct SqStack
    {
        SElemType *base;	// 在栈构造之前和销毁之后，base的值为NULL
        SElemType *top;		// 栈顶指针
        int stacksize;      // 当前已分配的存储空间，以元素为单位
    }
    SqStack, *PtrSqStack;

    Status InitSqStack(PtrSqStack pStack);		// 构造一个空栈	
    
    Status DestroySqStack(PtrSqStack pStack);	// 销毁栈
    
    Status ClearSqStack(PtrSqStack pStack);		// 把栈pStack置为空栈
    
    Status IsEmptySqStack(SqStack S);			// 判断栈S是否为空栈
    
    int SqStackLength(SqStack S);				// 返回栈的长度，元素得个数
    
    Status GetTop(SqStack S, SElemType *pElem);	// 返回栈顶元素
    
    Status Push(PtrSqStack pStack, SElemType elem);		// 压入新的栈顶元素
    
    Status Pop(PtrSqStack pStack, SElemType *pElem);	// 退出栈顶
    
    Status SqStackTraverse(SqStack S, Status (*visit)());	// 从栈底到栈顶依次对栈中的每个元素调用函数visit(), 一旦visit()失败，则操作失败

#endif	/*  STACK_H  */
