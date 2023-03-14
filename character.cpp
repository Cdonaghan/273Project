#include"character.h"
#include"game.h"
#include "enemy.h"
#include "enemytype.h"
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
void character::attackenemy(enemy &x,double b)
{
		x.health -= b;
}
void character::goblinparry(goblin &s, character c) 
{ // rand function, while loop while health<50,, change attack
	//access specific class enemy with its attacks 
	//parry for each enemy, talked about constructor but having 
	//seperate enemy classes is more organised and specfic
	int x = rand() % (3 - 1 + 1) + 1;
	int chance = rand() % (100 - 1 + 1) + 1;
	if (chance <= s.deflect)//update even odd idea for big boss,, phase attack
	{
		cout << "deflected"<<endl;
	}
	else
	{
		switch (x)
		{
		case 1:
			s.bowattack;
			break;
		case 2:
<<<<<<< HEAD
			s.daggerattack; 
=======
			s.daggerattack;
>>>>>>> aa1bcd5811f14ad57fe6c03b46f4ebcba9ccaf3f
				break;
		case 3:
			s.swordattack;
			break;
		}
	}

				//c.gethealth = -s.attackcharacter;
		//recognise what enemy attack it is,, taken from health
}


void character::trollparry(troll &s, character c)
{
	//access specific class enemy with its attacks 
	//parry for each enemy, talked about constructor but having 
	//seperate enemy classes is more organised and specfic
	int x = rand() % (3 - 1 + 1) + 1;// create more troll attacks
	int chance = rand() % (100 - 1 + 1) + 1;
	if (chance <= s.deflect)//update even odd idea for big boss
	{
		cout << "deflected" << endl;
	}
	else
	{
		switch (x)
		{
		case 1:
		 s.clubattack;
			break;
		default:
			s.clubattack;
			break;
		}

	}
}
void character:: mutantparry(mutant& s, character c)
{
	//access specific class enemy with its attacks 
	//parry for each enemy, talked about constructor but having 
	//seperate enemy classes is more organised and specfic
	int x = rand() % 2 + 1;
	int chance = rand() % (100 - 1 + 1) + 1;
	if (chance <= s.deflect)//update even odd idea for big boss
	{
		cout << "deflected" << endl;
	}
	else
	{
		switch (x)
		{
		case 1:
			s.smash;
			break;
		case 2:
			s.acid;
			break;
		}

	}
}
void character::dragonparry(dragon& s, character c)
{
	//access specific class enemy with its attacks 
	//parry for each enemy, talked about constructor but having 
	//seperate enemy classes is more organised and specfic
	int x = rand() % 2 + 1;
	int chance = rand() % (100 - 1 + 1) + 1;
	if (chance <= s.deflect)//update even odd idea for big boss
	{
		cout << "deflected" << endl;
	}
	else
	{
		switch (x)
		{
		case 1:
			s.fireattack;
			break;
		case 2:
			s.tailattack;
			break;
		}

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
	cout << this->Weapon << endl;
}
void character::setWeapon(string x)
{
	x = weapon;
}
void character::getPotion()
{
	cout <<  this->potion << endl;
}
void character::setPotion(string x)
{
	x = potion;
}

