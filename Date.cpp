#include "Date.h"

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

void Date::setYear(unsigned int y) {
	year = y;
}

void Date::setMonth(unsigned int m) {
	month = m;
}

void Date::setDay(unsigned int d) {
	day = d;
}

void Date::setDate(unsigned int y, unsigned int m, unsigned int d) {
	year = y;
	month = m;
	day = d;
}

unsigned int Date::getYear() const {
	return year;
}

unsigned int Date::getMonth() const {
	return month;
}

unsigned int Date::getDay() const {
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

unsigned int Date::numOfDays(unsigned int y, unsigned int m) {

	bool isLeap = false;

	if ((y % 400 == 0) || (y % 4 == 0 && y % 100 != 0))
		isLeap = true;

	switch (m) {
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
	else
		return false;
}

bool Date::isNotEqualTo(const Date &date) {
	return !isEqualTo(date);
}

bool Date::isAfter(const Date &date) {

	if (date.getYear() < year)
		return true;
	else if (date.getYear() > year)
		return false;
	else {
		if (date.getMonth() < month)
			return true;
		else if (date.getMonth() > month)
			return false;
		else {
			if (date.getDay() < day)
				return true;
			else if (date.getDay() > day)
				return false;
			else
				return false;
		}
	}
}

bool Date::isBefore(const Date &date) {
	if (isNotEqualTo(date) && !isAfter(date))
		return true;
	else
		return false;
}

