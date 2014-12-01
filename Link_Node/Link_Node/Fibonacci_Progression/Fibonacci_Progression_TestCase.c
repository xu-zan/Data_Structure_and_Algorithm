/**********************************************************************************
 * File name		: Fibonacci_Progression_TestCase.c
 * Description		: Design the test case to validate the Fibonacci 
 *					  progression module.
 * Creator			: XU ZAN
 * Creation date	: Tue.	Oct. 28, 2014
 * Copyright(C)		2014	All rights reserved.
 *
 **********************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#include "Fibonacci_Progression_TestCase.h"
#include "Fibonacci_Progression.h"

void Test_Generating_Fibonacci_Progression(void)
{
	COUNT n = 0;
	ULONG64 *pFibonacciArray = NULL,
		    ulFibobacciValue_ItemN = 0;
	char sFiboStatus[128] = {0};
	printf("Please enter the item number of Fibonacci progression : n = ");
	scanf("%d", &n);
#if 0
	ulFibobacciValue_ItemN = Fibonacci(n, &pFibonacciArray);
#else
	ulFibobacciValue_ItemN = Generate_Fibonacci_Progression(n, &pFibonacciArray, sFiboStatus);
#endif
	Print_Fibonacci_Progression_List(n, pFibonacciArray);
	Print_Fibonacci_Ratio_List(n, pFibonacciArray);

	free(pFibonacciArray);
	pFibonacciArray = NULL;
}