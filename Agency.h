#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <ostream>
#include <fstream>
#include <iomanip>

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
	
	void showAgencyInfo();
	void storeClients();
	void storePacks();
	vector<num> searchPacks(string dest);
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

	void addClient();
	void addPack();
	void deleteClient();

	void loadClients();
	void loadPacks();

	vector<num> searchPack(int id);
	num searchClient();
	void showClient(num v_pos); // show specific
	void showClients(); // showAll clients
};