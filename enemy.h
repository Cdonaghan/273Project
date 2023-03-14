#pragma once

#include"game.h"
#include "character.h"

class enemy : public character
{
public:
	enemy();
	~enemy();
	void setname(string x);
	void enemytostring();
	double getdeflect();
	void setdeflect(double x);
	//void setenemyhealth(double x);


	//enemy and boss attacks
	void attackcharacter(character &x, double b);



	
};
