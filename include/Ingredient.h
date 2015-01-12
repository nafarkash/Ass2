/*
 * Ingredient.h
 *
 *  Created on: Nov 16, 2013
 *      Author: Naor Farcas & Roei Biton
 */

#ifndef INGREDIENT_H_
#define INGREDIENT_H_

#include <vector>
#include <string>
#include "Product.h"
using namespace std;

class Ingredient {
public:
    Ingredient():name_(""), supplier_(""), price_(0), Vsuppliers_(), Vprices_(), m_prods_(){};
	Ingredient(const string &name,const string &supp,const double price);
    
    void setSupplier(const string &sup) {supplier_ = sup;}
    void setPrice (const double price) {price_ = price;}
    void AddProd (Product* prod) {m_prods_.push_back(prod);}
    void AddSup (const string &supp) {this->Vsuppliers_.push_back(supp);}
    void AddPrice (double price) {this->Vprices_.push_back(price);}
    Product* getProd(int index) {return this->m_prods_[index];}
    double getPrice() {return price_;}
    const string& getName() {return name_;}
    const string& getSupplier() {return supplier_;}
    const string& getVSuppliers(int index) {return this->Vsuppliers_[index];}
    double getVprices(int index) {return this->Vprices_[index];}
    void setVPrices(int index, double price) {this->Vprices_[index] = price;}
    void setVSuppliers (int index,const string &supplier) {this->Vsuppliers_[index] = supplier;}
    const int ProdQuan() {return (int)this->m_prods_.size();}
    const int PriceQuan() {return (int)this->Vprices_.size();}
	virtual ~Ingredient();
    
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
