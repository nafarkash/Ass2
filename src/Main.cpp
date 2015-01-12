/*
 * Main.cpp
 *
 *  Created on: Nov 16, 2013
 *      Author: Naor Farcas & Roei Biton
 */


#include "../include/Main.h"
#include <iostream>
int main(int argc, char* argv[]){
    if (argc==5){
        Products prod;
        Suppliers supp;
        Ingredients ingre;
        Customers cust;
        CoffeeShop sim(argv[1]);
        
        sim.List_input(argv[3], supp, ingre);
        sim.Compute_Price(argv[2],prod,ingre);
        sim.Read_Commands (argv[4], prod, supp, cust);
        sim.collage_and_profit(cust);
    }
    else {
        LoggerParams loggerParams("Logger.log",1,1);
        CAppLogger::Instance().Log("Not enough arguments. Program aborted",Poco::Message::PRIO_FATAL);
    }
    return 0;
}


