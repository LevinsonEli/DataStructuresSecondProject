#pragma once
#include <string>
using namespace std;

class Player
{
private:
	int id;
	string name;
public:
	Player();
	Player(int id, string name);
	Player(Player * player);

	bool setId(int id);
	bool setName(string name);
	int getId() const;
	string getName() const;
};