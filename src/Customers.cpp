//
//  Customers.cpp
//  Ass2
//
//  Created by naorfarkash on 19/11/13.
//  Copyright (c) 2013 naorfarkash. All rights reserved.
//

#include "../include/Customers.h"

void Customers::AddCustomer (string &name, Product* prod, int Vip){
    Customer* tmp;
    if (Vip){
        tmp = new VipCustomer(name,prod);
    }
    else {
        tmp = new RegularCustomer(name,prod);
    }
    
    this->m_customers.push_back(tmp);
}

Customers::~Customers(){
    for (unsigned int i=0; i<m_customers.size(); i++) {
        delete m_customers[i];
    }
    
}
