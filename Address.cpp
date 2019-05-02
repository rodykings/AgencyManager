#include "Address.h"

Address::Address() {
	this->street = "";
	this->door = 0;
	this->floor = "";
	this->zipCode = "";
	this->location = "";
}

Address::Address(string street, int door, string floor, string zipCode, string location) {
	this->street = street;
	this->door = door;
	this->floor = floor;
	this->zipCode = zipCode;
	this->location = location;
}

// "street / door / floor / zipCode / location"
Address::Address(string addressStr) {
	
	string doorStr;
	
	unsigned int counter = 0;

	for (size_t i = 0; i < addressStr.length(); i++) {

		if (addressStr[i] == '/')
			counter++;
		else if (addressStr[i] == ' ' && (addressStr[i + 1] == '/' || addressStr[i - 1] == '/')) {
			continue;
		}
		else {
			switch (counter) {
			case 0:
				this->street += addressStr[i];
				break;
			case 1:
				doorStr += addressStr[i];
				break;
			case 2:
				this->floor += addressStr[i];
				break;
			case 3:
				this->zipCode += addressStr[i];
				break;
			case 4:
				this->location += addressStr[i];
				break;
			}
		}
	}
	this->door = stoi(doorStr);
}

string Address::toString() {
	return street + " / " + to_string(door) + " / " + floor + " / " + zipCode + " / " + location;
}

