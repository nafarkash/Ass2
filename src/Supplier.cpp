/*
 * Supplier.cpp
 *
 *  Created on: Nov 16, 2013
 *      Author: Naor Farcas & Roei Biton
 */

#include "../include/Supplier.h"



Supplier::Supplier(const string &name) : name_(name), m_ingredients() {
}

Supplier::~Supplier() {
    //default destructor
}

