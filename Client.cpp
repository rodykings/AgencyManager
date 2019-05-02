#include "Client.h"

//Default Constructor
Client::Client() {
	Address address = {};
	vector<unsigned int> boughtPacks = {};

	this->name = "";
	this->nif = 0;
	this->numPeople = 0;
	this->address = address;
	this->boughtPacks = boughtPacks;
	this->moneySpent = 0;
}

//Create New Client
Client::Client(string name, unsigned int nif, unsigned int numPeople, Address address) {
	this->name = name;
	this->nif = nif;
	this->numPeople = numPeople;
	this->address = address;
	this->boughtPacks = {};
	this->moneySpent = 0;
}

//To create Clients from a file
Client::Client(string name, unsigned int nif, unsigned int numPeople, Address address, string boughtPacks, int moneySpent) {
	this->name = name;
	this->nif = nif;
	this->numPeople = numPeople;
	this->address = address;
	this->boughtPacks = this->boughtPacksVector(boughtPacks);
	this->moneySpent = moneySpent;
}

void Client::setName(string name) {
	this->name = name;
}	
void Client::setNif(unsigned int nif) {
	this->nif = nif;
}
void Client::setNumPeople(unsigned int numPeople) {
	this->numPeople = numPeople;
}
void Client::setAddress(Address address) {
	this->address = address;

}
void Client::setBoughtPacks(vector<unsigned int> boughtPacks) {
	this->boughtPacks = boughtPacks;
}
void Client::setMoneySpent(int moneySpent) {
	this->moneySpent = moneySpent;
}

vector<unsigned int> Client::boughtPacksVector(string bought) {

	vector<unsigned int> b;

	for (size_t i = 0; i < bought.size(); i++)
	{
		char temp = bought[i];
		if (temp == ';')
			continue;
		else
			b.push_back(temp);
	}

	return b;
}