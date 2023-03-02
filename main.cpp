
#include<iostream>
#include<string>
#include"game.h"
using namespace std;
int main()
{
	enemy bad;
	Game game;
	character user;

	while (((game.getplaying()==true)  && (game.playerdies(user)==false)))
	{
		game.mainmenu();
		//start going through story

	}

}