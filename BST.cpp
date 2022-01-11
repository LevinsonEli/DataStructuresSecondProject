#include "BST.h"

BST::BST()
{
	this->root = nullptr;
}

BST::BST(BSTNode * root)
{
	this->root = root;
}

BSTNode * BST::getRoot() const
{
	return this->root;
}

bool BST::IsEmpty() const
{
	return this->root == nullptr;
}

Player * BST::Find(int id) const
{
	if (IsEmpty())
	{
		return nullptr;
	}
	else
	{
		BSTNode * currentNodeInTree = this->root;

		while (currentNodeInTree != nullptr)
		{
			if (id > currentNodeInTree->getPlayer()->getId())
				currentNodeInTree = currentNodeInTree->getRight();
			else if (id < currentNodeInTree->getPlayer()->getId())
				currentNodeInTree = currentNodeInTree->getLeft();
			else
				return currentNodeInTree->getPlayer();
		}

		return nullptr;
	}
}

bool BST::Delete(int id)
{
	if (!IsEmpty())
	{
		BSTNode * currentNodeInTree = this->root;
		BSTNode * prevNodeInTree = nullptr;		// parent

		while (currentNodeInTree != nullptr)
		{
			if (id < currentNodeInTree->getPlayer()->getId())
			{
				prevNodeInTree = currentNodeInTree;
				currentNodeInTree = currentNodeInTree->getLeft();
			}
			else if (id > currentNodeInTree->getPlayer()->getId())
			{
				prevNodeInTree = currentNodeInTree;
				currentNodeInTree = currentNodeInTree->getRight();
			}
			else
			{
				if (currentNodeInTree->HasOnlyOneChild())
					deleteNodeWithOneChild(currentNodeInTree, prevNodeInTree);
				else
					deleteNodeWithTwoChilds(currentNodeInTree);
				return true;
			}
		}
	}
	return false;
}

void BST::MakeEmpty()
{
	if (this->root != nullptr)
	{
		makeNodesEmpty(this->root);
		this->root = nullptr;
	}
}

void BST::makeNodesEmpty(BSTNode * node)
{
	if (node != nullptr)
	{
		if (node->getLeft() == nullptr && node->getRight() == nullptr)
		{
			delete node;
			node = nullptr;
		}
		else
		{
			makeNodesEmpty(node->getLeft());
			makeNodesEmpty(node->getRight());
			delete node;
			node = nullptr;
		}
	}
}

void BST::Insert(Player * newPlayer, int & comparisonNum)
{
	BSTNode * newNode = new BSTNode(newPlayer, nullptr, nullptr);
	BSTNode * currentNodeInTree = this->root;

	if (IsEmpty())
	{
		this->root = newNode;
	}
	else
	{
		while (currentNodeInTree != nullptr)
		{
			comparisonNum++;
			if (newPlayer->getId() > currentNodeInTree->getPlayer()->getId())
			{
				if (currentNodeInTree->getRight() == nullptr)
				{
					currentNodeInTree->setRight(newNode);
					return;
				}
				else
					currentNodeInTree = currentNodeInTree->getRight();
			}
			else
			{
				if (currentNodeInTree->getLeft() == nullptr)
				{
					currentNodeInTree->setLeft(newNode);
					return;
				}
				else
					currentNodeInTree = currentNodeInTree->getLeft();
			}
		}
	}
}

void BST::PrintFirstElementsOfTree(int k, int &comparisonNum)
{
	if (this->root != nullptr)
	{
		printFirstNodes(this->root, k, comparisonNum);
	}
}

void BST::printFirstNodes(BSTNode * node, int k, int &comparisonNum)
{
	if (node != nullptr)
	{
		comparisonNum++;
		if (node->getPlayer()->getId() < k)
		{
			PrintSubTreeInOrder(node->getLeft());
			node->PrintPlayer();
			printFirstNodes(node->getRight(), k, comparisonNum);
		}
		else
		{
			printFirstNodes(node->getLeft(), k, comparisonNum);
		}
	}
}

void BST::PrintSubTreeInOrder(BSTNode * node)
{
	if (node != nullptr)
	{
		if (node->getLeft() == nullptr && node->getRight() == nullptr)
		{
			node->PrintPlayer();
		}
		else
		{
			PrintSubTreeInOrder(node->getLeft());
			node->PrintPlayer();
			PrintSubTreeInOrder(node->getRight());
		}
	}
}

void BST::deleteNodeWithOneChild(BSTNode * node, BSTNode * parent)
{
	if (node->getLeft() == nullptr)
	{
		if (parent == nullptr)
		{
			this->root = node->getRight();
		}
		else
		{
			parent->setRight(node->getRight());
		}
	}
	else
	{
		if (parent == nullptr)
		{
			this->root = node->getLeft();
		}
		else
		{
			parent->setLeft(node->getLeft());
		}
	}
	delete node;
}

void BST::deleteNodeWithTwoChilds(BSTNode * node)
{
	Player * maxOfLeftSubTree = getMaxOfSubTreeAndDelete(node->getLeft(), node);
	node->setPlayer(maxOfLeftSubTree);
}

Player * BST::getMaxOfSubTreeAndDelete(BSTNode * node, BSTNode * parent)
{
	BSTNode * currentNode = node;
	BSTNode * parentNode = parent;
	while (currentNode->getRight() != nullptr)
	{
		parentNode = currentNode;
		currentNode = currentNode->getRight();
	}
	Player * maxPlayerToReturn = new Player(currentNode->getPlayer());
	if (parentNode == parent)
	{
		parent->setLeft(currentNode->getLeft());
	}
	else
	{
		parentNode->setRight(currentNode->getLeft());
	}
	delete currentNode;
	return maxPlayerToReturn;
}