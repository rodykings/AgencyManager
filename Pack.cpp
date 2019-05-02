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
Pack::Pack(int id, vector<string> places, Date start, Date end, num price, num spots, num soldSpots)
{
	this->id = stoul(id);
	this->places = splitPlaces(places);
	this->start = Date(start);
	this->end = Date(end);
	this->price = stoul(price);
	this->spots = stoul(spots);
	this->soldSpots = stoul(soldSpots);
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
	size_t i = 0;
	string temp = "";

	while (i < places.length())
	{
		while (places[i] != '-' || places[i] != ',')
		{
			temp += places[i];
			i++;
		}
		sepPlaces.push_back(temp);
		temp = "";
		i++;
	}

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

