//
// Created by ADMiN on 26.12.2018.
//


#pragma once

#include <ostream>

class Date{
    int year;
    int month;
    int day;

    void inputYear();

    void inputMonth();

    void inputDay();

public:

    Date();

    Date(int y, int m, int d);

    Date(Date &date);

    ~Date();

    void setYear(int y);

    void setMonth(int m);

    void setDay(int d);

    int getYear() const;

    int getMonth() const;

    int getDay() const;

    void input();

    void operator=(const Date &date);

    friend std::ostream &operator<<(std::ostream &os, const Date &date);

};


