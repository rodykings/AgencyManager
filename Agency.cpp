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

//CONSTRUCTOR FROM FILE
Agency::Agency(string fileName, bool& readFileFail)
{
	ifstream in;
	in.open(fileName);

	nif = 0;
	numPacks = 0;
	profit = 0;
	lastPack = 0;

	if (in.fail()) {
		cerr << "ERROR Unable to open " << fileName << " !\n" << endl;
		readFileFail = true;
	}
	else {
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

		loadClients(readFileFail);
		loadPacks(readFileFail);
	}
}

//SHOW AGENCY INFO
void Agency::showAgencyInfo() {
	cout << name << endl;
	cout << nif << endl;
	cout << url << endl;
	cout << this->address.toString() << endl;
};

/*---READ DATA FROM FILES---*/
void Agency::loadClients(bool& readFileFail) {

	ifstream in;
	in.open(clientsFile);

	if (in.fail()) {
		cerr << "ERROR Unable to open " << clientsFile << " !\n" << endl;
	}
	else {
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
}
void Agency::loadPacks(bool& readFileFail)
{
	ifstream in;
	in.open(packsFile);

	if (in.fail()) {
		cerr << "ERROR Unable to open " << packsFile << " !\n" << endl;
	}
	else {
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
	
}

/*---WRITE DATA IN FILES---*/
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

/*---CLIENTS MANAGEMENT---*/
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
	cout << "\tFloor ( - if none ):";
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
	clientChanges = true;
}//ADD CLIENT
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
			clientChanges = true;
			system("pause");
		}
	}
	else {
		cout << "\nClient not found!\n\n";
		system("pause");
	}
	cout << endl;
}
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
			clientChanges = true;

		} while (moreEdits);
	}
	else {
		cerr << "ERROR Client not found!\n" << endl;
		system("pause");
	}
}
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
void Agency::showClient() {
	system("cls");

	cout << "SEARCH CLIENT\n";
	cout << "-------------\n";

	int vpos = searchClient();

	if (vpos >= 0) {

		cout << endl << "| 1-Display sold packs | 2-Display most famous unvisited destinations |\n\n";

		clients[vpos].show();
		cout << endl;

		int option;
		selectOption(option, 2);

		switch (option) {
		case -1:
			break;
		case 1:
			cout << endl;
			showPacks(clients[vpos].getBoughtPacks(), false);
			system("pause");
			break;
		case 2:
			cout << endl;
			vector<string> unvisitedPlaces = {};
			vector<string> mVisitedPlaces = mostVisitedPlaces();
			vector<string> vPlaces = clients[vpos].visitedPlaces(packs);
			size_t mvpSize = mVisitedPlaces.size();
			size_t vpSize = vPlaces.size();

			bool notVisited = true;
			for (size_t i = 0; i < mvpSize; i++) {
				for (size_t u = 0; u < vpSize; u++) {
					if (vPlaces[u] == mVisitedPlaces[i]) {
						notVisited = false;
					}
				}
				if (notVisited) {
					unvisitedPlaces.push_back(mVisitedPlaces[i]);
				}
				notVisited = true;
			}
			
			size_t unvisitedSize = unvisitedPlaces.size();

			if (unvisitedSize == 0) {
				cout << "\nThere�s no unvisited place to visit\n";
			}
			else {
				cout << "\nUnvisited most visited places:\n\n";
				for (size_t t = 0; t < unvisitedSize; t++) {
					cout << t + 1 << ". " << unvisitedPlaces[t] << endl;
				}
			}
		}
		system("pause");
	}
	else {
		cerr << endl << "ERROR Client not found!\n" << endl;
		system("pause");
	}
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

/*---PACKS MANAGEMENT---*/
void Agency::addPack() {
	
	system("cls");

	cout << "ADD PACK\n";
	cout << "--------\n\n";

	lastPack++;
	int id = lastPack;
	string places ="";
	Date start, end;
	num price = 0, spots = 0, soldSpots = 0;
	cout << "Tour Sites: ";
	cin.ignore(1000, '\n');
	getline(cin, places);
	bool valid = false;
	do{
		 start = inputDate("Start Date (YYYY/MM/DD): ");
		 end = inputDate("End Date (YYYY/MM/DD): ");
		valid = validStartEnd(start, end);
		if (!valid)
			cerr << "ERROR Inconsistent Start and End Date !\n";
	} while (!valid);
	
	inputNum("Price: ", price);
	inputNum("Available Spots: ", spots);

	Pack newPack(id, places, start, end, price, spots, soldSpots);
	packs.push_back(newPack);

	cout << "\n\nPack successfully added!\n\n";
	packChanges = true;
	system("pause");
}				
void Agency::deletePack()
{
	system("cls");
	cout << "DELETE PACK \n";
	cout << "-----------\n" << endl;
	int id;
	inputInt("Package ID: ", id);
	cout << endl;

	vector<num> vpos = searchPack(id);
	if (vpos.size() == 0) {
		cerr << "ERROR Package not found! \n\n";
	}
	else{
		packs[vpos[0]].show();

		bool opt = yesOrNo("Are you sure you want to remove this package ? [y/n] ");
		if (opt)
		{
			int packID = -packs[vpos[0]].getID();
			packs[vpos[0]].setID(packID);
			cout << endl << "Package is now unavailable! \n" << endl;
			packChanges = true;
		}
	}
	system("pause");
	cout << endl;
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
			packChanges = true;

		} while (moreEdits);

	}
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
	cout << setw(12) << left << "Sold Spots";
	cout << setw(12) << left << "Price/Pax" << endl;
	cout << endl;

	size_t size = packs.size();
	for (size_t i = 0; i < size; i++)
	{
		cout << setw(4) << left << packs[i].getID();
		cout << setw(40) << left << packs[i].placesToString();
		cout << setw(12) << left << packs[i].getStart().getDate();
		cout << setw(12) << left << packs[i].getEnd().getDate();
		cout << setw(14) << left << packs[i].getSpots();
		cout << setw(12) << left << packs[i].getSoldSpots();
		cout << setw(12) << left << packs[i].getPrice();
		cout << endl;
	}
	cout << endl;
	system("pause");
}
void Agency::showPacks(vector<num> vec, bool positionVector = false) {

	cout << setw(4) << left << "ID";
	cout << setw(40) << left << "Places";
	cout << setw(12) << left << "Begin Date";
	cout << setw(12) << left << "End Date";
	cout << setw(14) << left << "Total Spots";
	cout << setw(12) << left << "Sold Spots";
	cout << setw(12) << left << "Price/Pax" << endl;
	cout << endl;

	size_t size = vec.size();
	for (size_t i = 0; i < size; i++)
	{
		num pos = 0;
		if (!positionVector) //if the vector contains id it translates them into positions
			pos = vec[i] - 1;
		else
			pos = vec[i];

		cout << setw(4) << left << packs[pos].getID();
		cout << setw(40) << left << packs[pos].placesToString();
		cout << setw(12) << left << packs[pos].getStart().getDate();
		cout << setw(12) << left << packs[pos].getEnd().getDate();
		cout << setw(14) << left << packs[pos].getSpots();
		cout << setw(12) << left << packs[pos].getSoldSpots();
		cout << setw(12) << left << packs[pos].getPrice();
		cout << endl;
	}
	cout << endl;
}

