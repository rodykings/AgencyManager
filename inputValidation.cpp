#include "inputValidation.h"

void inputString(string message,string &value) {

	cout << message;
	getline(cin, value);

}

void inputInt(string message, num &value) {

	cout << message;
	cin >> value;
	while (cin.fail()) {
		errorMessage();
		cout << message;
		cin >> value;
	}
	
}
void inputInt(string message, num& value, num size){

	cout << message;
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
