#include "Menu.h"



void mainMenu(Agency agency) {
	system("cls");

	const string line = "----------------------------------------------------------";

	agency.showAgencyInfo();

	cout << endl << line << endl;
	cout << '|' << "                " << "   " << "       MENU      " << "   " << "                " << " | " << endl;
	cout << line << endl;
	cout << '|' << "OPERATIONS      " << " | " << "CLIENTS          " << " | " << "PACKS           " << " | " << endl;
	cout << line << endl;
	cout << '|' << "1.BUY PACK      " << " | " << "5.ADD CLIENT     " << " | " << "9.ADD PACK      " << " | " << endl;
	cout << '|' << "2.SHOW CLIENTS  " << " | " << "6.UPDATE CLIENT  " << " | " << "10.UPDATE PACK   " << " | " << endl;
	cout << '|' << "3.SHOW PACKS    " << " | " << "7.DELETE CLIENT  " << " | " << "11.DELETE PACK   " << " | " << endl;
	cout << '|' << "4.STATISTICS    " << " | " << "8.SEARCH CLIENT  " << " | " << "12.SEARCH PACK   " << " | " << endl;
	cout << line << endl;
	cout << '|' << "                " << "   " << "  CTR+Z - EXIT   " << "   " << "                " << " | " << endl;
	cout << line << endl << endl;

	int option;
	selectOption(option, 12);

	num nif;
	vector<Client> newVect;

	switch (option)
	{
	//BUY PACK	
	case 1:

		break;
	//SHOW CLIENTS	
	case 2:
		agency.showClients();
		break;
	//SHOW PACKS	
	case 3:
		agency.showPacks();
		break;
	//STATISTICS	
	case 4:
		
		break;
	//ADD CLIENT	
	case 5:
		agency.addClient();
		break;
	//UPDATE CLIENT	
	case 6:
		agency.updateClient();
		break;
	//DELETE CLIENT	
	case 7:
		agency.deleteClient();
		break;
	//SEARCH CLIENT	
	case 8:

		break;
	//ADD PACK	
	case 9:
		agency.addPack();
		break;
	//UPDATE PACK
	case 10:
		agency.updatePack();
		break;
	//DELETE PACK
	case 11:
		agency.deletePack();
		break;
	//SEARCH PACK
	case 12:
		
		break;
	default:
		break;
	}
	mainMenu(agency);
}

void updateClientMenu(int& option, Client client, Agency& agency) {
	system("cls");

	cout << "EDIT CLIENT\n";
	cout << "-----------\n" << endl;
	cout << "| 1-Edit Name | 2-Edit NIF | 3-Edit Household | 4-Edit Address |\n" << endl;

	client.show();
	cout << endl;

	selectOption(option, 4);
}

void updatePackMenu(int& option, Pack &pack, Agency& agency) {
	system("cls");

	cout << "EDIT PACK\n";
	cout << "---------\n" << endl;
	cout << "| 1-Edit Tour Sites | 2-Edit Start Date | 3-Edit End Date | 4-Edit Price | 5-Edit Number of Spots |\n" << endl;

	pack.show();
	cout << endl;

	selectOption(option, 5);
}

