//
// Created by ADMiN on 24.12.2018.
//
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <cstdio>
#include <iostream>
#include "Ticket.h"


Ticket::Ticket() : Order(), Truck() {


}

Ticket::Ticket(const Ticket &ticket) {
    consumption = ticket.consumption;
    carrying = ticket.carrying;

    planned = ticket.getDate();

    target = new char[strlen(ticket.target) + 1];

    strcpy(target, ticket.target);

    length = ticket.length;

    weight = ticket.weight;

    price = ticket.price;
}

Ticket::Ticket(int y, int m, int d, const char *tar, float len, float wei, float cary, float cons) : Truck(cary,cons), Order(y, m, d, tar, len, wei){

}

Ticket::Ticket(const Order &order, const Truck &truck){

    consumption = truck.getConsumption();
    carrying = truck.getCarrying();

    planned = order.getDate();

    target = new char[strlen(order.getTarget()) + 1];

    strcpy(target, order.getTarget());

    length = order.getLength();

    weight = order.getWeight();

    price = getPrice();
}

std::ostream &operator<<(std::ostream &os, Ticket &ticket) {
    os << ticket.getDate() << "Length: " << ticket.length << "Weight: " << ticket.weight
       << "Target: " << ticket.target <<"Carrying: " << ticket.carrying << " Fuel consumption: " << ticket.consumption
       << "Order price: " << ticket.price;
    return os;
}

Ticket::~Ticket() {



}

void Ticket::input() {

    Order::input();
    Truck::input();

}

void Ticket::operator=(const Ticket &ticket){

    this->setDate(ticket.getDate());
    this->setWeight(ticket.getWeight());
    this->setLength(ticket.getLength());
    this->setTarget(ticket.getTarget());
    this->setCarrying(ticket.getCarrying());
    this->setConsumption(ticket.getConsumption());

}