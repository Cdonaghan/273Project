#pragma once
#include<string>
#include<iostream>
using namespace std;
class character
{
public:
	character();
	virtual ~character();
	string getname() const;
	void setname(string x);
	int level();
	double gethealth();
	void sethealth();
	void tostring();
	double maxhealth() const;
	int inchealth(int health, int x);
	int dechealth(int health, int x);
private:
	string name;
	int level;
	int exp;
	double health;
	double maxhealth;
	int xpos;
	int ypos;
};
