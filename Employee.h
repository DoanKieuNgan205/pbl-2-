#pragma once
#include "User.h"
#include "Order.h"
#include <string>
#include <iostream>

using namespace std;

class Employee : public User {
private:
    string position; 
    string employeeId;
    string name;
    double salary;

public:
    Employee(string id, const string& name, const string& position,double salary);
        
    void createInvoice();

    string displayInfo() const ;

    string getPosition() const { return position; }
    
    void setPosition(const string& position) { this->position = position; }

    string getEmployeeId() const;
    void setEmployeeId(string id);

    double getSalary() const;
    void setSalary(double newSalary);

    string updateEmployeeInfo();

};
