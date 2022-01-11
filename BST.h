#pragma once
#include "BSTNode.h"
#include <iostream>
using namespace std;

class BST
{
private:
	BSTNode * root;
public:
	BST();
	BST(BSTNode * root);
	BSTNode * getRoot() const;
	
	bool IsEmpty() const;
	Player * Find(int id) const;
	bool Delete(int id);
	void MakeEmpty();
	void Insert(Player * newPlayer, int & comparisonNum);
	void PrintFirstElementsOfTree(int k, int &comparisonNum);
	void PrintSubTreeInOrder(BSTNode * node);

private:
	void deleteNodeWithOneChild(BSTNode * node, BSTNode * parent);
	void deleteNodeWithTwoChilds(BSTNode * node);
	Player * getMaxOfSubTreeAndDelete(BSTNode * node, BSTNode * parent);
	void makeNodesEmpty(BSTNode * node);
	void printFirstNodes(BSTNode * node, int k, int &comparisonNum);
};