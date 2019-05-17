#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <ostream>
#include <fstream>
#include <iomanip>
#include <map>

#include "Client.h"
#include "Pack.h"
#include "Address.h"
#include "inputValidation.h"

using namespace std;

class Agency
{
public:
	Agency();
	Agency(string fileName, bool& readFileFail); //alternate constructor

	bool clientChanges = false;
	bool packChanges = false;

	void showAgencyInfo();
	void storeClients();
	void storePacks();
	void showAllClients(); 
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
	void searchPack(bool available = false);
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

	void loadClients(bool& readFileFail);
	void loadPacks(bool& readFileFail);

	vector<num> searchPack(int id);
	vector<num> searchPack(string dest, bool available = false);
	vector<num> searchPack(Date start, Date end, bool available = false);
	num searchClient();
	vector<string> mostVisitedPlaces();
	
	
};