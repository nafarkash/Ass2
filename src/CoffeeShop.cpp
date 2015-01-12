/*
 * CoffeeShop.cpp
 *
 *  Created on: Nov 16, 2013
 *      Author: Naor Farcas & Roei Biton
 */

#include <stdlib.h>
#include <iostream>
#include "../include/CoffeeShop.h"

CoffeeShop::CoffeeShop(const char* log):profit(0),revenue(0),img(){
	string line;
	vector <string> tokens;
	vector <string> input_tok;
	ifstream fs("/Users/naorfarkash/Desktop/workspace/Ass2/Ass2/log.conf");
	if (fs.is_open()){
        // running till the end of the file
		while (getline (fs,line)) {
			tokens = Split_Line(line, '=');
			input_tok.push_back(tokens[1]);
		}
        
		LoggerParams loggerParams(input_tok[0],atoi(input_tok[1].c_str()),atoi(input_tok[2].c_str()));
		CAppLogger::InitializeLoggerParams(loggerParams);
	} else {
        LoggerParams loggerParams("Default_Logger.log",5,5);
        CAppLogger::InitializeLoggerParams(loggerParams);
        string err(log);
        CAppLogger::Instance().Log(err + " not found.",Poco::Message::PRIO_FATAL);
	}
    
	
    fs.close();
}


