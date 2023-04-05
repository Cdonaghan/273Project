#include"game.h"
#include"character.h"
#include"inventory.h"
#include "enemytype.h"
#include<string>
#include<iostream>
using namespace std;
void Game::endgamecredits()
{
	cout << "\n\n\n\n\n\n\n\n273 project: Text Based RPG Game" << "\n\n" << "created by Daniel Conaghan and Santiago Rivett Barragan" << "\n\n\n\n\n";
	cout << "\n\n\n\t\t\t\t\t\t50-50 equal contribution in this project\n\n\n\n";

	cout << "\t\t\t\t\t\tRISE OF THE WARRIOR" << endl;

	cout << "\t\t\t\t\t\tKEEP AN EYE OUT FOR PART 2\n\n\n";
	getplaying();
}


Game::Game()
{
	choice = 0;
	playing = true;
}
Game::~Game() {}

bool Game::getplaying()
{
	cout << "come back again soon" << endl;
	//has abort because of the loop in walkthrough function. This is fine.
	abort();
	return this->playing = false;

}
bool Game::enemydied() { return true; }

void Game::choiceRemove(string x)
{
	cin.fail();//checker for anything other than an integer
	//clears input
	cin.ignore(1000, '\n');//discards input to either 1000 characters or until a new 
	//line so the storage reference has no memory

	cout << "wrong input  -- please type the correct name for your weapon of choice -- " << x << endl;
	x.clear();
}

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
		string choice{ "" };

		cout << "would you like to restart the fight?" << endl;
		cout << "\n yes \n" << "\n no \n" << endl;
		cin >> choice;
		if (choice == "yes")
		{
			cout << "Going Back <------" << endl;

			validChoice = true;
		}
		else if (choice == "no")
		{
			cout << playerdies();
			abort();
		}
		else {
			cin.fail();//checker for anything other than an integer
			//clears input
			cin.ignore(1000, '\n');//discards input to either 1000 characters or until a new 
			//line so the storage reference has no memory

			cout << "wrong input -- please type inv to view inventory" << choice << endl;
			choice.clear();
		}

	}



}






void Game::displayinv(character s, Inventory i)
{
	validChoice = false;
	while (validChoice == false) {
		cout << "type (inv) to view inventory, you may only use this when allowed " << endl; //not sure just preview atm
		string invChoice{ "" };
		cin >> invChoice;
		if (invChoice == "inv")
		{


			i.display(s);
			validChoice = true;
		}
		else
		{
			cin.fail();//checker for anything other than an integer
			//clears input
			cin.ignore(1000, '\n');//discards input to either 1000 characters or until a new 
			//line so the storage reference has no memory

			cout << "wrong input -- please type inv to view inventory" << invChoice << endl;
			invChoice.clear();
		}

	}
}


void Game::storylineSelect(character s, Inventory i)
{
	validChoice = false;
	while (validChoice == false)
	{

		string choice{ "" };
		cout << "what part of the storyline would you like to go to?\n";
		cout << "\n1: Start of Main Story" << endl;
		cout << "\n2: Left path";
		cout << "\n3: Right path" << endl;
		//update for more sections of story
		cin >> choice;
		if (choice == "0")
		{
			validChoice = true;
		}
		else if (choice == "1") {
			beginning(s, i);
			validChoice = true;
		}
		else if (choice == "2") {
			leftpath(s, i);
			validChoice = true;
		}
		else if (choice == "3") {
			rightPath(s, i);
			validChoice = true;
		}
		else {

			choiceRemove(choice);
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

	//cout << "Enter your name:";
	//cin >> names;
	//s.setname(names);



	//while loop for conditions to run the game 
	while ((this->playing == true) && (this->dead == false))


		/* Brief

		full game runs in while loop
		if player dies while loop ends


		*/
	{
		while (this->validChoice == false) {

			cout << "273 project: Text Based RPG Game" << "\n\n" << "created by Daniel Conaghan and Santiago Rivett Barragan" << "\n\n\n\n\n";

			cout << "Enter characters name: ";

			cin >> name;
			s.setname(name);

			cout << "\t\t\t\t\t\tRISE OF THE WARRIOR" << endl;
			cout << "\t\t\t\t\t\tMAIN MENU" << endl << endl;
			cout << "\t\t\t\t\t\t0: Exit" << endl;
			cout << "\t\t\t\t\t\t1: Start Game" << endl;
			cout << "\t\t\t\t\t\t2: Storyline " << endl;

			//code for going to certain points in the story
			/*
			cout << "\t\t\t\t\t\t2: Storyline
			"*/
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

			case 2:

				storylineSelect(s, i);

				//display functions fopr certain storypoints here
				//done in an if statement with an input checker
				//make look neat 
				//eg 
				//cout << "which part of the story would you like to travel too?"
				//if(choice == "Left path")
				//leftpath(s, i);

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
			string choice2{ "" };
			while (validChoice == false) {

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

					cout << "wrong input  -- please type the correct name for your weapon of choice -- " << choice2 << endl;
					choice2.clear();
				}




			}

			break;
			//string choice2; 
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
				choiceRemove(choice2);
			}



		}

		s.sethealth(200);

		displayinv(s, i);
		i.removeItem(0);
		cout << "note -- you will now notice you have levelled from 1 to 2!" << endl;
		cout << "note -- you will notice your battle stats, these will increase for when you level up when you enter the main body of the game!" << endl;
		cout << "levelling up can be done by defeating monsters as you go along your journey in this game" << endl;
		cout << "\n\nWalkthrough complete, Congulatations\n\n\n\n\n";
		cout << "context - in this world you play as a user of many weapons, including a wand for spells, a sword, bow and a dagger\n\n\n\n" << endl;



		//------------------------------------------------------------------
		//Main Story
		/*cout << "\n IN A OTHERWORLDIAN DIMENSION \n";
		cout << "Welcome to Io, a moon that orbits jupiter approximately 421700 km from its center." << endl;
		cout << "You have been on a research project to investigate and manipulate the space-time continuum and ended up teleporting from Jupiter to Io " << endl;
		cout << "For some reason as you have teleported, you have also found yourself approx 2431 years in the future." << endl;
		cout << "As you bring your head out the moondust, you notice that there are unrecognised beings being detected on your organism radar" << endl;
		cout << "you look down at your watch to check if it is intact" << endl;
		cout << "watch display Location - [IO], TIME UNKNOWN" << endl;;
		cout << " you go to check your bag\n\n\n\n\n" << endl;

		cout << "context - in this world you play as a user of many weapons, including a wand for spells, a sword, bow and a dagger\n\n\n\n" <<endl;*/
		beginning(s, i);

		getplaying();
	}

}

//---------------------------------------------------------------



void Game::beginning(character s, Inventory i)
{
	cout << "\nIN A OTHERWORLDIAN DIMENSION \n";
	cout << "\nWelcome to Io, a moon that orbits jupiter approximately 421700 km from its center." << endl;
	cout << "\nYou have been on a research project to investigate and manipulate the space-time continuum and ended up teleporting from Jupiter to Io " << endl;
	cout << "\nFor some reason as you have teleported, you have also found yourself approx 2431 years in the future." << endl;
	cout << "\nAs you bring your head out the moondust, you notice that there are unrecognised beings being detected on your organism radar" << endl;
	cout << "\nyou look down at your watch to check if it is intact" << endl;
	cout << "\nwatch display Location - [IO], TIME UNKNOWN" << endl;;
	cout << "\nyou go to check your bag\n\n\n\n\n" << endl;
	s.setlevel(1);

	displayinv(s, i);

	cout << "To your right you notice a sign that says" << endl;
	cout << "\n\nSurvivors this way!!!\n\n" << endl;
	cout << "which way do you turn?\n" << endl;
	cout << "left\n" << "right\n" << endl;

	validChoice = false;
	string userChoice = { " " };
	while (validChoice == false)
	{

		cin >> userChoice;

		if (userChoice == "left")
		{
			cout << "you have chosen the left path" << endl;
			this->validChoice = true;
			leftpath(s, i);
		}
		else if (userChoice == "right") {
			cout << "you have chosen the right path" << endl;
			this->validChoice = true;
			rightPath(s, i);
		}
		else {
			cout << "wrong input please try again" << endl;
			cin.fail();//checker for anything other than an integer
			if (userChoice == "left")
			{
				cout << "you have chosen the left path" << endl;
				leftpath(s, i);
				getplaying();
				this->validChoice = true;

			}
			else if (userChoice == "right") {
				cout << "you have chosen the right path" << endl;
				rightPath(s, i);
				getplaying();
				this->validChoice = true;

			}
			else {
				cout << "wrong input please try again" << endl;
				cin.fail();//checker for anything other than an integer
				//clears input
				cin.ignore(1000, '\n');//discards input to either 1000 characters or until a new 
				//line so the storage reference has no memory

				cout << "wrong input  -- please type the correct name for your weapon of choice -- " << endl;
				userChoice.clear();
			}
		}
		getplaying();
	}
}





