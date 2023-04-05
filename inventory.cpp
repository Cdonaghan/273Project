#include "inventory.h"


void Inventory::getWeapon()
{
    cout << this->Weapon << endl;
}
void Inventory::setWeapon(string x)
{
    x = this->Weapon;
}
string Inventory::getPotion()
{
    return potion;
}
void Inventory::setPotion(string x)
{
    x = potion;
}

string Inventory::getsword()
{
    return sword;
}

void Inventory::setsword(string x)
{
    x = this->sword;

}

void Inventory::setbow(string x)
{
    x = this->bow;
}

string Inventory::getbow()
{
    return bow;
}
void Inventory::setdagger(string x)
{
    x = this->dagger;
}
string Inventory::getdagger()
{
    return dagger;
}


vector<character> items;
void Inventory::addItem(string x) {
    items.push_back(x);
}
void Inventory::removeItem(int index) {
    items.erase(items.begin() + index);
}
void Inventory::display(character s) {
    ;
    if (items.empty()) {
        cout << "Your inventory is empty.\n";
        //cout << "-1";
        character::tostring(s);
    }
    else {
        cout << "Your inventory contains " << items.size() << " item(s):\n";
        for (auto i : items)
            cout << i << endl;
        character::tostring(s);


    }


}

void Inventory::setdragonsword(string x)
{
	x = this->aerondight;
}
string Inventory::getdragonsword()
{
	return aerondight;
}
void Inventory::setwand(string x)
{
	x = this->wand;
}
string Inventory::getwand()
{
	return wand;
}






