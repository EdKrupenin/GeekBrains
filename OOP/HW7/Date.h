#pragma once
#include <iostream>

class Date {
    int d_day{};
    int d_month{};
    int d_year{};

public:
    Date() {}

    Date(int day, int month, int year)
        : d_day(day), d_month(month), d_year(year) {}

    Date(const Date& other) = default;

    int get_day() const;

    int get_month() const;

    int get_year() const;

    void set_day(int day);

    void set_month(int month);

    void set_year(int year);

    friend std::ostream& operator<<(std::ostream& out, const Date& date);

    friend Date& operator< (Date& date1, Date& date2);

    friend Date& operator> (Date& date1, Date& date2);
};