void Game::leftpath(character s, Inventory i)
{
	while ((this->playing == true) && (this->dead == false))
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
		string userChoice = { " " };
		while (validChoice == false)
		{

			cin >> userChoice;

			if (userChoice == "1")
			{
				cout << "You pick up the sword" << endl;
				i.addItem(i.getsword());

				validChoice = true;

			}
			else if (userChoice == "2")
			{
				cout << "You are detected by the goblin, he catches you as you run away and eats you" << endl;
				restart(s); // already aborts code
				//validChoice = true;

			}
			else {
				cout << "wrong input please try again" << endl;
				cin.fail();//checker for anything other than an integer
				//cin.clear();//clears input
				cin.ignore(1000, '\n');//discards input to either 1000 characters or until a new 
				//line so the storage reference has no memory

				cout << "wrong input  -- please type the correct name for your weapon of choice -- " << endl;
				userChoice.clear();
			}
		}


		displayinv(s, i);

		goblin e;

		cout << "\nNow you have your sword. You are ready to take on the goblin\n" << endl;
		this->validChoice = false;
		cout << "Along your travels you see a fat goblin and he wants to take your family" << endl;
		cout << "What do you do?\n\n";

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
		}

		if (s.gethealth() <= 0)
		{
			restart(s);
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


		cout << "\nthe small goblin falls to the floor and you go over to its lifeless structure\n";
		cout << "you search it for any item and find the dagger, you pick it up as it may come in handy at some point.\n";
		i.addItem(i.getdagger());
		cout << "\nyou notice the goblin is also carrying a scroll. You take the scroll from his belt and read it.\n";
		cout << "    TO WHOMSTEVER THIS MAY CONCERN\n" << endl;
		cout << "There is an escape pod on the top of the highest hill in the area, if you are reading this i hope you know this is a sign to make it to the top of the hill and get out of here" << endl;



		getplaying();
	}

	getplaying();

}







//-------------------------------------------------------------------------


