/*
 * Ingredients.cpp
 *
 *  Created on: Nov 16, 2013
 *      Author: Naor Farcas & Roei Biton
 */


#include "../include/Ingredients.h"


const int Ingredients::search_for_item (const string &name) const{
	int ans =-1;
	for (unsigned int i=0; i<m_ingredients.size() && ans == -1; i++){
		if (m_ingredients[i]->getName() == name){
			ans =i;
		}
	}
	return ans;
}

void Ingredients::AddIngre(const string &name,const string &sup,const double price){
	Ingredient* tmp= new Ingredient(name,sup,price);
	this->m_ingredients.push_back(tmp);
}

Ingredients::~Ingredients() {
    for (unsigned int i=0; i<m_ingredients.size(); i++) {
        delete m_ingredients[i];
    }
}




