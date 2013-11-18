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

void List_input (string &file_name, Suppliers* suppliers, Ingredients* ingredients){
    
	fstream fs;
    int Iindex=-1, Sindex=-1;
    // N == products name, S == products Supllier, P == product price.
    string line, N, S, P;
    vector<string> tokens;
    
	fs.open("/Users/naorfarkash/Desktop/workspace/Ass2/Ass2/Suppliers.conf", fstream::in);
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
            Iindex = ingredients->search_for_item(N);
            if (Iindex != -1){
                if (atof(P.c_str())<ingredients->getIngre(Iindex)->getPrice()){ //replace if cheaper
                	ingredients->getIngre(Iindex)->setPrice(atof(P.c_str()));
                	ingredients->getIngre(Iindex)->setSupplier(S);
                }
                
            }
            else {
            	ingredients->AddIngre(N,S,atof(P.c_str()));
            }
            
            // pushing supplier & respective price to ingredients vectors
            if (Iindex==-1) {
                ingredients->getIngre(ingredients->Quantity()-1)->AddSup(S);
                ingredients->getIngre(ingredients->Quantity()-1)->AddPrice(atof(P.c_str()));
            }
            else {
                ingredients->getIngre(Iindex)->AddSup(S);
                ingredients->getIngre(Iindex)->AddPrice(atof(P.c_str()));
            }
         
            Sindex = suppliers->search_for_item(S);
            if (Sindex == -1){
            	suppliers->AddSup(S);
            }
            //creating ingredient list for the supplier
            if (Sindex==-1) {
                if (Iindex==-1) {
                    suppliers->getSupp(suppliers->Quantity()-1)->AddIngre(ingredients->getIngre(ingredients->Quantity()-1));
                }
                else {
                   suppliers->getSupp(suppliers->Quantity()-1)->AddIngre(ingredients->getIngre(Iindex));
                }
                
            }
            else {
                if (Iindex==-1) {
                    suppliers->getSupp(Sindex)->AddIngre(ingredients->getIngre(ingredients->Quantity()-1));
                }
                else {
                    suppliers->getSupp(Sindex)->AddIngre(ingredients->getIngre(Iindex));
                }
            }
		}
        
	}
    
	fs.close();
    
}


void Compute_Price(string &file_name, Products* products, Ingredients* ingredients){
    
    fstream fs;
    vector<string> tokens;
    int index = -1;
    double summer=0;
    string line;
    
	fs.open("/Users/naorfarkash/Desktop/workspace/Ass2/Ass2/Products.conf", fstream::in);
	if (fs.is_open()){
        // running till the end of the file
		while (getline (fs,line)) {
            summer = 0;
            //seperates the sentence into tokens
            tokens = Split_Line(line);
            if (tokens.size()!=0){   // not pushing empty lines into vector
                products->AddProd(tokens);
                for (unsigned int i=1; i<tokens.size();i++){
                    index = ingredients->search_for_item(tokens[i]);
                    summer+=ingredients->getIngre(index)->getPrice();
                    int pos = products->search_for_item(tokens[0]);
                    ingredients->getIngre(index)->AddProd(products->returnProd(pos));
                }
                summer = (summer+0.25)*1.5;
                products->returnProd(products->Quantity()-1)->setPrice(summer);
                
            }
        }
        std::cout<< products->returnProd(12)->getName() <<" " << products->returnProd(12)->getPrice() <<std::endl;
    }
    fs.close();
}

void Out_File (vector<vector<string> > &Shopping_list, vector<string> &Products, vector<double> &price){
    fstream Sh, Me;
    string line;
    Sh.open ("ShoppingList.out", fstream::out);
    if (Sh.is_open()){
        for (unsigned int i=0; i<Shopping_list.size(); i++) {
            line = "";
            for (unsigned int j=0; j<Shopping_list[i].size(); j++) {
                line += Shopping_list[i][j] + ",";
            }
            line = line.substr(0,line.size()-1);
            Sh << line << "\n";
        }
        
        
    }
    Sh.close();
    
    Me.open ("Menu.out", fstream::out);
    if (Me.is_open()){
        for (unsigned int i=0; i<Products.size(); i++) {
            Me << Products[i] << "," << price[i] << "\n";
        }
        
        
    }
    Me.close();
    
}




