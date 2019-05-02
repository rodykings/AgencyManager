#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

#include "Date.h"
#include "inputValidation.h"

using namespace std;

class Pack {
public:
	//---CONSTRUCTORS---//
	Pack();
	Pack(num id, vector<string> places, Date start, Date end, num price, num spots, num soldSpots);

	//---SET methods---//
	void setID(num id);
	void setPlaces(vector<string> places);
	void setStart(Date start);
	void setEnd(Date end);
	void setPrice(num price);
	void setSpots(num spots);
	void setSoldSpots(num soldSpots);

	//---GET methods---//
	num getID() const;
	vector<string> getPlaces() const;
	Date getStart() const;
	Date getEnd() const;
	num getPrice() const;
	num getSpots() const;
	num getSoldSpots() const;
	
	vector<string> splitPlaces(string places);
	string placesToString();


private:
	unsigned int id;
	vector<string> places;
	Date start;
	Date end;
	num price, spots, soldSpots;
};