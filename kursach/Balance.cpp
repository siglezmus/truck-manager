//
// Created by ADMiN on 25.12.2018.
//

#include "Balance.h"
#include "Trip.h"
#include <iostream>
#include <iomanip>

using namespace std;


Balance::Balance() {
	list = new Trip[0];
	num = 0;
}

Balance::~Balance() {
	delete[] list;
}

Balance::Balance(Trip *balance, int amount) {
	num = amount;

	list = new Trip[num];
	for (int i = 0; i < num; i++)
	{
		list[i] = balance[i];
	}
}

Trip & Balance::operator[](int i)
{
	//if (i < 0 || i > num - 1)
		//throw ExceptionOutOfRange("Out of range");
		return list[i];
}

int Balance::getNum() const {
	return num;
}

Trip* Balance::getBalance() {
	return list;
}

void Balance::setNum(int n) {
	num = n;
}

void Balance::show() {
	std::cout << "Number of trips: " << num << std::endl;

	for (int i = 0; i < num; i++)
	{
		std::cout << list[i] << std::endl;
	}
}

void Balance::addTrip(const Trip &trip) {

	Trip *temp = list;
	list = new Trip[num + 1];
	for (int i = 0; i < num; i++) {
		list[i] = temp[i];
	}
	list[num] = trip;
	num++;
	delete[] temp;
}

int Balance::numInput() {

	char input[8];
	int size = -1;
	do {
		cout << "Input size(size>0): ";
		cin >> input;
		size = atof(input);
		fflush(stdin);
	} while (size <= 0);
	return size;
}

void Balance::input() {

	int size = numInput();
	
	for (int i = 0; i < size; ++i) {
		Trip trip;
		trip.input();
		addTrip(trip);
	}

}



ostream &operator<<(ostream &os, Balance &balance) {
	os << left << setw(6) << "Planned year" << left << setw(3) << "Planned month" << left << setw(3) << "Planned day"
		<< left << setw(20) << "Length of trip in km" << left << setw(20) << "Weight in tons" << left << setw(25) << "Auto carrying in tons"
		<< left << setw(30) << "Fuel consumption in l/100km" << left << setw(20) << "Order price in usd" << left << setw(6) << "Release year"
		<< left << setw(3) << "Release month" << left << setw(3) << "Release day" << left << setw(15) << "Consumed fuel"
		<< endl;
	for (int i = 0; i < balance.getNum(); i++) {

		os << left << setw(6) << balance[i].getTicket().getDate().getYear()
			<< left << setw(3) << balance[i].getTicket().getDate().getMonth()
			<< left << setw(3) << balance[i].getTicket().getDate().getDay()
			<< left << setw(20) << balance[i].getTicket().getLength()
			<< left << setw(20) << balance[i].getTicket().getWeight()
			<< left << setw(25) << balance[i].getTicket().getCarrying()
			<< left << setw(30) << balance[i].getTicket().getConsumption()
			<< left << setw(20) << balance[i].getTicket().getPrice()
			<< left << setw(6) << balance[i].getRelease().getYear()
			<< left << setw(3) << balance[i].getRelease().getMonth()
			<< left << setw(3) << balance[i].getRelease().getDay()
			<< left << setw(15) << balance[i].getConsumed()


			<< endl;
	}
	return os;
}


