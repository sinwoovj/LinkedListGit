#include <iostream>
#include "Sorts.h"
#include "SingleLinkedList.h"
#include "Nodes.h"
#include "DocObj.h"

int main(void)
{
	SingleLinkList list;
	
	list.AddFront(1);
	list.AddFront(10);
	list.AddFront(32);
	list.AddFront(55);

	const SingleNode* curr = list.Head();

	std::cout << list << std::endl;

	while (curr != nullptr)
	{
		printf("%d ", curr->mData);
		curr = curr->pNext;
	}

	// should print
	// 55 32 10 1
	return 0;
}