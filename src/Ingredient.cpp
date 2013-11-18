/*
 * Ingredient.cpp
 *
 *  Created on: Nov 16, 2013
 *      Author: roeibit
 */

#include "../include/Ingredient.h"

Ingredient::Ingredient(){
   
}
Ingredient::Ingredient(const string &name, string &supp, double price) : name_(name), supplier_(supp), price_(price){
}


Ingredient::~Ingredient() {
	// TODO Auto-generated destructor stub
}

