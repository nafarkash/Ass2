/*
 * Product.cpp
 *
 *  Created on: Nov 16, 2013
 *      Author: roeibit
 */

#include "../include/Product.h"
Product::Product(vector<string> &vec):name_(vec[0]), price_(0){
    m_ingredients = vec;
    m_ingredients.erase(m_ingredients.begin());
    
}

Product::Product() {
	// TODO Auto-generated constructor stub
    
}

void Product::AddIngre (string &name){
    m_ingredients.push_back(name);
}

Product::~Product() {
	// TODO Auto-generated destructor stub
}

