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
//#include "SubMenu.h"


class Agency
{
public:
	Agency();
	Agency(string fileName); //alternate constructor
	
	
	void showAgencyInfo();
	void storeClients();
	void storePacks();
	void showAllClients(); // showAll clients
	void showPacks(); //show all packs
	void showPacks(vector<num> boughtPacks, bool positionVector);
	void addClient();
	void addPack();
	void deleteClient();
	void updateClient();
	void updatePack();
	void deletePack();
	void statistics();
	void showClient();
	void searchPack();

	void buyPack();
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

	
	void loadClients();
	void loadPacks();

	vector<num> searchPack(int id);
	vector<num> searchPack(string dest);
	vector<num> searchPack(Date start, Date end);
	num searchClient();
	
	
};