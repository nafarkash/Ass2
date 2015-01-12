/*
 * Product.h
 *
 *  Created on: Nov 16, 2013
 *      Author: Naor Farcas & Roei Biton
 */

#ifndef PRODUCT_H_
#define PRODUCT_H_
#include <vector>
#include <string>

using namespace std;

class Product {
public:
    Product(vector<string> &vec);
    Product():name_(""), price_(0), m_ingredients(){};
    virtual ~Product();
    void AddIngre (const string &name);
    const string& getName() {return name_;}
    const double getPrice() {return price_;}
    void setPrice(double price) {price_=price;}
private:
    string name_;
    double price_;
    vector<string> m_ingredients;
};

#endif /* PRODUCT_H_ */
