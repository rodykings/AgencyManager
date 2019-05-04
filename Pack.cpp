#include "Pack.h"

Pack::Pack()
{
	id = 0;
	places = {};
	Date start;
	Date end;
	price = 0;
	spots = 0;
	soldSpots = 0;
}
//receives information read from agency file
Pack::Pack(int id, string places, Date start, Date end, num price, num spots, num soldSpots)
{
	this->id = id;
	this->places = splitPlaces(places);
	this->start = start;
	this->end = end;
	this->price = price;
	this->spots = spots;
	this->soldSpots = soldSpots;
}

void Pack::setID(int id)
{
	this->id = id;
}
void Pack::setPlaces(vector<string> places) 
{
	this->places = places;
}
void Pack::setStart(Date start)
{
	this->start = start;
}
void Pack::setEnd(Date end)
{
	this->end = end;
}
void Pack::setPrice(num price)
{
	this->price = price;
}
void Pack::setSpots(num spots)
{
	this->spots = spots;
}
void Pack::setSoldSpots(num soldSpots)
{
	this->soldSpots = soldSpots;
}

int Pack::getID() const {
	return id;
}
vector<string> Pack::getPlaces() const  {
	return places;
}
Date Pack::getStart() const  {
	return start;
}
Date Pack::getEnd() const  {
	return end;
}
num Pack::getPrice() const  {
	return price;
}
num Pack::getSpots() const  {
	return spots;
}
num Pack::getSoldSpots() const  {
	return soldSpots;
}

vector<string> Pack::splitPlaces(string places)
{
	vector<string> sepPlaces;
	string temp = "";

	size_t length = places.length();
	for (size_t i = 0; i < length; i++)
	{
		if (places[i] == ',' || places[i] == '-')
		{
			sepPlaces.push_back(trimString(temp));
			temp = "";
		}
		else if (places[i] != ' ')
			temp += places[i];
	}
	sepPlaces.push_back(trimString(temp));

	return sepPlaces;
}
string Pack::placesToString()
{
	string p = "";

	p += places[0];
	for (size_t i = 1; i < places.size(); i++)
	{
		if (i == 1)
			p += "-" + places[1];
		else
			p += ", " + places[i];
	}

	return p;
}

