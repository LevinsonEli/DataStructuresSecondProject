#include "SortedList.h"

SortedList::SortedList()
{
	this->root = nullptr;
}

void SortedList::setRoot(ListNode * root)
{
	this->root = root;
}

ListNode * SortedList::getRoot() const
{
	return this->root;
}

bool SortedList::IsEmpty() const
{
	return this->root == nullptr;
}

void SortedList::Insert(Player * newPlayer, int & comparisonNum)
{
	if (IsEmpty())
	{
		ListNode * newNode = new ListNode(newPlayer, nullptr);
		this->root = newNode;
	}
	else
	{
		comparisonNum++;
		ListNode * currentNodeInList = this->root;

		// If the new player's id is smaller then the root's id
		if (currentNodeInList->getPlayer()->getId() > newPlayer->getId())
		{
			ListNode * newNode = new ListNode(newPlayer, this->root);
			this->root = newNode;
		}
		else
		{
			// Find the appropriate place to insert
			while (currentNodeInList->getNext() != nullptr &&
				newPlayer->getId() > currentNodeInList->getNext()->getPlayer()->getId()
				)
			{
				comparisonNum++;
				currentNodeInList = currentNodeInList->getNext();
			}

			ListNode * newNode = new ListNode(newPlayer, currentNodeInList->getNext());
			currentNodeInList->setNext(newNode);
		}
	}
}

void SortedList::PrintList()
{
	if (!IsEmpty())
	{
		ListNode * currentNodeInList = this->root;
		while (currentNodeInList != nullptr)
		{
			cout << currentNodeInList->getPlayer()->getId() << " " <<
				    currentNodeInList->getPlayer()->getName() << endl;
			currentNodeInList = currentNodeInList->getNext();
		}
	}
}