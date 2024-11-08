#pragma once
#include "Model/User.h"
#include "Model/Employee.h"
#include "Model/Manager.h"
#include "Model/Product.h"
#include "Model/Cart.h"
#include  "Datastructures/Vector.h"
#include <vector>
#include <string>
using namespace std; 

class DataController {
public:

    void saveEmployeeData(const Vector<Employee>& employees);
    Vector<Employee> loadEmployeeData();
    void saveCustomerData(const Vector<Customer>& customers);
    Vector<Customer> loadCustomerData();
    void saveManagerData(const Vector<Manager>& managers);
    Vector<Manager> loadManagerData();

};


