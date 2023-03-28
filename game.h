#pragma once
#include"character.h"
#include "inventory.h"
#include<string>
using namespace std;
#include<iomanip>
#include<ctime>
//main menu class
class Game
{
public:
	Game();
	virtual ~Game();
	void script();
	bool getplaying();
	bool playerdies();
	bool enemydied();
	void displayinv(character s, Inventory i);

private:
	int choice;
	bool playing = true;
	bool dead = false;
};
