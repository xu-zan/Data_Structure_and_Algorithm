/*******************************************************************************
 * File name        : Test_String.c
 * Description      : Design the test case to verify the algorithm of string.
 * Creator          : XU ZAN
 * Creation date    : Thu.  Nov. 27, 2014
 * Copyright(C)     2014    All rights reserved.
 *******************************************************************************/

#include "Test_String.h"
#include "String.h"
#include <stdio.h>

void TestCase4_HeapString(void)
{
	char *sampleStr = "This is a sample string",
         *testStr = "This is a string under test";
	HString sampleHStr      = {NULL, 0}, 
            testHStr        = {NULL, 0},
            concatedHStr    = {NULL, 0},
            subHStr         = {NULL, 0};
	
	int iResult = 0;
	iResult = StrAssign(&sampleHStr, sampleStr);
    iResult = StrAssign(&testHStr, testStr);
	
	printf("The length of heap string under test is : %d.\n", StrLength(sampleHStr));
	printf("The content of heap string under test is : \"%s\"\n", sampleHStr.ch);
    
    if (0 != StrCompare(sampleHStr, testHStr))
    {
        printf("The 2 heap string are compared different.\n");
    }
    Concat(&concatedHStr, sampleHStr, testHStr);
	printf("The concated string is : \"%s\"\n", concatedHStr.ch);
	
	SubString(&subHStr, testHStr, 12, 7);
	printf("The sub-string of test heap string is : \"%s\"\n", subHStr.ch);
	
	StrInsert(&testHStr, 9, sampleHStr);
	printf("The new test heap string is : \"%s\"\n", testHStr.ch);
	
	return;
}

void TestCase4_SequencialString(void)
{
}


void TestCase4_LinkListString(void)
{
}