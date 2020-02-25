//
// Created by ADMiN on 24.12.2018.
//
#define _CRT_SECURE_NO_WARNINGS

#include <cstring>
#include <cstdio>
#include <iostream>
#include "Order.h"

Order::Order(){

    planned = Date(2018,1,1);

    target = new char[5];

    strcpy(target, "none");

    length = 0.0;

    weight = 0.0;

    price = 0.0;
}

Order::Order(int y, int m, int d, const char *tar, float len, float wei){

    planned = Date(y,m,d);

    target = new char[strlen(tar) + 1];

    strcpy(target, tar);

    length = len;

    weight = wei;

    float k = 10.0; // ценна перевозки 1т груза на 1 км

    price = len*wei*k;
}

Order::Order(Order &order){

    planned = Date(order.getDate().getYear(),order.getDate().getMonth(),order.getDate().getDay());

    target = new char[strlen(order.getTarget()) + 1];

    strcpy(target, order.getTarget());

    length = order.getLength();

    weight = order.getWeight();

    price = order.getPrice();

}

Order::~Order(){
    delete[] target;
}

float Order::getLength() const{
    return length;
}

float Order::getWeight() const{
    return weight;
}

float Order::getPrice() const{
    return price;
}

char* Order::getTarget() const{
    return target;
}

const Date& Order::getDate()const{
    return planned;
}

void Order::setLength(float len){
    Order::length = len;
    float k = 10.0; // ценна перевозки 1т груза на 1 км
    price = weight*length*k;
}

void Order::setWeight(float wei){
    Order::weight = wei;
    float k = 10.0; // ценна перевозки 1т груза на 1 км
    price = weight*length*k;
}

void Order::setPrice(float pri){
    Order::price = pri;
}

void Order::setTarget(char *tar){
    Order::target = new char[strlen(tar) + 1];
    strcpy(Order::target, tar);
}

void Order::setDate(int y, int m, int d){
    planned = Date(y,m,d);
}

void Order::setDate(const Date &date){

    planned = Date(date.getYear(), date.getMonth(), date.getDay());
}

void Order::input() {

    planned.input();

    inputTarget();

    inputLength();

    inputWeight();
}


void Order::inputWeight(){
    char input[32];
    do {
        std::cout << "Input weight of order in tons: ";
        std::cin >> input;
        weight = atof(input);
        fflush(stdin);
    } while (weight < 0 || weight > 100000);

    float k = 10.0; // ценна перевозки 1т груза на 1 км

    price = weight*length*k;
}

void Order::inputLength(){
    char input[32];
    do {
        std::cout << "Input length of way in km: ";
        std::cin >> input;
        length = atof(input);
        fflush(stdin);
    } while (length < 0 || length > 100000);

    float k = 10.0; // ценна перевозки 1т груза на 1 км

    price = weight*length*k;
}

void Order::inputTarget(){
    do {
        std::cout << "Input name(from 1 to 20): ";
        std::cin >> target;
        fflush(stdin);
    } while (strlen(target) > 20 || strlen(target) < 1);
}

std::ostream &operator<<(std::ostream &os, const Order &order) {
    os << order.planned << "Length: " << order.length << "Weight: " << order.weight << "Target: " << order.target << "Price: " << order.price;
    return os;
}

void Order::operator=(const Order &order){

    this->setDate(order.getDate());
    this->setWeight(order.getWeight());
    this->setLength(order.getLength());
    this->setTarget(order.getTarget());

}