	//main.h
	void eastpath(character s, Inventory i);
	void westpath(character s, Inventory i);

	//inventory.cpp
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

	//inventory.h

	void setwand(string x);
	string getwand();
	void setdragonsword(string x);
	string getdragonsword();

protected:
	string aerondight = { "aerondight" };


	//charcter.h


	void attackenemy(character& x);
	void aerondightattack(character& x);

	void dragonattack(character& x);
	void checkhealth();

protected:
	double dragonsword;
	
	//character.cpp

	this->dragonsword = 80;

	void character::disphealth()
	{
		cout << "You're health is: " << this->health << endl << endl;
	}

	void character::aerondightattack(character& x)
	{
		x.health -= this->dragonsword;
		if (x.health <= 0)
		{
			x.health = 0;
			//enemydied();
		}
		cout << "\t\t\t\t\YOU HIT HIM!!\tEnemy health is: " << x.health << endl;
	}
	void character::dragonattack(character& x)
	{
		x.health -= this->dragonsword;
		if (x.health <= 0)
		{
			x.health = 0;
			//enemydied();
		}
		cout << "\t\t\t\t\YOU HIT IT !!\tDRAGONS health is: " << x.health << endl;
	}
