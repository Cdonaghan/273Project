#include"game.h"
#include"character.h"
#include"inventory.h"
#include "enemytype.h"
#include<string>
#include<iostream>

using namespace std;

Game::Game()
{
	//choice = 0;
	playing = true;
}
Game::~Game() {}

bool Game::getplaying()
{
	//ends game loop
	cout << "come back again soon" << endl;
	//has abort because of the loop in walkthrough function. This is fine.
	abort();
	return this->playing = false;
	
}
bool Game::enemydied() { return true; }

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

//call string inside loop for any choice otherwise this will not work
void Game::choiceRemove(string x)
{ 
	 cin.fail();//checker for anything other than an integer
					//clears input
					cin.ignore(1000, '\n');//discards input to either 1000 characters or until a new 
					//line so the storage reference has no memory

					cout << "wrong input  -- please type the correct name for your weapon of choice -- " << x << endl;
					x.clear();
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

	string choice {""};
	cout << "what part of the storyline would you like to go to?\n";
	cout << "\n1: Start of Main Story" << endl;
	cout << "\n2: Left path" << endl;
	cout << "\n3: Right path" << endl;
//update for more sections of story
    cin >> choice;
	if (choice == "0")
	{
validChoice = true;
	}
	else if (choice == "1"){beginning(s,i);
		validChoice = true;
	}
	else if (choice == "2"){leftpath(s,i);
	validChoice = true;}
	else if (choice == "3"){rightPath(s,i);
	validChoice = true;}
	else {
		
	 choiceRemove(choice);
	}
	}

}

/*void Game::getUserName(character s, string r)
{
cout << "\n\nEnter characters name: ";
   
		 cin >> r;
		 
}*/

