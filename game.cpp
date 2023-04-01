#include"game.h"
#include"character.h"
#include"inventory.h"
#include "enemytype.h"
#include<string>
#include<iostream>

using namespace std;

Game::Game()
{
	choice = 0;
	playing = true;
}
Game::~Game(){}

bool Game::getplaying()
{
	cout << "come back again soon" << endl;
	return this->playing = false;
}
bool Game::enemydied(){return true;}

bool Game::playerdies()
{
	cout << "you are dead, you will now need to restart" << endl;
	return this->dead = true; 
	abort();
}


void Game::restart(character s)
{
validChoice = false;
while (validChoice == false)
{
string choice {""};

	cout << "would you like to restart the fight?" << endl;
	cout << "\n yes \n" << "\n no \n" << endl;
    cin >> choice;
	if (choice == "yes")
	{
		cout << "Going Back <------" << endl;
		
		validChoice = true;
	} else if (choice == "no")
	{
		cout << playerdies();
		abort();
	} else {
		cin.fail();//checker for anything other than an integer
				//clears input
				cin.ignore(1000, '\n');//discards input to either 1000 characters or until a new 
				//line so the storage reference has no memory
				
				cout << "wrong input -- please type inv to view inventory" << choice <<endl;
				choice.clear();
	}

}
	


}
/*void Game::choiceRemove(int x)
{ 
	if (cin.fail())//checker for anything other than an integer
						{
							
							cin.clear();//clears input
							cin.ignore(1000, '\n');//discards input to either 1000 characters or until a new 
							//line so the storage reference has no memory
							cout << "wrong input" << endl;
							;
						}
						else {
							cout << "wrong input " << endl;
							;
						}
}*/
void Game::displayinv(character s, Inventory i)
{   validChoice = false;
while (validChoice == false){
	cout << "type (inv) to view inventory, you may only use this when allowed " << endl; //not sure just preview atm
	string invChoice{ "" };
	cin >> invChoice;
	if (invChoice == "inv")
	{


		i.display(s);
		validChoice = true;
	} else {
		cin.fail();//checker for anything other than an integer
				//clears input
				cin.ignore(1000, '\n');//discards input to either 1000 characters or until a new 
				//line so the storage reference has no memory
				
				cout << "wrong input -- please type inv to view inventory" << invChoice <<endl;
				invChoice.clear();
	 }

}
}


//----------------------------------------------------------------------