/*---SEARCH PACK FUNCTIONS---*/
void Agency::searchPack(bool available) {
	system("cls");
	cout << "SEARCH PACKS\n";
	cout << "------------\n" << endl;
	cout << "| 1-Search by Destination | 2-Search by Date | 3-Search by Date and Destination |\n" << endl;

	int option;
	selectOption(option, 3);

	vector<num> vpos, vpos2, vposIntersection;
	string dest = "";
	Date start;
	Date end;
	bool valid = false;
	switch (option) {
	case -1:
		break;
	case 1: //search by destination
		cin.ignore(1000, '\n');
		cout << endl << "Destination: "; getline(cin, dest);
		vpos = searchPack(dest, available);
		break;
	case 2:	//search by date
		do {
			start = inputDate("Start: ");
			end = inputDate("End: ");
			valid = validStartEnd(start, end);
			if (!valid)
				cerr << "ERROR Inconsistent Start and End Date !\n";
		} while (!valid);
		vpos = searchPack(start, end, available);
		break;
	case 3: //search by date and destination
		cin.ignore(1000, '\n');
		cout << endl << "Destination: "; getline(cin, dest);
		vpos = searchPack(dest, available);
		do {
			start = inputDate("Start Date: ");
			end = inputDate("End Date: ");
			valid = validStartEnd(start, end);
			if (!valid)
				cerr << "ERROR Inconsistent Start and End Date !\n";
		} while (!valid);
		
		vpos2 = searchPack(start, end, available);
		
		vposIntersection = vectorIntersect(vpos, vpos2);
		vpos = vposIntersection;
	}

	if (vpos.size() != 0) {
		cout << endl;
		showPacks(vpos, true);
	}
	else {
		cerr << endl << "ERROR No matches found! \n" << endl;
	}
	system("pause");
}
//SEARCH PACK BY ID
vector<num> Agency::searchPack(int id) {

	vector<num> finalIdx;

	size_t size = packs.size();
	if ((unsigned int)abs(id) > size)
		return finalIdx;

	for (size_t i = 0; i < size; i++) {
		if (abs(packs[i].getID()) == id)
			finalIdx.push_back(i);
	}
	return finalIdx;
}
//SEARCH PACKS BY DESTINATION
vector<num> Agency::searchPack(string dest, bool available){

	vector<num> vpos;
	
	dest = stringToUpper(dest);
	size_t size = packs.size();
	for (size_t i = 0; i < size; i++)
	{
		vector<string> temp = packs[i].getPlaces();
		if (available && packs[i].getID() < 0)
			continue;
		for (size_t j = 0; j < temp.size(); j++)
		{
			if (stringToUpper(temp[j]) == dest)
				vpos.push_back(i);
		}
	}
	return vpos;
}
//SEARCH PACKS BY DATE
vector<num> Agency::searchPack(Date start, Date end, bool available)
{
	vector<num> vpos;
	
	size_t size = packs.size();
	for (size_t i = 0; i < size; i++)
	{
		if (available && packs[i].getID() < 0)
			continue;
		if ((packs[i].getStart().isAfter(start)|| packs[i].getStart().isEqualTo(start)) && (packs[i].getEnd().isBefore(end) || packs[i].getEnd().isEqualTo(end)))
			vpos.push_back(i);
	}
	return vpos;
}

