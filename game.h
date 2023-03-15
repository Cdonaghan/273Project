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
	bool getplaying();
	void firstencounter();
	bool playerdies(double x);

private:
	int choice;
	bool playing;
};
