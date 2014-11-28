/*******************************************************************************************************
 * Toolbox module		: Fibonacci_Progression
 * Description			: 研究和实现数学上著名的斐波那契数列, 并整理形成一个工具箱模块.
 * =====================================================================================================
 * File name			: Fibonacci_Progression.c
 * Description			: Implement the "Fibonacci progression" and its API function set 
 *						  of "Fibonacci progression".
 * Creator				: XU ZAN
 * Creation date		: Tue.	Oct. 28, 2014
 * Copyright(C) 2014	Hella Shanghai Electronics Co., Ltd.	
 * All rights reserved
 *
 *******************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Fibonacci_Progression.h"

static ULONG64 *g_FibonacciList = NULL;

static ULONG64 Fibonacci_ItemN(COUNT n);

ULONG64	Fibonacci(COUNT n, ULONG64 **FibonacciArray)
/*******************************************************************************************************
 * Function name	: Fibonacci
 * Description		: 产生Fibonacci数列列表
 * Inputs			: n
 * Outputs			: Fibonacci_Progresssion_List[]
 * Return			: Fibonacci(n)  ---- 第n项Fibonacci值
 *******************************************************************************************************/
{
	ULONG64 ull64Fibonacci = 0;
	ULONG64 *pFibTempArray = (ULONG64 *)calloc(n, sizeof(ULONG64));
	int i = 0;

	g_FibonacciList = (ULONG64 *)malloc(sizeof(ULONG64)*n);
	ull64Fibonacci = Fibonacci_ItemN(n);
	*FibonacciArray = pFibTempArray;

	for (i=0; (unsigned)i<n; i++)
	{
		memcpy(pFibTempArray+i, g_FibonacciList+i, sizeof(ULONG64));
	}
	free(g_FibonacciList);

	return ull64Fibonacci;
}

static ULONG64 Fibonacci_ItemN(COUNT n)				// 计算一个Fibonacci第n项的值
{
	ULONG64 ull64FibValue = 0;
	if (n==0)
	{
		ull64FibValue = 1;
		g_FibonacciList[0] = 1;
	}
	else if (n==1)
	{
		ull64FibValue = 1;
		g_FibonacciList[1] = 1;
	}
	else
	{
		ull64FibValue = Fibonacci_ItemN(n-1) + Fibonacci_ItemN(n-2);
		g_FibonacciList[n-1] = ull64FibValue;
	}
	return ull64FibValue;
}

void Print_Fibonacci_Progression_List(COUNT n, ULONG64 *FibonacciArray)	// 打印Fibonacci progression列表
{
	int index = 0;
	printf("Fibonacci progression list :\n");
	printf("--------------------------------------------------------------------\n");
	printf("    n			|    Fibonacci item                                 \n");
	printf("--------------------------------------------------------------------\n");
	for (index=0; (unsigned)index<n; index++)
	{
	printf("    %d			|    %lld					\n", index+1, *(FibonacciArray+index));
	printf("--------------------------------------------------------------------\n");
	}
	printf("\n\n");
	return;
}

void	Print_Fibonacci_Ratio_List(COUNT n, ULONG64 *FibonacciArray)		// 打印Fibonacci数列相邻两项比值列表
{
	int i = 0;

	printf("Fibonacci progression ratio list :\n");
	printf("--------------------------------------------------------------------\n");
	printf("    n			|    Fibonacci ratio [F(n-1)/F(n)]                  \n");
	printf("--------------------------------------------------------------------\n");
	for (i=0; (unsigned)i<n-1; i++)
	{
	printf("    %d			|    %0.012f				\n", i+1, ((double)*(FibonacciArray+i))/((double)*(FibonacciArray+i+1)));
	printf("--------------------------------------------------------------------\n");
	}
	printf("\n\n");
	return;
}


ULONG64 Generate_Fibonacci_Progression(COUNT	n,
									   ULONG64	**FibonacciProgression, 
									   char		*sFibonacciStatus)
{
	ULONG64 *FiboArray = calloc(n+1, sizeof(ULONG64));
	unsigned int i = 0;

	for (i=0; i<=n; i++)
	{
		if (i==0)
		{
			*(FiboArray+i) = 1;
			continue;
		}
		if (i==1)
		{
			*(FiboArray+i) = 1;
			continue;
		}
		*(FiboArray+i) = *(FiboArray+i-1) + *(FiboArray+i-2);
		if (*(FiboArray+i) > 0xFFFFFFFFFFFFFFFF)	// The max fibonacci item had exceeded the max. expression range (64-bit).
		{
			sprintf(sFibonacciStatus, "%s", "Fibonacci progression is too big. Overflow!");
			break;	// Overflow then exit.
		}
		else
		{
			sprintf(sFibonacciStatus, "%s", "Fibonacci progression OK.");
		}
	}
	*FibonacciProgression = FiboArray;
	return *(FiboArray+i-1);
}