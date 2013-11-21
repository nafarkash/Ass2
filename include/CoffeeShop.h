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
#include "Customers.h"

using namespace std;

#ifndef COFFEESHOP_H_
#define COFFEESHOP_H_



vector<string> Split_Line (string &line);
void List_input (string &file_name, Suppliers &suppliers, Ingredients &ingredients);
void Compute_Price(string &file_name, Products &products, Ingredients &ingredients);
void Read_Commands (string &file_name, Products &products, Suppliers &suppliers, Customers &customers);
void Update_Price (Ingredient* Curr_Ingre, double price, string &supplier);
void Update_Price_Helper(Ingredient* Curr_Ingre, double price, string &supplier);


#endif /* COFFEESHOP_H_ */
