#include"enemytype.h"

goblin::goblin()
{
	this->name = { "" };
	this->level = 1;
	this->health = 200;
	this->bow_attack = 15;
	this->dagger_attack = 10;
	this->sword_attack = 25;
	this->goblindeflect = 10; //deflect chance for goblin
}

goblin::~goblin()
{

}
void goblin::bowattack(character& s)
{
	cout << "Goblin is using bow attack\n\n";
	attackcharacter(s, this->bow_attack);
}
void goblin::daggerattack(character& s)
{
	cout << "Goblin is using dagger attack\n\n";
	attackcharacter(s, this->dagger_attack);
}
void goblin::swordattack(character& s)
{
	cout << "Goblin is using sword attack\n\n";
	attackcharacter(s, this->sword_attack);
}

void goblin::goblinparry(goblin& s, character& c)
{
	//why he atack 2 times wen parry?
	int x = rand() % (3 - 1 + 1) + 1;
	int chance = rand() % (100 - 1 + 1) + 1;
	if (chance <= this->goblindeflect)
	{
		cout << "\t\t\t\t\you deflected the goblins attack" << endl;
	}
	/*else
	{
		switch (x)
		{
		case 1:
			s.bowattack(c);
			break;
		case 2:
			s.daggerattack(c);
			break;
		case 3:
			s.swordattack(c);
			break;
		}
	}*/
}


//---------------------------------------------------------------------

troll::troll()
{
	this->name = { "" };
	this->level = 5;
	this->health = 500;
	this->club_attack = 15;
	this->trolldeflect = 25;
}
troll::~troll()
{

}
void troll::clubattack()
{
	character s;
	attackcharacter(s, this->club_attack);
}
void troll::trollparry(troll& s, character c)
{
	int x = rand() % (3 - 1 + 1) + 1;// create more troll attacks
	int chance = rand() % (100 - 1 + 1) + 1;
	if (chance <= this->trolldeflect)
	{
		cout << "deflected" << endl;
	}
	else
	{
		switch (x)
		{
		case 1:
			s.clubattack();
			break;
		default:
			s.clubattack();
			break;
		}

	}
}

//------------------------------------------------------------------

mutant::mutant()
{
	this->name = { "" };
	this->level = 5;
	this->health = 500;
	this->smashattack = 15;
	this->acidattack = 45;
	this->mutantdeflect = 25;
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

void mutant::mutantparry(mutant& s, character c)
{
	int x = rand() % 2 + 1;
	int chance = rand() % (100 - 1 + 1) + 1;
	if (chance <= this->mutantdeflect)
	{
		cout << "deflected" << endl;
	}
	else
	{
		switch (x)
		{
		case 1:
			s.smash();
			break;
		case 2:
			s.acid();
			break;
		}

	}
}

//-------------------------------------------------------------------------

dragon::dragon()
{

	this->name = { "" };
	this->level = 5;
	this->health = 500;
	this->fire_attck = 15;
	this->tail_attck = 45;
	this->dragondeflect = 25;
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

void dragon::dragonparry(dragon& s, character c)
{
	int x = rand() % 2 + 1;
	int chance = rand() % (100 - 1 + 1) + 1;
	if (chance <= this->dragondeflect)
	{
		cout << "deflected" << endl;
	}
	else
	{
		switch (x)
		{
		case 1:
			s.fireattack();
			break;
		case 2:
			s.tailattack();
			break;
		}
	}
}


