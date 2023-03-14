#include"character.h"
#include"game.h"
#include "enemy.h"
#include "enemytype.h"
using namespace std;
character::character()
{
	this->name =  "" ;
	this->level = 1;
	this->exp = 1;
	//algorithm to level up and so that exp increases per level up
	this->expnext = pow(level, 3) + 1;
	this->health = 200;
	this->maxhealth = 20000;
	this-> sworddamage=50;
	this->explosionspell = 100;
	this->attackspell = 25;
	this->healingpotion = 25;
	
}
//destructor
character::~character()
{

}
  //getter and setter for name
string character::getname()
{
	return name;
}
void character::setname(string x)
{
	name=x;
}
//getter and setter for exp
double character::getexp()
{
	return exp;
}
void character::setexp(double x)
{
	x=exp;
}
//function to increase exp
void character::incexp(int x)
{
	exp += x;
}
//getter and setter for level
int character::getlevel()
{
	return level;
}
void character::setlevel(int x)
{
	level=x;
}
//function to display stats. will be called when command is given
void character::tostring()
{
	cout << "Name: " << this->name<<endl;
	cout << "Level: " << this->level<<endl;
	cout << "Experience points: " << this->exp << endl;
	cout << "Experience points needed for next level up: " << this->expnext << endl;
	cout << "Health: " << this->health << endl;
	cout << "Sword damage: " << this->sworddamage << endl;
	cout << "Explosion spell: " << this->explosionspell << endl;
	cout << "Attack spell: " << this->attackspell << endl;
	cout << "Healing potion heals character" << this->healingpotion << " per potion" << endl;
}
void character::levelup()
//if loop to see throughout game if exp>expnext
//for next level up once level inc
{
	if (exp >= expnext)
	{
		this->exp -= this->expnext;
		level++;
		expnext = pow(level, 3) +1;
		//for level 1 to show how levelling works to the audience
	}
}

//getter and setter for health
double character::gethealth()
{
	return health;
}
void character::sethealth(double x)
{
	x = health;
}

//max health param
double character:: maxihealth()
{
	return maxhealth;
}
void character::decreasehealth(double x)
{
	this->health -= x;
}
/*void character::attackenemy(goblin &x,double b)
{
		x.health -= b;
}*///fix this to every enemy type








void character::healingpot()
{
	health += healingpotion;
	if (health >= maxhealth)
	{
		health = maxhealth;
	}
}

//explosion spell
void character::explosion()
{
	character s;
	enemy c;
	c.attackcharacter(c,this->explosionspell);
	s.health -= 15;
}

//attack spell
void character::attackspelll()
{
	enemy c;
	c.attackcharacter(c, this->attackspell);
		
}
void character::getWeapon()
{
	cout << this->Weapon << endl;
}
void character::setWeapon(string x)
{
	x = this->Weapon;
}
void character::getPotion()
{
	cout <<  this->potion << endl;
}
void character::setPotion(string x)
{
	x = potion;
}