vector<string> CoffeeShop::Split_Line (string &line, char sign){
    vector<string> ans;
    // find first occurrence of "sign" in the string
    int dif = (int)line.find_first_of(sign);
    string token;
    while (dif!=-1){
        dif = line.find_first_of(sign);
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

void CoffeeShop::List_input (const char* file_name, Suppliers &suppliers, Ingredients &ingredients){
    
    int Iindex=-1, Sindex=-1;
    // N == products name, S == products Supllier, P == product price.
    string line, N, S, P;
    vector<string> tokens;
    
<<<<<<< Updated upstream
	fs.open("/Suppliers.conf", fstream::in);
=======
	ifstream fs("/Users/naorfarkash/Desktop/workspace/Ass2/Ass2/Suppliers.conf");
>>>>>>> Stashed changes
	if (fs.is_open()){
        
        // running till the end of the file
		while (getline (fs,line)) {
            //seperates the sentence into tokens
            tokens = Split_Line(line, ',');
            S = tokens[0];
            N = tokens[1];
            P = tokens[2];
            
            
            // search_for_item func returns the place of the product 'N' in the vector 'name' if found
            // otherwise returns -1;
            Iindex = ingredients.search_for_item(N);
            if (Iindex != -1){
                if (atof(P.c_str())<ingredients.getIngre(Iindex).getPrice()){ //replace if cheaper
                	ingredients.getIngre(Iindex).setPrice(atof(P.c_str()));
                	ingredients.getIngre(Iindex).setSupplier(S);
                }
                
            }
            else {
            	ingredients.AddIngre(N,S,atof(P.c_str()));
            }
            
            // pushing supplier & respective price to ingredients vectors
            if (Iindex==-1) {
                ingredients.getIngre(ingredients.Quantity()-1).AddSup(S);
                ingredients.getIngre(ingredients.Quantity()-1).AddPrice(atof(P.c_str()));
            }
            else {
                ingredients.getIngre(Iindex).AddSup(S);
                ingredients.getIngre(Iindex).AddPrice(atof(P.c_str()));
            }
            
            Sindex = suppliers.search_for_item(S);
            if (Sindex == -1){
            	suppliers.AddSup(S);
            }
            //creating ingredient list for the supplier
            if (Sindex==-1) {
                if (Iindex==-1) {
                    suppliers.getSupp(suppliers.Quantity()-1).AddIngre(&ingredients.getIngre(ingredients.Quantity()-1));
                }
                else {
                    suppliers.getSupp(suppliers.Quantity()-1).AddIngre(&ingredients.getIngre(Iindex));
                }
                
            }
            else {
                if (Iindex==-1) {
                    suppliers.getSupp(Sindex).AddIngre(&ingredients.getIngre(ingredients.Quantity()-1));
                }
                else {
                    suppliers.getSupp(Sindex).AddIngre(&ingredients.getIngre(Iindex));
                }
            }
        }
        
	}else{
		string err(file_name);
		CAppLogger::Instance().Log(err + " not found.",Poco::Message::PRIO_CRITICAL);
	}
    
	fs.close();
    
}


void CoffeeShop::Compute_Price(const char* file_name, Products &products, Ingredients &ingredients){
    
    vector<string> tokens;
    int index = -1;
    double summer=0;
    string line;
    
<<<<<<< Updated upstream
	fs.open("/Products.conf", fstream::in);
=======
	ifstream fs("/Users/naorfarkash/Desktop/workspace/Ass2/Ass2/Products.conf");
>>>>>>> Stashed changes
	if (fs.is_open()){
        // running till the end of the file
		while (getline (fs,line)) {
            summer = 0;
            //seperates the sentence into tokens
            tokens = Split_Line(line, ',');
            if (tokens.size()!=0){   // not pushing empty lines into vector
                products.AddProd(tokens);
                for (unsigned int i=1; i<tokens.size();i++){
                    index = ingredients.search_for_item(tokens[i]);
                    summer+=ingredients.getIngre(index).getPrice();
                    int pos = products.search_for_item(tokens[0]);
                    ingredients.getIngre(index).AddProd(&products.returnProd(pos));
                }
                summer = (summer+0.25)*1.5;
                products.returnProd(products.Quantity()-1).setPrice(summer);
                
            }
        }
    }else{
		string err(file_name);
		CAppLogger::Instance().Log(err + " not found.",Poco::Message::PRIO_CRITICAL);
	}
    
    fs.close();
}


void CoffeeShop::Read_Commands (const char* file_name, Products  &products, Suppliers &suppliers, Customers &customers){
    vector<string> tokens;
    int index = -1;
    string line, curr_Supp;
    Ingredient* curr_Ingre;
    double c_price =0;
    
    
<<<<<<< Updated upstream
	fs.open("/events.conf", fstream::in);
=======
	ifstream fs("/Users/naorfarkash/Desktop/workspace/Ass2/Ass2/events.conf");
>>>>>>> Stashed changes
	if (fs.is_open()){
        
        // running till the end of the file
		while (getline (fs,line)) {
            //seperates the sentence into tokens
            tokens = Split_Line(line, ',');
            if (tokens.size()!=0){   // not pushing empty lines into vector
                if (tokens[0]=="register") {
                    index = products.search_for_item(tokens[2]);
                    customers.AddCustomer(tokens[1], &products.returnProd(index), atoi(tokens[3].c_str()));
                    if (atoi(tokens[3].c_str())==1){
                    	CAppLogger::Instance().Log("New VIP Customer registered - "+tokens[1]+", Favorite product - "+tokens[2]+".",Poco::Message::PRIO_NOTICE);
                    }else {
                    	CAppLogger::Instance().Log("New regular Customer registered - "+tokens[1]+", Favorite product - "+tokens[2]+".",Poco::Message::PRIO_NOTICE);
                    }
                    
                }
                else if (tokens[0] == "purchase"){
                	vector < int > curr_cust = img.FindFaces(tokens[1], customers);
                	for (uint i = 0 ; i < curr_cust.size(); i++){
                		c_price = customers.getCust(curr_cust[i]).getProd()->getPrice();
                		c_price = customers.getCust(curr_cust[i]).computeProductPrice(c_price);
                		if (customers.getCust(curr_cust[i]).getProd()->getPrice() <= 5){
                            
                			//Accumulating revenue and profit
                			revenue += c_price;
                			profit += c_price-((customers.getCust(curr_cust[i]).getProd()->getPrice())/1.5);
                			CAppLogger::Instance().Log("Customer "+customers.getCust(curr_cust[i]).getName()+" purchased "+customers.getCust(curr_cust[i]).getProd()->getName(),Poco::Message::PRIO_WARNING);
                		}else{
                			CAppLogger::Instance().Log("Customer "+customers.getCust(curr_cust[i]).getName()+" failed to purchase "+customers.getCust(curr_cust[i]).getProd()->getName(),Poco::Message::PRIO_WARNING);
                		}
                	}
                }
                else if (tokens[0]=="supplier_change") {
                    index = suppliers.search_for_item(tokens[1]);
                    // finding the ingredient. Assuming ingredient exists
                    int i=0;
                    while (suppliers.getSupp(index).getIngre(i)->getName()!=tokens[2]) {
                        i++;
                    }
                    curr_Ingre = suppliers.getSupp(index).getIngre(i);
                    curr_Supp = suppliers.getSupp(index).getName();
                    int updated=0;
                    Update_Price(curr_Ingre, atof(tokens[3].c_str()), curr_Supp, &updated);
                    string msg = "Supplier "+curr_Supp+" change the price of "+curr_Ingre->getName();
                    CAppLogger::Instance().Log(msg,Poco::Message::PRIO_NOTICE);
                    ostringstream up;
                    up << updated;
                    string str_up = up.str();
                    CAppLogger::Instance().Log("Products updated: "+str_up,Poco::Message::PRIO_NOTICE);
                }
            }
        }
    }else{
		string err(file_name);
		CAppLogger::Instance().Log(err + " not found.",Poco::Message::PRIO_CRITICAL);
	}
    fs.close();
}


void CoffeeShop::Update_Price (Ingredient* Curr_Ingre, double price, string &supplier, int* updated){
    double lowest = 0;
    int i=0;
    string newSupp=supplier;
    // finding the ingrediets supplier
    while (Curr_Ingre->getVSuppliers(i)!=supplier) {
        i++;
    }
    Curr_Ingre->setVPrices(i, price);
    
    if (price < Curr_Ingre->getPrice()) {
        //the ingredient price is lowered
        Update_Price_Helper(Curr_Ingre, price, supplier, updated);
    }
    // the cheapest supplier has increased his price, find the cheapest
    else if (price > Curr_Ingre->getPrice() && Curr_Ingre->getSupplier()==supplier){
        // find the lowest price
        lowest = Curr_Ingre->getVprices(0);
        newSupp = Curr_Ingre->getVSuppliers(0);
        for (int i=1; i<Curr_Ingre->PriceQuan(); i++) {
            if (Curr_Ingre->getVprices(i) < lowest){
                lowest = Curr_Ingre->getVprices(i);
                newSupp = Curr_Ingre->getVSuppliers(i);
            }
        }
        //the products price is increased
        Update_Price_Helper(Curr_Ingre, lowest, newSupp, updated);
    }
    
}

//This function updates the products price
void CoffeeShop::Update_Price_Helper(Ingredient* Curr_Ingre, double price, string &supplier, int* updated){
    double dif = 0, newPrice, oldPrice;
    
    dif = Curr_Ingre->getPrice() - price;
    Curr_Ingre->setSupplier(supplier);
    Curr_Ingre->setPrice(price);
    //Running through all the Products with this ingredient & change their price
    for (int i =0; i<Curr_Ingre->ProdQuan(); i++) {
    	if (Curr_Ingre->getProd(i)->getPrice()<= 5){(*updated)++;}
    	oldPrice=Curr_Ingre->getProd(i)->getPrice();
        //retrieve the original price & change it by dif
        newPrice = Curr_Ingre->getProd(i)->getPrice()/1.5 - 0.25 - dif;
        newPrice = (newPrice+0.25)*1.5;
        Curr_Ingre->getProd(i)->setPrice(newPrice);
        if (oldPrice<=5 && newPrice > 5 ){
        	CAppLogger::Instance().Log("Product "+Curr_Ingre->getProd(i)->getName()+" was removed from the menu.",Poco::Message::PRIO_WARNING);
        }
        if (oldPrice>5 && newPrice <= 5 ){
        	CAppLogger::Instance().Log("Product "+Curr_Ingre->getProd(i)->getName()+" was added to the menu.",Poco::Message::PRIO_WARNING);
        }
    }
    
    
    
}
void CoffeeShop::collage_and_profit(Customers& customers){
	ostringstream rev;
	rev << revenue;
	string str_rev = rev.str();
    ostringstream prof;
	prof << profit;
	string str_prof = prof.str();
	CAppLogger::Instance().Log("The total revenue is "+ str_rev+", while the total profit is "+str_prof,Poco::Message::PRIO_WARNING);
	img.collage(customers);
}