void Game::walkthrough()
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
		while (this->validChoice == false) {

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
			cout << "come again!" << endl;
				abort();

			case 1:


				this->validChoice = true;
				break;

			default:
				if (cin.fail())//checker for anything other than an integer
				{
					cin.clear();//clears input
					cin.ignore(1000, '\n');//discards input to either 1000 characters or until a new 
					//line so the storage reference has no memory
					cout << "wrong input" << endl;
				}
				//choiceRemove(choice);
			}

		}


		//---------------------------------------------------
		this->validChoice = false;

		//character creation and start game
		cout << "Enter characters name: ";

		cin >> name;
		s.setname(name);
		cout << "Welcome " << name << endl;
		cout << "\n\nFirst lets have a walkthrough of the basic combat and inventory before starting the game\n\n\n";

		while (this->validChoice == false)
		{
			//cout << "\n\n\n make Inventory accessor to see potions ect::::::\n\n";

			cout << "Type 'yes' to start this walkthrough : ";
			cin >> start;
			if (start == "yes")
			{
				this->validChoice = true;
			}
			else
			{
				cout << "wrong input please type 'yes' " << endl;
			}
		}
		//--------------------------------------------------------
		cout << "in combat you will be faced with a series of attack and a defence option \n\n\n";
		cout << "Here are your starting stats: \n\n";
		s.tostring(s);
		this->validChoice = false;
		cout << "Along your travels you see a fat goblin and he wants to take your family" << endl;
		cout << "What do you do?\n\n";
		while (this->validChoice == false) {
			e.setname("Hagrid");

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
						{
							cin.clear();//clears input
							cin.ignore(1000, '\n');//discards input to either 1000 characters or until a new 
							//line so the storage reference has no memory
							cout << "wrong input" << endl;
							;
						}
						else {
							cout << "wrong input " << endl;
							;
						}

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
				this->validChoice = true;
				break;


			case 2:

				cout << "you let you and your fam die " << endl;
				abort();
				break;



			default:


				if (cin.fail())//checker for anything other than an integer
				{
					cin.clear();//clears input
					cin.ignore(1000, '\n');//discards input to either 1000 characters or until a new 
					//line so the storage reference has no memory
					cout << "wrong input" << endl;
				}
			}
		}
		//--------------------------------------------------------------
				//Assign dialogue for attacks and stories

		if (s.gethealth() <= 0)
		{

			playerdies();
			abort();
			//break;
		}

		if (e.gethealth() <= 0)
		{
			cout << "congratulations warrior you defeted the goblin\n" << endl;
			cout << "you gain 1 xp from defeating the goblin, this will allow you to level up" << endl;
			s.incexp(1);
			s.levelup();
			

		}

           //s.getlevel();

		while (s.gethealth() > 0)
		{

			cout << "\n\nthe goblin drops to the floor and drops all of his weapons, you have a choice to pick up one" << endl;
			cout << "Type the name of the weapon you want to pick up?" << endl;
			cout << "bow\n" << "sword\n" << "dagger" << endl;
			
			validChoice = false;
			
			while (validChoice == false){
				string choice2{ "" };
			cin >> choice2;
			if (choice2 == "sword")  //insatciate name like goblin sword
			{
				i.addItem(i.getsword());
                validChoice = true;
			}
			else if (choice2 == "bow")
			{
				i.addItem(i.getbow());
				validChoice = true;
			}
			else if (choice2 == "dagger")
			{
				i.addItem(i.getdagger());
				validChoice = true;
			}
			else
			{
				cin.fail();//checker for anything other than an integer
				//clears input
				cin.ignore(1000, '\n');//discards input to either 1000 characters or until a new 
				//line so the storage reference has no memory
				
				cout << "wrong input  -- please type the correct name for your weapon of choice -- " << choice2 <<endl;
				choice2.clear();
			}
			
			

	
		}
		
		break;
		
		}

			s.sethealth(200);

         displayinv(s, i);
		 i.removeItem(0);
		 cout << "note -- you will now notice you have levelled from 1 to 2!" << endl;
		 cout << "note -- you will notice your battle stats, these will increase for when you level up when you enter the main body of the game!" <<endl;
		 cout << "levelling up can be done by defeating monsters as you go along your journey in this game" << endl;
		cout << "\n\nWalkthrough complete, Congulatations\n\n\n\n\n";
		cout << "context - in this world you play as a user of many weapons, including a wand for spells, a sword, bow and a dagger\n\n\n\n" <<endl;

		

		//------------------------------------------------------------------
		//Main Story
		cout << "\nIN A OTHERWORLDIAN DIMENSION \n";
		cout << "\nWelcome to Io, a moon that orbits jupiter approximately 421700 km from its center." << endl;
		cout << "\nYou have been on a research project to investigate and manipulate the space-time continuum and ended up teleporting from Jupiter to Io " << endl;
		cout << "\nFor some reason as you have teleported, you have also found yourself approx 2431 years in the future." <<endl;
        cout << "\nAs you bring your head out the moondust, you notice that there are unrecognised beings being detected on your organism radar" << endl;
		cout << "\nyou look down at your watch to check if it is intact" <<endl;
		cout << "\nwatch display Location - [IO], TIME UNKNOWN" << endl;;
		cout << "\nyou go to check your bag\n\n\n\n\n" << endl;
		s.setlevel(1);

        displayinv(s,i);

		cout << "To your right you notice a sign that says" << endl;
		cout << "\n\nSurvivors this way!!!\n\n" << endl;
		cout << "which way do you turn?\n" << endl;
		cout <<"left\n" << "right\n" << endl;
		
		validChoice = false;
		string userChoice = {" "};
		while (validChoice == false)
		{
		
		cin >> userChoice;

		if (userChoice == "left")
		{
			cout << "you have chosen the left path" << endl;
			this->validChoice = true;
			leftpath(s,i);
        } else if (userChoice == "right"){
			cout << "you have chosen the right path" << endl;
			this->validChoice = true;
			rightPath(s,i);
		}else{
			cout <<"wrong input please try again" << endl;
			cin.fail();//checker for anything other than an integer
				//clears input
				cin.ignore(1000, '\n');//discards input to either 1000 characters or until a new 
				//line so the storage reference has no memory
				
				cout << "wrong input  -- please type the correct name for your weapon of choice -- "  <<endl;
				userChoice.clear();
		}
		}
	}
}

//---------------------------------------------------------------


