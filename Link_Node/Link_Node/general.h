/**********************************************************************************************
 * File name		: general.h
 * Description		: Define some general constants, preprocessors and types.
 * Creator			: XU ZAN
 * Creation date	: Tue.	Oct. 28, 2014
 * Copyright(C)		2014	All rights reserved.
 *
 **********************************************************************************************/


#ifndef GENERAL_H
#define GENERAL_H

	// 函数结果状态代码
	#define TRUE			1
	#define FALSE			0
	#define OK				1
	#define ERROR			0
	#define INFEASIBLE		-1
	#define OVERFLOW		-2

	typedef int Status;		// Status是函数的类型,其值是函数结果状态代码

	// 数据元素的类型
	typedef int ElemType;

#endif	/*  GENERAL_H  */