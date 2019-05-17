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
	this->spentMoney = 0;
}

//NEW CLIENT CONSTRUCTOR
Client::Client(string name, num nif, num numPeople, Address address) {
	this->name = name;
	this->nif = nif;
	this->numPeople = numPeople;
	this->address = address;
	this->boughtPacks = {};
	this->spentMoney = 0;
}

//READ FORM A FILE CONSTRUCTOR
Client::Client(string name,  num nif, num numPeople, Address address, string boughtPacks, num moneySpent) {
	this->name = name;
	this->nif = nif;
	this->numPeople = numPeople;
	this->address = address;
	this->boughtPacks = boughtPacksVector(boughtPacks);
	this->spentMoney = moneySpent;
}


/*-----SET METHODS------*/

void Client::setName() {
	string value;
	cin.ignore(1000, '\n');
	cout << "New Name: "; getline(cin, value);
	this->name = value;
}	
void Client::setNIF() {
	num val;
	inputNum("New NIF: ",val, 9);
	this->nif = val;
}
void Client::setNumPeople() {
	num val;
	inputNum("New Household: ", val);
	this->numPeople = val;
}
void Client::setAddress() {

	string street, floor, zipCode, location;
	num door;
	cout << "Street: "; 
	cin.ignore(1000, '\n');
	cin.clear();
	getline(cin, street);
	inputNum("Door: ", door);
	cout << "Floor: "; cin >> floor;
	cout << "Zip Code: "; cin >> zipCode;
	cout << "Location: "; cin >> location;

	Address newAddress(street, door, floor, zipCode, location);

	this->address = newAddress;
}
void Client::setBoughtPacks(int packID) {
	this->boughtPacks.push_back(packID);
}
void Client::setMoneySpent(num moneySpent) {
	this->spentMoney = moneySpent;
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
num Client::getSpentMoney() const{
	return this->spentMoney;
}


/*-----OTHER METHODS------*/

vector<num> Client::boughtPacksVector(string bought) {

	vector<num> b;
	string temp;
	size_t length = bought.size();

	for (size_t i = 0; i < length; i++)
	{
		if (bought[i] == ';' || i == length - 1) {
			if (i == length - 1)
				temp += bought[i];
			b.push_back(stoul(temp));
			temp = "";
		}
		else
			temp += bought[i];
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
			b += to_string(boughtPacks[i]);
		else
			b += to_string(boughtPacks[i]) + ";";
	}

	return b;
}
void Client::show()
{
	cout << "::::::::::\n";
	cout << setw(11) << "Name: " << name << endl;
	cout << setw(11) << "NIF: " << nif << endl;
	cout << setw(11) << "Household: " << numPeople << endl;
	cout << setw(11) << "Address: " << address.toString() << endl;
	cout << setw(11) << "Packages: " << boughtToString() << endl;
	cout << setw(11) << "Spent: " << spentMoney << endl;
	cout << "::::::::::\n";
	cout << endl;
}