//
//  RegularCustomer.cpp
//  Ass2
//
//  Created by naorfarkash on 19/11/13.
//  Copyright (c) 2013 naorfarkash. All rights reserved.
//

#include "../include/Customer.h"
RegularCustomer::RegularCustomer(){
    
}

RegularCustomer::RegularCustomer(string &name, Product* prod){
    name_ = name;
    m_Prod = prod;
}



double RegularCustomer::computeProductPrice(double originalPrice){
    return originalPrice;
}

RegularCustomer::~RegularCustomer(){
    
}