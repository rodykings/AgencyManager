#pragma once

#include <string>
#include <iostream>
#include "inputValidation.h"

using namespace std;

class Date {
public:
	Date();
	Date(num year, num month, num day);
	Date(string yearMonthDay);// yearMonthDaymust be in format "yyyy/mm/dd"
	Date(string message, string& value);
	bool dateValidation(string date);
	void setYear(num year);
	void setMonth(num month);
	void setDay(num day);
	void setDate(num year, num month, num day);
	num getYear() const;
	num getMonth() const;
	num getDay() const;
	string getDate()const;  // returns the date in format "yyyy/mm/dd"
	void show() const;       // shows the date on the screen in format "yyyy/mm/dd"
	bool isValid();
	bool isEqualTo(const Date &date);
	bool isNotEqualTo(const Date &date);
	bool isAfter(const Date &date);
	bool isBefore(const Date &date);
private:
	num year;
	num month;
	num day;
	num numOfDays(num year, num month);
};