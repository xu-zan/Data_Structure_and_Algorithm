/***************************************************************
 * File name		: Test_Link_Node.c
 * Description		: 测试链表的用例
 * Creator			: XU ZAN
 * Creation date	: Thur.	Nov. 20, 2014
 * Copyright(C)		2014	All rights reserved.
 *
 ***************************************************************/

#include "Test_Link_Node.h"

#include "Link_Node.h"
#include <stdio.h>
#include <stdlib.h>

void TestCase_Link_List(void)
{
	Status result = 0;
	ElemType e = 0;
	LinkList myLinkList = {NULL, NULL, 0};
	Link myNode			= NULL, 
		 myNode1		= NULL,
		 myNode2		= NULL,
		 Nodes			= NULL, 
		 Node2BeDeleted = NULL,
		 TargetNode		= NULL,
		 PosTargetNode	= NULL;

	result = InitList(&myLinkList);
	if (result == OK)
		result = CreateLinkList(&myLinkList, 10);
	DisplayLinkList(myLinkList);
	DisplayList(myLinkList.head);

	MakeNode(&myNode, 705);
	Append(&myLinkList, myNode);
	DisplayLinkList(myLinkList);

	/* Create an independent link-nodes.
	 */
	CreateLinkNode(&Nodes, 5);
	Append(&myLinkList, Nodes);
	DisplayLinkList(myLinkList);

	InsFirst(&Nodes, myNode);
	DisplayList(Nodes);

	Remove(&myLinkList, &e);
	DisplayLinkList(myLinkList);
	printf("Currently the link list has %d nodes.\nIts length is %d.\n", 
		ListLength(myLinkList), 
		GetLinkNodeLength(myLinkList.head));

	printf("Retrieve the %dth node from the link list.\n", 5);
	GetSpecifiedNode(myLinkList.head, 5, &TargetNode, &e);
	printf("The %dth node address is : 0x%08X, and his data is : %d\n\n\n",	5, TargetNode, e);

	printf("Insert a new node before the target node :\n");
	MakeNode(&myNode1, -99);
	MakeNode(&myNode2, 99);
	InsBefore(&myLinkList, &TargetNode, myNode2);
	DisplayLinkList(myLinkList);
	DisplayList(TargetNode);
	InsAfter(&myLinkList, &TargetNode, myNode1);
	DisplayLinkList(myLinkList);
	DisplayList(TargetNode);

	printf("Modify the data of 1 node you specified 0x%08X :\n", myNode);
	SetCurElem(&myNode, 666);
	DisplayLinkList(myLinkList);
	printf("Locate %dth node. ", 9);
	LocatePos(myLinkList, 9, &PosTargetNode);
	printf("Its data is : %d\n", GetCurElem(PosTargetNode));
	printf("The previous node of node 0x%08X is : 0x%08X\n", PosTargetNode, PriorPos(myLinkList, PosTargetNode));
	printf("The next node of node 0x%08X is : 0x%08X\n", PosTargetNode, NextPos(myLinkList, PosTargetNode));

	printf("Directly insert a new node at position %d\n", 15);
	LinkListInsert(&myLinkList, 15, 9999);
	DisplayLinkList(myLinkList);

	/*
	DelFirst(&Nodes, &Node2BeDeleted);
	DisplayList(Nodes);
	DisplayLinkList(myLinkList);
	 */

	DestroyList(&myLinkList);
	DisplayLinkList(myLinkList);
}

void TestCase_Link_Node(void)
{
	Link Nodes = NULL;
	int n = 0;
	
	printf("Please enter the node counters : ");
	scanf("%d", &n);
	// InitLinkNode(&Nodes);
	CreateLinkNode(&Nodes, n);

	DisplayList(Nodes);

	DestroyLinkNode(&Nodes);
	DisplayList(Nodes);
}