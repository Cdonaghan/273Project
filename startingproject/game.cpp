#include"game.h"
#include<string>
#include<iostream>
using namespace std;
Game::Game()
{
	choice = 0;
	playing = true;
}
Game::~Game()
{

}
void Game::mainmenu()
{
	cout << "MAIN MENU" << endl<<endl;
	cout << "0: Stay main menu" << endl;
	cout << "1: Start game" << endl;
	cout << "Choice: ";
	cin >> choice;
	switch (choice)
	{
	case 0:
		playing = false;
		break;
	default:
		break;
	}
}
bool Game::getplaying() const
{
	return playing;
}
