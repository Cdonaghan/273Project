void Game::westpath(character s, Inventory i)
{
	
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

