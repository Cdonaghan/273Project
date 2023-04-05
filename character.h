#pragma once

//#include "enemy.h"

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
	void tostring(character s);//user can access player information

	string getname();
	void setname(string x);

	void getlevel();
	void setlevel(int x);
	double getexp();
	void setexp(double x);
	void incexp(int x);
	void levelup(character &s);

	double gethealth();
	void sethealth(double x);
    void getexpnext();
    void healingpot();
    void checkhealth();
    double maxihealth();
    void decreasehealth(character & s, double x);

	//battle methods
	void attackenemy(character& x);




	//different enemies inherit but alter inside chance decreases
	void explosion(character& bad);
	void attackspelll(character& bad);
    void daggerAttack(character &bad);
    // weapons

    //void getWeapon();
	//void setWeapon(string x);

	//potions

	//string getPotion();
	//void setPotion(string x);

//string setsword(string x); 
//void getsword();

void checkHealingPots(character& s);
void incHealingPot(character& s, int x);
int getHealPotNum();

//void attackenemy(character& x);
void aerondightattack(character& x);

void dragonattack(character& x);
//void checkhealth();	
void disphealth();

protected:
	string name;
	int level;
	double exp;
	double expnext;
	double health;
	double dragonsword;
	double maxhealth;
	double sworddamage;
	double explosionspell;
	double attackspell;
	double healingpotion;
	double daggerattack;
	double deflect = 80;
	int healingPotNum;
	/*string sword = { "Sword" };
	string bow = { "Bow" };
	string wand = { "Wand" };
	string potion = { "Potion" };
	string Weapon;*/

};

/*
BRIEF
will need to implement functions to set weapon user wants to equip
so ive built getters and setters and made string types to hold the name
user command to set weapon could be based on "equip sword" and setter will be called
this also helps for the inventory when creating a copy constructor.
*/





