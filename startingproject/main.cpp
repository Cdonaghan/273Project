#include"game.h"
#include<iostream>
#include<string>
using namespace std;
int main()
{
	Game game;
	game.initgame();
	while (game.getplaying()==true)
	{
		game.mainmenu();
		cout << "hello and welcome" << endl;

		//santi is a pleb
	}
}