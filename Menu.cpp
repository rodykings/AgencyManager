#include "Menu.h"



void mainMenu(Agency agency) {
	system("cls");

	const string line = "----------------------------------------------------------";

	int option;
	bool fail = false;

	do {
		fail = false;

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

		cout << "OPTION:";

		cin >> option;

		if (cin.fail()) {
			if (cin.eof()) {
				exit(1);
			}
			cin.clear();
			cin.ignore();
			system("cls");
			fail = true;
		}
		else if (option <= 0 || option > 10) {
			system("cls");
			fail = true;
		}
		else
			fail = false;

	} while (fail);

	int nif;
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