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
	this->address = address;
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

	string name = "";
	string address = "";
	num nif = 0;
	num numPeople = 0;
	string boughtPacks = "";
	num spentMoney = 0;

	size_t counter = 0;

	while (getline(in, line)) {

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
			spentMoney = stoul(line);
			break;
		case 6:
			Address newAddress(address);
			Client newClient(name, nif, numPeople, newAddress, boughtPacks, spentMoney);
			clients.push_back(newClient);
			counter = -1;
			break;
		}
		counter++;
	}
	Address newAddress(address);
	Client newClient(name, nif, numPeople, newAddress, boughtPacks, spentMoney);
	clients.push_back(newClient);

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

	int id = 0;
	num price = 0, spots = 0, soldSpots = 0;
	string start, end;
	string places = "";

	size_t i = 0;
	while (getline(in, line))
	{
		switch (i)
		{
		case 0:
			id = stoi(line);
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
			Date startDate(start);
			Date endDate(end);
			Pack newPack(id, places, startDate, endDate, price, spots, soldSpots);
			packs.push_back(newPack);
			break;
		}
		i++;
	}
	Pack newPack2(id, places, start, end, price, spots, soldSpots);
	packs.push_back(newPack2);

	in.close();
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
		out << to_string(clients[i].getSpentMoney()) << endl;
		
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
void Agency::addClient() {

	system("cls");

	cout << "ADD CLIENT" << endl;
	cout << "----------\n" << endl;

	string name = "";
	num nif = 0;
	num numPeople = 0;
	num door = 0;
	string street = "", floor = "", zipCode = "", location = "";
	
	cout << "Name:";
	cin.ignore(1000, '\n');
	getline(cin, name);
	inputNum("NIF:", nif, 9);
	inputNum("Group Size:", numPeople);
	cout << "Address:\n\tStreet:";
	cin.ignore();
	getline(cin, street);
	inputNum("\tDoor:", door);
	cout << "\tFloor:";
	cin.ignore();
	getline(cin, floor);
	cout << "\tZip Code:";
	cin >> zipCode;
	cout << "\tLocation:";
	cin.ignore(1000, '\n');
	getline(cin, location);

	Address newAddress(street, door, floor, zipCode, location);
	Client newClient(name, nif, numPeople, newAddress);
	clients.push_back(newClient);
}

//ADD PACKS
void Agency::addPack() {
	
	system("cls");

	cout << "ADD PACK\n";
	cout << "--------\n\n";

	lastPack++;
	int id = lastPack;
	string places ="";
	string start, end;
	num price = 0, spots = 0, soldSpots = 0;
	cout << "Tour Sites: ";
	cin.ignore(1000, '\n');
	getline(cin, places);
	Date startDate("Start Date (YYYY/MM/DD): ", start);
	Date endDate("End Date (YYYY/MM/DD): ", end);
	inputNum("Price: ", price);
	inputNum("Available Spots: ", spots);

	Pack newPack(id, places, start, end, price, spots, soldSpots);
	packs.push_back(newPack);

	cout << "\n\nPack successfully added!\n\n";
	system("pause");


}
//DELETE PACKS							
void Agency::deletePack()
{
	cout << "DELETE PACK \n";
	cout << "-----------\n" << endl;
	int id;
	inputInt("Package ID: ", id);
	cout << endl;

	vector<num> vpos = searchPack(id);
	if (vpos.size() == 0) {
		cerr << "ERROR Package not found! \n\n";
		system("pause");
	}
	else{
		packs[vpos[0]].show();

		bool opt = yesOrNo("Are you sure you want to remove this package ? [y/n] ");
		if (opt)
		{
			int packID = -packs[vpos[0]].getID();
			packs[vpos[0]].setID(packID);
			cout << "Package is now unavailable! \n";
			system("pause");
		}
	}
	cout << endl;
}

//SHOW AGENCY INFO
void Agency::showAgencyInfo() {
	cout << name << endl;
	cout << nif << endl;
	cout << url << endl;
	cout << this->address.toString() << endl;
};

//SEARCH FOR A SPECIFIC CLIENT
num Agency::searchClient()
{
	num nif;
	inputNum("\nNIF: ", nif, 9);

	size_t size = clients.size();
	for (size_t i = 0; i < size; i++)
	{
		if (clients[i].getNIF() == nif)
			return i;	
	}
	return -1;
}

