/*
 * Suppliers.cpp
 *
 *  Created on: Nov 16, 2013
 *      Author: Naor Farcas & Roei Biton
 */

#include "../include/Suppliers.h"




const int Suppliers::search_for_item (const string &name) const{
	int ans =-1;
	for (unsigned int i=0; i<m_suppliers.size() && ans == -1; i++){
		if (m_suppliers[i]->getName() == name){
			ans =i;
		}
	}
	return ans;
}

void Suppliers::AddSup(const string &name){
	Supplier * tmp = new Supplier(name);
	this->m_suppliers.push_back(tmp);
}

Suppliers::~Suppliers() {
    for (unsigned int i=0; i<m_suppliers.size(); i++) {
        delete m_suppliers[i];
    }
}




