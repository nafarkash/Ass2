//
//  Customer.h
//  Ass2
//
//  Created by naorfarkash on 19/11/13.
//  Copyright (c) 2013 naorfarkash. All rights reserved.
//

#ifndef Customer_h
#define Customer_h
#include <string>
#include "Product.h"
using namespace std;

class Customer {

public:
    virtual double computeProductPrice(double originalPrice)=0;
    virtual ~Customer() {};
protected:
    string name_;
    Product* m_Prod;
    
    
};


class VipCustomer: public Customer {
public:
    VipCustomer();
    VipCustomer(string &name, Product* prod);
    double computeProductPrice(double originalPrice);
    virtual ~VipCustomer();
    
};

class RegularCustomer: public Customer {
public:
    RegularCustomer();
    RegularCustomer(string &name, Product* prod);
    double computeProductPrice(double originalPrice);
    virtual ~RegularCustomer();
};
#endif