void Agency::showAllClients() 
{
	system("cls");

	const unsigned int NAME_MAX_SIZE = 20;	//FUNCTION THAT CALCULATES THE MAX NAME SIZE !!!

	cout << "ALL CLIENTS \n";
	cout << "----------- \n";
	cout << endl;
	cout << setw(NAME_MAX_SIZE) << left << "Name";
	cout << setw(15) << left << "NIF";
	cout << setw(4) << left << "N";
	cout << setw(15) << left << "Packages";
	cout << setw(10) << left << "Spent";
	cout << "Adress" << endl;
	cout << endl;

	size_t size = clients.size();
	for (size_t i = 0; i < size; i++)
	{
		cout << setw(NAME_MAX_SIZE) << left << clients[i].getName();
		cout << setw(15) << left << clients[i].getNIF();
		cout << setw(4) << left << clients[i].getNumPeople();
		cout << setw(15) << left << clients[i].boughtToString();
		cout << setw(10) << left << clients[i].getSpentMoney();
		cout << clients[i].getAddress().toString() << endl;
	}
	cout << endl;
	system("pause");
}

void Agency::showPacks()
{
	system("cls");

	cout << "ALL PACKS \n";
	cout << "----------- \n";
	cout << endl;
	cout << setw(4) << left << "ID";
	cout << setw(40) << left << "Places";
	cout << setw(12) << left << "Begin Date";
	cout << setw(12) << left << "End Date";
	cout << setw(14) << left << "Total Spots";
	cout << setw(4) << left << "Sold Spots" << endl;
	cout << endl;

	size_t size = packs.size();
	for (size_t i = 0; i < size; i++)
	{
		cout << setw(4) << left << packs[i].getID();
		cout << setw(40) << left << packs[i].placesToString();
		cout << setw(12) << left << packs[i].getStart().getDate();
		cout << setw(12) << left << packs[i].getEnd().getDate();
		cout << setw(14) << left << packs[i].getSpots();
		cout << setw(4) << left << packs[i].getSoldSpots();
		cout << endl;
	}
	cout << endl;
	system("pause");
}

//DELETE CLIENT
void Agency::deleteClient()
{
	system("cls");
	cout << "REMOVE CLIENT \n";
	cout << "------------- \n";

	num vpos = searchClient();

	if (vpos != -1)
	{
		cout << endl;
		clients[vpos].show();

		bool opt = yesOrNo("Are you sure you want to remove this client ? [y/n]");
		if (opt)
		{
			clients.erase(clients.begin() + vpos);
			cout << "\nClient Deleted!\n";
			system("pause");
		}
	}
	else {
		cout << "\nClient not found!\n\n";
		system("pause");
	}
	cout << endl;
}


/*-----SEARCH PACK FUNCTIONS-----*/
//SEARCH PACK BY ID
vector<num> Agency::searchPack(int id) {

	vector<num> finalIdx = {};

	size_t size = packs.size();
	for (size_t i = 0; i < size; i++) {
		if (abs(packs[i].getID()) == id)
			finalIdx.push_back(i);
	}
	return finalIdx;
}
//SEARCH PACKS BY DESTINATION
vector<num> Agency::searchPack(string dest){

	vector<num> vpos;
	
	dest = stringToUpper(dest);
	size_t size = packs.size();
	for (size_t i = 0; i < size; i++)
	{
		vector<string> temp = packs[i].getPlaces();
		for (size_t j = 0; j < temp.size(); j++)
		{
			if (stringToUpper(temp[j]) == dest)
				vpos.push_back(i);
		}
	}
	return vpos;
}
//SEARCH PACKS BY DATE
vector<num> Agency::searchPack(Date start, Date end)
{
	vector<num> vpos;
	
	size_t size = packs.size();
	for (size_t i = 0; i < size; i++)
	{
		// if start is the same or after the pack start date and before the pack end date
		if (!start.isBefore(packs[i].getStart()) && start.isBefore(packs[i].getEnd())) 
		{
			//if the end date is before or equal to the pack end date
			if (end.isBefore(packs[i].getEnd()) || end.isEqualTo(packs[i].getEnd()))
				vpos.push_back(i);
		}
	}
	return vpos;
}


