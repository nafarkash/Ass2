/*
 * Products.h
 *
 *  Created on: Nov 16, 2013
 *      Author: Naor Farcas & Roei Biton
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
	Products():m_products(){};
	virtual ~Products();
    void AddProd (vector<string> &vec);
    const int search_for_item (const string &name) const;
    Product& returnProd (int index) {return *this->m_products[index];}
    const int Quantity() {return (int)this->m_products.size();}
};
#endif /* PRODUCTS_H_ */
