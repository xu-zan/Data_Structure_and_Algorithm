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
#include "Circular_Link_List/Test_Dual_Link_Node.h"
#include "Linear_Link_List/Test_Link_Node.h"

void Test_Case(void)
{
	// Test_Linear_Link_List();

	// TestCase_DualLinkNode();

	// Test_Case_Fibonacci_Progression();
	// Test_Case_DoubleArrayExport();

	Test_Link_Node();
}

void Test_Case_Fibonacci_Progression(void)
{
	Test_Generating_Fibonacci_Progression();
}

void Test_Case_DoubleArrayExport(void)
{
	// Test_ReferenceOutputDoubleArray();
	Test_Self_Increment_Decrement();
}

void Test_Linear_Link_List(void)
{
	// TestCase_LinearLinkNode();

	// TestCase_MergeLinkNode();

	// TestCase_LinkNodeSort();

	// TestCase_LinkNodeStatistics();
	TestCase_Merge2LinkNodes();
}

void Test_Circular_Link_List(void)
{
	TestCase_DualLinkNode();
}


void Test_Link_Node(void)
{
	TestCase_Link_List();

	// TestCase_Link_Node();
}