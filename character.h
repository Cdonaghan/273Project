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
	void parry(enemy x);
	//different enemies inherit but alter inside chance decreases
	void explosion();
	void attackspelll();
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
};

