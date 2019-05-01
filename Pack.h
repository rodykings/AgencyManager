#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

#include "Date.h"

using namespace std;

class Pack {
public:
	Pack();
	Pack(unsigned int id, string places, string start, string end, unsigned int price, unsigned int spots, unsigned int soldSpots);
	void setID(unsigned int id);
	void setPlaces(vector<string> places);
	void setStart(Date start);
	void setEnd(Date end);
	void setPrice(unsigned int price);
	void setSpots(unsigned int spots);
	void setSoldSpots(unsigned int soldSpots);
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