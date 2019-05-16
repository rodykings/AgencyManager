#include "Agency.h"
#include "Operations.h"
#include "Menu.h"

int main() {
	bool readFileFail = false;
	Agency agency("agency.txt", readFileFail);
	
	if (readFileFail)
		return 1;

	bool moreOperations = true;
	do {
		mainMenu(agency, moreOperations);
	} while (moreOperations);

	system("cls");
	if (agency.clientChanges)
	{
		agency.storeClients();
		cout << "[!] Changes to clients saved successfully\n" << endl;
	}
	if (agency.packChanges) {
		agency.storePacks();
		cout << "[!] Changes to packages saved successfully\n" << endl;
	}
	return 0;
}