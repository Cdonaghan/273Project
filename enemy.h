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
	//void setenemyhealth(double x);


	//enemy and boss attacks
	void attackcharacter(character &x, double b);
protected:
	double enemyhealth;
	
};