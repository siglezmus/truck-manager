//
// Created by ADMiN on 24.12.2018.
//
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <cstdio>
#include <iostream>
#include "Trip.h"

Trip::Trip() {
    //int y, int m, int d, char *tar, float len, float wei, float cary, float cons
    ticket = Ticket(2018,1,1,"none", 0.0f , 0.0f, 0.0f, 0.0f);
    release = Date(2018,1,1);
    consumed = 0;
}

Trip::~Trip() {

}

Trip::Trip(int y, int m, int d,const char *tar, float len, float wei, float cary, float cons,int y1, int m1, int d1) {
    ticket = Ticket(y, m, d, tar, len, wei, cary, cons);
    release = Date(y1,m1,d1);
    consumed = len/100 * cons;
}

Trip::Trip(Trip &trip) {
    ticket = Ticket(trip.getTicket().getDate().getYear(), trip.getTicket().getDate().getMonth(),trip.getTicket().getDate().getDay(), trip.getTicket().getTarget(), trip.getTicket().getLength(), trip.getTicket().getWeight(), trip.getTicket().getCarrying(), trip.getTicket().getConsumption());
    release = Date(trip.release);
    consumed = trip.consumed;
}

std::ostream &operator<<(std::ostream &os, Trip &trip) {
    os << trip.ticket << trip.release << "Consumed fuel: " << trip.consumed;
    return os;
}

Ticket& Trip::getTicket() {
    return ticket;
}

const Date& Trip::getRelease() {
    return release;
}

float Trip::getConsumed() {
    return consumed;
}

void Trip::input(){

    ticket.input();

    release.input();

    consumed = ticket.getConsumption() * ticket.getLength() / 100;
}

void Trip::operator=(const Trip &trip){

    this->ticket = trip.ticket;
    this->release = trip.release;
    this->consumed = trip.consumed;

}
