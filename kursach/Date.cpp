//
// Created by ADMiN on 24.12.2018.
//

#include <iostream>
#include "Date.h"

Date::Date(){
    this->year = 2018;
    this->month = 1;
    this->day = 1;
}

Date::Date(int y, int m, int d){
    this->year = y;
    this->month = m;
    this->day = d;
}

Date::Date(Date &date){
    this->year = date.year;
    this->month = date.month;
    this->day = date.day;
}

Date::~Date(){}

int Date::getYear() const {
    return year;
}

int Date::getMonth() const {
    return month;
}

int Date::getDay() const {
    return day;
}

void Date::setYear(int y) {
    Date::year = y;
}

void Date::setMonth(int m) {
    Date::month = m;
}

void Date::setDay(int d) {
    Date::day = d;
}

void Date::input() {
    inputYear();
    inputMonth();
    inputDay();
}

void Date::inputYear() {
    char input[32];
    do {
        std::cout << "Input year: ";
        std::cin >> input;
        year = atof(input);
        fflush(stdin);
    } while (year <= 2015 || year >= 2020);
}

void Date::inputMonth() {
    char input[32];
    do {
        std::cout << "Input month: ";
        std::cin >> input;
        month = atof(input);
        fflush(stdin);
    } while (month <= 0 || month > 12);
}

void Date::inputDay() {
    char input[32];
    do {
        std::cout << "Input day: ";
        std::cin >> input;
        day = atof(input);
        fflush(stdin);
    } while (day <= 0 || day > 31);
}

std::ostream &operator<<(std::ostream &os, const Date &date) {
    os << "Year: " << date.year << " Month: " << date.month << "Day: " << date.day;
    return os;
}

void Date::operator=(const Date &date){

    this->setYear(date.getYear());
    this->setMonth(date.getMonth());
    this->setDay(date.getDay());

}