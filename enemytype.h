#pragma once
#include"enemy.h"
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
private:
	double bow_attack;
	double dagger_attack;
	double sword_attack; //only big goblins use sword

};
class troll : public enemy
{
public:
	troll();
	~troll();
	void clubattack();

	///more attacks
private:
	double club_attack;
};
class mutant : public enemy
{
	//assign attacks like before
	mutant();
	~mutant();
	void smash(); // he rapes the character violently
	void acid();
private:
	double smashattack;
	double acidattack;

};
class dragon : public enemy
{//repeat
	//dragon attacks

	dragon();
	~dragon();
	void fireattack();
	void tailattack();
	//add more or less
	//add more enemy spells apart from inherited ones
private:
	double fire_attck;
	double tail_attck;

};