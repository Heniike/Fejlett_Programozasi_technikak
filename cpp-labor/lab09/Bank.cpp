//
// Created by asus on 11/25/2023.
//

#include <algorithm>
#include <fstream>
#include "Bank.h"

Bank::Bank(const string &name) : name(name){}

int Bank::newCustomer(const string &firstName, const string &lastName) {
    customers.emplace_back(firstName, lastName);
    return customers.back().getId();
}

bool Bank::deleteCustomer(int id) {
    auto item = remove_if(customers.begin(), customers.end(),
                          [id](const Customer& customer){
                              return customer.getId() == id;
    });
    if(item != customers.end()){
        customers.erase(item, customers.end());
        return true;
    }
    return false;
}

Customer &Bank::getCustomer(int id) {
    //static Customer *dummyCustomer;

    for (auto& customer:customers) {
        if(customer.getId() == id){
            return customer;
        }
    }
    //return *dummyCustomer;
}

void Bank::printCustomers(ostream &os) const {
    for(const auto& customer : customers){
        os << customer << endl;
    }
}

void Bank::printCustomersAndAccounts(ostream &os) const {
    for(const auto& customer : customers){
        os << customer << endl;
    }
}

vector<int> Bank::loadCustomers(const string &filename) {
    vector<int> customerIDs;
    ifstream file(filename);
    if(file.is_open()){
        string firstName, lastName;
        while(file >> firstName >> lastName){
            int customerID = newCustomer(firstName, lastName);
            customerIDs.push_back(customerID);

            getCustomer(customerID).newAccount(0);
            getCustomer(customerID).newAccount(1000);
        }
        file.close();
    }else{
        cout << "Error when opening file" << endl;
    }
    return customerIDs;
}


