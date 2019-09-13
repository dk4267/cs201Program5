#include "Register.h"
#include <string>
#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;


Register::Register() {
	numProducts = 0;
}

void Register::AddProduct(Product* p) {
	//Makes sure the limit of 50 items is not surpassed, then adds the Product pointer to the end of the numProducts array
	if (numProducts < 50) {
		prodList[numProducts] = p;
		numProducts += 1;
	}
}

void Register::PrintReceipt(ostream& out) {
	out << "****************************************" << endl;
	out << "*            UMKC BOOKSTORE            *" << endl;
	out << "****************************************" << endl;
	out << endl;
	out << "Qty Description                  Total  " << endl;
	out << "--- ---------------------------- -------" << endl;

	//Calculate the total by looping through prodList
	double total = 0.00;
	for (int i = 0; i < numProducts; i++) {
		prodList[i]->Print(out);
		total += prodList[i]->CalculateTotal();
	}
	out << endl;
	out << "Grand total: $" << total << endl;
	out << "Items sold: " << numProducts << endl;
	out << endl;
	out << "* Thank you for shopping at our store! *";
}

Register::~Register() {
	//delete prodList to free up the memory
	delete[] prodList;
	prodList = NULL;
}
