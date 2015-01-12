//
//  Customers.h
//  Ass2
//
//  Created by naorfarkash on 19/11/13.
//  Copyright (c) 2013 naorfarkash. All rights reserved.
//

#ifndef Customers_h
#define Customers_h
#include <vector>
#include "Customer.h"
using namespace std;

class Customers {
public:
    Customers():m_customers(){};
    void AddCustomer (string &name, Product* prod, int Vip);
    Customer& getCust(int index) {return *this->m_customers[index];}
    const int Quantity() const {return (int)this->m_customers.size();}
    virtual ~Customers();
private:
    vector< Customer * > m_customers;
    
    
};

#endif
