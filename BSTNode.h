#pragma once
#include "Player.h"

class BSTNode
{
private:
	Player * player;
	BSTNode * left;
	BSTNode * right;
public:
	BSTNode();
	BSTNode(Player * player, BSTNode * left, BSTNode * right);
	BSTNode * getRight() const;
	BSTNode * getLeft() const;
	Player * getPlayer() const;
	void setLeft(BSTNode * newLeft);
	void setRight(BSTNode * newRight);
	void setPlayer(Player * newPlayer);

	~BSTNode();

	bool HasOnlyOneChild() const;
	void PrintPlayer() const;
};