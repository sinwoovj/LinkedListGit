#include "SingleLinkedList.h"
#include "Nodes.h"

SingleLinkList::SingleLinkList()
{
	this->mHead = nullptr;
	this->mTail = nullptr;
	this->size = 0;
}

SingleLinkList::SingleLinkList(const SingleLinkList& other)
{
	this->mHead = nullptr;
	this->mTail = nullptr;
	this->size = 0;
	//Deep copy..
	const SingleNode* temp = other.mHead;
	while (temp != nullptr)
	{
		this->AddEnd(temp->mData);
		temp = temp->pNext;
	}
}

const SingleNode* SingleLinkList::Head() const
{
	return this->mHead;
}

const SingleNode* SingleLinkList::Tail() const
{
	return this->mTail;
}

int SingleLinkList::Size() const
{
	return this->size;
}

int SingleLinkList::AllocatedMemSize() const
{
	return this->size * sizeof(SingleNode);
}

bool SingleLinkList::AddFront(const SingleNode* node)
{
	// NullPtr Test
	if (node != nullptr)
	{
		if (AddFront(node->mData))
			return true;
	}
	return false;
}

bool SingleLinkList::AddFront(int val)
{
	// Dynamic Allocation and Test
	SingleNode* np = new SingleNode(val);
	if (np != nullptr)
	{
		np->pNext = this->mHead;
		this->mHead = np;
		this->size += 1;
		return true;
	}
	return false;
}

bool SingleLinkList::AddEnd(const SingleNode* node)
{
	// NullPtr Test
	if (node != nullptr)
	{
		if(AddEnd(node->mData))
			return true;
	}
	return false;
}

bool SingleLinkList::AddEnd(int val)
{
	// Dynamic Allocation and Test
	SingleNode* np = new SingleNode(val);
	if (np != nullptr)
	{
		this->mTail->pNext = np;
		this->mTail = np;
		this->size += 1;
		return true;
	}
	return false;
}

bool SingleLinkList::AddAtIndex(const SingleNode* node, int index)
{
	// NullPtr Test
	if (node != nullptr)
	{
		if (AddAtIndex(node->mData, index))
			return true;
	}
	return false;
}

bool SingleLinkList::AddAtIndex(int val, int index)
{
	// Dynamic Allocation and Test
	SingleNode* np = new SingleNode(val);
	if (np != nullptr)
	{
		SingleNode* curr = this->mHead;

		int cnt = 0;
		while (curr != nullptr && cnt++ == index)
		{
			np->pNext = curr->pNext;
			curr->pNext = np;
		}
		this->size += 1;
		return true;
	}
	return false;
}

bool SingleLinkList::DeleteFront()
{
	if (this->mHead != nullptr)
	{
		if (size == 1)
		{
			delete this->mHead;
			this->mTail = nullptr;
		}
		else
		{
			SingleNode* temp = mHead->pNext;
			delete this->mHead;
			mHead = temp;
		}
		this->size -= 1;
		return true;
	}
	return false;
}

bool SingleLinkList::DeleteEnd() // stay
{
	if (this->mTail != nullptr)
	{
		if (size == 1)
		{
			delete this->mTail;
			this->mHead = nullptr;
		}
		else
		{
			DeleteIndex(size);
		}
		return true;
	}
	return false;
}

bool SingleLinkList::DeleteAll()
{
	if (this->size > 0)
	{
		while (this->size > 0)
		{
			DeleteFront();
		}
		return true;
	}
	return false;
}

SingleLinkList::~SingleLinkList()
{
	if (this->mHead != nullptr || this->mTail != nullptr)
	{
		SingleNode* curr = this->mHead;

		while (curr != nullptr)
		{
			SingleNode* temp = curr;
			curr = curr->pNext;
			delete temp;
		}
	}
	//delete[] this; // head~tail delete
}

bool SingleLinkList::DeleteIndex(int index)
{
	if (size > 0 && size > index)
	{
		if (index == 0)
		{
			delete this->mHead;
			this->mTail = nullptr;
			return true;
		}
		else
		{
			SingleNode* curr = this->mHead;
			SingleNode* temp = nullptr;
			int cnt = 0;
			while (curr != nullptr)
			{
				if (cnt == index - 1)
					temp = curr;
				if (cnt == index)
				{
					if(temp != nullptr)
						temp->pNext = nullptr;
					delete curr;
					return true;
				}
				cnt++;
			}
		}
	}
	return false;
}

const SingleNode* SingleLinkList::operator[](int index) const
{
	SingleNode* curr = this->mHead;

	int cnt = 0;
	while (curr != nullptr && cnt++ < index)
	{
		curr = curr->pNext;
	}
	return curr;
}

SingleLinkList& SingleLinkList::operator=(const SingleLinkList& other)
{
	if (!this->DeleteAll())
		return *this;
	//Deep copy..
	const SingleNode* temp = other.mHead;
	while (temp != nullptr)
	{
		this->AddEnd(temp->mData);
		temp = temp->pNext;
	}
	return *this;
}

SingleLinkList& SingleLinkList::operator+=(const SingleLinkList& other)
{
	//Deep copy..
	const SingleNode* temp = other.mHead;
	while (temp != nullptr)
	{
		this->AddEnd(temp->mData);
		temp = temp->pNext;
	}
	return *this;
}

SingleNode* SingleLinkList::FindValue(int val)
{
	SingleNode* curr = this->mHead;
	SingleNode* res = nullptr;
	int cnt = 0;
	while (curr != nullptr)
	{
		if (curr->mData == val)
		{
			res = curr;
			return res;
		}
		curr = curr->pNext;
	}
	return nullptr;
}

int SingleLinkList::FindIndex(const SingleNode* node)
{
	int cnt = 0;
	SingleNode* curr = this->mHead;
	while (curr != nullptr)
	{
		if (curr == node)
		{
			return cnt;
		}
		curr = curr->pNext;
		cnt++;
	}
	return -1;
}

SingleNode* SingleLinkList::FindReplace(int findVal, int replaceVal)
{
	SingleNode* curr = this->mHead;
	while (curr != nullptr)
	{
		if (curr->mData == findVal)
		{
			curr->mData = replaceVal;
			return curr;
		}
		curr = curr->pNext;
	}
	return nullptr;
}

std::ostream& operator<<(std::ostream& os, const SingleLinkList& list)
{
	const SingleNode* curr = list.Head();

	while (curr != nullptr)
	{
		os << curr->mData << " ";
		curr = curr->pNext;
	}
	return os;
}

std::istream& operator>>(std::istream& is, const SingleLinkList& list)
{
	is >> list;
	return is;
}
