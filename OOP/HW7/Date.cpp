#include "Date.h"
int Date::get_day() const {
	return d_day;
}
int Date::get_month() const {
	return d_month;
}
int Date::get_year() const {
	return d_year;
}

void Date::set_day(int day) {
	d_day = day;
}

void Date::set_month(int month) {
	d_month = month;
}

void Date::set_year(int year) {
	d_year = year;
}

std::ostream& operator<<(std::ostream& out, const Date& date) {
	out << "Date: " << date.get_day() << "." << date.get_month() << "." << date.get_year() << "\n";
	return out;
}

Date& operator<(Date& date1, Date& date2)
{
	if (date1.d_year > date2.d_year)
		return date1;
	if (date1.d_year < date2.d_year)
		return date2;
	else {
		if (date1.d_month > date2.d_month)
			return date1;
		if (date1.d_month < date2.d_month)
			return date2;
		else {
			if (date1.d_day > date2.d_day)
				return date1;
			if (date1.d_day < date2.d_day)
				return date2;
			else
				return date1;
		}
	}
}

Date& operator>(Date& date1, Date& date2)
{
	return date2 < date1;
}
