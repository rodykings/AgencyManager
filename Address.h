#pragma once

#include <string>
#include <fstream>

using namespace std;

class Address {
	public:
		Address();
		Address(string street, int door, string floor, string zipCode, string location);
		Address(string addressStr); // "street / door / floor / zipCode / location"
		string toString();
	private:
		string street;
		unsigned int door;
		string floor;
		string zipCode;
		string location;
};