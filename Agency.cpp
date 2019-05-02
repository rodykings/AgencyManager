#include "Agency.h"

//default constructor
Agency::Agency()
{
	name = "";
	nif = 000000000;
	url = "";
	Address address;
	clientsFile = "";
	packsFile = "";
	numPacks = 0;
	profit = 0;
	lastPack = 0;
}
//alternate constructor
Agency::Agency(string fileName)
{
	ifstream in;
	in.open(fileName);

	string line;

	getline(in, name);	//name
	getline(in, line);	//nif
	nif = stoul(line);
	getline(in, url);	//url
	getline(in, line);	//address
	Address address(line);
	getline(in, clientsFile);//clients file
	getline(in, packsFile);	//packs file
	numPacks = 0; //CRIAR FUN��O
	profit = 0;	
	lastPack = 0;
}

void Agency::loadClients() {

	ifstream in;
	in.open(clientsFile);

	string line;

	while (getline(in, line)) {

		string name;
		unsigned int nif;
		unsigned int numPeople;
		string address;
		string boughtPacks;
		unsigned int moneySpent;

		size_t counter = 0;
		switch (counter)
		{
		case 0:
			name = line;
			break;
		case 1:
			nif = stoul(line);
			break;
		case 2:
			numPeople = stoul(line);
			break;
		case 3:
			address = line;
			break;
		case 4:
			boughtPacks = line;
			break;
		case 5:
			moneySpent = stoul(line);
			break;
		case 6:
			Address newAddress(address);
			Client newClient(name, nif, numPeople, address, boughtPacks, moneySpent);
			break;
		}
	}
}

// adds a pack to the packs vector
void Agency::loadPacks()
{
	ifstream in;
	in.open(packsFile);
	
	string line;

	getline(in, line);		//lastPack
	lastPack = stoul(line);

	unsigned int id = 0;
	string places = "", start = "", end = "";
	unsigned int price = 0;
	unsigned int spots = 0, soldSpots = 0;

	size_t i = 0;
	while (getline(in, line))
	{
		switch (i)
		{
		case 0:
			id = stoul(line);
			break;
		case 1:
			places = line;
			break;
		case 2:
			start = line;
			break;
		case 3:
			end = line;
			break;
		case 4:
			price = stoul(line);
			break;
		case 5:
			spots = stoul(line);
			break;
		case 6:
			soldSpots = stoul(line);
			break;
		case 7:	// "::::::::::" add pack to vector
			i = -1; 
			Pack newPack(id, places, start, end, price, spots, soldSpots);
			this->packs.push_back(newPack);
			break;
		}
		i++;
	}
	Pack newPack2(id, places, start, end, price, spots, soldSpots);		//n�o adiciona o �ltimo, por n�o ter "::::::::::"
	packs.push_back(newPack2);
}

void Agency::showAgencyInfo() {
	cout << name << endl;
	cout << nif << endl;
	cout << url << endl;
	cout << address.toString() << endl;
};