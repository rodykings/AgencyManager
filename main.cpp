#include "Agency.h"
#include "Operations.h"
#include "Menu.h"

int main() {
	Agency agency("agency.txt");
	
	bool moreOperations = true;
	do {
		mainMenu(agency, moreOperations);
	} while (moreOperations);

	agency.storeClients();
	agency.storePacks();
	return 0;
}