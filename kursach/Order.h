//
// Created by ADMiN on 26.12.2018.
//
#pragma once
#ifndef COURSE_ORDER_H
#define COURSE_ORDER_H

#include <ostream>
#include "Date.h"

class Order{

protected:
    char *target;// пунк назначения
    float length; // в км
    float weight; // в тоннах
    Date planned;
    float price;

private:

    void inputTarget();

    void inputLength();

    void inputWeight();

public:

    Order();

    Order(int y, int m, int d, const char *tar, float len, float wei);

    Order(Order &order);

    ~Order();

    float getLength() const;

    float getWeight() const;

    float getPrice() const;

    char* getTarget() const;

    const Date& getDate() const;

    void setLength(float len);

    void setWeight(float wei);

    void setPrice(float pri);

    void setTarget(char* tar);

    void setDate(int y, int m, int d);

    void setDate(const Date &date);

    void input();

    void operator=(const Order &order);

    friend std::ostream &operator<<(std::ostream &os, const Order &order);

};

#endif //COURSE_ORDER_H
