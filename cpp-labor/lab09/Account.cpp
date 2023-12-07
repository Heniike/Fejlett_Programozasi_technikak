//
// Created by asus on 11/25/2023.
//

#include "Account.h"

int Account::counter = 1;

Account::Account(double balance) : id(counter++), balance(balance){}

void Account::deposit(double amount) {
    balance += amount;
}

bool Account::withdraw(double amount) {
    if(amount > balance){
        cout << "Nincs elegedno penz a szamlan" << endl;
        return false;
    }
    balance -=amount;
    return true;
}

int Account::getId() const {
    return id;
}

double Account::getBalance() const {
    return balance;
}

void Account::print(ostream &os) const {
    os << "Account ID: " << id << ", balance: " << balance << endl;
}

ostream &operator<<(ostream &os, const Account &account) {
    account.print(os);
    return os;
}

