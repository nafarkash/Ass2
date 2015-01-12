/*
 * Ingredients.h
 *
 *  Created on: Nov 16, 2013
 *      Author: Naor Farcas & Roei Biton
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
    Ingredients():m_ingredients(){};
    virtual ~Ingredients();
    void AddIngre(const string &name,const string &sup,const double price);
    Ingredient& getIngre(int index) {return *this->m_ingredients[index];}
    const int search_for_item (const string &name) const;
    const int Quantity() const {return (int)this->m_ingredients.size();}
};
#endif /* INGREDIENTS_H_ */
