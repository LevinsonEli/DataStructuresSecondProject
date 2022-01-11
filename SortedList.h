#pragma once
#include "ListNode.h"
#include <iostream>
using namespace std;

class SortedList
{
private:
	ListNode * root;
public:
	SortedList();
	void setRoot(ListNode * root);
	ListNode * getRoot() const;

	bool IsEmpty() const;
	void Insert(Player * newPlayer, int & comparisonNum);
	void PrintList();
};