#pragma once
#include "Sorts.h"
#include <iostream> //std::iostream // std::ostream
//DO NOT MODIFY INCLUDES

class SingleNode;

class SingleLinkList
{
	//All data in the SingleLinkList should be private

	SingleNode* mHead;
	SingleNode* mTail;
	int size;

public:

	///////////////////////
	//Constructors
	///////////////////////
	SingleLinkList();
	SingleLinkList(const SingleLinkList& other);
	///////////////////////
	//Gettors
	///////////////////////
	const SingleNode* Head() const;
	const SingleNode* Tail() const;
	int Size() const;
	int AllocatedMemSize() const;
	///////////////////////
	//Node adding
	///////////////////////
	bool AddFront(const SingleNode* node);
	bool AddFront(int val);

	bool AddEnd(const SingleNode* node);
	bool AddEnd(int val);

	//This should fail if the index is invalid
	bool AddAtIndex(const SingleNode* node, int index);
	bool AddAtIndex(int val, int index);

	///////////////////////
	//Delete functions
	///////////////////////

	bool DeleteFront();
	bool DeleteEnd();
	bool DeleteAll();
	~SingleLinkList();
	//This should fail if the index is invalid
	bool DeleteIndex(int index);


	///////////////////////
	// operators
	///////////////////////
	//This iterates
	const SingleNode* operator[](int index) const;

	//Copies values
	SingleLinkList& operator=(const SingleLinkList& other);

	//Inserts copies of the nodes at the end
	SingleLinkList& operator+=(const SingleLinkList& other);

	//Output Operator
	friend std::ostream& operator<<(std::ostream& os, const SingleLinkList& list);

	//Input operator
	friend std::istream& operator>>(std::istream& is, const SingleLinkList& list);


	///////////////////////
	// Finds
	///////////////////////
	//Find
	SingleNode* FindValue(int val);
	int FindIndex(const SingleNode* node);


	SingleNode* FindReplace(int findVal, int replaceVal);


	///////////////////////
	// Friend functions
	///////////////////////
	friend void ::Sort::SortLowerFirst(SingleLinkList* list);	//1,2,3,4,5,6,7,8,9...
	friend void ::Sort::SortHigherFirst(SingleLinkList* list);	//9,8,7,6,5,4,3,2,1...
	friend void ::Sort::SortOddFirsts(SingleLinkList* list);	//1,7,5,3,9,2,6,8,4
	
};