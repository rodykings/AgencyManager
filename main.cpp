#include "Agency.h"
#include "Operations.h"

int main() {
	Agency agency("agency.txt");
	agency.storeClients();
	agency.storePacks();
	vector<num> pos = agency.searchPacksByDest();
	for (size_t i = 0; i < pos.size(); i++)
		cout << pos[i] << endl;
	return 0;
}