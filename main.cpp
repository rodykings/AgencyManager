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

	agency.storeClients();
	agency.storePacks();
	return 0;
}