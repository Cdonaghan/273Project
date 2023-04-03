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
		cout << "\nYou walk closer to the sign, the closer you get you notice that something is wrong, there is blood splattered on the sign with a big bloody handprint on it.\n";
		cout << "You walk a few more paces and see what is shaped like an escape pod ahead of you.\nIn excitment you starting running in hope of finding resources or even better a surivor. \n";
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
				displayinv(s, i);
				validChoice = true;

			}
			else if (userChoice1 == "2")
			{
				cout << "You panic and start screaming, the troll spots you instantly and lets out a horrible roar.\n It starts running to you and kills you with a deadly blow\n.";
				restart(s);// already aborts code
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
				cout << "With one last swing of the sword you take the goblins head clean off\nCongradulations Warrior you have defeated the Goblin" << endl;
				cout << "you gain 2 xp from defeating the goblin\n";
				cout << "you search the goblins lifless body for any items and find a wand and 2 healing potions!\n";
				cout << "you pick them both up up as it may come in handy at some point as you know some useful spells.\n";
				s.incexp(2);
				s.levelup();
				//s.setlevel(2);
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
				cout << "A loud bang thorws them both to the floor shortly followed by a thunderous roar,";
				cout << "He stands up again insantly and proceeds to say with more urgency.\n'The ship is going down a dragon I repeat A FIREBREATHING DRAGON has attacked and intercepted this mission. The crew have now escaped via escape pods with 2 more for myself and Lutenet Garcia we are sending this message out to warn anyone in the area this world is not saf.... '\n ";
				cout << "Before he could finish a large claw breaks the ship window and pierces the Lutenent Garcia in the chest and is dragged out of the ship window.\n";
				cout << "Oh Shit Garcia is dead. I'll keep this short I dont know how much time I have left. This ship is projected to crash in a few minutes and I need to escape. The ship and all this cargo is looking to crash in the forrest. If there are any survivors meet there\n\n And just like that the projection ended.\n\n";
				cout << "Still confused by this extremely advanced technology the only thought on your mind is surival and this meant finding this ship.\n Several unanswered questions enter you mind like:\nHow did I end up here?, does anyone know that I'm here?, where is planet IO?, what are those creatures trying to kill me?\n With all these questions only thing that remains constant is that YOU NEED TO FIND THIS SHIP AND GET THE HELL OUT OF HERE\n"; 
				string continuestorychoice2 = { "" };
				validChoice = false;
				cout << "\n\nYou have completed the first part of the story, would you like to continue?\n";
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
			mutant p;
			cout << "You ignore the hostage and continue walking to explore the rest of the pod. You come across a chest and look inside, theres a wand and a scroll. You take the wand as you know a few powerful spells which will come in very handy.\n";
			cout << "The scroll reads.\n\t\t\t\t'My Ship got attacked by a dragon and I have just escaped through this escape pod,\n\t\t\t\t\I'm not sure if Ill make it out alive but if anyone of my crew finds this meet in the forrest.\n\t\t\t\t\I have sent out a telegram to all my crew and we should all regroup there.\n\t\t\t\t\I'm not sure if Ill make it out alive but if anyone of my crew finds this meet in the forrest.\n\t\t\t\t\Commander Salamander'\n";
			i.addItem(i.getwand());
			i.addItem(i.getscroll());
			displayinv(s, i);
			cout << "'If I find this ship it could help me escape this godforsaken world and use any remaining escape pods to go back home to my family'\n. You take a step outside the pod and look around you for any sign of a forrest that the scroll mentioned. In the distance you hear some disturbing growling. You walk cautiously ahead and see what is shaped like a human.\nExcited you start jogging towards the figure, maybe he's lost and looking for the forrest too. The figure turns around from hearing your footsteps, his mouth is covered in blood and in his hand is a half eaten leg. He gets down on all fours and starts running towards you\n. ";
			cout << "What do you do?\n1.Do you run back into the escape pod\n2.Fight the creature\n";
			int userchoice2323{};
			cin >> userchoice2323;
			if (userchoice2323 == 1)
			{
				cout << "You run back into the escape pod and slam the door shut behind you. As you slam the door the sound echoes through the escape pod, the goblin holding the human hostage pounces on your back and pierces you through the chest with his sword, killing you\n";
				restart(s);
			}
			else if (userchoice2323 == 2)
			{
				cout << "\n\n Now you have a wand and a sword you can change up your attack combinations\n";
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
					restart(s);
				}
				if (p.gethealth() <= 0)
				{
					cout << "The mutant cripples over as you hit him with a thunderous final blow, you have defeated it! \n" << endl;
					cout << "you gain 5 xp from defeating the mutant\n";
					cout << "you search the mutants body to find 2 healing potions!\n";
					cout << "Despite this victory the only thought going on in your head is to find the remains of this ship and escape this world.\nYou start debating if you are dreaming or if this is actually real\nThis isnt my lab, where am I?. Where is planet IO?. Does anyone know I'm here?. What were those creatures I saw trying to kill me?. Why does my watch say time unknown?. \nAll these questions reamin unanswered, but the only thing that reamins unchanged is that I NEED TO FIND THIS SHIP AND GET THE HELL OUT OF HERE\n";					i.addItem(i.getPotion());
					i.addItem(i.getPotion());
					s.incexp(5);
					s.levelup();	
					//s.setlevel(2);
					displayinv(s, i);
					string continuestorychoice = { "" };
					//validChoice = false;
					cout << "\n\nYou have completed the first part of the story, would you like to continue?\n";
					cout<< "note -- if not you will be asked to restart\n";
					cout << "1. Continue\n2. Restart\n";
					cin >> continuestorychoice;
					while (validChoice == false)
					{
						if (continuestorychoice == "1")
						{
							rightPathStory(s, i);
							//validChoice = true;
						}
						else if (continuestorychoice == "2")
						{
							restart(s);
							walkthrough();
							validChoice = true;
						}
						else
						{
							choiceRemove(continuestorychoice);
						}
					}
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
void Game::rightPathStory(character s, Inventory i)
{
	//memory saved
	//rest of story
	//start flash back to family
	//treks to find the ship
	// get to ship, need to fuel it uo
	// dragon hoards treasure,, keeping as triphy
	// all creatures serve him as he is king
	// aware of you and wants to kill you so u dont ursurp his rule
	// new sword to kill dragon,, aerondight
	//troll, goblin and final dragon fight guarding the ship
	// 
	//kill dragon,m go back to station,, contact and 50 years have passed
	//other ending stranded
	while ((this->playing == true) && (this->dead == false))
	{
		cout << "\n\t\t\t\t\t\Part 2\n\n";
		cout << "It's getting late. You constinue to wander into the distance but you can't see anything anymore. You decide to find some shelter and try get some sleep and set off in the morning again\n";
		cout << "The moment you rest your head you fall fast asleep\n\n\n";
		cout << "\t\t\t\t\t\Five Years Earlier\n\t\t\t\t\t\Kennedy Space Center, Florida\n\n";
		cout << "'Why do you have to go Daddy' says your 5 year old daughter\n 'I'll be back in a few months Daisy I promise. This is a really important project that Daddy has been selected for. This could change absoltely everything princess. You never know I could be famous when I get back and get you that puppy you always wanted' As you pinch her cheeks she giggles\n ";
		cout << "'Do you pinky promise?'\n You get down on your knees to get eye level with her.\n 'You know you can't break a pinky promise right?' with a little tear running down her cheek\nYou wipe the tear and say 'I pinky promise princess'\n\n ";

		cout << "\t\t\t\t\t\Five Later Earlier\n\t\t\t\t\t\Planet IO, Universe unknown\n\n";
		cout << "You wake up in a sweat and sit up in attempt to control your breathing. You must have been asleep for around a few hours as the sky is beginning to clear up. Impatient you get up and start walking towards the forrest. At the foot to the enterance of the forrest you notice a cave that seems to have a fire lit inside.\n";
		cout << "What do you do?\n1. Explore the cave\n2. Enter the forrest\n";
		string rps1{ "" };
		if (rps1 == "1")
		{
			cout << "You walk into the cave and notice bones scatterred all over the floor, the closer you get to the cackling fire in the distance you hear what sounds like two human voices conversing.\n'Hello is anyone here?' you say loudly.\n You hear in the distance 'Put the fire out you idiot something got into the cave!' another voice said with a very trembly voice 'Oh God. Oh God. Chris I can't even stand what if that thing follwed us back in here. We are so dead. Oh God'\nYou walk very cautiouly sword in one hand and the wand in another and there before your eyes are two humans. One is lying on the ground with what appears like a broken leg whilst the other is standing in front of him weilding a sword pointing straight at me. ";
			cout << "'Who are you?' says the man holding the sword.\n 'My name is " << s.getname() << "I won't hurt you I just saw the fire and looked to see if there were any surivors.I need help I have no idea where I am' you lower your weapons.\nThe man also lowers his sword 'I'm not sure of how much help we can be, Thomas over there broke his leg when our ship crashed in the forrest, I had to carry him to this cave with some of those awful creatures on our tail. We lost them and have been staying here overnight'\n\n";
			cout << "Wait did they mention the forrest!\n'I'm looking for that ship that crashed in the forrest, it could be my only way out of here. Where is it?' you say\n'I was hoping you wouldn't say that. I'll tell you what I'll tell you where it is if you give us your healing potions for my partner, deal?'\n";
			string yesorno{ "" };
			cout << "What do you do?\n1. Give him all your potions\n2. No I need them\n";
			if (yesorno == "1")
			{
				i.removeItem(2);
				displayinv(s, i);

				cout << "'God thank you so much " << s.getname() << " this should get Thomas up and running in a day or two. Okay just as promised you need to the ship wreckage you need to enter the forrest and head East and in a few hours of walkiing in this direction you should find it'.";
			}
			else if (yesorno == "2")
			{

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
		else if (rps1 == "2")
		{

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

		getplaying();
		//rest of story
		//start flash back to family
		//treks to find the ship
		// get to ship, need to fuel it uo
		// dragon hoards treasure,, keeping as triphy
		// all creatures serve him as he is king
		// aware of you and wants to kill you so u dont ursurp his rule
		// new sword to kill dragon,, aerondight
		//troll, goblin and final dragon fight guarding the ship
		// 
		//kill dragon,m go back to station,, contact and 50 years have passed
		//other ending stranded

		
		
	}
	//getplaying();	
}
