/*
 * Ingredient.h
 *
 *  Created on: Nov 16, 2013
 *      Author: roeibit
 */

#ifndef INGREDIENT_H_
#define INGREDIENT_H_

#include <vector>
#include <string>
#include "Product.h"
using namespace std;

class Ingredient {
public:
    Ingredient();
	Ingredient(const string &name, string &supp, double price);
    
    void setSupplier(string &sup) {supplier_ = sup;}
	void setPrice (double price) {price_ = price;}
    void AddProd (Product* prod) {m_prods_.push_back(prod);}
    void AddSup (string &supp) {this->Vsuppliers_.push_back(supp);}
    void AddPrice (double price) {this->Vprices_.push_back(price);}
    Product* getProd(int index) {return this->m_prods_[index];}
    double getPrice() {return price_;}
	string getName() {return name_;}
    string getSupplier() {return supplier_;}
    string getVSuppliers(int index) {return this->Vsuppliers_[index];}
    double getVprices(int index) {return this->Vprices_[index];}
    void setVPrices(int index, double price) {this->Vprices_[index] = price;}
    void setVSuppliers (int index, string &supplier) {this->Vsuppliers_[index] = supplier;}
    int ProdQuan() {return this->m_prods_.size();}
    int PriceQuan() {return this->Vprices_.size();}
	virtual ~Ingredient();
    
    // temporary functions
    double getPos(int index) {return this->Vprices_[index];}
    int getSize() {return this->Vprices_.size();}
    
private:
	string name_;
	string supplier_;
	double price_;
    //containers of all the Suppliers and their respective prices
    vector<string> Vsuppliers_;
    vector<double> Vprices_;
    
	vector < Product * > m_prods_;
    


    
};

#endif /* INGREDIENT_H_ */
