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
	void continueToNext(character s, Inventory i);
	bool playerdies();
	bool enemydied();
	void endgamecredits();
	//void getUserName(character s, string name);
	void displayinv(character s, Inventory i);
	//void walkthrough(character s, Inventory i, string start, string name);
	void leftpath(character s, Inventory i);
	void rightPath(character s, Inventory i);
	void beginning(character s, Inventory i);
	void leftPathStory(character s, Inventory i);
	void leftpathStoryContd(character s, Inventory i);
	void leftpathMutantFight(character s, Inventory i);
	void leftpathDragonLore(character s, Inventory i);
	void leftpathDragonFight(character s, Inventory i);
	void leftpathFinalLore();
	void choiceRemove(string x);
    void healUp(character s);
	void rightPathStory(character s, Inventory i);    void restart(character s);
    void storylineSelect(character s, Inventory i);
	void eastpath(character s, Inventory i);
	void westpath(character s, Inventory i);

	

private:
	int choice;
	bool playing = true;
	bool dead = false;
	bool validChoice = false;
};
