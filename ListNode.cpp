#include "ListNode.h"

ListNode::ListNode()
{
	this->player = new Player();
	this->next = nullptr;
}

ListNode::ListNode(Player * player, ListNode * next)
{
	this->player = new Player(player);
	this->next = next;
}

Player * ListNode::getPlayer() const
{
	return this->player;
}

ListNode * ListNode::getNext() const
{
	return this->next;
}

void ListNode::setNext(ListNode * newNext)
{
	this->next = newNext;
}

ListNode::~ListNode()
{
	delete this->player;
}
