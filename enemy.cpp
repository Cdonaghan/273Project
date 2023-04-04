#include "enemy.h"
#include"character.h"
enemy::enemy()
{
	this->name = " ";
	this->deflect = { 0 };
	this->health = { 0 };
	this->maxhealth = { 0 };
}
enemy::~enemy()
{

}
void enemy::setname(string x)
{
	name = x;
}

string enemy::getname()
{
return name;
}
void enemy::attackcharacter(character& x, double b)
//called through from enemytype 
//dialogue needed
{
	x.decreasehealth(x, b);
}
void enemy::enemytostring()
{
	cout << "\t\t\t\t\t\tEnemy Name: " << this->name << endl;
	cout << "\t\t\t\t\t\tEnemy Health: " << this->health << endl;
	cout << "\t\t\t\t\t\tEnemy Level: " << this->level << endl;
}
//inheritance

double enemy::getdeflect()
{
	return deflect;
}
void enemy::setdeflect(double x)
{
	deflect = x;
}

void enemy::enemySetHealthZero()
{
	this->health = 0;
}

