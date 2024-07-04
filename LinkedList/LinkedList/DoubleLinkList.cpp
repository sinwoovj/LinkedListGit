#include "DoubleLinkList.h"
#include "Nodes.h"

DoubleLinkList::DoubleLinkList()
{
	this->mHead = nullptr;
	this->mTail = nullptr;
	this->size = 0;
}

DoubleLinkList::DoubleLinkList(const DoubleLinkList& other)
{
	this->mHead = other.mHead;
	this->mTail = other.mTail;
	this->size = other.size;
}

const DoubleNode* DoubleLinkList::Head() const
{
	return this->mHead;
}

const DoubleNode* DoubleLinkList::Tail() const
{
	return this->mTail;
}

int DoubleLinkList::Size() const
{
	return this->size;
}

int DoubleLinkList::AllocatedMemSize() const
{
	return this->size * sizeof(DoubleNode);
}

bool DoubleLinkList::AddFront(const DoubleNode* node)
{
	return false;
}

bool DoubleLinkList::AddFront(int val)
{
	return false;
}

bool DoubleLinkList::AddEnd(const DoubleNode* node)
{
	return false;
}

bool DoubleLinkList::AddEnd(int val)
{
	return false;
}

bool DoubleLinkList::AddAtIndex(const DoubleNode* node, int index)
{
	return false;
}

bool DoubleLinkList::AddAtIndex(int val, int index)
{
	return false;
}

bool DoubleLinkList::DeleteFront()
{
	return false;
}

bool DoubleLinkList::DeleteEnd()
{
	return false;
}

bool DoubleLinkList::DeleteAll()
{
	return false;
}

DoubleLinkList::~DoubleLinkList()
{
	delete[] this;
}

bool DoubleLinkList::DeleteIndex(int index)
{
	return false;
}

const DoubleNode* DoubleLinkList::operator[](int index) const
{
	return nullptr;
}

DoubleLinkList& DoubleLinkList::operator=(const DoubleLinkList& other)
{
	return *this;
}

DoubleLinkList& DoubleLinkList::operator+=(const DoubleLinkList& other)
{
	return *this;
}

DoubleNode* DoubleLinkList::FindValue(int val)
{
	return nullptr;
}

int DoubleLinkList::FindIndex(const DoubleNode* node)
{
	return 0;
}

DoubleNode* DoubleLinkList::FindReplace(int findVal, int replaceVal)
{
	return nullptr;
}
