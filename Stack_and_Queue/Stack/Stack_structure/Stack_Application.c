/******************************************************************
 * File name		: Stack_Application.c
 * Description		: "栈"这种数据结构的应用.
 * Creator			: XU ZAN
 * Creation date	: Mon.	Nov. 24, 2014
 * Copyright(C)		2014	All rights reserved.
 *
 ******************************************************************/

#include "Stack.h"

void Decimal_Conversion_Octal(void)
{
	unsigned int num = 0;
	SqStack S = {0};

	InitStack(&S);
	printf("Please enter a decimal format of number : ");
	scanf("%d", &num);
}


void Decimal_Conversion_Hex(void)
{
}