//
// Created by ADMiN on 26.12.2018.
//
#pragma once


#include <ostream>

class Truck{

protected:
    float carrying; //грузоподьемность в тоннах
    float consumption; //  в литрах/100км

private:

    void inputCarrying();

    void inputConsumption();

public:

    Truck();

    Truck(float cary, float cons);

    Truck(Truck &truck);

    ~Truck();

    float getCarrying() const;

    float getConsumption() const;

    void setCarrying(float cary);

    void setConsumption(float cons);

    void input();

    void operator=(const Truck &truck);

    friend std::ostream &operator<<(std::ostream &os, const Truck &truck);

};


