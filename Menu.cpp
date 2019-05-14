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
	cout << '|' << "1.BUY PACK      " << " | " << "4.NEW CLIENT     " << " | " << "7.NEW PACK      " << " | " << endl;
	cout << '|' << "2.SHOW CLIENTS  " << " | " << "5.UPDATE CLIENT  " << " | " << "8.UPDATE PACK   " << " | " << endl;
	cout << '|' << "3.SHOW PACKS    " << " | " << "6.DELETE CLIENT  " << " | " << "9.DELETE PACK   " << " | " << endl;
	cout << line << endl;
	cout << '|' << "                " << "   " << "  10. STATISTICS " << "   " << "                " << " | " << endl;
	cout << line << endl << endl;

	int option;
	selectOption(option, 10);

	num nif;
	vector<Client> newVect;

	switch (option)
	{
		//COMPRAR PACOTE
	case 1:


		break;
		//VER clients
	case 2:
		
		break;
		//VER PACOTES
	case 3:

		break;
		//NOVO CLIENTE
	case 4:
		
		break;
		//ALTERAR CLIENTE
	case 5:
		
		break;
		//REMOVER CLIENTE
	case 6:
		
		break;
		//NOVO PACOTE
	case 7:
		
		break;
		//ALTERAR PACOTE
	case 8:
		break;
		//REMOVER PACOTE
	case 9:
		
		break;
		//exit
	case 10:
		exit(1);
		break;

	default:
		break;
	}
}

void updateClientMenu(int& option, Client client) {
	system("cls");

	cout << "EDIT CLIENT\n";
	cout << "-----------\n" << endl;
	cout << "| 1-Edit Name | 2-Edit NIF | 3-Edit | 4-Edit Household | 5-Edit Address |\n";
}