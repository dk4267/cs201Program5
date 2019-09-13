#include "Product.h"
#include <string>
#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;


Product::Product() {
	price = 0.00;
	quantity = 0;
	description = "";
}

Product::Product(double inPrice, int inQuantity) {
	price = inPrice;
	quantity = inQuantity;
	description = "";
}

void Product::SetPrice(double inPrice) {
	price = inPrice;
}

void Product::SetQuantity(int inQuantity) {
	quantity = inQuantity;
}

void Product::SetDescription(string inDescription) {
	description = inDescription;
}

void Product::Print(ostream& out) {
	//This class's version of the Print function is never actually used, since it is a virtual function
	out << setw(3) << right << quantity << " ";
	out << setw(28) << left << description << " ";
	out << setw(7) << left << "$" << right << fixed << setprecision(2) << CalculateTotal() << endl;
}

double Product::CalculateTotal() {
	//This is also a virtual function, and the one from this class is also never actually used
	return (quantity * price);
}

Product::~Product()
{
}
