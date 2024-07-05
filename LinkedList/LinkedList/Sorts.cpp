#include "Sorts.h"
#include "Nodes.h"
#include "SingleLinkedList.h"
#include <stdbool.h>

void Sort::SortLowerFirst(SingleLinkList* list)
{
	SingleNode* min;
	SingleNode* tmp;
	int num = 0;
	for (int i = 0; i < list->size; i++)
	{
		min = list->mHead;
		tmp = list->mHead;
		for (int k = 0; k < i; k++)
		{
			min = list->mHead->pNext;
			tmp = list->mHead->pNext;
		}
		for (int j = 0; j < list->size; j++)
		{
			if (min->mData < tmp->mData)
			{
				min = tmp;
				num = j;
			}
			tmp = tmp->pNext;
		}
		list->DeleteIndex(num); // delete tmp;
		list->AddFront(min);
	}
}

void Sort::SortHigherFirst(SingleLinkList* list)
{
	SingleNode* max;
	SingleNode* tmp;
	int num = 0;
	for (int i = 0; i < list->size; i++)
	{
		max = list->mHead;
		tmp = list->mHead;
		num = 0;
		for (int k = 0; k < i; k++)
		{
			max = list->mHead->pNext;
			tmp = list->mHead->pNext;
		}
		for (int j = 0; j < list->size; j++)
		{
			if (max->mData > tmp->mData)
			{
				max = tmp;
				num = j;
			}
			tmp = tmp->pNext;
		}
		list->DeleteIndex(num); // delete tmp;
		list->AddFront(max);
	}
}

void Sort::SortOddFirsts(SingleLinkList* list)
{
	SingleNode odd;

}

void Sort::SortLowerFirst(DoubleLinkList* list)
{

}

void Sort::SortHigherFirst(DoubleLinkList* list)
{

}

void Sort::SortOddFirsts(DoubleLinkList* list)
{

}
