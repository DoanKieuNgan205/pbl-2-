#include "User.h"
#include "Vector.h"
#include "Pair.h" 
#include <iostream>
#include <stdexcept>

User::User(string id, const string& name, const string& email, const string& phone, const string& password)
    : userId(id), name(name), email(email), phone(phone), password(password) {}

bool User::login(string email, string password) {

    const int maxAttempts = 3; 
    int loginAttempts = 0;

    while (loginAttempts < maxAttempts) {
        if (this->email == email && this->password == password) {
            cout << "Login successful for user: " << name << endl;
            return true; 
        } else {
            loginAttempts++;
            cout << "Login failed. Attempt " << loginAttempts << " of " << maxAttempts << "." << endl;

            if (loginAttempts >= maxAttempts) {
                char recover;
                cout << "Too many failed attempts. Do you want to recover your password? (y/n): ";
                cin >> recover;

                if (recover == 'y' || recover == 'Y') {
                    recoverPassword(); 
                } else {
                    cout << "Please try logging in again later." << endl;
                }
            } else {
                cout << "Enter email: ";
                cin >> email;
                cout << "Enter password: ";
                cin >> password;
            }
        }
    }
    return false; 
}


void User::logout() {
    char choice;
    cout << "Ban co muon dang xuat khong? (y/n): ";
    cin >> choice;

    if (choice == 'y' || choice == 'Y') {
    cout << "User " << name << " has logged out." << endl;
    }
}

string User::displayInfo() const {
    cout << "User ID: " << userId << endl;
    cout << "Name: " << name << endl;
    cout << "Email: " << email << endl;
    cout << "Phone: " << phone << endl;
}

void User::sendRecoveryCode() {
    recoveryCode = to_string(rand() % 900000 + 100000); 
    cout << "A recovery code has been sent to " << email << ": " << recoveryCode << endl;
}

void User::recoverPassword() {
    cout << "Recovering password for user: " << name << endl;
    // Logic to recover password, e.g., sending a recovery email
    cout << "Please enter your registered phone number or email to receive a recovery code." << endl;

    string input;
    cout << "Enter phone or email: ";
    cin >> input;

    if (input == phone || input == email) {
            cout << "Recovery code has been sent to " << (input == phone ? "your phone." : "your email.") << endl;
            cout << "Please enter the recovery code to reset your password." << endl;

        sendRecoveryCode(); 

        string enteredCode;
        cout << "Enter the recovery code: ";
        cin >> enteredCode;

    if (enteredCode == recoveryCode) { 
            cout << "Recovery successful. Please enter your new password: ";
            string newPassword;
            cin >> newPassword;
            password = newPassword;
            cout << "Your password has been reset successfully." << endl;
        } else {
            cout << "Invalid recovery code. Please try again." << endl;
        }
    } else {
            cout << "Invalid contact information. Cannot proceed with password recovery." << endl;
    } 

}



    

    
    
        
        
    


