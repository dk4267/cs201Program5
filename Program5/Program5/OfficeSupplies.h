#ifndef OFFICE_SUPPLIES_H
#define OFFICE_SUPPLIES_H

#include "Product.h"
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

class OfficeSupplies :
	public Product
{
public:
	OfficeSupplies();
	//Default constructor, sets the item count equal to zero

	void SetCount(int inCount);
	//Setter which sets the item's count

	void Print(ostream& out);
	//Prints the item's info into an output stream: quantity, description, count, and price

	~OfficeSupplies();
	//Class destructor

private:
	int count;
};

#endif