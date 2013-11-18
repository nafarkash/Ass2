/*
 * Products.h
 *
 *  Created on: Nov 16, 2013
 *      Author: roeibit
 */

#ifndef PRODUCTS_H_
#define PRODUCTS_H_
#include <vector>
#include "Product.h"
using namespace std;

class Products {
private:
	vector< Product * > m_products;
public:
	Products();
	virtual ~Products();
    void AddProd (vector<string> &vec);
    int search_for_item (string &name);
    Product* returnProd (int index) {return m_products[index];}
    int Quantity() {return this->m_products.size();}
};
#endif /* PRODUCTS_H_ */
