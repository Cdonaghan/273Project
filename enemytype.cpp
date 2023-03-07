#include"enemytype.h"
goblin::goblin()
{
	this->name = { "" };
	this->level = 1;
	this->health = 100;
	this->bow_attack = 15;
	this->dagger_attack = 10;
	this->sword_attack = 25;
	this->deflect = 10;
}
goblin::~goblin()
{

}
void goblin::bowattack()
{
	character s;
	attackcharacter(s, this->bow_attack);
}
void goblin::daggerattack()
{
	character s;
	attackcharacter(s, this->dagger_attack);
}
void goblin::swordattack()
{
	character s;
	attackcharacter(s, this->sword_attack);
}

//---------------------------------------------------------------------

troll::troll()
{
	this->name = { "" };
	this->level = 5;
	this->health = 500;
	this->club_attack = 15;
	this->deflect = 25;
}
troll::~troll()
{

}
void troll::clubattack()
{
	character s;
	attackcharacter(s, this->club_attack);
}

//------------------------------------------------------------------

mutant::mutant()
{
	this->name = { "" };
	this->level = 5;
	this->health = 500;
	this->smashattack = 15;
	this->acidattack = 45;
	this->deflect = 25;
}
mutant::~mutant()
{

}
void mutant::smash()
{
	character s;
	attackcharacter(s, this->smashattack);
}
void mutant::acid()
{
	character s;
	attackcharacter(s, this->acidattack);
}

//-------------------------------------------------------------------------

dragon::dragon()
{

	this->name = { "" };
	this->level = 5;
	this->health = 500;
	this->fire_attck = 15;
	this->tail_attck = 45;
	this->deflect = 25;
}
dragon::~dragon()
{

}
void dragon::fireattack()
{
	character s;
	attackcharacter(s, this->fire_attck);
}
void dragon::tailattack()
{
	character s;
	attackcharacter(s, this->tail_attck);
}

