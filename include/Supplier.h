/*
 * Supplier.h
 *
 *  Created on: Nov 16, 2013
 *      Author: roeibit
 */

#ifndef SUPPLIER_H_
#define SUPPLIER_H_
#include <vector>
#include <string>
#include "Ingredient.h"
using namespace std;

class Supplier {
public:
    Supplier();
	Supplier(string &name);
	virtual ~Supplier();
    string getName() {return this->name_;}
    void AddIngre (Ingredient* ingre) {this->m_ingredients.push_back(ingre);}
private:
	const string name_;
	vector < Ingredient * > m_ingredients;
	
    
    
    
};

#endif /* SUPPLIER_H_ */
