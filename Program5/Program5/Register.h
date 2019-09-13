#ifndef REGISTER_H
#define REGISTER_H

#include "Product.h"
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

class Register
{
public:
	Register();
	//Default constructor, initializes numProducts to zero

	void AddProduct(Product* p);
	//Adds a pointer to a Product object to prodList

	void PrintReceipt(ostream& out);
	//Prints a receipt with the info from each product in prodList

	~Register();
	//Class destructor, deletes prodList

private:
	int numProducts;
	Product** prodList = new Product*[50];
	//A array of pointers to Product objects. Since Product is an abstract class, this array can hold either
	//Shirt or OfficeSupplies objects
};

#endif
