/*
 * Suppliers.h
 *
 *  Created on: Nov 16, 2013
 *      Author: roeibit
 */

#ifndef SUPPLIERS_H_
#define SUPPLIERS_H_
#include <vector>
#include "Supplier.h"
using namespace std;

class Suppliers {
    
private:
	vector< Supplier * > m_suppliers;
    
public:
	Suppliers();
	virtual ~Suppliers();
	int search_for_item(string &name);
	Supplier * getSupp(int index) {return this->m_suppliers[index];}
	void AddSup (string &name);
    int Quantity() {return this->m_suppliers.size();}
};

#endif /* SUPPLIERS_H_ */
