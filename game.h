#pragma once
#include"character.h"
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
	void mainmenu();
	bool getplaying() const;
	bool playerdies (character x);

private:
	int choice;
	bool playing;
};
