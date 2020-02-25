//
// Created by ADMiN on 26.12.2018.
//
#pragma once
//Путевка = Ticket
#include "Order.h"
#include "Truck.h"

class Ticket: public Order, public Truck{

public:

    Ticket();
    Ticket(const Ticket &ticket);
    Ticket(const Order &order, const Truck &truck);
    Ticket(int y, int m, int d,const char *tar, float len, float wei, float cary, float cons);
    ~Ticket();
    void input();
    void operator=(const Ticket &ticket);
    friend std::ostream &operator<<(std::ostream &os, Ticket &ticket);

};

