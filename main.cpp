#include "Agency.h"
#include "Operations.h"

int main() {
	Agency agency("agency.txt");
	agency.storeClients();
	agency.storePacks();
	return 0;
}