/*
 * Suppliers.h
 *
 *  Created on: Nov 16, 2013
 *      Author: Naor Farcas & Roei Biton
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
	Suppliers():m_suppliers(){};
	virtual ~Suppliers();
	const int search_for_item(const string &name) const;
	Supplier& getSupp(int index) {return *this->m_suppliers[index];}
	void AddSup (const string &name);
    const int Quantity() {return (int)this->m_suppliers.size();}
};

#endif /* SUPPLIERS_H_ */