void Game::continueToNext(character s, Inventory i)
{
	 
	   validChoice = false;
	   cout << "would you like to continue?\n";
	   cout << "note -- if not you will be asked to restart\n";
	   cout << "1. Continue?\n" <<  "2. Restart?\n";
       
	   while (validChoice == false)
	   {
		string choice = {""};
		cin >> choice;
		if (choice == "1")
		{
			//leftPathStory(s,i);
			validChoice = true;
		} else if (choice == "2")
		{

			restart(s);
			walkthrough();
			validChoice = true;
		}
		else 
		{
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
	string names;
	Inventory i; //inventory declaration
	
    cout << "enter your name" << endl;
	cin >> names;
	s.setname(names);

	//while loop for conditions to run the game 
	while ((this->playing == true) && (this->dead == false))


		/* Brief

		full game runs within functions
		if player dies while loop ends

		*/
	
        
	{
		while (this->validChoice == false) {



			cout << "273 project: Text Based RPG Game" << "\n\n" << "created by Daniel Conaghan and Santiago Rivett Barragan" << "\n\n\n\n\n";

         
            
			cout << "\t\t\t\t\t\tRISE OF THE WARRIOR" << endl;
			cout << "\t\t\t\t\t\tMAIN MENU" << endl << endl;
			cout << "\t\t\t\t\t\t0: Exit" << endl;
			cout << "\t\t\t\t\t\t1: Start Game" << endl;
			cout << "\t\t\t\t\t\t2: Storyline "<< endl;

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

				storylineSelect(s,i);

				//display functions for certain storypoints here
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
		
		cout << "Welcome " << names << endl;
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
            /*//string choice2; 
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
			}*/
			
			

		}

		s.sethealth(200);

		displayinv(s, i);
		i.removeItem(0);
		cout << "note -- you will now notice you have levelled from 1 to 2!" << endl;
		cout << "note -- you will notice your battle stats, these will increase for when you level up when you enter the main body of the game!" << endl;
		cout << "levelling up can be done by defeating monsters as you go along your journey in this game" << endl;
		cout << "\n\nWalkthrough complete, Congulatations\n\n\n\n\n";
		cout << "context - in this world you play as a user of many weapons, including a wand for spells, a sword, bow and a dagger\n\n\n\n" << endl;



		
        beginning(s,i);
		
     getplaying();
	}

}

//---------------------------------------------------------------



void Game::beginning(character s, Inventory i)
{

	cout << "\n Beginnning of Main story \n";
	cout << "\nIN A OTHERWORLDIAN DIMENSION \n";
		cout << "\nWelcome to Io, a moon that orbits jupiter approximately 421700 km from its center." << endl;
		cout << "\nYou have been on a research project to investigate and manipulate the space-time continuum and ended up teleporting from Jupiter to Io " << endl;
		cout << "\nFor some reason as you have teleported, you have also found yourself approx 2431 years in the future." <<endl;
        cout << "\nAs you bring your head out the moondust, you notice that there are unrecognised beings being detected on your organism radar" << endl;
		cout << "\nyou look down at your watch to check if it is intact" <<endl;
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
			leftpath(s,i);
			getplaying();
			this->validChoice = true;
			
        } else if (userChoice == "right"){
			cout << "you have chosen the right path" << endl;
			rightPath(s,i);
			getplaying();
			this->validChoice = true;
			
		}else{
			cout <<"wrong input please try again" << endl;
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
		cout << "1.Pick up sword\n" << "2.Take your chances and run" << endl;


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
			else if (userChoice == "2") {
				cout << "You are detected by the goblin, he catches you as you run away and eats you" << endl;
				playerdies();
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
		validChoice = true;
		
	} // end of battle with first goblin, will tell storyline and build another function around the second fight 

        cout << "\nthe small goblin falls to the floor and you go over to its lifeless structure\n";
        cout << "you search it for any item and find the dagger, you pick it up as it may come in handy at some point.\n";
        i.addItem(i.getdagger());
        cout << "\nyou notice the goblin is also carrying a scroll. You take the scroll from his belt and read it.\n";
        cout << "\nTO WHOEVER THIS MAY CONCERN\n" << endl;
        cout << "There is an escape pod on the top of the tallest hill in the area.\n";
		cout << "if you are reading this i hope you know this is a sign to make it to the top of the hill and get out of here" << endl;
		cout << "you feel tired from all the chaos and lie down. You find yourself shutting your eyes and falling sound asleep" << endl;

       cout << "\n\n\n DARKNESS \n\n\n" << endl;
	   cout << "\nThe sun is shining, it is summer. The smell of freshly-cut grass is prominent as you walk out into the garden \n";
       cout << "\n'Let's play Catch!' Your daughter shouts from across the garden as she proceeds to launch a ball towards you \n";
	   cout << "\nIt doesn't go far although you habve a big cheesy ear-to-ear grin as you know it was her best attempt\n";
	   cout << "\nYou tell her what an excellent throw it was and she is a good girl as you throw it back to her\n";
	   cout << "\nYou must push through, even if the chances are slim of ever seeing your daughteragain\n";
       cout << "\nHer laugh is so loud and prominent. It is the last thing you hear before a big crash\n";
	   cout << "\n\nBOOM\n\n";
	   

	   /*string choice = {""};
	   validChoice = false;
	   cout << "would you like to continue?\n";
	   cout << "note -- if not you will be asked to restart\n";
	   cout << "1. Continue?\n" <<  "2. Restart?\n";
       cin >> choice;
	   while (validChoice == false)
	   {
		if (choice == "1")
		{
			leftPathStory(s,i);
			validChoice = true;
		} else if (choice == "2")
		{

			restart(s);
			walkthrough();
			validChoice = true;
		}
		else 
		{
          choiceRemove(choice);
		}

	   }*/
	   continueToNext(s,i);
	   leftPathStory(s,i);
	    getplaying();}



//---------------------------------------------
//Troll fight
void Game::leftPathStory(character s, Inventory i)
{
cout << "\nYou awake from the dream only to a massive meteor strike about 5 miles south\n";
cout << "\nThe force from the strike rippled through your body, almost enough to bring your feet off the ground\n";
cout << "\nYou look for the tallest hill in all directions, the tallest one should signal north.\n";
cout << "\nYou spot it and make your way towards it.\n";
cout << "\nSword and Dagger in hand, you make your way along the rubble surface of Io. Observing what looked like man made structure as you walk past\n";
cout << "\nOne in particular. Has the resemblance of a supermarket. You feel hungry. Do you enter?\n";


	   validChoice = false;
	   cout << "1. Enter the Supermarket\n" <<  "2. Continue\n";
       
	   while (validChoice == false)
	   {
		string choice3 = {" "};
		cin >> choice3;
		if (choice3 == "1")
		{
			
			
			validChoice = true;
		} else if (choice3 == "2")
		{
			
			 

			leftpathStoryContd(s,i);
			getplaying();
			validChoice = true;
		}
		else 
		{
          
					choiceRemove(choice3);
		}
	
	   }
	    
      cout << "\nYou open the crooked door, A big gust of wind hits as you are slammed back into the door\n";
	  cout << "\nYou look up to see what had happened and you notice a troll, standing to the left\n";
	  cout << "\nIt is holstering a club. Ready to charge at you.\n";
	  cout << "\nwhat do you do\n";

      
	   validChoice = false;
	   cout << "1. Fight the troll?\n" <<  "2. Take your chances and run\n";
       
	   while (validChoice == false)
	   {
		string choice4 = {""};
		cin >> choice4;
		if (choice4 == "1")
		{
			
			validChoice = true;
		} else if (choice4 == "2")
		{
            cout << "You dodge the Troll and jump out the smashed window and flee from the supermarket, towards the hill\n";
			leftpathStoryContd(s,i);
			validChoice = true;
		}
		else 
		{
          choiceRemove(choice4);
		}

	   }

       troll r;
	   validChoice = false;

	   while (this->validChoice == false) {
		int choice;
			r.setname("Zodd - Boss troll");
            cout << "\nPress 1 to attack\n";
			cout << "1. Attack" << endl;

			//cout << "Select '1' \n\n";
			cin >> choice;


			switch (choice)
			{
			case 1:
				//cout << "You challenge him and he squares up \n";
				cout << "Enemies stats: \n\n";
				r.enemytostring();
				cout << "Here are your select battle moves \n\n";

				do
				{

					int ans;
					cout << "\n1.Sword attack\n2.Dagger attack\n";
					cout << "Select to choose your fate: " << "\n\n";
					cin >> ans;
					switch (ans)
					{
					case 1:
						s.attackenemy(r);
						break;

						case 2:
						s.daggerAttack(r);

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
					if (r.gethealth() <= 0)
					{
						r.enemySetHealthZero();
						//enemydied();
					}
					else {
						cout << "\n\n\t\t\t\tNOW ITS THE GOBLIN'S TURN TO ATTACK\n\n";

						int x = 1;
						switch (x)
						{
						case 1:
							r.clubattack(s);
							break;

						}

					}


				} while (((r.gethealth() > 0) && (s.gethealth() > 0)) || (enemydied() == false));
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
			s.sethealth(200);
			validChoice = false;
		
		}

		if (r.gethealth() <= 0)
		{
			cout << "congratulations warrior you defeted "<< r.getname() << endl;
			cout << "you gain 2 xp\n";
			s.incexp(2);
			s.levelup();
			//displayinv(s,i);
			
			
		}
		cout << "\nYou search the supermarket for food but cannot find any\n";
		cout << "\nOn the till desk you find two dark purple liquids in a goblet-like containers and another scroll\n";
		cout << "\nThe scroll Reads\n";
		cout << "\nFOR ANY SURVIVOR\n";
		cout << "\nI assume you have defeated any monsters on your path to collecting this scroll, even the troll guarding these items\n";
		cout << "\nYour path still beckons ahead, take these two healing potions for any battles along the way\n";
		cout << "\ngood luck survivor, the escape pod is waiting...\n";
		
		 continueToNext(s,i);

	     leftpathStoryContd(s,i);

         getplaying();
		
		}

		
		
		
		//-----------------------------------------
		

void Game::leftpathStoryContd(character s, Inventory i)
{
	cout << "\nYou walk on past the supermarket towards the hill\n";
	cout << "\nIt is alot closer now, You can see a massive fence surrounding the hill\n";
	cout << "\nThere appears to be no way around it and you have to enter through the gates\n";
	cout << "\nwhat do you do?\n";
	cout << "\n1. Enter through the gates\n2. Look for another way\n";
	
	
	validChoice = false;
	
	while (validChoice == false)
	{
		string choice5 {""};
		cin >> choice5;
		if (choice5 == "1")
		{
         leftpathMutantFight(s,i);
		 
		 validChoice = true;
		}
		else if (choice5 == "2")
		{
          validChoice = true;
		}
		else 
		{
			choiceRemove(choice5);
		}
	}
cout << "you begin to make your way around the hill's circumference\n";
cout << "\noh no, you encounter another goblin\n";
cout << "what do you do?" << "\n1.Fight\n2.run\n";
goblin e;
validChoice = false;


while (validChoice == false)
{
string choice7;
cin >> choice7;
if (choice7 == "1")
{

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
						
						case 2:
						s.daggerAttack(e);

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
		validChoice = true; //to break the second loop
		
	}
validChoice = true; //to break the first loop
}
else if (choice7 == "2")
{
cout << "the goblin catches you and kills you" << endl;
restart(s);
leftpathStoryContd(s,i);
//validChoice = true;
} else 
{
choiceRemove(choice7);
}
}
cout << "\nyou circle the hill and find there is no other option but to enter through the gates\n";
continueToNext(s,i);
leftpathMutantFight(s,i);
getplaying();
}
void Game::leftpathMutantFight(character s, Inventory i)
{
cout << "welcome to the mutant fight\n";
displayinv(s,i);
getplaying();
}
 
//-------------------------------------------------------------------------
//right path

void Game::rightPath(character s, Inventory i)
{
	while ((this->playing == true) && (this->dead == false))
	{
		{while ((this->playing == true) && (this->dead == false))
	{
		//surivor,, notice escape pod look arund see a chest see weapon,, off to distance you see goblin after a ghirl you ntoice her hiding 
		//option 1.flee  2. attack

		//flee--> left path --> troll 
		//attack-->  kill --> she knows whwere the rest of the ship where escape pods from
		// guraded its guarded by a dragon through the forrest its dangerous 


		//---------------------------------------------------------------------
		cout << "\nYou walk closer to the sign, the closer you get you notice that something is wrong, there is blood splattered on the\n sign with a big bloody handprint on it.\n";
		cout << "You walk a few more paces and see what is shaped like an escape pod.\nIn excitment you starting running in hope of finding resources or even better a surivor. \n";
		cout << "ITS AN ESCAPE POD.\n" << "Out of nowhere you hear a piercing scream and hide behind some rubble. " << "The screaming suddenly stops with an errie crunch.\n";
		cout << "Right beside you in the rubble is a freshly cut arm torn clean off!!\n";
		cout << "You take a peak above the rubble to see what caused the screming\nITS A TROLL KILLING A HUMAN.\n";
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
				cout << "\nYou hide behind the rubble until the troll leaves and you start walking to the escape pod.";
				cout << " Inside you find a bloody sword on the ground,  you pick it up and start following a trail of blood on the floor.\n";
				cout << " You follow the trail and see that a golbin is holding an injured survivor hostage.\n ";
				validChoice = true;

			}
			else if (userChoice1 == "2")
			{
				cout << "You panic and start screaming, the troll spots you instantly and lets out a horrible roar.\n It starts running to you and kills you with a deadly blow\n.";
				playerdies(); // already aborts code
				//validChoice = true;

			}
			else {
				cout << "wrong input please try again" << endl;
				cin.fail();//checker for anything other than an integer
				//cin.clear();//clears input
				cin.ignore(1000, '\n');//discards input to either 1000 characters or until a new 
				//line so the storage reference has no memory

				cout << "wrong input  -- please type the correct input -- " << endl;
				userChoice1.clear();
			}
		}


		displayinv(s, i);
		goblin e;

		cout << "\nNow you have a sword in your inventory do you\n1. Fight the goblin\n2. Continue exploring the escape pod\n";

		string userchoice2{ "" };
		cout << "What do you do:";
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
				cout << "Select your move:";
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
						break;						
					}
				}
			} while (((e.gethealth() > 0) && (s.gethealth() > 0)) || (enemydied() == false));
			this->validChoice = true;
			break;

			if (s.gethealth() <= 0)
			{{ 
				playerdies();
				abort();
			}
			if (e.gethealth() <= 0)
			{
				cout << "congratulations warrior you defeted the goblin\n" << endl;
				cout << "you gain 1 xp from defeating the goblin\n";
				s.incexp(1);
				s.levelup();

			}
		}
		continueToNext(s,i);



			}			
	
		
		else if (userchoice2 == "2")
		{
			cout << "\nYou rescue the hostage but he is seriously bleeding out and doesnt have a lot of time left.\nHis name is 'Igor' and he escaped his ship using the escape pod as the ship got taken down by a dragon.\n Before passing away he says that beyond the forrest is the wreckage with a more escape pods from where I can escape.";
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

		}	
	}		
	

		getplaying();
}




/*
		else if (userchoice2 == "2")
		{
			cout << "\nYou rescue the hostage but he is seriously bleeding out and doesnt have a lot of time left.\nHis name is 'Igor' and he escaped his ship using the escape pod as the ship got taken down by a dragon.\n Before passing away he says that beyond the forrest is the wreckage with a more escape pods from where I can escape.";
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

		}*/

		getplaying();
	}




}












