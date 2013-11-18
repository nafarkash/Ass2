/*
 * Ingredients.h
 *
 *  Created on: Nov 16, 2013
 *      Author: roeibit
 */

#ifndef INGREDIENTS_H_
#define INGREDIENTS_H_
#include <vector>
#include "Ingredient.h"

using namespace std;

class Ingredients {
private:
    vector< Ingredient * > m_ingredients;
    
public:
    Ingredients();
    virtual ~Ingredients();
    void AddIngre(string &name, string &sup, double price);
    Ingredient* getIngre(int index) {return this->m_ingredients[index];}
    int search_for_item (string &name);
    int Quantity() {return this->m_ingredients.size();}
};
#endif /* INGREDIENTS_H_ */
