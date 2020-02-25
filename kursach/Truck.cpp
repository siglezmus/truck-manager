//
// Created by ADMiN on 24.12.2018.
//

#include <iostream>
#include "Truck.h"

Truck::Truck(){
    this->carrying = 2.0;
    this->consumption = 15.0;
}

Truck::Truck(float cary, float cons){
    this->carrying = cary;
    this->consumption = cons;
}

Truck::Truck(Truck &truck){
    this->carrying = truck.carrying;
    this->consumption = truck.consumption;
}

Truck::~Truck(){}

float Truck::getConsumption() const {
    return consumption;
}

float Truck::getCarrying() const {
    return carrying;
}

void Truck::setConsumption(float cons) {
    Truck::consumption = cons;
}

void Truck::setCarrying(float cary) {
    Truck::carrying = cary;
}

void Truck::input() {
    inputCarrying();
    inputConsumption();
}

void Truck::inputConsumption(){
    char input[32];
    do {
        std::cout << "Input fuel consumption in l/100km: ";
        std::cin >> input;
        consumption = atof(input);
        fflush(stdin);
    } while (consumption  < 0.0 || consumption  > 50.0);
}

void Truck::inputCarrying(){
    char input[32];
    do {
        std::cout << "Input carrying in tons: ";
        std::cin >> input;
        carrying = atof(input);
        fflush(stdin);
    } while (carrying < 0.0 || carrying > 100.0);
}

std::ostream &operator<<(std::ostream &os, const Truck &truck) {
    os << "Carrying: " << truck.carrying << " Fuel consumption: " << truck.consumption;
    return os;
}

void Truck::operator=(const Truck &truck){

    this->setCarrying(truck.getCarrying());
    this->setConsumption(truck.getConsumption());

}