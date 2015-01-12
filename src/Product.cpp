/*
 * Product.cpp
 *
 *  Created on: Nov 16, 2013
 *      Author: Naor Farcas & Roei Biton
 */

#include "../include/Product.h"
Product::Product(vector<string> &vec):name_(vec[0]), price_(0), m_ingredients(){
    m_ingredients = vec;
    m_ingredients.erase(m_ingredients.begin());
    
}


void Product::AddIngre (const string &name){
    m_ingredients.push_back(name);
}

Product::~Product() {
}

