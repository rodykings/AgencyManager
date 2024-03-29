#include "Date.h"

Date::Date() {
	this->year = 0;
	this->month = 0;
	this->day = 0;
}
Date::Date(num year, num month, num day) {
	this->year = year;
	this->month = month;
	this->day = day;
}

Date::Date(string yearMonthDay) {

	string strYear;
	string strMonth;
	string strDay;

	for (int i = 0; i < 10; i++) {
		if (i < 4) {
			strYear += yearMonthDay[i];
		}
		else if (i > 4 && i < 7) {
			strMonth += yearMonthDay[i];
		}
		else if (i > 7 && i < 10) {
			strDay += yearMonthDay[i];
		}
		else {
			continue;
		}
	}

	year = stoul(strYear);
	month = stoul(strMonth);
	day = stoul(strDay);

}

void Date::setYear(num day) {
	this->year = year;
}
void Date::setMonth(num month) {
	this->month = month;
}
void Date::setDay(num d) {
	this->day = day;
}
void Date::setDate(num y, num m, num d) {
	year = y;
	month = m;
	day = d;
}

num Date::getYear() const {
	return year;
}
num Date::getMonth() const {
	return month;
}
num Date::getDay() const {
	return day;
}
string Date::getDate() const {

	string strMonth;
	if (month < 10)
		strMonth = "0" + to_string(month);
	else
		strMonth = to_string(month);

	string strDay;
	if (day < 10)
		strDay = "0" + to_string(day);
	else
		strDay = to_string(day);


	return to_string(year) + "/" + strMonth + "/" + strDay;
}

void Date::show() const {
	cout << getDate();
}

num Date::numOfDays(num year, num month) {

	bool isLeap = false;

	if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0))
		isLeap = true;

	switch (month) {
	case 1:
		return 31;
		break;
	case 2:
		if (isLeap)
			return 29;
		else
			return 28;
		break;
	case 3:
		return 31;
		break;
	case 4:
		return 30;
		break;
	case 5:
		return 31;
		break;
	case 6:
		return 30;
		break;
	case 7:
		return 31;
		break;
	case 8:
		return 31;
		break;
	case 9:
		return 30;
		break;
	case 10:
		return 31;
		break;
	case 11:
		return 30;
		break;
	case 12:
		return 31;
		break;
	}
	return 0;

}

bool Date::isValid() {

	if (day > numOfDays(year, month)) {
		return false;
	}
	if (month > 12) {
		return false;
	}

	return true;
}

bool Date::isEqualTo(const Date &date) {

	if ((year == date.getYear()) && (month == date.getMonth()) && (day = date.getDay()))
		return true;
	return false;
}

bool Date::isNotEqualTo(const Date &date) {
	return !isEqualTo(date);
}

bool Date::isAfter(const Date &date) {

	if (year < date.getYear())
		return false;
	if (month < date.getMonth())
		return false;
	if (day > date.getDay())
		return true;

	return false;

}

bool Date::isBefore(const Date &date) {
	if (this->isNotEqualTo(date) && !this->isAfter(date))
		return true;

	return false;
}



