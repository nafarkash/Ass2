/*
 * Supplier.h
 *
 *  Created on: Nov 16, 2013
 *      Author: Naor Farcas & Roei Biton
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
	Supplier(const string &name);
    const string& getName() {return this->name_;}
    Ingredient* getIngre(int index) {return this->m_ingredients[index];}
    void AddIngre (Ingredient* ingre) {this->m_ingredients.push_back(ingre);}
    virtual ~Supplier();
private:
	const string name_;
	vector < Ingredient * > m_ingredients;
	
    
    
    
};

#endif /* SUPPLIER_H_ */