/*-----UPDATE FUNCTIONS-----*/
void Agency::updateClient()
{
	int vpos = searchClient();

	if (vpos >= 0)
	{
		bool moreEdits = true;
		do {
			
			system("cls");

			cout << "EDIT CLIENT\n";
			cout << "-----------\n" << endl;
			cout << "| 1-Edit Name | 2-Edit NIF | 3-Edit Household | 4-Edit Address |\n" << endl;

			clients[vpos].show();
			cout << endl;

			int option;
			selectOption(option, 4);

			switch (option) {
			case -1:
				moreEdits = false;	//exit function
				break;
			case 1:
				clients[vpos].setName();
				break;
			case 2:
				clients[vpos].setNIF();
				break;
			case 3:
				clients[vpos].setNumPeople();
				break;
			case 4:
				clients[vpos].setAddress();
				break;
			}

		} while (moreEdits);
	}
	else {
		cerr << "ERROR Client not found!\n" << endl;
		system("pause");
	}
		

}
void Agency::updatePack() {

	int id;
	inputInt("Pack ID: ", id);

	vector<num> vpos = searchPack(id);


	if (vpos.size() != 0)
	{
		bool moreEdits = true;
		do {
			
			system("cls");

			cout << "EDIT PACK\n";
			cout << "---------\n" << endl;
			cout << "| 1-Edit Tour Sites | 2-Edit Start Date | 3-Edit End Date | 4-Edit Price | 5-Edit Number of Spots |\n" << endl;

			packs[vpos[0]].show();
			cout << endl;

			int option;
			selectOption(option, 5);

			switch (option) {
			case -1:
				moreEdits = false;	//exit function
				break;
			case 1:
				packs[vpos[0]].setPlaces();
				break;
			case 2:
				packs[vpos[0]].setStart();
				break;
			case 3:
				packs[vpos[0]].setEnd();
				break;
			case 4:
				packs[vpos[0]].setPrice();
				break;
			case 5:
				packs[vpos[0]].setSpots();
				break;
			}

		} while (moreEdits);

	}
}

void Agency::statistics()
{
	system("cls");
	cout << "STATISTICS\n";
	cout << "----------\n" << endl;
	cout << "| 1-Agency Information | 2-Most visited places |\n\n";

	int opt;
	selectOption(opt, 2);

	num clientSize = clients.size();
	num soldPacks = 0;
	num profit = 0;

	num counterId = 0;
	num currentnId = 0;
	num boughtNum = 0;
	num packSize = 0;
	size_t pack = 0;
	size_t client = 0;

	vector<vector<num>> visitedPlaces;

	switch (opt) {

	case 1:

		cout << "\n\nAGENCY INFORMATION\n";
		cout << "------------------\n" << endl;

		for (client = 0; client < clientSize; client++) {
			packSize = clients[client].getBoughtPacks().size();
			for (pack = 0; pack < packSize; pack++) {
				soldPacks++;
			}
		}

		cout << "Sold Packs: " << soldPacks << endl;

		for (size_t client = 0; client < clientSize; client++) {
			profit += clients[client].getSpentMoney();
		}

		cout << "Profit: " << profit << endl << endl;

		system("pause");
		break;
	case 2:
		cout << "\n\nMOST VISITED PLACES\n";
		cout << "------------------\n" << endl;

		vector<string> mostVisitedPlaces;

		map<num, num> placesMap;

		for (client = 0; client < clientSize; client++) {
			packSize = clients[client].getBoughtPacks().size();
			pack = 0;
			for (pack = 0; pack < packSize; pack++) {
				if (mostVisitedPlaces.find(abs(clients[client].getBoughtPacks()[pack])) == mostVisitedPlaces.end()) {
					// not found
				}
				else {
					// found
				})
			}
			visitedPlaces.push_back({pack, boughtNum});
		}
		system("pause");
		break;
	}
}

void Agency::showPacks(vector<num> boughtPacks) {

	cout << setw(4) << left << "ID";
	cout << setw(40) << left << "Places";
	cout << setw(12) << left << "Begin Date";
	cout << setw(12) << left << "End Date";
	cout << setw(14) << left << "Total Spots";
	cout << setw(4) << left << "Sold Spots" << endl;
	cout << endl;

	size_t size = boughtPacks.size();
	for (size_t i = 0; i < size; i++)
	{
		cout << setw(4) << left << packs[boughtPacks[i]].getID();
		cout << setw(40) << left << packs[boughtPacks[i]].placesToString();
		cout << setw(12) << left << packs[boughtPacks[i]].getStart().getDate();
		cout << setw(12) << left << packs[boughtPacks[i]].getEnd().getDate();
		cout << setw(14) << left << packs[boughtPacks[i]].getSpots();
		cout << setw(4) << left << packs[boughtPacks[i]].getSoldSpots();
		cout << endl;
	}
	cout << endl;
}
void Agency::showClient() {
	system("cls");

	cout << "SEARCH CLIENT\n";
	cout << "-------------\n" << endl;
	cout << "| 1-Display sold packs | 2-Display most famous unvisited destinations |\n";

	num vpos = searchClient();

	if (vpos >= 0) {

		clients[vpos].show();
		cout << endl;

		int option;
		selectOption(option, 2);

		switch (option) {
		case -1:
			break;
		case 1:
			cout << endl;
			showPacks(clients[vpos].getBoughtPacks());
		}
	}

	system("pause");
}


