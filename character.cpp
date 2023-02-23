#include"character.h"
character::character()
{
	name = { "" };
	level = 0;
	exp = 0;
	health = 0;
	maxhealth = 200;

}
character::~character()
{

}
string character::getname() const
{
	return name;
}
void character::setname(string x)
{
	x = name;
}
int character::level()
{
	return level;
}
