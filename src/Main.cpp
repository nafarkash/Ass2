/*
 * Main.cpp
 *
 *  Created on: Nov 16, 2013
 *      Author: roeibit
 */


#include "../include/Main.h"
#include <iostream>
int main(int argc, char* argv[]){
	Products* prod = new Products();
	Suppliers* supp = new Suppliers();
	Ingredients* ingre = new Ingredients();
	string a= "a";
    
	List_input(a, supp, ingre);
    Compute_Price(a,prod,ingre);
    
    std::cout<< prod->returnProd(12)->getName() <<" " << prod->returnProd(12)->getPrice() <<std::endl;
    
    delete supp;
    delete ingre;
    
	return 0;
}


