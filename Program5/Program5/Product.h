#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
#include <fstream>
using namespace std;

class Product
{
public:
	Product();
	//Default constructor, sets all values to either 0 or empty strings

	Product(double inPrice, int inQuantity);
	//Overloaded constructor, takes a price and quantity as parameters and sets those values. Sets description to empty string

	void SetPrice(double inPrice);
	//Setter which sets the price of each item

	void SetQuantity(int inQuantity);
	//Setter which sets the quantity of the items

	void SetDescription(string inDescription);
	//Setter which sets the item's description

	virtual void Print(ostream& out) = 0;
	//Pure virtual function, prints item's data into a given output stream

	virtual double CalculateTotal();
	//Virtual function which calculates the total price of the item by multiplying price by quantity

	~Product();
	//Class destructor

protected:
	double price;
	int quantity;
	string description;
};

#endif