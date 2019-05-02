#include "Agency.h"

//DEFAULT CONSTRUTCTOR
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

//CONSTRUCTOR FROM FILES
Agency::Agency(string fileName)
{
	ifstream in;
	in.open(fileName);

	string line;

	getline(in, name);	
	getline(in, line);	
	nif = stoul(line);
	getline(in, url);	
	getline(in, line);	
	Address address(line);
	getline(in, clientsFile);
	getline(in, packsFile);	
	in.close();

	numPacks = 0; 
	profit = 0;	
	lastPack = 0;

	loadClients();
	loadPacks();
}

//READ CLIENTS FROM FILE
void Agency::loadClients() {

	ifstream in;
	in.open(clientsFile);

	string line;
	string name;
	string nif;
	string numPeople;
	string address;
	string boughtPacks;
	string moneySpent;

	size_t counter = 0;

	while (getline(in, line)) {

		switch (counter)
		{
		case 0:
			name = line;
			break;
		case 1:
			nif = line;
			break;
		case 2:
			numPeople = line;
			break;
		case 3:
			address = line;
			break;
		case 4:
			boughtPacks = line;
			break;
		case 5:
			moneySpent = line;
			break;
		case 6:
			Address newAddress(address);
			Client newClient(name, nif, numPeople, address, boughtPacks, moneySpent);
			counter = -1;
			break;
		}
		counter++;
	}
	Address newAddress(address);
	Client newClient(name, nif, numPeople, address, boughtPacks, moneySpent);

	in.close();
}

//READ PACKS FROM FILE
void Agency::loadPacks()
{
	ifstream in;
	in.open(packsFile);
	
	string line;

	getline(in, line);		//lastPack
	lastPack = stoul(line);

	string id , price , spots, soldSpots, places, start, end;

	size_t i = 0;
	while (getline(in, line))
	{
		switch (i)
		{
		case 0:
			id = line;
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
			price = line;
			break;
		case 5:
			spots = line;
			break;
		case 6:
			soldSpots = line;
			break;
		case 7:	// "::::::::::" add pack to vector
			i = -1; 
			Pack newPack(id, places, start, end, price, spots, soldSpots);
			this->packs.push_back(newPack);
			break;
		}
		i++;
	}
	Pack newPack2(id, places, start, end, price, spots, soldSpots);
	packs.push_back(newPack2);
}

//WRITE CLIENTS IN FILE
void Agency::storeClients() {
	
	ofstream out;
	out.open(clientsFile, ofstream::out, ofstream::trunc);

	size_t size = clients.size();
	for (size_t i = 0; i < size; i++)
	{
		out << clients[i].getName() << endl;
		out << to_string(clients[i].getNIF()) << endl;
		out << to_string(clients[i].getNumPeople()) << endl;
		out << clients[i].getAddress().toString() << endl;
		out << clients[i].boughtToString() << endl;
		out << to_string(clients[i].getMoneySpent()) << endl;
		
		if (i != size - 1)
			out << "::::::::::\n";
	}
	out.close();
}

//WRITE PACKS IN FILE
void Agency::storePacks() {
	ofstream out;
	out.open(packsFile, ofstream::out, ofstream::trunc);

	out << to_string(lastPack) << endl; //add last pack id to the first line

	size_t size = packs.size();
	for (size_t i = 0; i < size; i++)
	{
		out << to_string(packs[i].getID()) << endl;
		out << packs[i].placesToString() << endl;
		out << packs[i].getStart().getDate() << endl;
		out << packs[i].getEnd().getDate() << endl;
		out << to_string(packs[i].getPrice()) << endl;
		out << to_string(packs[i].getSpots()) << endl;
		out << to_string(packs[i].getSoldSpots()) << endl;
		if(i != (size-1))
			out << "::::::::::" << endl;

	}
	out.close();
}


//ADD CLIENTS
void Agency::addClients() {

	string name;
	unsigned int nif;


	cin << 

}

//ADD PACKS
void Agency::addPacks() {



}

//SHOW AGENCY INFO
void Agency::showAgencyInfo() {
	cout << name << endl;
	cout << nif << endl;
	cout << url << endl;
	cout << address.toString() << endl;
};

void Agency::addPack()
{

}