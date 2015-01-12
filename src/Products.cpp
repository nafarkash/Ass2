/*
 * Products.cpp
 *
 *  Created on: Nov 16, 2013
 *      Author: Naor Farcas & Roei Biton
 */

#include "../include/Products.h"

void Products::AddProd (vector<string> &vec){
    Product* tmp = new Product(vec);
    m_products.push_back(tmp);
}

const int Products::search_for_item (const string &name) const{
	int ans =-1;
	for (unsigned int i=0; i<m_products.size() && ans == -1; i++){
		if (m_products[i]->getName() == name){
			ans =i;
		}
	}
	return ans;
}

Products::~Products() {
    for (unsigned int i=0; i<m_products.size(); i++) {
        delete m_products[i];
    }
}




