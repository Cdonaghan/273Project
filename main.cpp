
#include<iostream>
#include<string>
#include"game.h"
#include "enemy.h"
using namespace std;
int main()
{
	enemy bad;
	Game game;
	character user;

	while (((game.getplaying()==true)  && (game.playerdies(user.gethealth())==false)))
	{
		game.mainmenu();
		//start going through story

	}

}