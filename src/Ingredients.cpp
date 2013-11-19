/*
 * Ingredients.cpp
 *
 *  Created on: Nov 16, 2013
 *      Author: roeibit
 */


#include "../include/Ingredients.h"

Ingredients::Ingredients() {
    
    
}


int Ingredients::search_for_item (string &name){
	int ans =-1;
	for (unsigned int i=0; i<m_ingredients.size() && ans == -1; i++){
		if (m_ingredients[i]->getName() == name){
			ans =i;
		}
	}
	return ans;
}

void Ingredients::AddIngre(string &name, string &sup, double price){
	Ingredient* tmp= new Ingredient(name,sup,price);
	this->m_ingredients.push_back(tmp);
}

Ingredients::~Ingredients() {
    for (int i=0; i<m_ingredients.size(); i++) {
        delete m_ingredients[i];
    }
}




