void Game::rightPath(character s, Inventory i)
{
	while ((this->playing == true) && (this->dead == false))
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
				cout << "congratulations warrior you defeted the goblin\n" << endl;
				cout << "you gain 1 xp from defeating the goblin\n";
				cout << "you search the goblins lifless body for any items and find a wand and 2 healing potions!\n";
				cout << "you pick them both up up as it may come in handy at some point as you know some useful spells.\n";
				s.incexp(1);
				s.levelup();
				i.addItem(i.getwand());
				i.addItem(i.getPotion());
				i.addItem(i.getPotion());
				displayinv(s, i);
				this->validChoice = true;
				cout << "\n\n\n\nYou rescue the hostage but he is seriously bleeding out.\n";
				cout << "He very weakly said his name is 'Commander Salamander' and he escaped his ship as it got attacked by a dragon.";
				cout << " Before passing away he reaches into his jacket and pulls out a projector.\n";
				cout << "You take it from his lifeless body and it suddenly lights up projecting the commander with another man. There are loud sirens in the background to where he proceedes to speak very frantically with a great sense of urgency.\n ";
				cout << "'Mayday Mayday Mayday this is Commander Salamander and Lutenent Garcia here our ship is reaching critical damage is there anyone out there??'\n";
				cout << "A loud bang thorws them both to the floor shortly followed by a thunderous roar\n";
				cout << "He stands up again insantly and proceeds to say with more urgency\n\t\t\t\t\ 'The ship is going down a dragon I repeat A FIREBREATHING DRAGON has attacked and intercepted this mission. The crew have now escaped via escape pods with 2 more for myself and Lutenet Garcia we are sending this message out to warn anyone in the area this world is not saf.... ' ";
				cout << "\nBefore he could finish a large claw enters breaks the ship window and pierces the Lutenent Garcia in the chest and is sent dragged out of the ship window.\n";
				cout << "Oh Shit Garcia is dead. I'll keep this short. This ship is projected to crash in a few minutes and I need to escape. The ship and all this cargo is going to crash in the forrest. If there are any survivors meet there\n\n And just like that the projection ended.\n";
				cout << "If you find this forrest and locate the ship you can use the remaining escape pod to leave this world and go back to your family, you step outside the escape pod and go in search of the lost ship.\n ";
				this->validChoice = true;
				getplaying();
			}
		}

		else if (userchoice2 == "2")
		{
			mutant p;
			cout << "You ignore the hostage and continue walking to explore the rest of the pod. You come across a chest and look inside, theres a wand and a scroll. You take the wand as you know a few powerful spells which will come in very handy.\n";
			cout << "The scroll reads.\n\t\t'My Ship got attacked by a dragon and I have just escaped through this escape pod,\n\t\t\t\t\I'm not sure if Ill make it out alive but if anyone of my crew finds this meet in the forrest.\n\t\t\t\t\I have sent out a telegram to all my crew and we should all regroup there.\n\t\t\t\t\I'm not sure if Ill make it out alive but if anyone of my crew finds this meet in the forrest.\n\t\t\t\t\Commander Salamander'\n";
			i.addItem(i.getwand());
			i.addItem(i.getscroll());
			displayinv(s, i);
			cout << "If I find this ship it could help me escape this godforsaken world and use any remaining escape pods to go back home to my family. You take a step outside the pod and look around you for any sign of a forrest that the scroll mentioned. In the distance you hear disturbing growling and loud chewing very nearby. You walk cautiously ahead and see what is shaped like a human.\nExcited you start jogging towards the figure, maybe hes lost and looking for the forrest. The figure turns around hearing your footsteps, his face is covered in blood and in his hand is a half eaten leg. He gets down on all fours and starts running towards you\n. ";
			cout << "What do you do?\n1.Do you run back into the escape pod\n2.Fight the creature\n";
			int userchoice2323{};
			cin >> userchoice2323;
			if (userchoice2323 == 1)
			{
				cout << "You run back into the escape pod and slam the door shut behind you. AS you slam the door the goblin pounces on your back and pierces you through the chest with his sword.\n";
				restart(s);
			}
			else if (userchoice2323 == 2)
			{
				cout << "\n\n Now you have a wand and a sword you can change up your attack combinations";
				p.setname("Mutant");
				p.enemytostring();
				cout << "Here are your battle moves\n\n";
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
							p.smash();
							break;
						case 2:
							p.acid();
							break;
						default:
							p.smash();
							break;
						}
					}
				} while (((p.gethealth() > 0) && (s.gethealth() > 0)) || (enemydied() == false));
				this->validChoice = true;
				if (s.gethealth() <= 0)
				{
					restart(s);
				}
				if (p.gethealth() <= 0)
				{
					cout << "congratulations warrior you defeted the mutant\n" << endl;
					cout << "you gain 5 xp from defeating the mutant\n";
					cout << "you search the mutants lifless body to find 2 healing potions!\n";
					cout << "You walk on to find the crashed ship\n";
					//cout << "you search the goblins lifless body  2 healing potions!\n";
					//cout << "you pick them both up up as it may come in handy at some point as you know some useful spells.\n";
					s.incexp(5);
					s.levelup();
					displayinv(s, i);
					getplaying();
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
