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
#include "inputValidation.h"

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
    num nif;
	num profit;
	num numPacks;
	string clientsFile;
	string packsFile;
	num lastPack;

	vector<Client> clients;
	vector<Pack> packs;

	void storeClients();
	void storePacks();
	void addClient();
	void addPack();
};