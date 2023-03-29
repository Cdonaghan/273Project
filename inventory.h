

#pragma once

#include "character.h"

#include <list>
using namespace std;


class Inventory : public character
{
public:
	vector<string> items;

	void addItem(string x);
	void removeItem(int index);
	void display(character s);
	//weapons

	void getWeapon();
	void setWeapon(string x);

	//potions

	string getPotion();
	void setPotion(string x);

	void setsword(string x);
	string getsword();

	void setbow(string x);
	string getbow();

	void setdagger(string x);
	string getdagger();

protected:
	string sword = { "Sword" };
	string bow = { "Bow" };
	string wand = { "Wand" };
	string potion = { "Potion" };
	string dagger = { "Dagger" };
	string Weapon;

};



