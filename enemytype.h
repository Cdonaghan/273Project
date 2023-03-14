#pragma once
#include"enemy.h"
#include "character.h"
class goblin : public enemy
{
	//attact attributes
	//health ect
public:
	goblin();
	~goblin();
	void bowattack();
	void daggerattack();
	void swordattack();
	 void goblinparry(goblin &s, character c );
protected:
	double bow_attack;
	double dagger_attack;
	double sword_attack; //only big goblins use sword
	double goblindeflect;

};
class troll : public enemy 
{
public:
	troll();
	~troll();
	void clubattack();
	void trollparry(troll &s, character c );

	///more attacks
protected:
	double club_attack;
	double trolldeflect;
	
};
class mutant : public enemy
{
	public:
	//assign attacks like before
	mutant();
	~mutant();
	void smash(); // he rapes the character violently
	void acid();
	void mutantparry(mutant& s, character c );
protected:
	double smashattack;
	double acidattack;
	double mutantdeflect;

};
class dragon : public enemy
{//repeat
	//dragon attacks
public:
	dragon();
	~dragon();
	void fireattack();
	void tailattack();
	void dragonparry(dragon& s, character c );
	//add more or less
	//add more enemy spells apart from inherited ones
protected:
	double fire_attck;
	double tail_attck;
	double dragondeflect;

};