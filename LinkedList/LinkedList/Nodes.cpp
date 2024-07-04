#include "Nodes.h"
#include <cstddef>

SingleNode::SingleNode()
{
	this->mData = NULL;
	this->pNext = nullptr;
}

SingleNode::SingleNode(int data)
{
	this->mData = data;
	this->pNext = nullptr;
}

DoubleNode::DoubleNode()
{
	this->mData = NULL;
	this->pNext = nullptr;
	this->pPrev = nullptr;
}

DoubleNode::DoubleNode(int data)
{
	this->mData = data;
	this->pNext = nullptr;
	this->pPrev = nullptr;
}
