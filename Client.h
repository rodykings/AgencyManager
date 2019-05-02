#pragma once

#include <string>

#include "Address.h"
#include "Pack.h"
#include "inputValidation.h"

using namespace std;

class Client {
	public:
		Client();
		Client(string name, unsigned int nif, unsigned int numPeople, Address address);
		Client(string name, num nif, num numPeople, num address, num boughtPacks, num moneySpent);

		//---SET methods---//
		void setName(string name);
		void setNif(unsigned int nif);
		void setNumPeople(unsigned int numPeople);
		void setAddress(Address address);
		void setBoughtPacks(vector<unsigned int> boughtPacks);
		void setMoneySpent(int moneySpent);

		//--GET methods--//
		string getName() const;
		unsigned int getNIF() const;
		unsigned int getNumPeople() const;
		Address getAddress() const;
		vector<unsigned int> getBoughtPacks() const;
		unsigned int getMoneySpent() const;

		string boughtToString();

	private:
		string name;
		unsigned int nif;
		unsigned int numPeople;
		Address address;
		vector<unsigned int> boughtPacks;
		unsigned int moneySpent;

		vector<unsigned int> boughtPacksVector(string bought);
};