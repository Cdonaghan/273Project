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
	void walkthrough();
	bool getplaying();
	bool playerdies();
	bool enemydied();
	void displayinv(character s, Inventory i);
	void leftpath(character s, Inventory i);
	void rightPath(character s, Inventory i);
	void beginning(character s, Inventory i);
	void choiceRemove(int x);
	void restart(character s);
	void storylineSelect(character s, Inventory i);

	

private:
	int choice;
	bool playing = true;
	bool dead = false;
	bool validChoice = false;
};
