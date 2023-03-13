

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
//get character stats and display whenever the command is called for inventory
//dynamically assorted array to store references to things the character ahs obtaines in the inventory


void initialise();

private:

 
 int  slotSpace; //subject to change
 
character** itemArray;

int noOfItems;


}; 



