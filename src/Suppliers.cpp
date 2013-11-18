/*
 * Suppliers.cpp
 *
 *  Created on: Nov 16, 2013
 *      Author: roeibit
 */

#include "../include/Suppliers.h"



Suppliers::Suppliers() {
	//default constructor
}

int Suppliers::search_for_item (string &name){
	int ans =-1;
	for (unsigned int i=0; i<m_suppliers.size() && ans == -1; i++){
		if (m_suppliers[i]->getName() == name){
			ans =i;
		}
	}
	return ans;
}

void Suppliers::AddSup(string &name){
	Supplier * tmp = new Supplier(name);
	this->m_suppliers.push_back(tmp);
}

Suppliers::~Suppliers() {
    for (int i=0; i<m_suppliers.size(); i++) {
        m_suppliers[i]->~Supplier();
    }
}




