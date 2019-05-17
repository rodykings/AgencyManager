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
	string site;
	cin.ignore(1000, '\n');
	cout << "Tour Sites (mainTourSite - local, local): "; getline(cin, site);
	
	this->places = splitPlaces(site);
}
void Pack::setStart()
{
	bool valid;

	Date start = inputDate("New Start Date (YYYY/MM/DD):");
	valid = validStartEnd(start, this->getEnd());
	if (!valid) {
		cerr << "ERROR Inconsistent New Start Date!\n";
		system("pause");
	}
	else
		this->start = start;
}
void Pack::setEnd()
{
	bool valid;

	Date end = inputDate("New End Date (YYYY/MM/DD):");
	valid = validStartEnd(this->getStart(), end);
	if (!valid) {
		cerr << "ERROR Inconsistent New End Date!\n1n";
		system("pause");
	}
	else
		this->end = end;
}
void Pack::setPrice()
{
	num price = this->price;

	cin.ignore(1000, '\n');
	cin.clear();
	inputNum("\nNew price:", price);

	this->price = price;
}
void Pack::setSpots()
{
	num spots = this->spots;

	cin.ignore(1000, '\n');
	cin.clear();
	inputNum("\nNew spots:", spots);
	if (spots < this->getSoldSpots()) {
		cout << "Invalid spots range!\n";
		
	}
	else if(spots == this->getSoldSpots()) {
		this->setID((this->getID() * (-1)));
		this->spots = spots;
	}
	else {
		if (this->getSpots() == this->getSoldSpots()) {
			this->setID((this->getID() * (-1)));
		}
		this->spots = spots;
	}
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

