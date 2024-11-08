#pragma once
#include "User.h"
#include "Product.h"
#include "Order.h"
#include "Vector.h"
#include <string>
using namespace std;

class Manager : public User {
private:
    string managerId;
    string department; // Bộ phận quản lý
    string level;  // Cấp bậc của quản lý

public:
    Manager(string id, const string& name, const string& department, string level);

    string getManagerId() const;
    void setManagerId(int id);

    void addProduct(Vector<Product>& products); 

    void updateProductStock(Vector<Product>& products, int productId, int newStock);

    string viewOrders(const Vector<Order>& orders) const;

    string updateUserInfo();

    string getDepartment() const {
        return department;
    }

    string getLevel() const {
        return level;
    }
};
