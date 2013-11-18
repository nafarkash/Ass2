/*
 * Ingredient.h
 *
 *  Created on: Nov 16, 2013
 *      Author: roeibit
 */

#ifndef INGREDIENT_H_
#define INGREDIENT_H_

#include <vector>
#include <string>
#include "Product.h"
using namespace std;

class Ingredient {
public:
    Ingredient();
	Ingredient(const string &name, string &supp, double price);
    
    void setSupplier(string &sup) {supplier_ = sup;}
	double getPrice() {return price_;}
	string getName() {return name_;}
	void setPrice (double price) {price_ = price;}
    void AddProd (Product* prod) {m_prods_.push_back(prod);}
    void AddSup (string &supp) {this->Vsuppliers_.push_back(supp);}
    void AddPrice (double price) {this->Vprices_.push_back(price);}
	virtual ~Ingredient();
    
private:
	string name_;
	string supplier_;
	double price_;
    //containers of all the Suppliers and their respective prices
    vector<string> Vsuppliers_;
    vector<double> Vprices_;
    
	vector < Product * > m_prods_;
    


    
};

#endif /* INGREDIENT_H_ */
