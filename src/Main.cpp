/*
 * Main.cpp
 *
 *  Created on: Nov 16, 2013
 *      Author: roeibit
 */


#include "../include/Main.h"
#include <iostream>
int main(int argc, char* argv[]){
	Products prod;
	Suppliers supp;
	Ingredients ingre;
    Customers cust;
    
	string a= "a";
    
	List_input(a, supp, ingre);
    Compute_Price(a,prod,ingre);
    Read_Commands (a, prod, supp, cust);
   // std::cout<< ingre->getIngre(14)->getName() << " "<<ingre->getIngre(14)->getPos(2) << " " << ingre->getIngre(14)->getSize()<< " " << ingre->getIngre(14)->getPrice() << std::endl;
    
	return 0;
}


