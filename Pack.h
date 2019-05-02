#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

#include "Date.h"

using namespace std;

class Pack {
public:
	//---CONSTRUCTORS---//
	Pack();
	Pack(string id, string places, string start, string end, string price, string spots, string soldSpots);

	//---SET methods---//
	void setID(unsigned int id);
	void setPlaces(vector<string> places);
	void setStart(Date start);
	void setEnd(Date end);
	void setPrice(unsigned int price);
	void setSpots(unsigned int spots);
	void setSoldSpots(unsigned int soldSpots);

	//---GET methods---//
	unsigned int getID() const;
	vector<string> getPlaces() const;
	Date getStart() const;
	Date getEnd() const;
	unsigned int getPrice() const;
	unsigned int getSpots() const;
	unsigned int getSoldSpots() const;
	
	vector<string> splitPlaces(string places);
	string placesToString(vector<string> places);


private:
	unsigned int id;
	vector<string> places;
	Date start;
	Date end;
	unsigned int price, spots, soldSpots;
};