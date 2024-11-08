#include "Controller/DataController.h"
#include "Datastructures/Vector.h"
#include "Datastructures/Pair.h"
#include "Model/Product.h"
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <filesystem>
using namespace std;


void DataController::saveEmployeeData(const Vector<Employee>& employees) {
    string filePath = "Data/Employee.csv";
    
    ofstream file(filePath);
    if (!file.is_open()) {
        cerr << "Không thể mở file để ghi: " << filePath << endl;
        return;
    }

    file << "ID,Name,Position,Salary\n";
    for (long i = 0; i < employees.getSize(); ++i) {
        const Employee& employee = employees[i];
        file << employee.getEmployeeId() << ","
             << employee.getName() << ","
             << employee.getPosition() << ","
             << employee.getSalary() << "\n";
    }

    file.close();
}

Vector<Employee> DataController::loadEmployeeData() {
    Vector<Employee> employees;
    string filePath = "Data/Employee.csv";
    
    ifstream file(filePath);
    if (!file.is_open()) {
        cerr << "Không thể mở file để đọc: " << filePath << endl;
        return employees;
    }

    string line;
    getline(file, line); 

    while (getline(file, line)) {
        stringstream ss(line);
        string id, name, position;
        double salary;

        getline(ss, id, ',');
        getline(ss, name, ',');
        getline(ss, position, ',');
        ss >> salary;

        Employee employee(id, name, position, salary);
        employees.pushback(employee);
    }

    file.close();
    return employees;
}

void DataController::saveCustomerData(const Vector<Customer>& customers) {
    string filePath = "Data/Customer.csv";
    
    ofstream file(filePath);
    if (!file.is_open()) {
        cerr << "Không thể mở file để ghi: " << filePath << endl;
        return;
    }

    file << "ID,Name,Email,Phone\n";
    for (long i = 0; i < customers.getSize(); ++i) {
        const Customer& customer = customers[i];
        file << customer.getId() << ","
             << customer.getName() << ","
             << customer.getEmail() << ","
             << customer.getPhone() << "\n";
    }

    file.close();
}

Vector<Customer> DataController::loadCustomerData() {
    Vector<Customer> customers;
    string filePath = "Data/Customer.csv";
    
    ifstream file(filePath);
    if (!file.is_open()) {
        cerr << "Không thể mở file để đọc: " << filePath << endl;
        return customers;
    }

    string line;
    getline(file, line); 

    while (getline(file, line)) {
        stringstream ss(line);
        string id, name, email, phone;

        getline(ss, id, ',');
        getline(ss, name, ',');
        getline(ss, email, ',');
        getline(ss, phone, ',');

        Customer customer(id, name, email, phone);
        customers.pushback(customer);
    }

    file.close();
    return customers;
}

void DataController::saveManagerData(const Vector<Manager>& managers) {
    string filePath = "Data/Manager.csv";
    
    ofstream file(filePath);
    if (!file.is_open()) {
        cerr << "Không thể mở file để ghi: " << filePath << endl;
        return;
    }

    file << "ID,Name,Department,Level\n";
    for (long i = 0; i < managers.getSize(); ++i) {
        const Manager& manager = managers[i];
        file << manager.getManagerId() << ","
             << manager.getName() << ","
             << manager.getDepartment() << ","
             << manager.getLevel() << "\n";
    }

    file.close();
}

Vector<Manager> DataController::loadManagerData() {
    Vector<Manager> managers;
    string filePath = "Data/Manager.csv";
    
    ifstream file(filePath);
    if (!file.is_open()) {
        cerr << "Không thể mở file để đọc: " << filePath << endl;
        return managers;
    }

    string line;
    getline(file, line); 

    while (getline(file, line)) {
        stringstream ss(line);
        string id, name, department, level;

        getline(ss, id, ',');
        getline(ss, name, ',');
        getline(ss, department, ',');
        getline(ss, level, ',');

        Manager manager(id, name, department, level);
        managers.pushback(manager);
    }

    file.close();
    return managers;
}