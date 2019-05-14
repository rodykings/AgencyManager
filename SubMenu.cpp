#include "SubMenu.h"

void updateClientMenu(int& option, Client client) {
	system("cls");

	cout << "EDIT CLIENT\n";
	cout << "-----------\n" << endl;
	cout << "| 1-Edit Name | 2-Edit NIF | 3-Edit Household | 4-Edit Address |\n" << endl;

	client.show();
	cout << endl;

	selectOption(option, 4);
}

void updatePackMenu(int& option, Pack pack) {
	system("cls");

	cout << "EDIT PACK\n";
	cout << "---------\n" << endl;
	cout << "| 1-Edit Tour Sites | 2-Edit Start Date | 3-Edit End Date | 4-Edit Price | 5-Edit Number of Spots |\n" << endl;

	pack.show();
	cout << endl;

	selectOption(option, 5);
}

void statisticsMenu(int& option)
{
	cout << "STATISTICS\n";
	cout << "----------\n" << endl;
	cout << "| 1-Agency Information | 2-Most";


}