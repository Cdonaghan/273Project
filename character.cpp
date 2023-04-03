#include"character.h"
#include"game.h"
#include "enemy.h"
#include "enemytype.h"
using namespace std;
character::character()
{
	this->name = "";
	this->level = 1;
	this->exp = 1;
	//algorithm to level up and so that exp increases per level up
	this->expnext = pow(level, 3) + 1;
	this->health = 200;
	this->maxhealth = 20000;
	this->sworddamage = 50;
	this->explosionspell = 100;
	this->attackspell = 25;
	this->healingpotion = 25;
	this->daggerattack = 15;

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
	name = x;
}
//getter and setter for exp
double character::getexp()
{
	return exp;
}
void character::setexp(double x)
{
	x = exp;
}
//function to increase exp
void character::incexp(int x)
{
	exp += x;
}
//getter and setter for level
void character::getlevel()
{
	cout << level;
}
void character::setlevel(int x)
{
	level = x;
}
//function to display stats. will be called when command is given
void character::tostring(character s)
{
	cout << "\t\t\t\t\t\tName: " << s.name << endl;
	cout << "\t\t\t\t\t\tLevel: " << s.level << endl;
	cout << "\t\t\t\t\t\tExperience points: " << s.exp << endl;
	cout << "\t\t\t\t\t\tExperience points needed for next level up: " << this->expnext << endl;
	cout << "\t\t\t\t\t\tHealth: " << s.health << endl << endl;
	cout << "\t\t\t\t\t\tBattle stats:\n";
	cout << "\t\t\t\t\t\tSword damage: " << s.sworddamage << endl;
	cout << "\t\t\t\t\t\tExplosion spell damage: " << s.explosionspell <<
		" using this potion will hurt you in the process" << endl;
	cout << "\t\t\t\t\t\tAttack spell damage: " << s.attackspell << endl;
	cout << "\t\t\t\t\t\tHealing potion: " << s.healingpotion << " per potion" << endl;
}
void character::levelup()
//if loop to see throughout game if exp>expnext
//for next level up once level inc
{
	if (exp >= expnext)
	{
		this->exp -= this->expnext;
		level++;
		expnext = pow(level, 3) + 1;
		//for level 1 to show how levelling works to the audience

		cout << "\nCongratulations, you have just levelled up\n";


	} else 
	{
		cout << "not enough xp to level yet!" << endl;

	}
}

//getter and setter for health
double character::gethealth()
{
	return health;
}
void character::sethealth(double x)
{
	health = x;
}

//max health param
double character::maxihealth()
{
	return maxhealth;
}
void character::decreasehealth(double x)
{
	health -= x;
	checkhealth();
	cout << "\t\t\OUCH\t\t\tYour health is: " << health << endl;
}
void character::attackenemy(character& x)
{
	x.health -= this->sworddamage;
	if (x.health <= 0)
				{
					x.health = 0;
					//enemydied();
				}
	cout << "\t\t\t\t\YOU HIT HIM!!\tEnemy health is: " << x.health << endl;
}
//explosion spell
void character::explosion(character& bad)
{
	bad.health -= this->explosionspell;
	this->health -= 15;
	checkhealth();
	cout << "\t\t\t\t\ EXPLOSION IS TOO POWERFUL IT HIT YOU TOO\tYour health is: " << this->health << endl;
	//c.attackcharacter(c, this->explosionspell);
	//s.health -= 15;
	if (bad.health <= 0)
				{
					bad.health = 0;
					//enemydied();
				}
		cout << "\t\t\t\t\ YOU HIT HIM!!\tEnemy health is: " << bad.health << endl;

	
}
//attack spell
void character::attackspelll(character& bad)
{
	bad.health -= this->attackspell;
	if (bad.health <= 0)
				{
					bad.health = 0;
					//enemydied();
				}
	cout << "\t\t\t\t\YOU HIT HIM!!\tEnemy health is: " << bad.health << endl << endl;
}

void character::daggerAttack(character& bad)
{
	bad.health -=this->daggerattack;
	if (bad.health <= 0)
				{
					bad.health = 0;
					//enemydied();
				}
	cout << "\t\t\t\t\YOU HIT HIM!!\tEnemy health is: " << bad.health << endl << endl;
}

//fix this to every enemy type
void character::healingpot()
{
	health += this->healingpotion;
	cout << "\t\t\t\t\t\tYour health is: " << health << endl << endl;


	if (health >= maxhealth)
	{
		health = maxhealth;
		cout << "\t\t\t\t\t\tYour health is " << maxhealth << endl;;
	}
}
/*void character::getWeapon()
{
	cout << this->Weapon << endl;
}
void character::setWeapon(string x)
{
	x = this->Weapon;
}
string character::getPotion()
{
	cout << this->potion << endl;
}
void character::setPotion(string x)
{
	x = potion;
}

string character::getsword()
{
return sword;
}

void character::setsword(string x)
{
	x = this->sword;
	
}*/


void character::checkhealth()
{
	if (health < 0){
health = 0;
	}
}

