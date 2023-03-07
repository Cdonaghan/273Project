#include"character.h"
#include"game.h"
#include "enemy.h"

character::character()
{
	this->name = { "" };
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
	this->deflect = 80;
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
void character::attackenemy(enemy &x,double b)
{
		x.health -= b;
}
void character::parry(enemy &s, character c )
{
	

	int chance = rand() % (100 - 1 + 1) + 1;
	if (chance <= this->deflect)//update even odd idea for big boss
	{
		cout << "deflected"<<endl;
	}
	else
	{
		c.gethealth = -s.attackcharacter;
		//recognise what enemy attack it is,, taken from health
		//attackcharacter(character &c,'input function to parry')
		//attack(sworddamage,, wait till created enemy class)
	}
}

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
	enemy c;
	attackenemy(c,this->explosionspell);
	health -= 15;
}

//attack spell
void character::attackspelll()
{
	enemy c;
	for (int i = 0; i < 2; i++)
	{
		attackenemy(c, this->attackspell);
		if (i == 2)
		{
			break;
		}
	}
}
void character::getWeapon()
{
	return this->Weapon;
}
void character::setWeapon(string x)
{
	x = weapon;
}
void character::getPotion()
{
	return this->potion;
}
void character::setPotion(string x)
{
	x = potion;
}

