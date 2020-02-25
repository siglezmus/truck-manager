#pragma once
//
// Created by ADMiN on 25.12.2018.
//

#include "Trip.h"

class Balance {

private:
	Trip *list;
	int num;
	int numInput();

public:

	Balance();
	~Balance();
	Balance(Trip *balance, int amount);
	Trip &operator[](int i);
	void show();
	int getNum() const;
	void setNum(int n);
	void input();
	void addTrip(const Trip &trip);
	Trip *getBalance();
	friend std::ostream &operator<<(std::ostream &os, Balance &balance);

};


