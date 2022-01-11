#pragma once
#include "Player.h"

class ListNode
{
private:
	Player * player;
	ListNode * next;
public:
	ListNode();
	ListNode(Player * player, ListNode * next);

	Player * getPlayer() const;
	ListNode * getNext() const;
	void setNext(ListNode * newNext);

	~ListNode();
};