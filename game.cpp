#include"game.h"
#include"character.h"
#include "enemytype.h"
#include "inventory.h"
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

bool Game::getplaying()
{
	return playing;
}
bool Game::enemydied()
{
	return true;
}

bool Game::playerdies()
{
	//function to call if you are dead
	/*if (x <= 0)
	{
		cout << "you are dead" << endl;
		
		return true;
	}
	else
	{
		return false;
	}
*/

cout << "you are dead, you will now need to restart" << endl;
return this-> dead = true; //this fixes loop issue


}



void Game::mainmenu()
{



	string start{ " " };
	string name;
	character s;
	goblin e;
	
    Inventory i; // inventory declaration



//while loop for conditions to run the game 
 while (((getplaying() == true) && (this->dead == false)))



/* Brief

full game runs in while loop
if player dies while loop ends 


*/

{
	cout << "273 project: Text Based RPG Game" << "\n\n" << "created by Daniel Conaghan and Santiago Rivett Barragan" << "\n\n\n\n\n";
	cout << "\t\t\t\t\t\tRISE OF THE WARRIOR" << endl;
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
		cout << "Welcome " << name << endl;

		cout << "Here are your starting stats: \n\n";
		s.tostring();
		//cout << "\n\n\n make Inventory accessor to see potions ect::::::\n\n";
		cout << "Type 'yes' to start this adventure: ";
		cin >> start;
		if (start == "yes")
		{
			cout << "Start introduction of story...... until an encounter\n\n\n";
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


s.setname("Hagrid");
	cout << "Along your travels you see a fat goblin and he wants to take your family" << endl;
	cout << "What do you do?\n\n";
	cout << "1. Attack" << endl;
	cout << "2. Give him your wife\n\n";
	cout << "Select '1' or '2'\n\n";
	cin >> choice;
	switch (choice)
	{
	case 1:
		cout << "You challenge him and he squares up \n";
		cout << "Enemies stats: \n\n";
		e.setname("Hagrid");
		e.enemytostring();
		cout << "Here are your select battle moves \n\n";
		do
		{
			
			int ans{ 0 };
			cout << "\n1.Sword attack\n2.Explosion attack\n3.Attack Spell\n4.Healing Potion\n5.Parry\n\n";
			cout << " Select to choose your fate: " << "\n\n";
			cin >> ans;
			switch (ans)
			{
			case 1:
				s.attackenemy(e);
				break;
			case 2:
				s.explosion(e);
				break;
			case 3:
				s.attackspelll(e);
				break;
			case 4:
				s.healingpot();
				break;
			case 5:
				e.goblinparry(e, s);
				break;
			default:
				cout << "wrong input enemy gets a free attack" << endl;
				e.daggerattack(s);
				break;
			}
			//enemy attack
			if (e.gethealth() <= 0)
			{
				enemydied();
			} else {
			cout << "\n\n\t\t\t\tNOW ITS THE ENEMIES TURN TO ATTACK\n\n";
			/*if (s.gethealth() < 0){
				s.sethealth(0); 
			}*/
			int x = rand() % (3 - 1 + 1) + 1;
			switch (x)
			{
			case 1:
				e.bowattack(s);
				break;
			case 2:
				e.daggerattack(s);
				break;
			case 3:
				e.swordattack(s);
				break;
			}
			/* if (s.gethealth() <= 0)
			{
            
		playerdies() == true;
			}*/
			}
		} while (((e.gethealth() > 0) && (s.gethealth() > 0) ) || (enemydied() == false) );
//issue with this and statement as above as it breaks to case 2 no matter what.
		break;

	case 2:

		cout << "you let ur fam die " << endl;
	
		break;


		/*
	default:
		cout << "too late u died" << endl;
		
	}
	//Assign dialogue for attacks and stories
	*/


}

if (s.gethealth() <= 0)
			{
            
		playerdies();
		break;
			}

if (e.gethealth() <= 0)
{
cout << "congratulations warrior you defeted the goblin" << endl;
}


while (s.gethealth() > 0)
{
cout << "type (inv) to view inventory, you may only use this when allowed " << endl; //not sure just preview atm
string invChoice{ "" };
cin >> invChoice;
   if (invChoice == "inv")
{


  i.addItem(i.getsword()); // might work

 i.addItem(i.getPotion());

  i.display();
   break;
}
} 


}

}

//times to call inventory
//when you pick up a new object -- prompt will tell you
//in a fight -- case statement 











































/*bool Game::getplaying()
{
	return playing;
}
bool Game::playerdies(double x)
{
	if (x <= 0)
	{
		cout << "you are dead";
		this->playing = false;
		return true;
	}
	else
	{
		return false;
	}

}







void Game::firstencounter()
{

	character e;
	goblin s;
	
	s.setname("Hagrid");
	cout << "Along your travels you see a fat goblin and he wants to rape ur family" << endl;
	cout << "What do you do?\n\n";
	cout << "1. Attack" << endl;
	cout << "2. Give him your wife\n\n";
	cout << "Select '1' or '2'\n\n";
	cin >> choice;
	switch (choice)
	{
	case 1:
		cout << "You call him a Degenrate fuck and he squares up to u\n";
		cout << "Enemies stats: \n\n";
		s.setname("Hagrid");
		s.enemytostring();
		cout << "Here are your select battle moves \n\n";
		do
		{
			int ans{ 0 };
			cout << "\n1.Sword attack\n2.Explosion attack\n3.Attack Spell\n4.Healing Potion\n5.Parry\n\n";
			cout << " Select to choose your fate: " << "\n\n";
			cin >> ans;
			switch (ans)
			{
			case 1:
				e.attackenemy(s);
				break;
			case 2:
				e.explosion(s);
				break;
			case 3:
				e.attackspelll(s);
				break;
			case 4:
				e.healingpot();
				break;
			case 5:
				s.goblinparry(s, e);
				break;
			default:
				cout << "wrong input enemy gets a free attack" << endl;
				s.daggerattack(e);
				break;
			}
			//enemy attack
			cout << "\n\n\t\t\t\tNOW ITS THE ENEMIES TURN TO ATTACK\n\n";
			int x = rand() % (3 - 1 + 1) + 1;
			switch (x)
			{
			case 1:
				s.bowattack(e);
				break;
			case 2:
				s.daggerattack(e);
				break;
			case 3:
				s.swordattack(e);
				break;
			}
			if (s.gethealth() <= 0)
			{
				cout << "Congradulations Warrior you have defated the goblin" << endl;
			}
		} while ((e.gethealth() > 0) && (s.gethealth() > 0));
//issue with this and statement as above as it breaks to case 2 no matter what.
		break;

	case 2:

		cout << "you let ur fam die cunt" << endl;
	this->playing = false;
		break;
	default:
		cout << "too late u died" << endl;
		
	}
	//Assign dialogue for attacks and stories
}



void inventoryIntro()
{
 i.addItem(i.getsword()); // might work

 i.addItem(i.getPotion());

  i.display();


}*/ 

