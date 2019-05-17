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
		void setName();
		void setNIF();
		void setNumPeople();
		void setAddress();
		void setBoughtPacks(vector<num> boughtPacks);
		void setMoneySpent(num moneySpent);

		//--GET methods--//
		string getName() const;
		num getNIF() const;
		num getNumPeople() const;
		Address getAddress() const;
		vector<num> getBoughtPacks() const;
		num getSpentMoney() const;

		vector<string> visitedPlaces(vector<Pack>& packs);
		string boughtToString();
		void show();

	private:
		string name;
		num nif;
		num numPeople;
		Address address;
		vector<num> boughtPacks;
		num spentMoney;

		vector<num> boughtPacksVector(string bought);
};