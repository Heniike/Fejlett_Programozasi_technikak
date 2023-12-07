//
// Created by asus on 11/25/2023.
//

#include <algorithm>
#include "Customer.h"

int Customer::counter = 1;

Customer::Customer(const string &firstName, const string &lastName) :
    id(counter++), firstName(firstName),lastName(lastName){}

const string &Customer::getFirstName() const {
    return firstName;
}

void Customer::setFirstName(const string &firstName) {
    this->firstName = firstName;
}

const string &Customer::getLastName() const {
    return lastName;
}

void Customer::setLastName(const string &lastName) {
    this->lastName = lastName;
}

Account &Customer::getAccount(int id) {
    for (auto& account : accounts) {
        if(account.getId() == id){
            return account;
        }
    }
}

int Customer::newAccount(double balance) {
    accounts.emplace_back(balance);
    return accounts.back().getId();
}

bool Customer::deleteAccount(int id) {
    auto it = remove_if(accounts.begin(), accounts.end(),
                        [id](const Account& account){
                            return account.getId() == id;
    });
    if(it != accounts.end()){
        accounts.erase(it, accounts.end());
        return true;
    }
    return false;
}
int Customer::getNumAccounts() const {
    return accounts.size();
}
void Customer::print(ostream &os) const {
    os << getId() << " " << getFirstName() << " " << getLastName() << endl;
    for (const auto& account: accounts) {
        os <<"\t" << account ;
    }
}
ostream &operator<<(ostream &os, const Customer &customer) {
    customer.print(os);
    return os;
}

Account &Customer::operator[](int index) {
    return accounts[index];
}






