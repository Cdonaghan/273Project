#pragma once
#include"character.h"
#include"game.h"
#include "enemy.h"
class enemy : public character
{
public:
	enemy();
	~enemy();
	void setname(string x);
	void tostring();
	double getdeflect();
	void setdeflect(double x);
	//enemy and boss attacks
	void attackcharacter(character& x, double b);

	//seperate classes with set vales
	//void bowattack();
	//void daggerattack();
	//void swordattack();

	//dragon attacks
	//double fireattack();
	//double tailattack();
	//add more or less
	//add more enemy spells apart from inherited ones
private:
	//string enemyname;
	//double enemyhealth;
	double bow_attack;
	double dagger_attack;
	double sword_attack;
	//double fire_attack;
	//double tail_attack;






};