void Agency::buyPack() {
	system("cls");

	cout << "BUY PACK\n";
	cout << "--------\n" << endl;

	int vpos = searchClient();

	if (vpos < 0) {
		cerr << "\n\nERROR Client not found!\n\n";
	}
	else {
		cout << endl;
		clients[vpos].show();

		if (yesOrNo("Do you want to buy a pack for this client? [y/n] ")) {
			if (yesOrNo("\nDo you want ot search for available packs? [y/n] ")) {
				searchPack(true);
			}
			system("cls");

			cout << "BUY PACK\n";
			cout << "--------\n" << endl;

			int id;
			inputInt("Pack ID: ", id);
			vector<num> pos = searchPack(id);
			
			if (pos.size() != 0) {
				num total_price = packs[id - 1].getPrice() * clients[vpos].getNumPeople();
				if ((packs[id - 1].getSoldSpots() + clients[vpos].getNumPeople()) > packs[id - 1].getSpots())
					cout << endl << "Package is full! \n\n";
				else {
					cout << endl;
					cout << "--------------------------------------------\n";
					cout << packs[id - 1].placesToString() << endl << endl;
					cout << packs[id - 1].getStart().getDate() << " ---- " << packs[id - 1].getEnd().getDate() << endl << endl;
					cout << "Total Price: " << total_price << endl;
					cout << "--------------------------------------------";
					cout << endl << endl;

					if (yesOrNo("Buy pack for " + clients[vpos].getName() + "? [y/n]")) {
						clients[vpos].setMoneySpent(clients[vpos].getSpentMoney() + total_price);
						clients[vpos].setBoughtPacks(id);
						packs[id - 1].setSoldSpots((packs[id - 1].getSoldSpots() + clients[vpos].getNumPeople()));
						if (packs[id - 1].getSoldSpots() == packs[id - 1].getSpots())
							packs[id - 1].setID((packs[id-1].getID() * (-1)));
						cout << "\n\nPackage bought successfully!\n\n";
						clientChanges = true;
						packChanges = true;
					}
				}
			}
			else {
				cerr << "\nERROR Package not found!\n\n";
			}
		}
	}
	system("pause");
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
	num placesSize = 0;
	size_t pack = 0;
	size_t client = 0;
	size_t place = 0;
	string placeStr = "";
	num max = 0;

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

		
		vector<string> visitedPlaces = mostVisitedPlaces();
		size_t size = visitedPlaces.size();

		for (size_t i = 0; i < size; i++) {
			cout << i + 1 << ". " << visitedPlaces[i] << endl;
		}

		cout << endl;
		system("pause");
	}
}

vector<string> Agency::mostVisitedPlaces() {
	vector<string> mostVisitedPlaces = {};
	map<string, num> placesMap;
	size_t packSize = packs.size();
	size_t pack = 0;
	size_t place = 0;
	size_t placesSize = 0;
	num max = 0;
	string placeStr = "";

	for (pack = 0; pack < packSize; pack++) {
		placesSize = packs[pack].getPlaces().size();
		for (place = 0; place < placesSize; place++) {
			if (placesMap.count(packs[pack].getPlaces()[place]) > 0)
			{
				map<string, num>::iterator it = placesMap.find(packs[pack].getPlaces()[place]);
				if (it != placesMap.end()) {
					//auto idx = find(packs[pack].getPlaces().begin(), packs[pack].getPlaces().end(), packs[pack].getPlaces()[place]);
					it->second += packs[pack].getSoldSpots();
				}

			}
			else
			{
				placesMap.insert(pair<string, num>(packs[pack].getPlaces()[place], packs[pack].getSoldSpots()));
			}
		}
	}

	while (placesMap.size() != 0) {

		map<string, num>::iterator it;

		for (it = placesMap.begin(); it != placesMap.end(); ++it)
		{
			if (it->second >= max) {
				placeStr = it->first;
				max = it->second;
			}
		}

		mostVisitedPlaces.push_back(placeStr);
		//cout << counter << ". " << placeStr << endl << endl;
		placesMap.erase(placeStr);
		max = 0;
	}

	return mostVisitedPlaces;

}