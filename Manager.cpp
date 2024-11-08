#include "Manager.h"
#include <iostream>

Manager::Manager(string id, const string& name, const string& department, string level)
    : User(id, name, email, phone, password){
        userId = id;
        this->name = name;
        this->email = email;
        this->phone = phone;
        this->password = password;
    }

void Manager::addProduct(Vector<Product>& products) { 
    char choice;
    cout << "Quan ly co muon them san pham moi khong? (y/n): ";
    cin >> choice;

    if (choice == 'y' || choice == 'Y') {
        int id;
        string name;
        double price;
        int quantity;

        cout << "Nhap thong tin san pham moi:" << endl;
        cout << "ID san pham: ";
        cin >> id;
        cout << "Ten san pham: ";
        cin.ignore();
        getline(cin, name);
        cout << "Gia san pham: ";
        cin >> price;
        cout << "So luong san pham: ";
        cin >> quantity;

        Product newProduct(id, name, price, quantity);
        products.pushback(newProduct);

        cout << "Da them san pham moi thanh cong!" << endl;
    }
}

void Manager::updateProductStock(Vector<Product>& products, int productId, int newStock) {
    bool found = false;
    for (int i = 0; i < products.getSize(); ++i) {
        if (products[i].getId() == productId) {
            products[i].setStock(newStock);
            cout << "Da cap nhat so luong san pham co ID " << productId << " thanh: " << newStock << endl;
            found = true;
            break;
        }
    }

    while (!found) {
        char choice;
        cout << "Khong tim thay san pham voi ma nay. Ban co muon thu lai khong? (y/n): ";
        cin >> choice;

        if (choice == 'y' || choice == 'Y') {
            cout << "Vui long nhap lai ma san pham: ";
            cin >> productId;
            cout << "Vui long nhap lai so luong moi: ";
            cin >> newStock;

            for (int i = 0; i < products.getSize(); ++i) {
                if (products[i].getId() == productId) {
                    products[i].setStock(newStock);
                    cout << "Cap nhat thanh cong so luong san pham." << endl;
                    found = true;
                    break;
                }
            }
        } else {
            cout << "Khong cap nhat so luong san pham." << endl;
            break;
        }
    }
}

string Manager::viewOrders(const Vector<Order>& orders) const {
    char choice;
    cout << "Ban co muon xem danh sach cac don hang da dat khong? (y/n): ";
    cin >> choice;

    if (choice == 'y' || choice == 'Y') {
        cout << "Danh sach don hang:" << endl;
        for (int i = 0; i < orders.getSize(); ++i) {
            orders[i].displayOrderDetails();
            cout << "-------------------" << endl;
        }
    } else {
        cout << "Khong hien thi danh sach don hang." << endl;
    }
}

string Manager::getManagerId() const { return managerId; }
void Manager::setManagerId(int id) { managerId = id; }

string Manager::updateUserInfo() {
        cout << "Update user information:" << endl;
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

        cout << "User information updated!" << endl;
    }
