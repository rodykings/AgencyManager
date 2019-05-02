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

bool dateValidation(string date)
{
	if (isdigit(date.find_first_not_of("0123456789/")))
		return false;

	if (date.length() != 10)
		return false;

	for (int i = 0; i < 4; i++)
	{
		if (!isdigit(date[i]))
			return false;
	}
	for (int j = 5; j < 7; j++)
	{
		if (!isdigit(date[j]))
			return false;
	}
	for (int x = 8; x <= 9; x++)
	{
		if (!isdigit(date[x]))
			return false;
	}
	return true;
}
