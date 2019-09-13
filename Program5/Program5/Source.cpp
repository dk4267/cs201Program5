//Debbie Kirchner
//dkkbd@mail.umkc.edu
//CS201 program 5
//4/6/2019

#include "Product.h"
#include "Shirt.h"
#include "OfficeSupplies.h"
#include "Register.h"

#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

int main() {

	ifstream in;
	ofstream out;
	string type;
	string description;
	string size;
	int count;
	int quantity;
	double price;

	//declare a Register object so that items can be added to its array
	Register reggie;

	in.open("products.txt");
	//Each item is either a SHIRT or SUPPLIES - an object is made depending on which type the item is
	//Info is then added to that object, and finally it is added to the Register object's array
	while (!in.eof()) {
		getline(in, type);
		if (type == "SHIRT") {
			Shirt* s = new Shirt;
			getline(in, description);
			s->SetDescription(description);
			in >> size;
			s->SetSize(size);
			in >> quantity;
			s->SetQuantity(quantity);
			in >> price;
			s->SetPrice(price);
			in.ignore();
			in.ignore();
			reggie.AddProduct(s);
		}
		else {
			OfficeSupplies* o = new OfficeSupplies;
			getline(in, description);
			o->SetDescription(description);
			in >> count;
			o->SetCount(count);
			in >> quantity;
			o->SetQuantity(quantity);
			in >> price;
			o->SetPrice(price);
			in.ignore();
			in.ignore();
			reggie.AddProduct(o);
		}
	}

	in.close();

	//Prints the final receipt from the Register object's array
	out.open("receipt.txt");
	reggie.PrintReceipt(out);
	out.close();

	//Deletes the array inside the Register object
	reggie.~Register();

	return 0;
}