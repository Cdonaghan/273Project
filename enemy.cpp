#include "enemy.h"
#include"character.h"
enemy::enemy() 
{
	this->name = { "" };
	this->deflect = { 0 };
	this->health = { 0 };
	this->maxhealth = { 0 };
}
enemy::~enemy()
{

}
void enemy::setname(string x)
{
	this->character::setname(name);
	x = this->name;
}
void enemy::attackcharacter(character &x, double b)
{

	//this->character::decreasehealth(b);
	x.decreasehealth(b);
	
}
void enemy::tostring()
{
	cout << "enemy name: " << this->name << endl;
	cout << "enemy health: " << this->health << endl;
	cout << "enemy level: " << this->level << endl;
}
//different per enemy therfore needs to be altered,, health too
//probs no need to add function as it will be inherited
//comment out for now
double enemy::getdeflect()
{
	return deflect;
}
void enemy::setdeflect(double x)
{
	deflect = x;
}
/*double enemy::gethealth()
{
	return health;
}
void enemy::sethealth(double x)
{
	x = health;
}

//max health param
double enemy::maxihealth()
{
	return maxhealth;
}
*/
/*void enemy::bowattack()
{
	this->health -= bow_attack;

}*/
