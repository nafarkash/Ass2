/*
 * CoffeeShop.h
 *
 *  Created on: Nov 16, 2013
 *      Author: Naor Farcas & Roei Biton
 */
#ifndef COFFEESHOP_H_
#define COFFEESHOP_H_

#include <vector>
#include <string>
#include <fstream>

#include "Suppliers.h"
#include "Ingredients.h"
#include "Products.h"
#include "Customers.h"
#include "ImgProc.h"
#include "CAppLogger.h"
#include "ImgProc.h"

using namespace std;




class CoffeeShop {
    
public:
	CoffeeShop();
	CoffeeShop(const char* log);
	void List_input (const char* file_name, Suppliers &suppliers, Ingredients &ingredients);
	void Compute_Price(const char* file_name, Products &products, Ingredients &ingredients);
	void Read_Commands (const char* file_name, Products &products, Suppliers &suppliers, Customers &customers);
	void collage_and_profit(Customers& customers);
    
private:
	vector<string> Split_Line (string &line, char sign);
	void Update_Price (Ingredient* Curr_Ingre, double price, string &supplier, int* updated);
	void Update_Price_Helper(Ingredient* Curr_Ingre, double price, string &supplier, int* updated);
	double profit;
	double revenue;
	ImgProc img;
    
    
};

#endif /* COFFEESHOP_H_ */
