/******************************************************************************************************
 * File name		: Stack.c
 * Description		: Implement the algorithm of Stack.
 * Creator			: XU ZAN
 * Creation date	: Thur.	April 24, 2014
 * Copyright(C)		2014	All rights reserved.
 *
 ******************************************************************************************************/

#include <stdlib.h>

#include "Stack.h"

Status InitSqStack(PtrSqStack pStack)
/* Create an empty stack
 */
{
    pStack->base = (SElemType *)malloc(STACK_INIT_SZIE * sizeof(SElemType));
    if (!(pStack->base))
    {
        exit(OVERFLOW);
    }

    pStack->top = pStack->base;
    pStack->stacksize = STACK_INIT_SZIE;

    return OK;
}
