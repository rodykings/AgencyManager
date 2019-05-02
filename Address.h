#pragma once

#include <string>
#include <fstream>

using namespace std;

class Address {
	public:
		Address();
		Address(string street, unsigned int door, string floor, string zipCode, string location);
		Address(string addressStr); // "street / door / floor / zipCode / location"
		string toString();
		string getStreet() const;
		unsigned int getDoor() const;
		string getFloor() const;
		string getZipCode() const;
		string getLocation() const;

	private:
		string street;
		unsigned int door;
		string floor;
		string zipCode;
		string location;
};