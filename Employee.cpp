#include "Employee.h"

Employee::Employee(string id, const string& name, const string& position, double salary)
        : User(id, name, email, phone, password), position(position), salary(salary) {
        userId = id;
        this->name = name;
        this->email = email;
        this->phone = phone;
        this->password = password;
    }

void Employee::createInvoice() {
        int orderId;
        string productName;
        double price;
        int quantity;

        cout << "Nhap ma don hang: ";
        cin >> orderId;
        cout << "Nhap ten san pham: ";
        cin.ignore(); 
        getline(cin, productName);
        cout << "Nhap gia san pham: ";
        cin >> price;
        cout << "Nhap so luong: ";
        cin >> quantity;

        Order order(orderId, productName, price, quantity);
        cout << "Hoa don duoc tao boi nhan vien: " << name << " (" << position << ")" << endl;
        order.displayOrderDetails();

    }

string Employee::displayInfo() const {
        cout << "ID: " << userId << endl;
        cout << "Ten: " << name << endl;
        cout << "Email: " << email << endl;
        cout << "Dien thoai: " << phone << endl;
        cout << "Chuc vu: " << position << endl;
    }

string Employee::getEmployeeId() const { return employeeId; }
void Employee::setEmployeeId(string id) { employeeId = id; }

double Employee::getSalary() const {return salary;}

void Employee::setSalary(double newSalary){
    if (newSalary >= 0) { 
            salary = newSalary;
        }
}


string Employee::updateEmployeeInfo() {
        cout << "Update employee information:" << endl;
        string newName, newEmail, newPhone;

        cout << "Enter new name: ";
        cin >> newName;
        setName(newName);

        cout << "Enter new email: ";
        cin >> newEmail;
        setEmail(newEmail);

        cout << "Enter new phone: ";
        cin >> newPhone;
        setPhone(newPhone);

        cout << "Employee information updated!" << endl;
    }