void Game::leftpath(character s, Inventory i)
{while ((this->playing == true) && (this->dead == false))
	{
//cout << "you have chosen the left path" << endl;
//displayinv(s,i);

cout << "\nYou notice shadows in the distance, they seem to resemble something of a human being shape\n";

cout << "\nAs you approach, it seems to resemble more and more like a monster! OH MY GOODNESS IT IS A GOBLIN-LIKE CREATURE. \n";
cout << "\nTo stop it from seeing you. You hide behind a small pile of rubble \n";
cout << "\nYou notice a sword on the top of the rubble. It looks rusty and like it has been there for a while.\n";
cout << "\nwhat do you do?\n" << endl;
cout << "1. Pick up sword\n" << "2.Take your chances and run" << endl;


validChoice = false;
		string userChoice = {" "};
		while (validChoice == false)
		{
		
		cin >> userChoice;

		if (userChoice == "1")
		{
			cout << "You pick up the sword" << endl;
			i.addItem(i.getsword());
			
			validChoice = true;
		
        } else if (userChoice == "2"){
			cout << "You are detected by the goblin, he catches you as you run away and eats you" << endl;
			playerdies(); // already aborts code
			//validChoice = true;
			
		}else{
			cout <<"wrong input please try again" << endl;
			cin.fail();//checker for anything other than an integer
				//cin.clear();//clears input
				cin.ignore(1000, '\n');//discards input to either 1000 characters or until a new 
				//line so the storage reference has no memory
				
				cout << "wrong input  -- please type the correct name for your weapon of choice -- "  <<endl;
				userChoice.clear();
		}
		}


displayinv(s,i);

goblin e;

cout << "\nNow you have your sword. You are ready to take on the goblin\n" << endl;
this->validChoice = false;
		cout << "You charge at the goblin with all your might" << endl;
		//cout << "What do you do?\n\n";
		while (this->validChoice == false) {
			e.setname("Small Goblin");

			cout << "1. Attack" << endl;
			
			//cout << "Select '1' \n\n";
			cin >> choice;


			switch (choice)
			{
			case 1:
				//cout << "You challenge him and he squares up \n";
				cout << "Enemies stats: \n\n";
				e.enemytostring();
				cout << "Here are your select battle moves \n\n";

				do
				{

					int ans;
					cout << "\n1.Sword attack\n";
					cout << " Select to choose your fate: " << "\n\n";
					cin >> ans;
					switch (ans)
					{
					case 1:
						s.attackenemy(e);
						break;
					
					default:
					{

						if (cin.fail())//checker for anything other than an integer
						{
							cin.clear();//clears input
							cin.ignore(1000, '\n');//discards input to either 1000 characters or until a new 
							//line so the storage reference has no memory
							cout << "wrong input" << endl;
							;
						}
						else {
							cout << "wrong input " << endl;
							;
						}

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
						cout << "\n\n\t\t\t\tNOW ITS THE GOBLIN'S TURN TO ATTACK\n\n";

						int x = 1;
						switch (x)
						{
						case 1:
							e.daggerattack(s);
							break;
						
						}

					}


				} while (((e.gethealth() > 0) && (s.gethealth() > 0)) || (enemydied() == false));
				this->validChoice = true;
				break;

			default:
				if (cin.fail())//checker for anything other than an integer
				{
					cin.clear();//clears input
					cin.ignore(1000, '\n');//discards input to either 1000 characters or until a new 
					//line so the storage reference has no memory
					cout << "wrong input" << endl;
				}
			}
			if (s.gethealth() <= 0)
		{
			restart(s);
			s.sethealth(200);
			validChoice = false;
		
		}

		if (e.gethealth() <= 0)
		{
			cout << "congratulations warrior you defeted the goblin\n" << endl;
			cout << "you gain 1 xp from defeating the goblin\n";
			s.incexp(1);
			s.levelup();
			//displayinv(s,i);
			break;
		}
		}

cout << "\nthe small goblin falls to the floor and you go over to its lifeless structure\n";
cout << "you search it for any item and find the dagger, you pick it up as it may come in handy at some point.\n";
i.addItem(i.getdagger());
cout << "\nyou notice the goblin is also carrying a scroll. You take the scroll from his belt and read it.\n";
cout << "    TO WHOMSTEVER THIS MAY CONCERN\n" << endl;


	

getplaying();
}


}





void Game::rightPath(character s, Inventory i)
{while ((this->playing == true) && (this->dead == false))
{
//cout << "you have chosen the right path" << endl;
displayinv(s,i);
getplaying();}


}






