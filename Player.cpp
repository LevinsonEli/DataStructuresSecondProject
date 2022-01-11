#include "Player.h"

Player::Player() {}
Player::Player(int id, string name)
{
	this->id = id;
	this->name = name;
}
Player::Player(Player * player)
{
	this->id = player->getId();
	this->name = player->getName();
}

bool Player::setId(int id)
{
	if (id <= 0)
		return false;
	this->id = id;
	return true;
}

bool Player::setName(string name)
{
	size_t indexOfFirstSpace = name.find(' ');
	if (indexOfFirstSpace == string::npos)
		return false;
	size_t indexOfSecondSpace = name.find(' ', indexOfFirstSpace + 1);
	if (indexOfSecondSpace != string::npos)
		return false;
	this->name = name;
	return true;
}

int Player::getId() const
{
	return this->id;
}

string Player::getName() const
{
	return this->name;
}