/************************************************************************************************
 * File name        : Test.c
 * Description      : Execute the test cases for the entire project.
 * Creator          : XU ZAN
 * Creation date    : Wed.  Nov. 26, 2014
 * Copyright(C)     2014    All rights reserved.
 * 
 ************************************************************************************************/

#include "Test.h"
#include "String_Structure/Test_String.h"

void General_Test_Cases(void)
{
    Perform_TestCase4_HeapString();
	return;
}

void Perform_TestCase4_HeapString(void)
{
	TestCase4_HeapString();
}