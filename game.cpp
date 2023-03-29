#include"game.h"
#include"character.h"
#include "enemytype.h"
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
	cout << "come back again soon" << endl;
	return this->playing = false;
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
	return this->dead = true; //this fixes loop issue
}

void Game::displayinv(character s, Inventory i)
{
	cout << "type (inv) to view inventory, you may only use this when allowed " << endl; //not sure just preview atm
	string invChoice{ "" };
	cin >> invChoice;
	if (invChoice == "inv")
	{


		//i.addItem(i.getsword()); // might work

		//i.addItem(i.getPotion());

		i.display();
	}

}


void Game::script()
{



	string start{ " " };
	
	character s;
	goblin e;
    string name;
	Inventory i; // inventory declaration



	//while loop for conditions to run the game 
	while ((this->playing == true) && (this->dead == false))



		/* Brief

		full game runs in while loop
		if player dies while loop ends


		*/
     {    
		while (this->validChoice == false){

	
		cout << "273 project: Text Based RPG Game" << "\n\n" << "created by Daniel Conaghan and Santiago Rivett Barragan" << "\n\n\n\n\n";
		cout << "\t\t\t\t\t\tRISE OF THE WARRIOR" << endl;
		cout << "\t\t\t\t\t\tMAIN MENU" << endl << endl;
		cout << "\t\t\t\t\t\t1: Exit" << endl;
		cout << "\t\t\t\t\t\t2: Start Game" << endl;
		cout << "\t\t\t\t\t\tChoice: ";
		cin >> choice;
		
		switch (choice)
		
		{
		case 1:
		    abort();

		case 2:
			//playing = true;
			//character creation and start game
			cout << "Enter characters name: ";
			
			cin >> name;
			s.setname(name);
			cout << "Welcome " << name << endl;

			cout << "Here are your starting stats: \n\n";
			s.tostring();
			//cout << "\n\n\n make Inventory accessor to see potions ect::::::\n\n";
			cout << "\n\nFirst lets have a walkthrough of the basic combat and inventory before starting the game\n\n\n";
			cout << "Type 'yes' to start this walkthrough : ";
			cin >> start;
			if (start == "yes")
			{
				cout << "in combat you will be faced with a series of attack and a defence option \n\n\n";
			}
			
			this->validChoice = true;
			break;

		default:
			if (cin.fail())//checker for anything other than an integer
				{cin.clear();//clears input
				cin.ignore(1000, '\n');//discards input to either 1000 characters or until a new 
				//line so the storage reference has no memory
				cout<<"wrong input" <<endl;
		        }
		}
		/*if (choice == 1)
		{
			abort();
			//this->validChoice = true;
			


		}else if (choice == 2){//playing = true;
			//character creation and start game
			cout << "Enter characters name: ";
			
			cin >> name;
			s.setname(name);
			cout << "Welcome " << name << endl;

			cout << "Here are your starting stats: \n\n";
			s.tostring();
			//cout << "\n\n\n make Inventory accessor to see potions ect::::::\n\n";
			cout << "\n\nFirst lets have a walkthrough of the basic combat and inventory before starting the game\n\n\n";
			cout << "Type 'yes' to start this walkthrough : ";
			cin >> start;
			if (start == "yes")
			{
				cout << "in combat you will be faced with a series of attack and a defence option \n\n\n";
			}
			
			this->validChoice = true;
			

		}else {if (cin.fail())//checker for anything other than an integer
				{cin.clear();//clears input
				cin.ignore(1000, '\n');//discards input to either 1000 characters or until a new 
				//line so the storage reference has no memory
				cout<<"wrong input" <<endl;
		        }}*/
	 } 



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

				int ans;
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
				{
					
					if (cin.fail())//checker for anything other than an integer
				{cin.clear();//clears input
				cin.ignore(1000, '\n');//discards input to either 1000 characters or until a new 
				//line so the storage reference has no memory
				cout<<"wrong input" <<endl;
			 ;} 
				else {cout<<"wrong input " <<endl;
			   ;}
				
					break;
				}
				
			}				
		
				//enemy attack
				if (e.gethealth() <= 0)
				{
					e.enemySetHealthZero();
					//enemydied();
				}
				else {
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
					
				}
				
				
			} while (((e.gethealth() > 0) && (s.gethealth() > 0)) || (enemydied() == false));
			
			break;

		case 2:

			cout << "you let ur fam die " << endl;

			break;


			
		default:
		
			
                if (cin.fail())//checker for anything other than an integer
				{cin.clear();//clears input
				cin.ignore(1000, '\n');//discards input to either 1000 characters or until a new 
				//line so the storage reference has no memory
				cout<<"wrong input" <<endl;
		        }
		}
		
		//Assign dialogue for attacks and stories
		


		

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
			
           cout << "the goblin drops to the floor and drops all of his weapons, you have a choice to pick up one" << endl;
           cout << "Type the name of the weapon you want to pick up?" << endl;
		   cout << "bow\n" << "sword\n" << "dagger" << endl;
           string choice2{""};
		   cin >> choice2;
		   if (choice2 == "bow")
		  // {
           //i.addItem(i.get)
		   //}
			displayinv(s, i);

			break;
		}

		cout << "\n\nWalkthrough complete, Congulatations\n\n\n";
		s.sethealth(200);

		cout << "welcome to io, a moon that orbits jupiter approximately 421700 km from its center." << endl;
		cout << "You have been on a research project to investigate and manipulate the space - time continuum and ended up teleporting from Jupiter to Io " << endl;
        //cout << 
	

		getplaying();
	



     }
}