#pragma once

struct SingleNode
{
	SingleNode();
	SingleNode(int data);

	int mData; // Data


	SingleNode* pNext; // reference
};

struct DoubleNode
{
	DoubleNode();
	DoubleNode(int data);

	int mData;
	DoubleNode* pNext;
	DoubleNode* pPrev;
};