#include "SubMenu.h"

void updateClientMenu(int& option, Client client) {
	system("cls");

	cout << "EDIT CLIENT\n";
	cout << "-----------\n" << endl;
	cout << "| 1-Edit Name | 2-Edit NIF | 3-Edit Household | 4-Edit Address |\n";

	cout << endl;
	client.show();
	cout << endl;

	selectOption(option, 4);
}