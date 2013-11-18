/*
 * Product.h
 *
 *  Created on: Nov 16, 2013
 *      Author: roeibit
 */

#ifndef PRODUCT_H_
#define PRODUCT_H_
#include <vector>
#include <string>

using namespace std;

class Product {
public:
    Product(vector<string> &vec);
	Product();
	virtual ~Product();
    void AddIngre (string &name);
    string getName() {return name_;}
    double getPrice() {return price_;}
    void setPrice(double price) {price_=price;}
private:
    string name_;
    double price_;
    vector<string> m_ingredients;
};

#endif /* PRODUCT_H_ */
