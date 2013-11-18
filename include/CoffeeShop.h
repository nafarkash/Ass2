/*
 * CoffeeShop.h
 *
 *  Created on: Nov 16, 2013
 *      Author: roeibit
 */
#include <vector>
#include <string>
#include <fstream>

#include "Suppliers.h"
#include "Ingredients.h"
#include "Products.h"

using namespace std;

#ifndef COFFEESHOP_H_
#define COFFEESHOP_H_




void List_input (string &file_name, Suppliers* suppliers, Ingredients* ingredients);
void Compute_Price(string &file_name, Products* products, Ingredients* ingredients);
int search_for_item (vector<string> &prod, string &name);



#endif /* COFFEESHOP_H_ */
