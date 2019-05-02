#include "Client.h"

//DEFAULT CONSTRUCTOR
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

//NEW CLIENT CONSTRUCTOR
Client::Client(string name, unsigned int nif, unsigned int numPeople, Address address) {
	this->name = name;
	this->nif = nif;
	this->numPeople = numPeople;
	this->address = address;
	this->boughtPacks = {};
	this->moneySpent = 0;
}

//READ FORM A FILE CONSTRUCTOR
Client::Client(string name,  string nif, string numPeople, string address, string boughtPacks, string moneySpent) {
	this->name = name;
	this->nif = stoul(nif);
	this->numPeople = stoul(numPeople);
	this->address = Address(address);
	this->boughtPacks = this->boughtPacksVector(boughtPacks);
	this->moneySpent = stoul(moneySpent);
}


/*-----SET METHODS------*/

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

/*-----GET METHODS------*/

string Client::getName() const {
	return this->name;
}
unsigned int Client::getNif() const {
	return this->nif;
}
unsigned int Client::getNumPeople() const {
	return this->numPeople;
}
Address Client::getAddress() const {
	return this->address;
}
vector<unsigned int> Client::getBoughtPacks() const {
	return this->boughtPacks;
}
unsigned int Client::getMoneySpent() const{
	return this->moneySpent;
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