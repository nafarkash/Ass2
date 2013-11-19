//
//  VipCustomer.cpp
//  Ass2
//
//  Created by naorfarkash on 19/11/13.
//  Copyright (c) 2013 naorfarkash. All rights reserved.
//

#include "../include/Customer.h"
VipCustomer::VipCustomer(){
    
}
VipCustomer::VipCustomer(string &name, Product* prod){
    name_ = name;
    m_Prod = prod;
}


double VipCustomer::computeProductPrice(double originalPrice){
    return originalPrice*0.8;
}

VipCustomer::~VipCustomer(){
    
}