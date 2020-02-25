#define _CRT_SECURE_NO_WARNINGS
#include <math.h>
#include <iostream>
#include <fstream>
#include <cstring>
#include "Trip.h"
#include "Balance.h"

using namespace std;

template<class T>
float middle(T *list, int size) {
	float sum = 0;
	for (int i = 0; i < size; i++) {
		sum += list[i];
	}
	float middle = (sum) / size;
	return middle;
}

template<class T>
void writeToTextFile(const char *path, int size, T *objects) {
	ofstream file(path, ios::out);
	if (file.is_open()) {
		for (int i = 0; i < size; i++) {
			file << objects[i] << endl << endl;
			file.flush();

		}
		file.close();
	}

}

template<class T>
void writeToBinaryFile(const char *path, int size, T *objects) {
	ofstream file(path, ios::out | ios::binary);
	if (file.is_open()) {
		file.write((char *)objects, sizeof(T) * size);
		file.flush();
		file.close();
	}

}

template<class T>
T *readBinaryFromFile(const char *path, int size) {
	T *objects = new T[size];
	ifstream file(path, ios::in | ios::binary);
	if (file.is_open()) {
		file.read((char *)objects, sizeof(T) * size);
		file.close();
	}
	return objects;
}

int main() {

	Balance balance;


	while (true) {
		char input[32];
		int choice;
		do {
			cout << "Input choice: " << endl;
			cout << "1 - Add data" << endl;
			cout << "2 - Print the table" << endl;
			cout << "3 - Write to file" << endl;
			cout << "4 - Read from file" << endl;
			cout << "5 - Search by price" << endl;
			cout << "6 - Search by destination" << endl;
			cout << "7 - Print average length" << endl;
			cout << "8 - Print average consumed fuel" << endl;
			cout << "9 - Exit" << endl;
			cin >> input;
			choice = atoi(input);
			fflush(stdin);
		} while (choice <= 0 || choice > 9);
		switch (choice) {
		case 1:
			balance.input();
			break;
		case 2:
			cout << balance << endl << endl;
			break;
		case 3:
			writeToBinaryFile("../binary.bin", balance.getNum(), balance.getBalance());
			writeToTextFile("../text.txt", balance.getNum(), balance.getBalance());
			cout << "Data has been writen" << endl << endl;
			break;
		case 4: {
			Balance resultBalance(readBinaryFromFile<Trip>("../binary.bin", balance.getNum()), balance.getNum());
			resultBalance.show();
			break;
		}
		case 5: {
			char input1[32];
			float price;
			bool found = false;
			do {
				cout << "Input price: ";
				cin >> input1;
				price = atof(input1);
				fflush(stdin);
			} while (price <= 0);
			for (int j = 0; j < balance.getNum(); ++j) {
				if (balance[j].getTicket().getPrice() == price) {
					cout << balance[j] << endl;
					found = true;
				}
			}
			if (!found) {
				cout << "No trips with such price" << endl;
			}
			break;
			
		}
		case 6: {
			char *name = new char[32];
			cout << "Input destination: ";
			cin >> name;
			bool found = false;
			for (int j = 0; j < balance.getNum(); ++j) {
				if (strcmp(name, balance[j].getTicket().getTarget()) == 0) {
					cout << balance[j] << endl;
					found = true;
				}
			}
			if (!found) {
				cout << "No figures with such name" << endl;
			}
			break;
		}
		case 7: {
			float *lens = new float[balance.getNum()];
			for (int i = 0; i < balance.getNum(); ++i) {
				lens[i] = balance[i].getTicket().getLength();
			}
			cout << "Average length of trips is:" << middle(lens, balance.getNum()) << endl;
			break;
		}
		case 8: {
			float *consd = new float[balance.getNum()];
			for (int i = 0; i < balance.getNum(); ++i) {
				consd[i] = balance[i].getConsumed();
			}
			cout << "Average consumed fuel is:" << middle(consd, balance.getNum()) << endl;
			break;
		}
		case 9:
			return 0;
		}
	}

	
	system("pause");
    return 0;
}