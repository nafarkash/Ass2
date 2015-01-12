/*
 * CoffeeShop.cpp
 *
 *  Created on: Nov 16, 2013
 *      Author: roeibit
 */

#include <stdlib.h>
#include <iostream>
#include "../include/CoffeeShop.h"


vector<string> Split_Line (string &line){
    vector<string> ans;
    // find first occurrence of ',' in the string
    unsigned long dif = line.find_first_of(",");
    string token;
    while (dif!=-1){
        dif = line.find_first_of(",");
        if (dif!=-1){
            token = line.substr(0,dif);
        }
        else{
            token = line.substr(0,line.size());
        }
        ans.push_back(token);
        // work on substring of line from "," occurrence
        line = line.substr(dif+1);
        
    }
    return ans;
}

void List_input (string &file_name, Suppliers &suppliers, Ingredients &ingredients){
    
	fstream fs;
    int Iindex=-1, Sindex=-1;
    // N == products name, S == products Supllier, P == product price.
    string line, N, S, P;
    vector<string> tokens;
    
	fs.open("/Suppliers.conf", fstream::in);
	if (fs.is_open()){
        
        // running till the end of the file
		while (getline (fs,line)) {
            //seperates the sentence into tokens
            tokens = Split_Line(line);
            S = tokens[0];
            N = tokens[1];
            P = tokens[2];
            
            
            // search_for_item func returns the place of the product 'N' in the vector 'name' if found
            // otherwise returns -1;
            Iindex = ingredients.search_for_item(N);
            if (Iindex != -1){
                if (atof(P.c_str())<ingredients.getIngre(Iindex)->getPrice()){ //replace if cheaper
                	ingredients.getIngre(Iindex)->setPrice(atof(P.c_str()));
                	ingredients.getIngre(Iindex)->setSupplier(S);
                }
                
            }
            else {
            	ingredients.AddIngre(N,S,atof(P.c_str()));
            }
            
            // pushing supplier & respective price to ingredients vectors
            if (Iindex==-1) {
                ingredients.getIngre(ingredients.Quantity()-1)->AddSup(S);
                ingredients.getIngre(ingredients.Quantity()-1)->AddPrice(atof(P.c_str()));
            }
            else {
                ingredients.getIngre(Iindex)->AddSup(S);
                ingredients.getIngre(Iindex)->AddPrice(atof(P.c_str()));
            }
         
            Sindex = suppliers.search_for_item(S);
            if (Sindex == -1){
            	suppliers.AddSup(S);
            }
            //creating ingredient list for the supplier
            if (Sindex==-1) {
                if (Iindex==-1) {
                    suppliers.getSupp(suppliers.Quantity()-1)->AddIngre(ingredients.getIngre(ingredients.Quantity()-1));
                }
                else {
                   suppliers.getSupp(suppliers.Quantity()-1)->AddIngre(ingredients.getIngre(Iindex));
                }
                
            }
            else {
                if (Iindex==-1) {
                    suppliers.getSupp(Sindex)->AddIngre(ingredients.getIngre(ingredients.Quantity()-1));
                }
                else {
                    suppliers.getSupp(Sindex)->AddIngre(ingredients.getIngre(Iindex));
                }
            }
		}
        
	}
    
	fs.close();
    
}


void Compute_Price(string &file_name, Products &products, Ingredients &ingredients){
    
    fstream fs;
    vector<string> tokens;
    int index = -1;
    double summer=0;
    string line;
    
	fs.open("/Products.conf", fstream::in);
	if (fs.is_open()){
        // running till the end of the file
		while (getline (fs,line)) {
            summer = 0;
            //seperates the sentence into tokens
            tokens = Split_Line(line);
            if (tokens.size()!=0){   // not pushing empty lines into vector
                products.AddProd(tokens);
                for (unsigned int i=1; i<tokens.size();i++){
                    index = ingredients.search_for_item(tokens[i]);
                    summer+=ingredients.getIngre(index)->getPrice();
                    int pos = products.search_for_item(tokens[0]);
                    ingredients.getIngre(index)->AddProd(products.returnProd(pos));
                }
                summer = (summer+0.25)*1.5;
                products.returnProd(products.Quantity()-1)->setPrice(summer);
                
            }
        }
    }
    fs.close();
}


