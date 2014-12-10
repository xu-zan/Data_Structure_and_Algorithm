/*******************************************************************************************************
 * Toolbox module		: Fibonacci_Progression
 * Description			: 研究和实现数学上著名的斐波那契数列, 并整理形成一个工具箱模块.
 * =====================================================================================================
 * File name			: Fibonacci_Progression.h
 * Description			: Declare the prototype of "Fibonacci progression", and provide the API 
 *						  function set of "Fibonacci progression".
 * Creator				: XU ZAN
 * Creation date		: Tue.	Oct. 28, 2014
 * Copyright(C) 2014	Hella Shanghai Electronics Co., Ltd.	
 * All rights reserved
 *
 *******************************************************************************************************/


#ifndef FIBONACCI_PROGRESSION_H
#define FIBONACCI_PROGRESSION_H

	/***************************************************************************************************
	 * 意大利数学家列昂纳多-斐波那契 (leonardo Fibonacci)提出了斐波那契数列. 即:
	 * 从第2项开始, 相邻2项之和等于后1项.   用数学表达式来描述即为
	 *		F(n) = F(n-1) + F(n-2)		[n为自然数]
	 *		F(0) = 1
	 *		F(1) = 1
	 *
	 * 斐波那契数列 (Fibonacci progression)具有很多优美的性质, 并且应用广泛.
	 * 同时它也是研究和设计算法的重要参考模型。
	 *
	 * 为此，在此用C语言实现斐波那契数列，并形成一个有用的工具箱。
	 ***************************************************************************************************/
	#ifdef __cplusplus
		extern "C"
		{
	#endif
			#define STATUS_OK			 0
			#define STATUS_ERROR		!0
			#define STATUS_OVERFLOW		-1

			typedef unsigned long long ULONG64;		// 64-bit 
			typedef unsigned int COUNT;				// 表示自然数n
			typedef int STATUS;

			ULONG64	Fibonacci(COUNT n, ULONG64 **FibonacciArray);
			void	Print_Fibonacci_Progression_List(COUNT n, ULONG64 *FibonacciArray);	// 打印Fibonacci progression列表
			double  Fibonacci_Ratio(COUNT n);		// 计算Fibonacci数列相邻两项的比值, 即F(n-1)/F(n)
			void	Print_Fibonacci_Ratio_List(COUNT n, ULONG64 *FibonacciArray);		// 打印Fibonacci数列相邻两项比值列表


			ULONG64 Generate_Fibonacci_Progression(COUNT	n, 
												   ULONG64	**FibonacciProgression, 
												   char		*sFibonacciStatus);

	#ifdef __cplusplus
		}
	#endif

#endif	/*  FIBONACCI_PROGRESSION_H  */