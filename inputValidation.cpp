#include "inputValidation.h"


string errorMessage() {
	return "Invalid input! Try again!\n";
}

void inputString(string message,string &value) {

	cout << endl << message;
	getline(cin, value);

}

void inputInt(string message, int &value) {

	cout << endl << message;
	cin >> value;
	while (cin.fail()) {
		cout << errorMessage();
		cout << message;
		cin >> value;
	}
	
}
void inputInt(string message, num& value, num size){

	cout << endl << message;
	cin >> value;
	while (cin.fail() || to_string(value).length() != size) {
		cout << errorMessage();
		cout << message;
		cin >> value;
	}
}

void inputPlaces(vector<string> &places) {

	string newPlace;
	inputString("Main Place:", newPlace);
	places.push_back(newPlace);

	while (yesOrNo("Do you want o insert a new Place to visit?")) {
		inputString("New Place:", newPlace);
		places.push_back(newPlace);
	}


}

bool yesOrNo(string message)
{
	char input;
	cout << message; cin >> input;

	while (toupper(input) != 'Y' && toupper(input) != 'N') {
		cin.clear();
		cin.ignore(1000, '\n');
		cerr << "Invalid input! [y/n] ? ";
		cin >> input;
	}

	if (toupper(input) == 'Y')
		return true;
	return false;
}

