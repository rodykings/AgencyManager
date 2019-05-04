#include "Agency.h"
#include "Operations.h"

int main() {
	Agency agency("agency.txt");
	agency.storeClients();
	agency.storePacks();
	string up = "    asdn  onoi   ";
	cout << trimString(up) << endl;
	return 0;
}