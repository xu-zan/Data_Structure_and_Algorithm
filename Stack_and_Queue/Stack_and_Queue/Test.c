/*******************************************************************************
 * File name		: Test.c
 * Description		: Perform the test cases.
 * Creator			: XU ZAN
 * Creation date	: Sun.	Nov. 23, 2014
 * Copyright(C)		2014	All rights reserved.
 *
 *******************************************************************************/


#include "Test.h"

#include "Stack/Test_Stack.h"

void General_Test_Cases(void)
{
	TestCase_Stack();
	return;
}


void TestCase_Stack(void)
{
	Test_Stack_Operations();
}