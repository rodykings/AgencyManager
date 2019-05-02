#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <ostream>
#include <fstream>

#include "Client.h"
#include "Pack.h"
#include "Address.h"

using namespace std;

class Agency
{
public:
	Agency();
	Agency(string fileName); //alternate constructor
	void loadClients();
	void loadPacks();
	void showAgencyInfo();
private:
	string name;
	string url;
	Address address;
	unsigned int nif;
	unsigned int profit;
	unsigned int numPacks;
	string clientsFile;
	string packsFile;
	unsigned int lastPack;

	vector<Client> clients;
	vector<Pack> packs;

	void storeClients();
};