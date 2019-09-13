#include "OfficeSupplies.h"
#include <string>
#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;


OfficeSupplies::OfficeSupplies()
{
	count = 0;
}

void OfficeSupplies::SetCount(int inCount) {
	count = inCount;
}

void OfficeSupplies::Print(ostream& out) {
	//Figures out how many digits are in the count so that the output can look pretty
	int digits;
	if (count < 10) {
		digits = 1;
	}
	else if (count < 100) {
		digits = 2;
	}
	else if (count < 1000) {
		digits = 3;
	}
	else {
		digits = 4;
	}
	//Prints the output in a format that will be seen on the final receipt. Weird looking, but it works.
	out << setw(3) << right << quantity << " ";
	out << left << description << " (";
	out << left << count;
	out << setw(27 - description.length() - digits) << left << " count)";
	out << left << "$";
	out << setw(6) << right << fixed << setprecision(2) << CalculateTotal() << endl;
}

OfficeSupplies::~OfficeSupplies()
{
}
