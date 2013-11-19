/*
 * Products.cpp
 *
 *  Created on: Nov 16, 2013
 *      Author: roeibit
 */

#include "../include/Products.h"

Products::Products() {
	// TODO Auto-generated constructor stub
    
}

void Products::AddProd (vector<string> &vec){
    Product* tmp = new Product(vec);
    m_products.push_back(tmp);
}

int Products::search_for_item (string &name){
	int ans =-1;
	for (unsigned int i=0; i<m_products.size() && ans == -1; i++){
		if (m_products[i]->getName() == name){
			ans =i;
		}
	}
	return ans;
}

Products::~Products() {
    for (int i=0; i<m_products.size(); i++) {
        delete m_products[i];
    }
}