void Game::rightPath(character s, Inventory i)
{
	mutant p;
	goblin e;

	while ((this->playing == true) && (this->dead == false))
	{

		//surivor,, notice escape pod look arund see a chest see weapon,, off to distance you see goblin after a ghirl you ntoice her hiding 
		//option 1.flee  2. attack

		//flee--> left path --> troll 
		//attack-->  kill --> she knows whwere the rest of the ship where escape pods from
		// guraded its guarded by a dragon through the forrest its dangerous 


		//---------------------------------------------------------------------
		cout << "\n\n\n\nYou walk closer to the sign, the closer you get you notice that something is wrong,\n\nthere is blood splattered on the sign with a big bloody handprint on it.\n\n";
		cout << "You walk a few more paces and see what is shaped like an escape pod ahead of you.\nIn excitment you starting running in hope of finding resources or even better a surivor. \n\n";
		cout << "ITS AN ESCAPE POD.\n\n" << "Out of nowhere you hear a piercing scream and hide behind some rubble. " << "The screaming suddenly stops with an errie crunch.\n\n";
		cout << "Right beside you in the rubble is a freshly cut arm torn clean off!!\n\n";
		cout << "You take a peak above the rubble to see what caused the screaming\n\nITS A TROLL KILLING A HUMAN.\n\n\n";
		cout << "what do you do?\n";
		cout << "1. Hide until it leaves\n2. Start screaming and run away\n ";

		validChoice = false;
		string userChoice1 = { " " };
		while (validChoice == false)
		{

			cin >> userChoice1;

			if (userChoice1 == "1")
			{
				i.addItem(i.getsword());
				cout << "\n\n\n\nYou hide behind the rubble until the troll leaves and you start walking to the escape pod.\n\n";
				cout << "Inside you find a bloody sword on the ground, you pick it up and start following a trail of blood on the floor.\n\n";
				cout << "You follow the trail and see that a golbin is holding an injured survivor hostage.\n\n\n\n ";
				displayinv(s, i);
				validChoice = true;

			}
			else if (userChoice1 == "2")
			{
				cout << "\nYou panic and start screaming, the troll spots you instantly and lets out a horrible roar.\n\nIt starts running to you and kills you with a deadly blow.\n\n";
				playerdies();
				//validChoice = true;
			}
			else
			{
				cout << "wrong input please try again" << endl;
				cin.fail();//checker for anything other than an integer
				//cin.clear();//clears input
				cin.ignore(1000, '\n');//discards input to either 1000 characters or until a new 
				//line so the storage reference has no memory

				cout << "wrong input  -- please type the correct input -- " << endl;
				userChoice1.clear();
			}
		}





		cout << "\n\n\nNow you have a sword in your inventory do you\n1. Fight the goblin\n2. Continue exploring the escape pod\n";

		string userchoice2{ "" };
		cout << "What do you do: ";
		cin >> userchoice2;
		if (userchoice2 == "1")
		{
			e.setname("Small Goblin");
			cout << "Enemy stats:\n";
			e.enemytostring();
			cout << "Here are your battles moves\n\n";
			do
			{
				int ans{};
				cout << "\n1.Sword attack\n";
				cout << "Select your move: ";
				cin >> ans;
				switch (ans)
				{
				case 1:
					s.attackenemy(e);
					break;
				default:
					if (cin.fail())//checker for anything other than an integer
					{
						cin.clear();//clears input
						cin.ignore(1000, '\n');//discards input to either 1000 characters or until a new 
						//line so the storage reference has no memory
						cout << "wrong input" << endl;
					}
					else
					{
						cout << "wrong input\n";
					}
					break;
				}
				//enemy attack
				if (e.gethealth() <= 0)
				{
					e.enemySetHealthZero();
				}
				else
				{
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

			if (s.gethealth() <= 0)
			{
				restart(s);
				s.sethealth(200);
			}
			if (e.gethealth() <= 0)
			{
				cout << "\n\n\nWith one last swing of the sword you take the goblins head clean off\n\nCongradulations Warrior you have defeated the Goblin" << endl;
				cout << "you gain 2 xp from defeating the goblin\n\n";
				cout << "you search the goblins lifless body for any items and find a wand and 2 healing potions!\n\n";
				cout << "you pick them both up up as it may come in handy at some point as you know some useful spells.\n\n";
				s.incexp(2);
				s.levelup();
				//s.setlevel(2);
				i.addItem(i.getwand());
				i.addItem(i.getPotion());
				i.addItem(i.getPotion());
				displayinv(s, i);
				this->validChoice = true;
				cout << "\n\n\n\n\n\nYou rescue the hostage but he is seriously bleeding out.\n\n";
				cout << "He very weakly said his name is 'Commander Salamander' and he escaped his ship as it got attacked by a dragon.\n\n";
				cout << "Before passing away he reaches into his jacket and pulls out a projector.\n\n";
				cout << "You take it from his lifeless body and it suddenly lights up projecting the commander with another man.\n\nThere are loud sirens in the background to where he proceedes to speak very frantically with a great sense of urgency.\n\n";
				cout << "\t\t\t\t\t'Mayday Mayday Mayday this is Commander Salamander and Lutenent Garcia here our ship is\n\t\t\t\t\t reaching critical damage is there anyone out there??'\n\n";
				cout << "A loud bang thorws them both to the floor shortly followed by a thunderous roar, ";
				cout << "he stands up again insantly and proceeds to say with more urgency.\n\t\t\t\t\t\t'The ship is going down a dragon I repeat A FIREBREATHING DRAGON has attacked\n\t\t\t\t\t\t and intercepted this mission. The crew have now escaped\n\t\t\t\t\t\t via escape pods with 2 more for myself and Lutenet Garcia\n\t\t\t\t\t\t we are sending this message out to warn anyone in the area this world is not saf.... '\n";
				cout << "Before he could finish a large claw breaks the ship window and pierces the Lutenent Garcia in the chest and is dragged out of the\n\nship window.\n";
				cout << "\t\t\t\t\t\tOh Shit Garcia is dead. I'll keep this short I dont know how much time I have left.\n\t\t\t\t\t\tThis ship is projected to crash in a few minutes and I need to escape.\n\t\t\t\t\t\tThe ship and all this cargo is looking to crash in the forrest.\n\t\t\t\t\t\tIf there are any survivors meet there\n\nAnd just like that the projection ended.\n\n";
				cout << "Still confused by this extremely advanced technology the only thought on your mind is surival and this meant finding this ship.\n\nSeveral unanswered questions enter you mind like:\nHow did I end up here?, does anyone know that I'm here?, where is planet IO?, what are those creatures trying to kill me?\n\nWith all these questions only thing that remains constant is that YOU NEED TO FIND THIS SHIP AND GET THE HELL OUT OF HERE\n\n";
				string continuestorychoice2 = { "" };
				validChoice = false;
				cout << "\n\n\n\nYou have completed the first part of the story, would you like to continue?\n";
				cout << "note -- if not you will be asked to restart\n";
				cout << "1. Continue\n2. Restart\n";
				cin >> continuestorychoice2;
				while (validChoice == false)
				{
					if (continuestorychoice2 == "1")
					{
						rightPathStory(s, i);
						validChoice = true;
					}
					else if (continuestorychoice2 == "2")
					{
						restart(s);
						walkthrough();
						validChoice = true;
					}
					else
					{
						choiceRemove(continuestorychoice2);
					}
				}
				getplaying();


			}
		}

		else if (userchoice2 == "2")
		{

			cout << "\n\n\n\nYou ignore the hostage and continue walking to explore the rest of the pod. You come across a chest and look inside, theres a wand\n\nand a scroll. You take the wand as you know a few powerful spells which will come in very handy.\n";
			cout << "\nThe scroll reads.\n\t\t\t\t'My Ship got attacked by a dragon and I have just escaped through this escape pod,\n\t\t\t\t\I'm not sure if Ill make it out alive but if anyone of my crew finds this meet in the forrest.\n\t\t\t\t\I have sent out a telegram to all my crew and we should all regroup there.\n\t\t\t\t\I'm not sure if Ill make it out alive but if anyone of my crew finds this meet in the forrest.\n\t\t\t\t\Commander Salamander'\n\n";
			i.addItem(i.getwand());
			i.addItem(i.getscroll());
			displayinv(s, i);
			cout << "'If I find this ship it could help me escape this godforsaken world and use any remaining escape pods to go back home to my family'\n\nYou take a step outside the pod and look around you for any sign of a forrest that the scroll mentioned.\n\nIn the distance you hear some disturbing growling. You walk cautiously ahead and see what is shaped like a human.\n\nExcited you start jogging towards the figure, maybe he's lost and looking for the forrest too. The figure turns around from hearing\n\nyour footsteps, his mouth is covered in blood and in his hand is a half eaten leg. He gets down on all fours\n\nand starts running towards you.\n";
			cout << "\n\nWhat do you do?\n1.Do you run back into the escape pod\n2.Fight the creature\n";
			int userchoice2323{};
			cin >> userchoice2323;
			if (userchoice2323 == 1)
			{
				cout << "You run back into the escape pod and slam the door shut behind you. As you slam the door the sound echoes through the escape pod,\n\nthe goblin holding the human hostage pounces on your back and pierces you through the chest with his sword, killing you\n\n";
				validChoice = false;
				playerdies();
				abort();
			}
			else if (userchoice2323 == 2)
			{
				cout << "\n\n\n\nNow you have a wand and a sword you can change up your attack combinations\n";
				p.setname("Mutant");
				p.enemytostring();
				cout << "\n\n\nHere are your battle moves\n\n";
				do
				{

					int ans{};
					cout << "1.Sword Attack\n2.Explosion Spell\n3.Attack Spell\n4.Parry\n\n";
					cout << "Choose your fate warrior: ";
					cin >> ans;
					switch (ans)
					{
					case 1:
						s.attackenemy(p);
						break;
					case 2:
						s.explosion(p);
						break;
					case 3:
						s.attackspelll(p);
						break;
					case 4:
						p.mutantparry(p, s);
						break;
					default:
						if (cin.fail())//checker for anything other than an integer
						{
							cin.clear();//clears input
							cin.ignore(1000, '\n');//discards input to either 1000 characters or until a new 
							//line so the storage reference has no memory
							cout << "wrong input" << endl;
						}
						else
						{
							cout << "wrong input\n";
						}
						break;
					}
					//enemy attack
					if (p.gethealth() <= 0)
					{
						p.enemySetHealthZero();
					}
					else
					{
						cout << "\n\n\t\t\t\tNOW ITS THE MUTANTS TURN TO ATTACK\n\n";
						int x = rand() % 2 + 1;
						switch (x)
						{
						case 1:
							p.smash(s);
							break;
						case 2:
							p.acid(s);
							break;
						default:
							p.smash(s);
							break;
						}
					}
				} while (((p.gethealth() > 0) && (s.gethealth() > 0)) || (enemydied() == false));
				this->validChoice = true;
				if (s.gethealth() <= 0)
				{
					playerdies();
					restart(s);
				}
				if (p.gethealth() <= 0)
				{
					cout << "\n\n\nThe mutant cripples over as you hit him with a thunderous final blow, you have defeated it! \n" << endl;
					cout << "you gain 5 xp from defeating the mutant\n\n";
					cout << "you search the mutants body to find 2 healing potions!\n\n";
					cout << "Despite this victory the only thought going on in your head is to find the remains of this ship and escape this world.\n\nYou start debating if you are dreaming or if this is actually real\n\nThis isnt my lab, where am I?. Where is planet IO?. Does anyone know I'm here?. What were those creatures I saw trying to kill me?\n\n Why does my watch say time unknown?\n\nAll these questions reamin unanswered, but the only thing that reamins unchanged is that I NEED TO FIND THIS SHIP AND GET THE HELL OUT OF HERE\n";
					i.addItem(i.getPotion());
					i.addItem(i.getPotion());
					s.incexp(5);
					s.levelup();
					//s.setlevel(2);S
					displayinv(s, i);
					string continuestorychoice3 = { "" };
					validChoice = false;
					cout << "\n\n\n\nYou have completed the first part of the story, would you like to continue?\n";
					cout << "note -- if not you will be asked to restart\n";
					cout << "1. Continue\n2. Restart\n";
					cin >> continuestorychoice3;
					while (validChoice == false)
					{
						if (continuestorychoice3 == "1")
						{
							rightPathStory(s, i);
							validChoice = true;
						}
						else if (continuestorychoice3 == "2")
						{
							walkthrough();
							validChoice = true;
						}
						else
						{
							choiceRemove(continuestorychoice3);
						}

					}


				}

			}
			else
			{
				if (cin.fail())//checker for anything other than an integer
				{
					cin.clear();//clears input
					cin.ignore(1000, '\n');//discards input to either 1000 characters or until a new 
					//line so the storage reference has no memory
					cout << "wrong input" << endl;
				}
				else
				{
					cout << "wrong input\n";
				}
				break;
			}
		}
		//getplaying();
	}
}
void Game::rightPathStory(character s, Inventory i)
{

	troll t;
	while ((this->playing == true) && (this->dead == false))
	{

		cout << "\n\t\t\t\t\t\Part 2\n\n";
		cout << "It's getting late. You constinue to wander into the distance but you can't see anything anymore.\n\nYou decide to find some shelter and try get some sleep and set off in the morning again.";
		cout << " The moment you rest your head you fall fast asleep\n\n\n";
		cout << "\t\t\t\t\t\Five Years Earlier\n\t\t\t\t\t\Kennedy Space Center, Florida\n\n";
		cout << "'Why do you have to go Daddy' says your 5 year old daughter.\n\n'I'll be back in a few months Daisy I promise. This is a really important project that Daddy has been selected for,\n\nthis could change absoltely everything princess. You never know I could be famous when I get back and get you that puppy\n\n you always wanted'You pinch her cheeks and she giggles\n\n";
		cout << "'Do you pinky promise?'\n\n You get down on your knees to get eye level with her.\n\n'You know you can't break a pinky promise right?'\n\nA little tear runs down her cheek, you wipe the tear and say\n\n'I pinky promise princess I'll come back for you'\n\n ";

		cout << "\t\t\t\t\t\Five Later Later\n\t\t\t\t\t\Planet IO, Universe unknown\n\n";
		cout << "You wake up in a sweat and sit up in attempt to control your breathing. You must have been asleep for around a few hours\n\nas the sky is beginning to clear up. Impatient you get up and start walking towards the forrest.\n\nAt the foot to the enterance of the forrest you notice a cave that seems to have a fire lit inside.\n\n";
		cout << "What do you do?\n1. Explore the cave\n2. Enter the forrest\n";
		string rps1{ "" };
		cin >> rps1;
		if (rps1 == "1")
		{
			cout << "\n\n\n\nYou walk into the cave and notice bones scatterred all over the floor, the closer you get to the cackling fire in the distance\n\nyou hear what sounds like two human voices conversing.\n\n'Hello is anyone here?' you shout.\n\nYou hear in the distance\n'Put the fire out you idiot something got into the cave!'\n\nAnother voice said with a very trembly voice\n\n'Oh God. Oh God. Chris I can't even stand what if that thing follwed us back in here. I'm are so dead. Oh God'\n\nYou walk very cautiouly sword in one hand and the wand in another and there before your eyes are two humans.\n\nOne is lying on the ground with what appears like a broken leg whilst the other is standing in front of him weilding a sword pointing straight at me.\n\n";
			cout << "'Who are you?' says the man holding the sword.\n'My name is " << s.getname() << " I won't hurt you I just saw the fire and thought there'd be surivors. I need help I have no idea nwhere I am'\n\n you lower your weapon.\n\nThe man lowers his sword 'I'm not sure of how much help we can be, Thomas over there broke his leg when our ship crashed\n\nin the forrest, I had to carry him to this cave with some of those awful creatures on our tail.\n\nWe lost them and have been staying here overnight'\n\n";
			cout << "Wait did they mention the forrest!\n\n'I'm looking for that ship that crashed in the forrest, it could be my only way out of here. Where is it?' you say\n\n'I was hoping you wouldn't say that. I'll tell you what I'll tell you where it is if you give us your healing potions\n\nit's for my partner, deal?'\n\n";
			string yesorno{ "" };
			cout << "What do you do?\n1. Give him all your potions\n2. No I need them\n";
			cin >> yesorno;
			if (yesorno == "1")
			{
				string westoreast{ "" };
				cout << "\n\n\n\n'God thank you so much " << s.getname() << " this should get Thomas up and running in a day or two. Okay just as promised\n\nto find ship wreckage you need to enter the forrest and head East and in a few hours of walking in this direction you should find it'.\n\n";
				cout << "'I must warn you. The dragon that took out our ship is still there, it must think its proecting its land.\n\nIt's a suicide mission you know that right. Here take my armour you'll need it more than me'\n\n";
				cout << "You pick up the armour and put it on\n\n";
				s.sethealth(300);
				s.disphealth();
				i.addItem(i.getdragonsword());
				cout << "'If you intend on fighting this dragon I'm not sure that sword can pierce its scales.\n\nI remember doing some research into dragon fighting the only weapon that deal any damage is any weapon made of Aerondight.\n\n It'll pierce it's scales like butter. Here take it'\n\nHe drops his sword.\n ";
				i.removeItem(2);
				i.removeItem(2);
				s.incexp(15);
				s.levelup();
				displayinv(s, i);
				validChoice = false;
				cout << "You pick up his weapon and notice its remarkable colour. With this you exit the cave and head towards the forrest\n\n\n\n";
				cout << "Do you head East or West?\n1. East\n2. West\n";
				cin >> westoreast;
				while (validChoice == false)
				{
					if (westoreast == "1")
					{
						eastpath(s, i);
						validChoice = true;
					}
					else if (westoreast == "2")
					{
						westpath(s, i);
						validChoice = true;
					}
					else
					{
						choiceRemove(westoreast);
					}
				}
				getplaying();

			}
			else if (yesorno == "2")
			{
				cout << "\n\n'I cannot believe you are this selfish' he screams.\n\nHe continues shouting at you and you both start fighting until you both suddenly hear a loud roar.\n\n The dragon enters the cave and burns you all\n";
				playerdies();
				abort();
			}
			else
			{
				choiceRemove(yesorno);
			}
		}
		else if (rps1 == "2")
		{
			string rps2{ "" };
			cout << "\n\n\nYou proceed to walk towards the forrest ahead of you see another daunting creature.\n\nA Troll the size of a full grown tree is looking right at you holding a gigantic club.\n\nWhat do you do?\n1. Run to the cave\n2. Fight the troll\n";
			cout << "What do you choose to do? ";
			cin >> rps2;
			if (rps2 == "1")
			{
				cout << "\n\n\n\n\nYou run as fast as you can inside the cave, you see the fire lit inside more clearly now.\n\nYou hide behind a huge bolulder hoping the troll doesnt see you.\n\n";
				cout << "As the troll runs past, you notice there are two humans seeking refuge inside the cave. The troll runs straight towards them,\n\nthere is an injured man attempting to crawl away when the other is holding a luminous sword. The troll slams the club at the injured man\n\nwhilst kicking the other man into the cave wall killing them both.\n\n";
				cout << "You have just led these men to their deaths.\n\nThe luminous sword lands right next to you. You replace this with your original rusty bloody sword.\n\nYou rise from behind boulder and get ready to face the troll\n\n";
				//kills the 2 men insdie,, pick up sword fight troll,, rightwest or righteast decision
				i.removeItem(0);
				i.addItem(i.getdragonsword());
				t.setname("ARGOG the Bone Destroyer-- Troll Boss");
				cout << "Enemy stats:\n";
				t.enemytostring();
				cout << "Here are you battle moves:\n\n";
				do
				{
					int ans{};
					cout << "\n1. Aerondight sword attack\n2. Explosion Spell\n3. Attack Spell\n4. Parry\n";
					cin >> ans;
					switch (ans)
					{
					case 1: s.aerondightattack(t);
						break;
					case 2:
						s.explosion(t);
						break;
					case 3:
						s.attackspelll(t);
						break;
					case 4:
						t.trollparry(t, s);
						break;
					default:
					ault:
						if (cin.fail())//checker for anything other than an integer
						{
							cin.clear();//clears input
							cin.ignore(1000, '\n');//discards input to either 1000 characters or until a new 
							//line so the storage reference has no memory
							cout << "wrong input" << endl;
						}
						else
						{
							cout << "wrong input\n";
						}
						break;

					}
					//troll attack
					if (t.gethealth() <= 0)
					{
						t.enemySetHealthZero();
					}
					else
					{
						cout << "\n\n\t\t\tNOW ITS THE TROLLS TURN TO ATTACK\n\n";
						int x = 1;
						switch (x)
						{
						case 1:
							t.clubattack(s);
							break;
						default:
							t.clubattack(s);
							break;
						}

					}

				} while (((t.gethealth() > 0) && (s.gethealth() > 0)) || (enemydied() == false));

				if (s.gethealth() <= 0)
				{
					restart(s);
					s.sethealth(200);
				}
				if (t.gethealth() <= 0)
				{
					string westoreast2{ "" };
					cout << "\n\n\n\n\nThis victory was a very sore one as this was at the expense of the two men's lives hiding in the cave.\n\nYou have now acquired this new sword made of an interesting material. It was has a greater damage than your original sword\n\n";
					cout << "You gain 15xp from defeting the troll\n\n\n";
					s.incexp(15);
					s.levelup();
					s.tostring(s);
					cout << "You now leave the cave and head inside the forrest\n";
					cout << "Do you head East or West?\n1. East\n2. West\n";
					cin >> westoreast2;
					while (validChoice == false)
					{
						if (westoreast2 == "1")
						{
							eastpath(s, i);
							validChoice = true;
						}
						else if (westoreast2 == "2")
						{
							westpath(s, i);
							validChoice = true;
						}
						else
						{
							choiceRemove(westoreast2);
						}
					}

				}
			}
			else if (rps2 == "2")
			{
				cout << "\n\nYou lock eyes with the gigantic troll. He bashes the club of his head and starts charging at you\n\n";
				t.setname("ARGOG the Bone Destroyer-- Troll Boss");
				cout << "Enemy stats:\n";
				t.enemytostring();
				cout << "Here are you battle moves:\n\n";
				do
				{
					int ans{};
					cout << "\n1. Sword attack\n2. Explosion Spell\n3. Attack Spell\n4. Parry\n";
					cin >> ans;
					switch (ans)
					{
					case 1:
						s.attackenemy(t);
						break;
					case 2:
						s.explosion(t);
						break;
					case 3:
						s.attackspelll(t);
						break;
					case 4:
						t.trollparry(t, s);
						break;
					default:
						if (cin.fail())//checker for anything other than an integer
						{
							cin.clear();//clears input
							cin.ignore(1000, '\n');//discards input to either 1000 characters or until a new 
							//line so the storage reference has no memory
							cout << "wrong input" << endl;
						}
						else
						{
							cout << "wrong input\n";
						}
						break;

					}
					//enemy attack
					if (t.gethealth() <= 0)
					{
						t.enemySetHealthZero();
					}
					else
					{
						cout << "\n\n\t\t\tNOW ITS THE TROLLS TURN TO ATTACK\n\n";
						int x = 1;
						switch (x)
						{
						case 1:
							t.clubattack(s);
							break;
						default:
							t.clubattack(s);
							break;
						}
					}






				} while (((t.gethealth() > 0) && (s.gethealth() > 0)) || (enemydied() == false));

				if (s.gethealth() <= 0)
				{
					playerdies();
					restart(s);
				}
				if (t.gethealth() <= 0)
				{
					cout << "\n\nThe troll falls backwards with a massive BANG.\n\n";
					cout << "You gain 15xp from this battle\n\n";
					cout << "The bang has alerted a herd of goblins all of which are running straight towards you.\n\nYou run as fast as you can but a bow hits you right in the leg, you fall over and look backwards.\n\nJust as you turn around you a bow hits you in the face.\n\n";
					playerdies();
				}


			}
			else
			{
				choiceRemove(rps2);
			}

		}
		else
		{
			choiceRemove(rps1);
		}
	}
}

void Game::eastpath(character s, Inventory i)
{
	dragon d;
	troll t;
	mutant m;

	while ((this->playing == true) && (this->dead == false))
	{
		cout << "\nYou start walking East in hope to find this ship. The deeper you walk in the forrest the darker and more mysterious\n\n it gets, you cautiously walk both sword and wand in hand ready for any unexpected visitors.\n\nYou start to see the remains of broken trees, the ship must've crashed here it can't be too far from here.\n\n";
		cout << "As soon as you walk past the first broken trees ahead of you you can see what looks like a troll fighting a mutant,\n\nyou listen as you are amazed that you can make up what they are saying.\n\n'You are not allowed to enter here' roars the troll as he pushed the mutant out the way.\n\n'This land belongs to King Drug, he took down the ship and it is his now understood.\n\nIf you go anywhere near the ship I will kill you or even better King Drug will burn you alive'\n\n";
		cout << "The mutant is responce to that says\n\n'I've seen lots of tasty juicy humans walk into the forrest there must be more here! UGH never thought I'd be taking orders from\n\na fat troll.But fine I'll leave but I'll be back!'\n\n";
		cout << "Just like that the mutant starts running away.\n\nWhat do you do?\n1. Get the mutant and interogate him on what he knows?\n2. Kill the troll\n";
		string firstdec{ "" };
		cin >> firstdec;
		if (firstdec == "1")
		{
			cout << "\n\nYou catch up to the mutant and in doing so you step on a twig and it breaks, the mutant turns around and faces you.\n\nThe mutant licks his lips before getting on all fours and charges at you.\n\nYou get ready to fight\n\n";
			m.setname("Scaleface the mutant");
			m.enemytostring();
			cout << "Here are your battle moves\n\n";
			do
			{
				int ans{};
				cout << "1. Arondight sword attack\n2. Explosion Spell\n3. Attack Spell\n4. Parry\n\n";
				cout << "Choose you fate warrior: ";
				cin >> ans;
				switch (ans)
				{
				case 1:
					s.aerondightattack(m);
					break;
				case 2:
					s.explosion(m);
					break;
				case 3:
					s.attackspelll(m);
					break;
				case 4:
					m.mutantparry(m, s);
					break;
				default:
					if (cin.fail())//checker for anything other than an integer
					{
						cin.clear();//clears input
						cin.ignore(1000, '\n');//discards input to either 1000 characters or until a new 
						//line so the storage reference has no memory
						cout << "wrong input" << endl;
					}
					else
					{
						cout << "wrong input\n";
					}
					break;
				}
				//enemy attack
				if (m.gethealth() <= 0)
				{
					m.enemySetHealthZero();
				}
				else
				{

					cout << "\n\n\t\t\t\tNOW ITS THE MUTANTS TURN TO ATTACK\n\n";
					int x = rand() % 2 + 1;
					switch (x)
					{
					case 1:
						m.smash(s);
						break;
					case 2:
						m.acid(s);
						break;
					default:
						m.smash(s);
						break;
					}
				}


			} while (((m.gethealth() > 0) && (s.gethealth() > 0)) || (enemydied() == false));

			if (s.gethealth() <= 0)
			{
				playerdies();
			}
			if (m.gethealth() <= 0)
			{
				cout << "\n\nCongradulations you have defaeated the mutant, you have gained 20xp from this fight.\n\n";
				s.incexp(20);
				s.levelup();
				cout << "You strike down the mutant and pin him down ready to interrogate and extract some useful information.\n\n'Listen to me I know you can understand me. Tell me all you know about the wreckage and of King Drug'\n\nyou say this whilst pressing your sword on its throat\n\n";
				cout << "'Okay Okay. King Drug protects this land he took out the ship as he thought it was an enemy.\n\nHe's now taken the ship as some sort of treasure and doesnt let anyone near it that all I know.'\n\nThe mutant proceeds to spit out a mouthful of blood on the floor.\n\n";
				cout << "You press the sword firmly on his neck drawing some blood and say 'How can I get there without that troll seeing me?'\n\n'Theres an entrance thats unguarded just up ahead you just need to jump a fence up ahead..... \n\nWait is that sword made of Aerondight. Do you plan on killing the king?'\n\n";
				cout << "'I need to protect myself by any means neccisary. I must go back home to my family.\n\n'";
				string dec2{ "" };
				cout << "What do you do\n1. Kill the mutant\n2. Let him free\n\n";
				cin >> dec2;
				if (dec2 == "1")
				{
					string dec3{ "" };
					cout << "With a final swing of your blade you behead the mutant watching its head roll away from his lifeless body.\n\nYou start walking towards the fence the mutant told you about and jump over it.\n\nA few minutes have passed and in the distance you see it.\n\n";
					cout << "You catch the first glimpse of the wreckage. But more strangly no sign of a dragon anywhere.\n\nYou walk closer and closer to the wreackage and see the entrance to the ship just ahead of you with a dragon tail lying just next to the entrance.\n\n";
					cout << "What do you do?\n1. Enter the ship\n2. Follow the tail to get to the dragon\n\n";
					cin >> dec3;
					if (dec3 == "1")
					{
						string dec4{ "" };
						cout << "You enter the ship carefully and notice a sign hanging from the roof saying 'Escape Pods' with an arrow indicating the direction.\n\nExcited you start jogging.\n\nTHERES NO ESCAPE PODS LEFT\n\nYou start to panic and are on the verge of tears until a large deep voice says\n\n'ARE YOU BY ANY CHANCE LOOKING FOR THIS SURVIVOR'\n\nyou look out the window to see two large red eyes starting right at you.\n\nITS THE DRAGON\n\nYou notice an escape pod gripped in its mouth\n\n";
						cout << "'WHO DARES ENTER MY LAIR, HOW DID YOU GET IN. COME OUT NOW TRESSPASSER AND FACE ME'\n\n";
						cout << "What do you do?\n1.Stay in the ship and hide\n2.Leave the escape pod\n";
						cin >> dec4;




						if (dec4 == "1")
						{
							cout << "You hide under a desk frightned. The voice bellows again\n\n'YOU COWARD, FINE ILL JUST KILL YOU NOW THEN'\n\nThe Dragon spits fire into the entrance of the ship and incinerates you\n\n";
							playerdies();

						}
						else if (dec4 == "2")
						{
							string dec5{ "" };
							cout << "\nTrembling you step outside the ship and see the dragon right ahead of you with the escape pod still in its mouth\n\n'YOU WANT THIS COME AND GET IT'\n\nThe dragon throws the pod on the ground lets out a thunderous roar\n\n";
							cout << "What do you do\n1. Run away\n2. Draw your Aerondight sword and get ready to fight the dragon\n";
							cin >> dec5;

							if (dec5 == "1")
							{
								cout << "\n\nYou start flapping you arms like a little girl and run away.\n\n The dragon flaps its wings hovering in the air and plunges towards you\n\nThe dragon dives and hits you with its tail squishing you like an ant\n\n";
								playerdies();
							}
							else if (dec5 == "2")
							{
								cout << "\n'YOU THINK YOU CAN KILL ME WITH THAT, IT'LL TAKE ALOT MORE THAN THAT TO KILL THE MIGHTY KING DRUG' he echoes through the forrest\n\n";
								d.setname("KING DRUG--- MEGA BOSS FIGHT");
								d.enemytostring();
								cout << "Here are your battle moves\n\n";
								do
								{
									int ans{};
									cout << "1. Aerondight Sword Attack\n2. Explosion Spell\n3. Attack Spell\n4. Parry\n\n ";
									cout << "Choose wisely warrior: ";
									cin >> ans;
									switch (ans)
									{
									case 1:
										s.dragonattack(d);
										break;
									case 2:
										s.explosion(d);
										break;
									case 3:
										s.attackspelll(d);
										break;
									case 4:
										d.dragonparry(d, s);
										break;
									default:
										if (cin.fail())//checker for anything other than an integer
										{
											cin.clear();//clears input
											cin.ignore(1000, '\n');//discards input to either 1000 characters or until a new 
											//line so the storage reference has no memory
											cout << "wrong input" << endl;
										}
										else
										{
											cout << "wrong input\n";
										}
										break;
									}
									//dragon attack
									if (d.gethealth() <= 0)
									{
										d.enemySetHealthZero();
									}
									else
									{
										cout << "\n\n\t\t\t\tNOW ITS THE KINGS TURN TO ATTACK\n\n";
										int x = rand() % 2 + 1;
										switch (x)
										{
										case 1:
											d.fireattack(s);
											break;
										case 2:
											d.tailattack(s);
											break;
										default:
											d.fireattack(s);
											break;
										}
									}

								} while (((d.gethealth() > 0) && (s.gethealth() > 0)) || (enemydied() == false));
								//this->validChoice=true;
								if (s.gethealth() <= 0)
								{
									playerdies();
								}
								if (d.gethealth() <= 0)
								{
									cout << "\n\nYou stab the dragon right in the heart with the Aerondight Sword\n\nThe dragon lets out a large roar then falls face first into the ground.\n\nYou gain 30exp by defeating the dragon\n\n";
									s.incexp(30);
									s.levelup();
									cout << "\n\nYOU HAVE DEFEATED THE DRAGON\n\nYou quickly run to the escape pod and get the system running, the display is all very advanced but you can make out where Jupiter is\n\non the display. You select this option and with a quick flash and a slight movement of the pod you leave this world.\n\n\n";
									cout << "\n\t\t\t\t\t\You arrive in Jupiter\n\nYou step outside your pod with a swarm of humans all around you whispering 'who is that?'.\nYou ignore all this and walk into the command centre in a rush 'Where is Commander Sky?' you cry hoping for a responce\n";
									cout << "You get stopped by a man wearing the commanders uniform but this isn't Commander Sky.\n'You must be confused Commander Sky has been retired now for over 50 years now' he say in a worried tone.\n";
									cout << "\n'No,No,No you must be confused I was with him yesterday, there was an error in the lab and I got timetravelled to a distant planet I've only just returned now.\n";
									cout << "The commander says in a very sad tone 'Sir can you please come to my office'. You follow him and both sit down,\n'I don't know how else to say this but I belive you were in the lab failure in 2050 where a portal opened.\n\n\t\t\t\t\tIt's now year 2100 you have been missing for 50 years!'\n\n";
									cout << "You get a hold of the phone and start calling family relatives to try and get a hold of your daughter\nwho will now be 60 years old. You speak to your ex wife who informed you that she died\nwhen she was 15 due to cancer without her Dad by her side.\nWhen hearing this news you are heartbroken and start breaking down in tears.\nFrom here on, you set a personal task until you die to find a way back to planet IO and destroy it!\n\n ";
									//the end make function for the ending
									//end game
									endgamecredits();

								}

							}
							else
							{
								choiceRemove(dec5);
							}


						}
						else
						{
							choiceRemove(dec4);
						}






					}
					else if (dec3 == "2")
					{
						string dec6{ "" };
						cout << "\nYou follow the end of the tail back to the body and notice that the dragon is sleeping right next to an escape pod!\n\nYou slowly creep forward and try figure a way to get to the escape pod without waking the dragon.\n\nWhislt in thought process the tail sweeps you off your feet, the dragon wakes up.\n\n'WHO DARES ENTER MY LAIR, SHOW YOURSELF COWARD' the dragon bellows in a booming voice.\n\n'OH THERE YOU ARE YOU LITTLE VERMIN, YOU WANT THIS POD COME GET IT' the dragon lets out a thunderous roar\n\n";
						cout << "What do you do\n1. Run away\n2. You draw your Aerondight sword and get ready to fight the dragon\n";
						cin >> dec6;

						if (dec6 == "1")
						{
							cout << "\n\nYou start flapping you arms like a little girl and run away.\n\n The dragon flaps its wings hovering in the air and plunges towards you.\n\nThe dragon incinerates you were you stand\n\n";
							playerdies();
						}

						else if (dec6 == "2")
						{
							cout << "\n'YOU THINK YOU CAN KILL ME WITH THAT, IT'LL TAKE ALOT MORE THAN THAT TO KILL THE MIGHTY KING DRUG' he echoes through the forrest\n\n";
							d.setname("KING DRUG--- MEGA BOSS FIGHT");
							d.enemytostring();
							cout << "Here are your battle moves\n\n";
							do
							{
								int ans{};
								cout << "1. Aerondight sword attack\n2. Explosion Spell\n3. Attack Spell\n4. Parry\n\n ";
								cout << "Choose wisely warrior: ";
								cin >> ans;
								switch (ans)
								{
								case 1:
									s.dragonattack(d);
									break;
								case 2:
									s.explosion(d);
									break;
								case 3:
									s.attackspelll(d);
									break;
								case 4:
									d.dragonparry(d, s);
									break;
								default:
									if (cin.fail())//checker for anything other than an integer
									{
										cin.clear();//clears input
										cin.ignore(1000, '\n');//discards input to either 1000 characters or until a new 
										//line so the storage reference has no memory
										cout << "wrong input" << endl;
									}
									else
									{
										cout << "wrong input\n";
									}
									break;
								}
								//dragon attack
								if (d.gethealth() <= 0)
								{
									d.enemySetHealthZero();
								}
								else
								{
									cout << "\n\n\t\t\t\tNOW ITS THE KINGS TURN TO ATTACK\n\n";
									int x = rand() % 2 + 1;
									switch (x)
									{
									case 1:
										d.fireattack(s);
										break;
									case 2:
										d.tailattack(s);
										break;
									default:
										d.fireattack(s);
										break;
									}
								}

							} while (((d.gethealth() > 0) && (s.gethealth() > 0)) || (enemydied() == false));
							//this->validChoice = true;
							if (s.gethealth() <= 0)
							{
								playerdies();
							}
							if (d.gethealth() <= 0)
							{
								cout << "\n\n\n The dragon lets out a large roar as you plunge your sword right into its heart.\n\nIt falls backwards and its tail hits the escape pod with a loud bang.";
								s.incexp(30);
								s.levelup();
								cout << "\n\nYOU HAVE DEFEATED THE DRAGON\n\nYou quickly run to the escape pod and push the dragons tail off the escape pod.\n\nIn the distance you can see two giant trolls running to your location\n\nYou enter the pod in a hurry and get the system working, the display is all very advanced but you can make out where Jupiter\n\nis on the display you select this option.\n\n";
								cout << "The display system reads\n\t\t\t\t\t\Not enough gas to reach this destination\n\nIn rage you start hitting the monitor, the trolls reach you location and start beating the pod with their clubs.\n\nThe glass breaks and you run out of all hope you just stand there unphased you manage to whisper before a troll pulls you out the pod and starts beating you\n\n\t\t\t\t\t\I'm so sorry Daisy, I love you'\n\n\n";
								endgamecredits();
							}


						}

						else
						{
							choiceRemove(dec6);
						}



					}
					else
					{
						choiceRemove(dec3);
					}




				}
				else if (dec2 == "2")
				{
					s.sethealth(300);
					//mutant screams you kill him troll comes you fight him,, dragon aware of you. 2nd scenerio
					cout << "\n\n'Go on get out of here' you say as you let him go.\n\n The injured mutant starts hobbling away as soon as he get far enough away from you it suddenly screams\n\n'HELP, HELP a human is trying to kill King Drug'\n\nOut of nowhere the troll that was guarding the entrance to the lair charges at you with his deadly club in hand\n\nAs he runs at you he hits the goblin smashing him into the tree\n\n";
					cout << "The troll lets out a furious roar, you pull out your sword ready to fight the troll\n\n";
					t.setname("AZOG THE GATEKEEPER-- Troll Boss");
					cout << "Enemy stats:\n";
					t.enemytostring();
					cout << "Here are you battle moves:\n\n";
					do
					{
						int ans{};
						cout << "\n1. Aerondight sword attack\n2. Explosion Spell\n3. Attack Spell\n4. Parry\n";
						cin >> ans;
						switch (ans)
						{
						case 1: s.aerondightattack(t);
							break;
						case 2:
							s.explosion(t);
							break;
						case 3:
							s.attackspelll(t);
							break;
						case 4:
							t.trollparry(t, s);
							break;
						default:
							if (cin.fail())//checker for anything other than an integer
							{
								cin.clear();//clears input
								cin.ignore(1000, '\n');//discards input to either 1000 characters or until a new 
								//line so the storage reference has no memory
								cout << "wrong input" << endl;
							}
							else
							{
								cout << "wrong input\n";
							}
							break;
						}

						//troll attack
						if (t.gethealth() <= 0)
						{
							t.enemySetHealthZero();
						}
						else
						{
							cout << "\n\n\t\t\tNOW ITS THE TROLLS TURN TO ATTACK\n\n";
							int x = 1;
							switch (x)
							{
							case 1:
								t.clubattack(s);
								break;
							default:
								t.clubattack(s);
								break;
							}

						}

					} while (((t.gethealth() > 0) && (s.gethealth() > 0)) || (enemydied() == false));
					if (s.gethealth() <= 0)
					{
						playerdies();
					}
					if (t.gethealth() <= 0)
					{
						cout << "\n\n\n\n\nYou hit AZOG with an explosion spell follwoed by a swift stab to the gut.\n\nWith this AZOG the gatekeeper falls to his knees then falls face first onto the ground.\n";
						cout << "You gain 20xp from defeting the troll\n\n\n";
						s.incexp(15);
						s.levelup();
						cout << "\nVictorious in this battle you walk towards the ship, you see the mutant the troll had hit against the tree, it is dead.\nYou walk through the gates that the troll was guarding and there in front of you lies the ship wreckage and right beside it\nthe dragon is standing up and staring right back at you with menacing eyes.\n\n";
						cout << "'YOU KILLED MY GATEKEEPER' bellows the dragon\n\n'BUT YOU WON'T KILL ME'\n\n";
						d.setname("KING DRUG--MEGA BOSS FIGHT");
						d.enemytostring();
						cout << "\n\nHere are your battle moves\n\n";
						do
						{
							int ans{};
							cout << "1. Aerondight Sword Attack\n2. Explosion Spell\n3. Attack Spell\n4. Parry\n\n";
							cout << "Choose wisely Warrior: ";
							cin >> ans;
							switch (ans)
							{
							case 1:
								s.dragonattack(d);
								break;
							case 2:
								s.explosion(d);
								break;
							case 3:
								s.attackspelll(d);
								break;
							case 4:
								d.dragonparry(d, s);
								break;
							default:

								if (cin.fail())//checker for anything other than an integer
								{
									cin.clear();//clears input
									cin.ignore(1000, '\n');//discards input to either 1000 characters or until a new 
									//line so the storage reference has no memory
									cout << "wrong input" << endl;
								}
								else
								{
									cout << "wrong input\n";
								}
								break;
							}
							//dragon attack
							if (d.gethealth() <= 0)
							{
								d.enemySetHealthZero();
							}
							else
							{

								cout << "\n\n\t\t\t\tNOW ITS THE KINGS TURN TO ATTACK\n\n";
								int x = rand() % 2 + 1;
								switch (x)
								{
								case 1:
									d.fireattack(s);
									break;
								case 2:
									d.tailattack(s);
									break;
								default:
									d.fireattack(s);
									break;
								}

							}

						} while (((d.gethealth() > 0) && (s.gethealth() > 0)) || (enemydied() == false));

						if (s.gethealth() <= 0)
						{
							playerdies();
						}
						if (d.gethealth() <= 0)
						{
							cout << "\n\n\nYou plunge the Aerondight sword right into the dragons heart\n\nIt lets out a large roar then falls face first into the ground.\n\n You gain 30exp by defeating the dragon\n\n\n";
							s.incexp(30);
							s.levelup();

							cout << "\n\nYou stab the dragon right in the heart with the Aerondight Sword\n\nThe dragon lets out a large roar then falls face first into the ground.\n\nYou gain 30exp by defeating the dragon\n\n";
							s.incexp(30);
							s.levelup();
							cout << "\n\nYOU HAVE DEFEATED THE DRAGON\n\nYou quickly run to the escape pod and get the system running, the display is all very advanced but you can make out where Jupiter is\n\non the display. You select this option and with a quick flash and a slight movement of the pod you leave this world.\n\n\n";
							cout << "\n\t\t\t\t\t\You arrive in Jupiter\n\nYou step outside your pod with a swarm of humans all around you whispering 'who is that?'.\nYou ignore all this and walk into the command centre in a rush 'Where is Commander Sky?' you cry hoping for a responce\n";
							cout << "You get stopped by a man wearing the commanders uniform but this isn't Commander Sky.\n'You must be confused Commander Sky has been retired now for over 50 years now' he say in a worried tone.\n";
							cout << "\n'No,No,No you must be confused I was with him yesterday, there was an error in the lab and I got timetravelled to a distant planet I've only just returned now.\n";
							cout << "The commander says in a very sad tone 'Sir can you please come to my office'. You follow him and both sit down,\n'I don't know how else to say this but I belive you were in the lab failure in 2050 where a portal opened.\n\n\t\t\t\t\tIt's now year 2100 you have been missing for 50 years!'\n\n";
							cout << "You get a hold of the phone and start calling family relatives to try and get a hold of your daughter\nwho will now be 60 years old. You speak to your ex wife who informed you that she died\nwhen she was 15 due to cancer without her Dad by her side.\nWhen hearing this news you are heartbroken and start breaking down in tears.\nFrom here on, you set a personal task until you die to find a way back to planet IO and destroy it!\n\n ";
							//the end make function for the ending
							//end game
							endgamecredits();

						}
					}
				}

				else
				{
					choiceRemove(dec2);
				}



			}


		}


		else if (firstdec == "2")
		{
			cout << "\n\nYou wait for the mutant to run away then you walk out of the darkness and face the troll.\n\nThe troll hit his club on the ground and lets out a thunderous roar. The roar echoed through the forrest.\n\n";
			t.setname("AZOG THE GATE KEEPER");
			t.enemytostring();
			cout << "\nHere are your battle moves\n\n";
			do
			{
				int ans{};
				cout << "1. Aerondight Sword Attack\n2. Explosion Spell\n3. Attack Spell\n4. Parry\n\n";
				cout << "Choose your fate Warrior: ";
				cin >> ans;
				switch (ans)
				{
				case 1:
					s.aerondightattack(t);
					break;
				case 2:
					s.explosion(t);
					break;
				case 3:
					s.attackspelll(t);
					break;
				case 4:
					t.trollparry(t, s);
					break;
				default:
					if (cin.fail())//checker for anything other than an integer
					{
						cin.clear();//clears input
						cin.ignore(1000, '\n');//discards input to either 1000 characters or until a new 
						//line so the storage reference has no memory
						cout << "wrong input" << endl;
					}
					else
					{
						cout << "wrong input\n";
					}
					break;
				}//enemy attack
				if (t.gethealth() <= 0)
				{
					t.enemySetHealthZero();
				}
				else
				{
					cout << "\n\n\t\t\tNOW ITS THE TROLLS TURN TO ATTACK\n\n";
					int x = 1;
					switch (x)
					{
					case 1:
						t.clubattack(s);
						break;
					default:
						t.clubattack(s);
						break;
					}
				}
			} while (((t.gethealth() > 0) && (s.gethealth() > 0)) || (enemydied() == false));
			if (s.gethealth() <= 0)
			{
				playerdies();
			}
			if (t.gethealth() <= 0)
			{
				cout << "\n\nAs you stand over the trolls dead body. The roar and the thud of the body hitting the ground had alerted both\n\nthe mutant from before as well as King Druk. The mutant jumps on your back and bites your neck, at the same time King Druk scortches\n\nyou with his fire breath.";
				playerdies();
			}



		}
		else
		{
			choiceRemove(firstdec);
		}

	}
	getplaying();
}





void Game::westpath(character s, Inventory i)
{
	//get lost,, go to end of forrest get frustrated,, 
	dragon d;
	troll t;
	mutant m;
	//level up therefore you reset health
	//you die
	while ((this->playing == true) && (this->dead == false))
	{
		string west1{ "" };
		cout << "\nYou start walking west into the forrest, you walk for hours and still no signs of any wreckage whatsoever.\n\nYou start getting frustrated but you need to carry on. Off into the distance you spot a group of 3 trolls walking in the forrest.\n\nMaybe they'll take you to the ship.\n\n";
		cout << "What do you do?\n1. Walk behind the trolls and see where they are going\n2. Don't follow them in case they spot you\n\n";
		cin >> west1;
		if (west1 == "1")
		{
			string west2{ "" };
			cout << "\n\nYou keep your distance but you still follow the trolls. You follow them for around 30 minutes until you see a gate\n\nthat is guarded by another troll. You move closer to hear what they are saying, one of the trolls say\n\n'Sup Azog do you know the King needs any more guards'\n\nThe guard troll responds,'The King only wants the best fighters not you pathetic trolls so walk on'\n\nOne of the other three trolls in excitment 'What are you even guarding in there is there treasure?'\n\n'No the King took down this ship and has now claimed it, now get lost or I'll kill all of you'\n\nAzog slings his club over his shoulder whilst taking a step forward making them all move.\n\n";
			cout << "The three trolls leave and you stay hidden\n\nThey mentioned that Azog is guarding the shipwreck for the King. The only issue is that the entrance is guarded.\n\n";
			cout << "What do you do?\n1. Find another way around the troll\n2. Fight the troll\n\n";
			cin >> west2;
			if (west2 == "1")
			{
				string west3{ "" };
				cout << "\nYou decide to walk around the area and try find an entrance. You see a fence that is unguarded\n\nyou hop the fence and can see in the distance the shipwreck. You start walking cautiously both sword and wand in hand towards the ship.You see the entrance just ahead of you.\n\n";
				cout << "You walk inside the ship and follow the directions pointing to 'Escape Pods'.\n\nYou look around and you notice there is one pod left but first you need to power the ship to lanuch it.\n\nYou walk to the command centre of the ship and turn the power on.\n\nMoments after starting the ignition a very loud deep voice bellows\n\n'WHO DARES ENTER MY SHIP, SHOW YOURSELF COWARD'\n\n";
				cout << "You hide under a desk and look outside the command centres wide windows for a sign of where the voice is coming from.\n\nTwo very large menacing eyes are staring right at you and the dragon says\n\n'HOW DARE YOU COME IN HERE AND TRY TAKE MY SHIP. IT IS MINE. COME OUT AND FACE ME HUMAN'\n\n";
				cout << "What do you do?\n1. Make a run for the escape pod\n2. Fight the dragon\n\n";
				cin >> west3;
				if (west3 == "1")
				{
					cout << "You make a run for the escape pod.\n\nYou can hear the dragon move and laugh it says\n\n'OH WE LOVE A RUNNER. IT MAKES THE KILL SO MUCH MORE EXCITING!'\n\nYou enter the escape pod and quickly select the planet Jupiter. The escape pod is flung upwards and you can feel the thursters powering you into the sky.\n\n'I've done it I've escaped'\n\nyou say with a sigh of releif and you sit down.\n\nBANG\n\n'YOU DIDNT LEAVE WITHOUT SAYING GOOD BYE' the dragon screams\n\nThe dragon starts biting the escape pod and you are squished\n\n";
					playerdies();
				}
				else if (west3 == "2")
				{
					cout << "\n\nYou draw your Aerondight sword, step outside the ship and get ready to fight the dragon\n\n";
					cout << "'YOU THINK YOU CAN KILL ME WITH THAT, IT'LL TAKE ALOT MORE THAN THAT TO KILL THE MIGHTY KING DRUG' it echoes followed by a loud roar\n\n";
					d.setname("KING DRUG--- MEGA BOSS FIGHT");
					d.enemytostring();
					cout << "Here are your battle moves\n\n";
					do
					{
						int ans{};
						cout << "1. Aerondight sword attack\n2. Explosion Spell\n3. Attack Spell\n4. Parry\n\n ";
						cout << "Choose wisely warrior: ";
						cin >> ans;
						switch (ans)
						{
						case 1:
							s.dragonattack(d);
							break;
						case 2:
							s.explosion(d);
							break;
						case 3:
							s.attackspelll(d);
							break;
						case 4:
							d.dragonparry(d, s);
							break;
						default:
							if (cin.fail())//checker for anything other than an integer
							{
								cin.clear();//clears input
								cin.ignore(1000, '\n');//discards input to either 1000 characters or until a new 
								//line so the storage reference has no memory
								cout << "wrong input" << endl;
							}
							else
							{
								cout << "wrong input\n";
							}
							break;
						}
						//dragon attack
						if (d.gethealth() <= 0)
						{
							d.enemySetHealthZero();
						}
						else
						{
							cout << "\n\n\t\t\t\tNOW ITS THE KINGS TURN TO ATTACK\n\n";
							int x = rand() % 2 + 1;
							switch (x)
							{
							case 1:
								d.fireattack(s);
								break;
							case 2:
								d.tailattack(s);
								break;
							default:
								d.fireattack(s);
								break;
							}
						}

					} while (((d.gethealth() > 0) && (s.gethealth() > 0)) || (enemydied() == false));
					//this->validChoice=true;
					if (s.gethealth() <= 0)
					{
						playerdies();
					}
					if (d.gethealth() <= 0)
					{
						cout << "\n\nYou stab the dragon right in the heart with the Aerondight Sword\n\nThe dragon lets out a large roar then falls face first into the ground.\n\nYou gain 30exp by defeating the dragon\n\n";
						s.incexp(30);
						s.levelup();
						cout << "\n\nYOU HAVE DEFEATED THE DRAGON\n\nYou quickly run to the escape pod and get the system running, the display is all very advanced but you can make out where Jupiter is\n\non the display. You select this option and with a quick flash and a slight movement of the pod you leave this world.\n\n\n";
						cout << "\n\t\t\t\t\t\You arrive in Jupiter\n\nYou step outside your pod with a swarm of humans all around you whispering 'who is that?'.\nYou ignore all this and walk into the command centre in a rush 'Where is Commander Sky?' you cry hoping for a responce\n";
						cout << "You get stopped by a man wearing the commanders uniform but this isn't Commander Sky.\n'You must be confused Commander Sky has been retired now for over 50 years now' he say in a worried tone.\n";
						cout << "\n'No,No,No you must be confused I was with him yesterday, there was an error in the lab and I got timetravelled to a distant planet I've only just returned now.\n";
						cout << "The commander says in a very sad tone 'Sir can you please come to my office'. You follow him and both sit down,\n'I don't know how else to say this but I belive you were in the lab failure in 2050 where a portal opened.\n\n\t\t\t\t\tIt's now year 2100 you have been missing for 50 years!'\n\n";
						cout << "You get a hold of the phone and start calling family relatives to try and get a hold of your daughter\nwho will now be 60 years old. You speak to your ex wife who informed you that she died\nwhen she was 15 due to cancer without her Dad by her side.\nWhen hearing this news you are heartbroken and start breaking down in tears.\nFrom here on, you set a personal task until you die to find a way back to planet IO and destroy it!\n\n ";
						//the end make function for the ending
						//end game
						endgamecredits();
					}
				}
				else
				{
					choiceRemove(west3);
				}
			}
			else if (west2 == "2")
			{
				cout << "You step away from the darkness so that the troll can see you.\n'And what do we have here'\nThe troll then lets out a furious roar, you pull out your sword and get ready to fight the troll";
				t.setname("AZOG THE GATE KEEPER");
				t.enemytostring();
				cout << "\nHere are your battle moves\n\n";
				do
				{
					int ans{};
					cout << "1. Aerondight Sword Attack\n2. Explosion Spell\n 3. Attack Spell\n4. Parry\n\n";
					cout << "Choose your fate Warrior: ";
					cin >> ans;
					switch (ans)
					{
					case 1:
						s.aerondightattack(t);
						break;
					case 2:
						s.explosion(t);
						break;
					case 3:
						s.attackspelll(t);
						break;
					case 4:
						t.trollparry(t, s);
						break;
					default:
						if (cin.fail())//checker for anything other than an integer
						{
							cin.clear();//clears input
							cin.ignore(1000, '\n');//discards input to either 1000 characters or until a new 
							//line so the storage reference has no memory
							cout << "wrong input" << endl;
						}
						else
						{
							cout << "wrong input\n";
						}
						break;
					}//enemy attack
					if (t.gethealth() <= 0)
					{
						t.enemySetHealthZero();
					}
					else
					{
						cout << "\n\n\t\t\tNOW ITS THE TROLLS TURN TO ATTACK\n\n";
						int x = 1;
						switch (x)
						{
						case 1:
							t.clubattack(s);
							break;
						default:
							t.clubattack(s);
							break;
						}
					}
				} while (((t.gethealth() > 0) && (s.gethealth() > 0)) || (enemydied() == false));
				if (s.gethealth() <= 0)
				{
					playerdies();
				}
				if (t.gethealth() <= 0)
				{
					cout << "\n\nAs you stand over the trolls dead body. The roar and the thud of the body hitting the ground has alerted the three trolls that were walking away. They all charge at you and you try to run away, you start running away from the trolls and find yourself at the edge of a cliff. You look down and there is a massive drop, theres no way you can surive this if you jumped. You stand still thinking about what you are going to do but the trolls have finally caught up to you. The three trolls pick you up and pull your limbs apart in a gruesome manner. \n\n ";
					playerdies();
				}
			}
			else
			{
				choiceRemove(west2);
			}



		}
		else if (west1 == "2")
		{
			cout << "\n\nYou decide to walk your own seperate path to avoid any trouble.\n\nYou continue to stay vigilant just in case there are some unexpected visitors along the way. You continue to walk in this direction until you reach the end of the forrest .You haven't eaten and drank for days, you are extremely dehydrated.\n'Maybe I just went the wrong way' you mumbled to yourself\n";
			cout << "It's getting late now you find shelter and sleep until the morning.\n\n'Well,Well,Well look what we have found here boys'\n\nYou wake up and sit up instantly you are cornered by a group of goblins. You try to run away but one of the goblins launches an arrow at your leg, you fall to the ground and start screaming in pain. \n\nA goblin jumps on you pinning you down with a dagger in his hand.\n\n'Shhhhh no need to scream it'll all be over very soon'\n\nThe goblins slits your throat.";
			playerdies();
		}
		else
		{
			choiceRemove(west1);
		}


	}
	getplaying();
}












