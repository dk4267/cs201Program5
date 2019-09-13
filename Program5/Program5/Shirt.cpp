#include "Shirt.h"
#include <string>
#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;


Shirt::Shirt() {
	size = "";
}

void Shirt::SetSize(string inSize) {
	size = inSize;
}

void Shirt::Print(ostream& out) {
	//Outputs the info so that it looks pretty on the receipt
	out << setw(3) << right << quantity << " ";
	out << left << size << " ";
	out << setw(27 - size.length()) << left << description << " ";
	out << left << "$";
	out << setw(6) << right << fixed << setprecision(2) << CalculateTotal() << endl;
}

double Shirt::CalculateTotal() {
	//Adds $1 to a shirt if its size is 2XL or 3XL, but only when it's the first time that the function has been called
	if ((size == "2XL") || (size == "3XL")) {
		if (plusSizeTax == 0) {
			price += 1.00;
			plusSizeTax = 1;
		}
	}
	return (quantity * price);
}



Shirt::~Shirt()
{
}
