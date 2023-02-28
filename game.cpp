#include"game.h"
#include"character.h"
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
	string start{ " " };
	string name;
	character s;
	cout << "273 project: text based rpg game" << "\n\n" << "created by Daniel Conaghan and Santiago Rivett Barragan" << "\n\n\n\n\n";
	cout << "\t\t\t\t\t\tNIGGERS IN PARIS" << endl;
	cout << "\t\t\t\t\t\tMAIN MENU" << endl << endl;
	cout << "\t\t\t\t\t\t0: Exit" << endl;
	cout << "\t\t\t\t\t\t1: Start Game" << endl;
	cout << "\t\t\t\t\t\tChoice: ";
	cin >> choice;
	switch (choice)
	{
	case 0:
		playing = false;
		cout << "\n\n\nCome back soon!!" << endl;
		break;
	case 1:
		playing = true;
		//character creation and start game
		cout << "Enter characters name: ";
		cin >> name;
		s.setname(name);
		cout << "Welcome " << name
			<< " the mighty dragon slayer" << endl
			<< "Here are your starting stats: \n\n";
		s.tostring();
		cout << "\n\nThis information can be accessed throughout the game just(accessor for throughout game to access)...." << endl;
		cout << "Type 'yes' to start this adventure: ";
		cin >> start;
		if (start == "yes")
		{
			cout << "Start introduction of story...... until an encounter"<< endl;
		}
		else
		{
			playing = false;
		}
		break;

	default:
		cout << "Please enter a '0' or a '1': " << endl;
		break;
	}
	playing = false;
}
bool Game::getplaying() const
{
	return playing;
}
bool Game::playerdies(character x)
{
	if (x.gethealth() <= 0)
	{
		cout << "you are dead";
		this->playing= false;
		return true;
	}
	else
	{
		return false;
	}
	
}