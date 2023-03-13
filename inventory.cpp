#include "inventory.h"

//constructor
inventory::inventory(){}

//destructor
inventory::~inventory(){}


//called at start of game

void inventory::initialise() 
{
    //creates references object that can be stored in array
    this->itemArray = new character*; 

    //sets number of items at start ofd game to 0
    this->noOfItems = 0;
}