#pragma once

#include <string>
#include <fstream>
#include "inputValidation.h"

using namespace std;

class Address {
	public:
		Address();
		Address(string street,num door, string floor, string zipCode, string location);
		Address(string addressStr); // "street / door / floor / zipCode / location"
		string toString() const;

		//---GET methods---//
		string getStreet() const;
		num getDoor() const;
		string getFloor() const;
		string getZipCode() const;
		string getLocation() const;

	private:
		string street;
		num door;
		string floor;
		string zipCode;
		string location;
};