#pragma once

#include <string>

#include "Address.h"
#include "Pack.h"
#include "inputValidation.h"

using namespace std;

class Client {
	public:
		Client();
		Client(string name, num nif, num numPeople, Address address);
		Client(string name, num nif, num numPeople, Address address, string boughtPacks, num moneySpent);

		//---SET methods---//
		void setName(string name);
		void setNif(num nif);
		void setNumPeople(num numPeople);
		void setAddress(Address address);
		void setBoughtPacks(vector<num> boughtPacks);
		void setMoneySpent(num moneySpent);

		//--GET methods--//
		string getName() const;
		num getNIF() const;
		num getNumPeople() const;
		Address getAddress() const;
		vector<num> getBoughtPacks() const;
		num getSpentMoney() const;

		string boughtToString();

	private:
		string name;
		num nif;
		num numPeople;
		Address address;
		vector<num> boughtPacks;
		num moneySpent;

		vector<num> boughtPacksVector(string bought);
};