#include "inputValidation.h"

void inputString(string message,string &value) {

	cout << endl << message;
	getline(cin, value);

}

void inputInt(string message, num &value) {

	cout << endl << message;
	cin >> value;
	while (cin.fail()) {
		errorMessage();
		cout << message;
		cin >> value;
	}
	
}
void inputInt(string message, num& value, num size){

	cout << endl << message;
	cin >> value;
	while (cin.fail() || to_string(value).length() != size) {
		errorMessage();
		cout << message;
		cin >> value;
	}
}

string errorMessage() {
	return "Invalid input! Try again!\n" ;
}
