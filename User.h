#pragma once
#include "Vector.h"
#include "Pair.h" 
#include <string>
using namespace std;
class User {
protected:
    string userId;
    string name;
    string email;
    string phone;
    string password;
    string recoveryCode;

public:
    User(string id, const string& name, const string& email, const string& phone, const string& password);

    string getUserId() const { return userId; }
    string getName() const { return name; }
    string getEmail() const { return email; }
    string getPhone() const { return phone; }
    string getPassword() const { return password; }

    void setUserId(string id) { userId = id; }
    void setName(const string& name) { this->name = name; }
    void setEmail(const string& email) { this->email = email; }
    void setPhone(const string& phone) { this->phone = phone; }
    void setPassword(const string& password) { this->password = password; }

    bool login(const string email, const string password);
    void logout();
    string displayInfo() const;
    void recoverPassword();
    void addRecoveryOption(const string& method, const string& info);
    void sendRecoveryCode();
};