#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

#include "Date.h"
#include "inputValidation.h"
#include "Operations.h"

using namespace std;

class Pack {
public:
	//---CONSTRUCTORS---//
	Pack();
	Pack(int id, string places, Date start, Date end, num price, num spots, num soldSpots);

	//---SET methods---//
	void setID(int id);
	void setPlaces();
	void setStart();
	void setEnd();
	void setPrice();
	void setSpots();
	void setSoldSpots();

	//---GET methods---//
	int getID() const;
	vector<string> getPlaces() const;
	Date getStart() const;
	Date getEnd() const;
	num getPrice() const;
	num getSpots() const;
	num getSoldSpots() const;
	
	//---OTHER METHODS---//
	vector<string> splitPlaces(string places);
	string placesToString();
	void show();



private:
	int id;
	vector<string> places;
	Date start;
	Date end;
	num price, spots, soldSpots;
};