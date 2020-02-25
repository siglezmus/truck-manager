//
// Created by ADMiN on 26.12.2018.
//


#pragma once
// Trip ~ Рейс
#include "Ticket.h"

class Trip{

public:

    Trip();
    ~Trip();
    Trip(int y, int m, int d,const char *tar, float len, float wei, float cary, float cons,int y1, int m1, int d1);
    Trip(Trip &trip);
    void input();
    friend std::ostream &operator<<(std::ostream &os, Trip &trip);
    Ticket& getTicket();
    float getConsumed();
    const Date& getRelease();
    void operator=(const Trip &trip);

private:

    Ticket ticket;
    float consumed;
    Date release;


};






