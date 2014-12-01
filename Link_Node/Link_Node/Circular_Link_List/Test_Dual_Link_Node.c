/********************************************************************************
 * File name		: Test_Dual_Link_Node.c
 * Description		: Design some test cases to verify the algorithm of 
 *					  "Dual-direction link node" structure.
 * Creator			: XU ZAN
 * Creation date	: Mon.	Nov. 17, 2014
 * Copyright(C)		2014	All rights reserved.
 *
 ********************************************************************************/

#include "Test_Dual_Link_Node.h"
#include "Dual_Link_Node.h"

#include <stdio.h>

void TestCase_DualLinkNode(void)
{
	ElemType e = 0;

	PtrDuLNode pMyDuLNode = NULL;
	ListCreate_DuLN(&pMyDuLNode, 5);
	ListDisplay_DuLN(pMyDuLNode);

	ListInsert_DuLN(&pMyDuLNode, 3, 10);
	ListDisplay_DuLN(pMyDuLNode);
	printf("This link list has %d nodes.\n", GetLength_DuLN(pMyDuLNode));

	printf("The pointer of %dth node is : 0x%08X\n", 5, GetElemPtr_DuLN(pMyDuLNode, 5));

	ListDelete_DuLN(&pMyDuLNode, 4, &e);
	ListDisplay_DuLN(pMyDuLNode);
	printf("This link list has %d nodes.\n", GetLength_DuLN(pMyDuLNode));

	ListDestroy_DuLN(&pMyDuLNode);
}