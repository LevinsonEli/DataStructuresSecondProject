#include "BSTNode.h"
#include <iostream>
using namespace std;

BSTNode::BSTNode()
{
	player = new Player();
	left = nullptr;
	right = nullptr;
}

BSTNode::BSTNode(Player * player, BSTNode * left, BSTNode * right)
{
	this->player = new Player(player);
	this->left = left;
	this->right = right;
}

BSTNode * BSTNode::getRight() const
{
	return this->right;
}

BSTNode * BSTNode::getLeft() const
{
	return this->left;
}

Player * BSTNode::getPlayer() const
{
	return this->player;
}

void BSTNode::setLeft(BSTNode * newLeft)
{
	this->left = newLeft;
}

void BSTNode::setRight(BSTNode * newRight)
{
	this->right = newRight;
}

void BSTNode::setPlayer(Player * newPlayer)
{
	this->player->setId(newPlayer->getId());
	this->player->setName(newPlayer->getName());
}

BSTNode::~BSTNode() 
{
	if (this && this->player != nullptr)
		delete this->player;
}

bool BSTNode::HasOnlyOneChild() const
{
	return this->left == nullptr && this->right != nullptr ||
		this->right == nullptr && this->left != nullptr;
}

void BSTNode::PrintPlayer() const
{
	if (this->player != nullptr)
		cout << this->getPlayer()->getId() << " " << this->getPlayer()->getName() << endl;
}