#include "inventory.h"
/*
//constructor
inventory::inventory(){}

//destructor
inventory::~inventory(){}


BRIEF:
getter and setter functions
subject to change 
will discuss further aboput usefulness and if more efficient functions 
can be called for beter use

//getter and setter for weapon
void inventory::addWeapon(){}

void inventory::setWeapon(){}

//getter and setter for potions
void inventory::addPotion(){}

void inventory::setPotion(){}

//getter and setter for scroll
void inventory::addscroll(){}

void inventory::setWeapon(){}

*/

inventory::inventory(){}
inventory::~inventory(){}


void inventory::initialise() //called at the start
{

this->invSpace = 40; //sets size of inventory
this->noOfItems = 0; //sets number of items = 0
this->invArray = new character* [this->invSpace]; //pointer to character to allow 
//data stored from objects to be placed into inventory
}

void inventory::addPotion()
{
//if user picks up potion
//and cin >> "store potion"
//invspace += invspace
//noOfItems += no of items
//for(int i = 0; i < this->invSpace; i++){
//character*[this->invspace] = character* potion;
//}
}

void inventory::displayinventory()
{
    for (int i = 0; i < this->invSpace; i++)
    {
        cout << *invArray << endl; 
    }
}





