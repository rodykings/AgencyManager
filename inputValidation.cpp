#include "inputValidation.h"


string errorMessage() {
	return "Invalid input! Try again!\n";
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

void inputString(string message,string &value) {

	cout << endl << message;
	getline(cin, value);
}

void inputInt(string message, int &value) {

	cout << endl << message;
	cin >> value;
	while (cin.fail()) {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << errorMessage();
		cout << message;
		cin >> value;
	}
}
void inputNum(string message, num& value){
	cout << message;
	cin >> value;
	while (cin.fail()) {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << errorMessage();
		cout << message;
		cin >> value;
	}
}
void inputNum(string message, num& value, num size){

	cout << message;
	cin >> value;
	while (cin.fail() || to_string(value).length() != size) {
		
		cout << errorMessage();
		cout << message;
		cin.clear();
		cin.ignore(1000, '\n');
		cin >> value;
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

void selectOption(int& option, num numOptions) {
	bool fail = true;

	do {

		cout << "Option(CTRL-Z to exit): "; cin >> option;

		if (cin.fail() || option < 1 || option > (int)numOptions)
		{
			if (cin.eof())
			{
				option = -1;
				fail = false;
				cin.clear();
			}
			else
			{
				cerr << "ERROR Invalid Option!\n";
				cin.clear();
				cin.ignore(1000, '\n');
			}
		}
		else
			fail = false;
	} while (fail);
}

Date inputDate(string message) {
	string date;
	cout << message; cin >> date;

	while (!dateValidation(date)) {
		cerr << endl << "ERROR Invalid date! \n";
		cout << message; cin >> date;
	}

	Date d(date);
	while (!d.isValid())
	{
		cerr << endl << "ERROR Invalid date! \n";
		cout << message; cin >> date;
		d = date;
	}

	return d;
}
bool validStartEnd(Date start, Date end)
{
	if (start.isBefore(end) || start.isEqualTo(end))
		return true;

	return false;
}
	
	

