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
			s.levelup(s);
			//displayinv(s,i);
			break;
		}


<<<<<<< HEAD
		cout << "\nthe small goblin falls to the floor and you go over to its lifeless structure\n";
		cout << "you search it for any item and find the dagger, you pick it up as it may come in handy at some point.\n";
		i.addItem(i.getdagger());
		cout << "\nyou notice the goblin is also carrying a scroll. You take the scroll from his belt and read it.\n";
		cout << "    TO WHOMSTEVER THIS MAY CONCERN\n" << endl;
		cout << "There is an escape pod on the top of the highest hill in the area, if you are reading this i hope you know this is a sign to make it to the top of the hill and get out of here" << endl;



		getplaying();
=======
       cout << "\n\n\n DARKNESS \n\n\n" << endl;
	   cout << "\nThe sun is shining, it is summer. The smell of freshly-cut grass is prominent as you walk out into the garden \n";
       cout << "\n'Let's play Catch!' Your daughter shouts from across the garden as she proceeds to launch a ball towards you \n";
	   cout << "\nIt doesn't go far although you habve a big cheesy ear-to-ear grin as you know it was her best attempt\n";
	   cout << "\nYou tell her what an excellent throw it was and she is a good girl as you throw it back to her\n";
	   cout << "\nYou must push through, even if the chances are slim of ever seeing your daughteragain\n";
       cout << "\nHer laugh is so loud and prominent. It is the last thing you hear before a big crash\n";
	   cout << "\n\nBOOM\n\n";
	   
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
						cout << "\n\n\t\t\t\tNOW ITS THE TROLL'S TURN TO ATTACK\n\n";

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
			s.incexp(10);
			s.levelup(s);
			//displayinv(s,i);
			
			
		}
		cout << "\nYou search the supermarket for food but cannot find any\n";
		cout << "\nOn the till desk you find two dark purple liquids in a goblet-like containers and another scroll\n";
		cout << "\nThe scroll Reads\n";
		cout << "\nFOR ANY SURVIVOR\n";
		cout << "\nI assume you have defeated any monsters on your path to collecting this scroll, even the troll guarding these items\n";
		cout << "\nYour path still beckons ahead, take these two healing potions for any battles along the way\n";
		cout << "\ngood luck survivor, the escape pod is waiting...\n";

		s.incHealingPot(s, 2);

		s.getHealPotNum();
		
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
>>>>>>> 0d2788a3b6fcd18020e77e7b0c54ab8633d1f82b
	}
cout << "you begin to make your way around the hill's circumference\n";
cout << "\noh no, you encounter another goblin\n";
cout << "what do you do?" << "\n1.Fight\n2.run\n";
goblin e;
validChoice = false;

<<<<<<< HEAD
	getplaying();
=======

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
			cout << "\nhe also has a healing pot\n";
			s.incHealingPot(s,1);
			s.incexp(1);
			s.levelup(s);
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


//continuing the left path

void Game::leftpathMutantFight(character s, Inventory i)
{
>>>>>>> 0d2788a3b6fcd18020e77e7b0c54ab8633d1f82b

displayinv(s,i);
cout << "\nYou enter through the gates\n";
cout << "\nThe gates slam shut behind you, between you and the base of the hill there is 100 yards, in the distance you see a massive creature\n";
cout << "\nProbably about 10 feet tall and 8 feet wide\n";
cout << "\nThe entity from a distance shouts\n";
cout << "\n\nWHO DARES ENTER MY CHAMBER OF DEATH\n\n";
cout << "\nYou cowar in fear, Then remember your daughter and how important it is you need to see her\n";
cout << "\nYou continue forward, holstering your sword and getting ready to fight to the death\n";

continueToNext(s,i);

cout << "\n'You have come to challenge me to this hill!!' Screams The entity\n";
cout << "\n As you get closer the entity resembles a big mutant with 4 arms!\n";
cout << "\nWhat is your name warrior!\n";
cout << "\nAHH YES " << s.getname() << "\n\nWHAT A FITTING NAME FOR A WARRIOR I AM EXCITED\n";
cout << "\nIT IS TIME FOR " << s.getname() << " TO FIGHT TO THE DEATHN\n";
cout << "\nAND DIE GRACEFULLY AT THE HANDS OF THE FOUR-ARMED MUTANT!\n";

while (s.getHealPotNum() > 0)
{
	healUp(s);
	s.checkHealingPots(s);
}

//------------------------------------------
//FIGHT TIME

mutant z;

validChoice = false;
cout << "\ndo you attack or let him devour you?\n";
cout << "\n1. Attack\n2. Die\n";

while (validChoice == false)
{
string choice7;
cin >> choice7;
if (choice7 == "1")
{

while (this->validChoice == false) {
			z.setname("AZERATH THE MIGHTY MUTANT");

			cout << "1. Attack" << endl;

			//cout << "Select '1' \n\n";
			
			cin >> choice;


			switch (choice)
			{
			case 1:
				//cout << "You challenge him and he squares up \n";
				cout << "Enemies stats: \n\n";
				z.enemytostring();
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
						s.attackenemy(z);
						break;
						
						case 2:
						s.daggerAttack(z);

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
					if (z.gethealth() <= 0)
					{
						z.enemySetHealthZero();
						//enemydied();
					}
					else {
						cout << "\n\n\t\t\t\tNOW ITS AZERATHS TURN TO ATTACK\n\n";

						int x = rand() % 2 + 1;
						switch (x)
						{
						case 1:
							z.acid(s);
							
							break;

							case 2:
							z.smash(s);
							break;

							

						} 

					}


				} while (((z.gethealth() > 0) && (s.gethealth() > 0)) || (enemydied() == false));
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

		if (z.gethealth() <= 0)
		{
			cout << "congratulations warrior you defeated Azerath!!!\n" << endl;
			cout << "you gain 30 xp\n";
			cout << "\nhe also has 4 healing pots for you to take on your journey up the hill.\n";
			s.incHealingPot(s,4);
			s.incexp(30);
			s.levelup(s);
			s.levelup(s);
			//displayinv(s,i);
			break;
		}
		validChoice = true; //to break the second loop
		
	}
validChoice = true; //to break the first loop
}
else if (choice7 == "2")
{
cout << "the mutant catches you and kills you" << endl;
restart(s);
leftpathStoryContd(s,i);
//validChoice = true;
} else 
{
choiceRemove(choice7);
}
}


getplaying();
}






