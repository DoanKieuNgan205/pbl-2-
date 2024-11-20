#pragma once
#include "User.h"
#include "Model/User.h"
#include "Model/Product.h"
#include "Model/Orders.h"
#include "Datastructures/Vector.h"
#include <string>
using namespace std;
class Manager : public User {
public:
    Manager();
    Manager(const string& id, const string& name, const string& email, const string& phone, const string& password, const string& address);
    void updateProductStock(Vector<Product>& productList, const string& productId, int newStock);
    void addNewProduct(Vector<Product>& productList, const Product& newProduct);
    void deleteProduct(Vector<Product>& productList, const string& productId);
};
