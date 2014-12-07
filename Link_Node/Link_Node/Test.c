/**********************************************************************************************
 * File name		: Test.c
 * Description		: Design the test case, used to verify the data structure and algorithm.
 * Creator			: XU ZAN
 * Creation date	: Tue.	Oct. 28, 2014
 * Copyright(C)		2014	All rights reserved.
 *
 **********************************************************************************************/

#include <stdio.h>
#include "Test.h"

#include "Fibonacci_Progression/Fibonacci_Progression_TestCase.h"
#include "misc/test_and_experiment.h"
#include "Linear_Link_List/Test_Linear_Link_List.h"

void Test_Case(void)
{
	Test_Linear_Link_List();

	// Test_Case_Fibonacci_Progression();
	// Test_Case_DoubleArrayExport();
}

void Test_Case_Fibonacci_Progression(void)
{
	Test_Generating_Fibonacci_Progression();
}

void Test_Case_DoubleArrayExport(void)
{
	Test_ReferenceOutputDoubleArray();
}

void Test_Linear_Link_List(void)
{
	// TestCase_LinearLinkNode();
	TestCase_MergeLinkNode();
}