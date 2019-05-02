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
Client::Client(string name, num nif, num numPeople, Address address) {
	this->name = name;
	this->nif = nif;
	this->numPeople = numPeople;
	this->address = address;
	this->boughtPacks = {};
	this->moneySpent = 0;
}

//READ FORM A FILE CONSTRUCTOR
Client::Client(string name,  num nif, num numPeople, Address address, num  boughtPacks, num moneySpent) {
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
void Client::setNif(num nif) {
	this->nif = nif;
}
void Client::setNumPeople(num numPeople) {
	this->numPeople = numPeople;
}
void Client::setAddress(Address address) {
	this->address = address;

}
void Client::setBoughtPacks(vector<num> boughtPacks) {
	this->boughtPacks = boughtPacks;
}
void Client::setMoneySpent(num moneySpent) {
	this->moneySpent = moneySpent;
}

/*-----GET METHODS------*/

string Client::getName() const {
	return this->name;
}
num Client::getNIF() const {
	return this->nif;
}
num Client::getNumPeople() const {
	return this->numPeople;
}
Address Client::getAddress() const {
	return this->address;
}
vector<num> Client::getBoughtPacks() const {
	return this->boughtPacks;
}
num Client::getMoneySpent() const{
	return this->moneySpent;
}


/*-----OTHER METHODS------*/

vector<num> Client::boughtPacksVector(string bought) {

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
string Client::boughtToString()
{
	string b = "";

	size_t size = boughtPacks.size();
	for (size_t i = 0; i < size; i++)
	{
		if (size == 1 || i == size - 1)
			b += boughtPacks[i];
		else
			b += boughtPacks[i] + ",";
	}

	return b;
}