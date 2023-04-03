#pragma once
#include"enemy.h"
#include "character.h"
class goblin : public enemy
{
public:
	goblin();
	~goblin();

	//assign more attacks
	void bowattack(character& s);
	void daggerattack(character& s);
	void swordattack(character& s);
	void goblinparry(goblin& s, character& c);
protected:
	double bow_attack;
	double dagger_attack;
	double sword_attack;
	double goblindeflect;

};
class troll : public enemy
{
public:
	troll();
	~troll();

	///more attacks
	void clubattack(character s);
	void trollparry(troll& s, character c);

protected:
	double club_attack;
	double trolldeflect;

};
class mutant : public enemy
{
public:
	mutant();
	~mutant();

	//assign more attacks
	void smash();
	void acid();
	void mutantparry(mutant& s, character c);
protected:
	double smashattack;
	double acidattack;
	double mutantdeflect;

};
class dragon : public enemy
{
public:
	dragon();
	~dragon();

	//assign more attacks
	void fireattack();
	void tailattack();
	void dragonparry(dragon& s, character c);

protected:
	double fire_attck;
	double tail_attck;
	double dragondeflect;

};