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
void Pack::setPlaces() 
{
	string mainSite;
	cin.ignore(1000, '\n');
	cout << "Main Tour Site: "; getline(cin, mainSite);
	
	string places;
	cin.ignore(1000, '\n');
	cout << "Insert remaining tour sites seperated by a comma ( '0' if none ): "; getline(cin, places);
	if (places != "0")
	{
		mainSite += "-" + places;
	}
	this->places = splitPlaces(mainSite);
}
void Pack::setStart()
{
	this->start = start;
}
void Pack::setEnd()
{
	this->end = end;
}
void Pack::setPrice()
{
	this->price = price;
}
void Pack::setSpots()
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
		else
			temp += places[i];
	}
	sepPlaces.push_back(trimString(temp));

	return sepPlaces;
}
string Pack::placesToString()
{
	string p = "";

	size_t size = places.size();
	if (size == 1)
		return places[0];

	for (size_t i = 0; i < size; i++)
	{
		if (i == 0)
			p += places[0] + " - ";
		else if (i == 1)
			p += places[i];
		else
			p += ", " + places[i];
	}

	return p;
}
void Pack::show() {

	cout << "::::::::::\n";
	cout << setw(13) << "ID: " << id << endl;
	cout << setw(13) << "Tour Site: " << placesToString() << endl;
	cout << setw(13) << "Start: " << start.getDate() << endl;
	cout << setw(13) << "End: " << end.getDate() << endl;
	cout << setw(13) << "Price: " << price << endl;
	cout << setw(13) << "Total Spots: " << spots << endl;
	cout << setw(13) << "Sold Spots : " << soldSpots << endl;
	cout << "::::::::::\n";
	cout << endl;
}

