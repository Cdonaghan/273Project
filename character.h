#pragma once
#include"game.h"
#include"enemy.h"
#include<string>
#include<iostream>
#include<math.h>
#include<random>
using namespace std;
class character
{
	//do we need getters and setter if we initilize health ect.
public:
	character();
	~character();
	void tostring();//user can access player information

	string getname();
	void setname(string x);

	int getlevel();
	void setlevel(int x);
	double getexp();
	void setexp(double x);
	void incexp(int x);
	void levelup();

	double gethealth();
	void sethealth(double x);
	void healingpot();
	double maxihealth();
	void decreasehealth(double x);

	//battle methods
	void attackenemy(enemy &x,double b);
	//void attack(int x);
<<<<<<< HEAD
	void character::mutantparry(mutant& s, character c, int x);
    void character::trollparry(troll &s, character c, int x);
    void character::goblinparry(goblin &s, character c,int x);
    void character::dragonparry(dragon& s, character c, int x);


=======
	void goblinparry(goblin& s, character c, int x);
	void trollparry(troll& s, character c, int x);
	void mutantparry(mutant& s, character c, int x);
	void dragonparry(dragon& s, character c, int x);
>>>>>>> aa1bcd5811f14ad57fe6c03b46f4ebcba9ccaf3f
	//different enemies inherit but alter inside chance decreases
	void explosion();
	void attackspelll();
//weapons

void getWeapon();
void setWeapon(string x);

//potions

void getPotion();
void setPotion(string x);



protected:
	string name;
	int level;
	double exp;
	double expnext;
	double health;
	double maxhealth;
	double sworddamage;
	double explosionspell;
	double attackspell;
	double healingpotion;
	double deflect;
	string sword = {"Sword"};
	string bow = {"Bow"};
	string wand = {"Wand"}; 
	string potion = {"Potion"}; 
	string Weapon;
	
	};

/*
BRIEF
will need to implement functions to set weapon user wants to equip
so ive built getters and setters and made string types to hold the name 
user command to set weapon could be based on "equip sword" and setter will be called 
this also helps for the inventory when creating a copy constructor.
*/





