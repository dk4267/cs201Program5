#ifndef SHIRT_H
#define SHIRT_H

#include "Product.h"
#include <string>
#include <fstream>
using namespace std;

class Shirt :
	public Product
{
public:
	Shirt();
	//Default destructor, sets shirt size equal to an empty string

	void SetSize(string inSize);
	//Setter which sets the size for the shirt

	void Print(ostream& out);
	//Prints the information for the shirt into an output stream: quantity, size, description, and price

	double CalculateTotal();
	//Calculates the total price of the shirt, and adds $1 to each shirt if it is size 2XL or 3XL

	~Shirt();
	//Class destructor

private: 
	string size;
	int plusSizeTax = 0;
	//plusSizeTax is only added if its value is zero - this makes sure that it is only added once even if the CalculateTotal()
	//function is called more than once
};

#endif