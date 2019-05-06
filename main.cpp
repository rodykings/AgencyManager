#include "Agency.h"
#include "Operations.h"
#include "Menu.h"

int main() {
	Agency agency("agency.txt");
	mainMenu(agency);
	agency.storeClients();
	agency.storePacks();
	return 0;
}