#include <ctime>  // time and localtime
#include "date.h"
#include <iostream>
#include <ostream>
#include <istream>

int Date::daysPerMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

Date::Date() {
	time_t timer = time(0); // time in seconds since 1970-01-01
	tm* locTime = localtime(&timer); // broken-down time
	year = 1900 + locTime->tm_year;
	month = 1 + locTime->tm_mon;
	day = locTime->tm_mday;
}

Date::Date(int y, int m, int d) : year(y), month(m), day(d) {}

int Date::getYear() const {
	return year;
}

int Date::getMonth() const {
	return month;
}

int Date::getDay() const {
	return day;
}

void Date::setDay(int d) {
	day = d;
}
void Date::setMonth(int m)  {
	month = m;
}

void Date::setYear(int y)  {
	year = y;
}


void Date::next() {
	++day;
	if (day > daysPerMonth[month-1]) {
		day = 1;
		++month;
		if (month > 12) {
			month = 1;
			++year;
		}
	}
}
std::ostream& operator<<(std::ostream& os, const Date& dt)
{
	os << dt.getYear() << '-' << dt.getMonth() << '-' << dt.getDay();
	return os;
}

std::istream& operator>> (std::istream& is, Date& dt)
{
	int day, month, year;
	char ch1, ch2;
	if (is >> year >> ch1 >> month >> ch2 >> day)
	{
		if (ch1 == '-' && ch2 == '-' && day > 0 && day < 32 && year > 0 && year < 9999 && month > 0 && month < 13) {

			dt.setDay(day);
			dt.setMonth(month);
			dt.setYear(year);
		} else {
			is.setstate(std::ios::failbit);
		}

	}

	return is;
}