void Read_Commands (string &file_name, Products  &products, Suppliers &suppliers, Customers &customers){
    fstream fs;
    vector<string> tokens;
    int index = -1;
    string line, curr_Supp;
    Ingredient* curr_Ingre;
    
    
	fs.open("/events.conf", fstream::in);
	if (fs.is_open()){
        
        //cout << products.returnProd(0)->getName() << " " << products.returnProd(0)->getPrice()<<endl;
      
        // running till the end of the file
		while (getline (fs,line)) {
            //seperates the sentence into tokens
            tokens = Split_Line(line);
            if (tokens.size()!=0){   // not pushing empty lines into vector
                if (tokens[0]=="register") {
                    index = products.search_for_item(tokens[2]);
                    customers.AddCustomer(tokens[1], products.returnProd(index), atoi(tokens[3].c_str()));
                }
                else if (tokens[0]=="purchase"){
                    
                }
                else if (tokens[0]=="supplier_change") {
                    index = suppliers.search_for_item(tokens[1]);
                    // finding the ingredient. Assuming ingredient exists
                    int i=0;
                    while (suppliers.getSupp(index)->getIngre(i)->getName()!=tokens[2]) {
                        i++;
                    }
                    curr_Ingre = suppliers.getSupp(index)->getIngre(i);
                    curr_Supp = suppliers.getSupp(index)->getName();
                    
                    cout<< "price " << suppliers.getSupp(index)->getIngre(i)->getPrice() << endl;
                    cout << products.returnProd(8)->getName() << " " << products.returnProd(8)->getPrice()<<endl;

                    Update_Price(curr_Ingre, atof(tokens[3].c_str()), curr_Supp);
                    
                    cout<< "price " << suppliers.getSupp(index)->getIngre(i)->getPrice() << endl;
                    cout << products.returnProd(8)->getName() << " " << products.returnProd(8)->getPrice()<<endl;

                }
            }
        }
    }
    fs.close();
}


void Update_Price (Ingredient* Curr_Ingre, double price, string &supplier){
    double lowest = 0;
    if (price<Curr_Ingre->getPrice()) {
        //the products price is lowered
        Update_Price_Helper(Curr_Ingre, price, supplier);
    }
    // the cheapest supplier has increased his price, find the cheapest
    else if (price>Curr_Ingre->getPrice() && Curr_Ingre->getSupplier()==supplier){
        // find the lowest price
        lowest = Curr_Ingre->getVprices(0);
        for (int i=1; i<Curr_Ingre->PriceQuan(); i++) {
            if (Curr_Ingre->getVprices(i)<lowest){
                lowest = Curr_Ingre->getVprices(i);
            }
        }
        //the products price is increased
        Update_Price_Helper(Curr_Ingre, lowest, supplier);
    }
    int i=0;
    // finding the ingrediets supplier
    while (Curr_Ingre->getVSuppliers(i)!=supplier) {
        i++;
    }
    Curr_Ingre->setVPrices(i, price);
    Curr_Ingre->setVSuppliers(i, supplier);
}

//This function updates the products price
void Update_Price_Helper(Ingredient* Curr_Ingre, double price, string &supplier){
    double dif = 0, newPrice;
    
    dif = Curr_Ingre->getPrice() - price;
    Curr_Ingre->setSupplier(supplier);
    Curr_Ingre->setPrice(price);
    //Running through all the Products with this ingredient & change their price
    for (int i =0; i<Curr_Ingre->ProdQuan(); i++) {
        //retrieve the original price & change it by dif
        newPrice = Curr_Ingre->getProd(i)->getPrice()/1.5 - 0.25 - dif;
        newPrice = (newPrice+0.25)*1.5;
        Curr_Ingre->getProd(i)->setPrice(newPrice);
    }

}
