#pragma once

#include <string>

#include "Address.h"
#include "Pack.h"

using namespace std;

class Client {
	public:
		Client();
		Client(string name, unsigned int nif, unsigned int numPeople, Address address);
		Client(string name, unsigned int nif, unsigned int numPeople, Address address, string boughtPacks, int moneySpent);
		void setName(string name);
		void setNif(unsigned int nif);
		void setNumPeople(unsigned int numPeople);
		void setAddress(Address address);
		void setBoughtPacks(vector<unsigned int> boughtPacks);
		void setMoneySpent(int moneySpent);
	private:
		string name;
		unsigned int nif;
		unsigned int numPeople;
		Address address;
		vector<unsigned int> boughtPacks;
		int moneySpent;

		vector<unsigned int> boughtPacksVector(string bought);
};