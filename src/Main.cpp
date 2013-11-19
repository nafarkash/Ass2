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
    Customers* cust = new Customers();
    
	string a= "a";
    
	List_input(a, supp, ingre);
    Compute_Price(a,prod,ingre);
    Read_Commands (a, prod, supp, cust);
   // std::cout<< ingre->getIngre(14)->getName() << " "<<ingre->getIngre(14)->getPos(2) << " " << ingre->getIngre(14)->getSize()<< " " << ingre->getIngre(14)->getPrice() << std::endl;
    
    delete supp;
    delete ingre;
    
	return 0;
}


