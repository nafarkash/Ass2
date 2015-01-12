/*
 * Ingredient.cpp
 *
 *  Created on: Nov 16, 2013
 *      Author: Naor Farcas & Roei Biton
 */

#include "../include/Ingredient.h"

Ingredient::Ingredient(const string &name,const string &supp,const double price) : name_(name), supplier_(supp), price_(price), Vsuppliers_(), Vprices_(), m_prods_(){
}


Ingredient::~Ingredient() {
	// TODO Auto-generated destructor stub
}

