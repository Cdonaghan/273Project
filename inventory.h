

#pragma once
#include "character.h"
#include "chest.h"
#include <vector>
using namespace std;


class inventory : public character
{

    /*BRIEF
     To store items user gains throughout the progress of the game. 
    To open or drop items if. Inventory can store unlimited of everything but 
    will only encounter each weapon once.
    So it’ll only be able to store each weapon for one space and not unlimited amounts of the one weapon.

    - will lnk to chest storage class 
    - based off of user commands so may have to implement while loop at the start of the game to check for user command at any point in the game

    */



  public:
//constructor
inventory();
//destructor
~inventory();

//adding space slot to inventory (will do further research in)
//probably some sort of (add slot constructor type function)

//notes for store function
//getter and setter for weapon
void addWeapon();
void setWeapon();

//getter and setter for potions
void addPotion();
void setPotion();

//getter and setter for random scrolls
//void addscroll();
//void setScroll();
//probably dont need to store scrolls 


//notes for equip function

//probably wont drop anything as inventory space is unlimited (up for discussion)

//get character stats and display whenever the command is called for inventory


//vector to store weapons
vector < shared_ptr<character>> setWeapon;

//vector to store potions 
vector < shared_ptr<character>> setPotion;





private:

//space for items
//weapons section

//potions
 
 int  slotSpace; //subject to change
 



}; 



