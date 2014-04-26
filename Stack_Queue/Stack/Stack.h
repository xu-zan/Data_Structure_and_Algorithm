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

    #define STACK_INIT_SZIE     100
    #define STACKINCREMENT      10

    typedef struct SqStack
    {
        SElemType *base;
        SElemType *top;
        int stacksize;
    }
    SqStack, *PtrSqStack;

    Status InitSqStack(PtrSqStack pStack);

#endif	/*  STACK_H  */
