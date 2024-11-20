#include "Model/Manager.h"

Manager ::Manager (){

}
Manager :: Manager(const string& id, const string& name, const string& email, const string& phone, const string& password, const string& address):User(id,name,email,phone,password,address){

}

void Manager::updateProductStock(Vector<Product>& productList, const string& productId, int newStock) {
    bool productFound = false;

    for (int i = 0; i < productList.getSize(); ++i) {
        if (productList[i].getProductId() == productId) {
            productList[i].setStock(newStock);
            productFound = true;
            cout << "Cập nhật số lượng sản phẩm thành công.\n";
            break;
        }
    }

    if (!productFound) {
        throw runtime_error("Không tìm thấy sản phẩm với ID: " + productId);
    }
}

void Manager::addNewProduct(Vector<Product>& productList, const Product& newProduct) {
    for (int i = 0; i < productList.getSize(); ++i) {
        if (productList[i].getProductId() == newProduct.getProductId()) {
            throw runtime_error("Sản phẩm với ID này đã tồn tại: " + newProduct.getProductId());
        }
    }

    productList.pushback(newProduct);
    cout << "Thêm sản phẩm mới thành công.\n";
}

void Manager::deleteProduct(Vector<Product>& productList, const string& productId) {
    bool productFound = false;

    for (int i = 0; i < productList.getSize(); ++i) {
        if (productList[i].getProductId() == productId) {
            productList.remove(i);  
            productFound = true;
            cout << "Xóa sản phẩm thành công.\n";
            break;
        }
    }

    if (!productFound) {
        throw runtime_error("Không tìm thấy sản phẩm với ID: " + productId);
    }
}
