#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include "Customer.h"
#include "Account.h"
#include "Bank.h"
using namespace std;

int main() {
    /*
    ///Exercise 1
    vector<string> fruits {
            "melon", "strawberry", "raspberry","apple", "banana", "walnut", "lemon"
    };

    string searchedItem = "berry";
    auto found = find_if(fruits.begin(), fruits.end(),
                         [searchedItem](const string& fruit){
                             return fruit.find(searchedItem) != string :: npos;
    });

    if (found != fruits.end()) {
        cout << "Van '" << searchedItem << "'.\n";
    } else {
        cout << "Nincs '" << searchedItem << "'.\n";
    }

    cout << "-------------------------------------------" << endl;

    ///Exercise 2
    vector<int> numbers {2, 4, 6, 8, 10, 12, 14};
    bool allEven = all_of(numbers.begin(), numbers.end(),
                          [](int number){
                              return number % 2 == 0;
    });

    if (allEven) {
        cout << "Minden szam paros\n";
    } else {
        cout << "Nem minden szam paros\n";
    }
    cout << "-------------------------------------------" << endl;

    ///Exercise 3
    for_each(numbers.begin(), numbers.end(),
             [](int &number){
        number *= 2;
    });

    cout << "A megduplazott szamok: " << endl;
    for (const auto& number : numbers) {
        cout << number << " ";
    }
    cout << endl;
    cout << "-------------------------------------------" << endl;

    ///Exercise 4
    vector<string> months {
            "January", "February", "March", "April", "May", "June",
            "July", "August", "September", "October", "November", "December"
    };

    int countFiveLetter = count_if(months.begin(), months.end(),
                                   [](const string &month){
                                       return month.length() == 5;
    });

    cout << "Az ot betubol allo honapok szama: " << countFiveLetter << endl;
    cout << "-------------------------------------------" << endl;

    ///Exercise 5
    vector<double> realNums{3.14, 2.71, 1.618, 0.577, 2.718};

    sort(realNums.begin(), realNums.end(),[](double a, double b){
        return a > b;
    });

    cout << "Csokkeno sorrendben a tomb: ";
    for (const auto& num : realNums) {
        cout << num << " ";
    }
    cout << endl;
    cout << "-------------------------------------------" << endl;

    ///Exercise 6
    vector<pair<string, double>> monthlyTemperatures {
            {"January", 0.5}, {"February", 2.3}, {"March", 8.1}, {"April", 15.2},
            {"May", 21.5}, {"June", 26.8}, {"July", 30.0}, {"August", 28.7},
            {"September", 23.2}, {"October", 16.7}, {"November", 9.3}, {"December", 3.6}
    };

    sort(monthlyTemperatures.begin(), monthlyTemperatures.end(),
         [](const auto& a, const auto& b){
             return a.second < b.second;
    });

    cout << "Atlaghomersekletek szerint novekvo sorrend: " << endl;
    for (const auto& month : monthlyTemperatures) {
        cout << month.first << ": " << month.second << " C" << endl;
    }
    cout << "-------------------------------------------" << endl;

    ///Exercise 7
    vector<double> realNumbers = {3.14, -2.71, -1.618, -0.577, 2.718};

    sort(realNumbers.begin(), realNumbers.end(),[](double a, double b){
       return abs(a) < abs(b);
    });
    cout<<"Abs ertekek szerint novekvo sorrendbe: " ;
    for (const auto& num : realNumbers) {
        cout << num << " ";
    }
    cout << endl;
    cout << "-------------------------------------------" << endl;

    ///Exercise 8
    transform(months.begin(), months.end(), months.begin(),
              [](string& month){
        transform(month.begin(), month.end(), month.begin(), ::tolower);
                  return month;
    });

    cout << "Honapok kisbetuvel kezdve: " << endl;
    for (const auto& month : months) {
        cout << month << " ";
    }
    cout << endl;
    cout << "-------------------------------------------" << endl;

    ///Exercise 9 - a -> furcsa ABC
    vector<char> alphabet{'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
                          'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

    random_shuffle(alphabet.begin(), alphabet.end());
    for(const auto& letter : alphabet){
        cout << letter << " ";
    }cout << endl;
    cout << "-------------------------------------------" << endl;

    ///b -> kisbetus honapok rendezese a furcsa ABC szerint
    vector<string> lowercaseMonths;
    transform(months.begin(), months.end(), back_inserter(lowercaseMonths),
              [](const string& month){
        string lowercaseMonth = month;
                  transform(lowercaseMonth.begin(), lowercaseMonth.end(), lowercaseMonth.begin(), ::tolower);
                  return lowercaseMonth;
    });


    sort(lowercaseMonths.begin(), lowercaseMonths.end(),
         [&alphabet](const string& a, const string& b){
        return lexicographical_compare(a.begin(),a.end(), b.begin(), b.end(),
                                       [&alphabet](char a, char b){
            return find(alphabet.begin(), alphabet.end(), a) < find(alphabet.begin(), alphabet.end(), b);
        });
    });

    for(const auto& month : lowercaseMonths){
        cout << month << " ";
    }
    cout << endl;
    cout << "-------------------------------------------" << endl;
    */

    ///Extra feladat tesztelese a Main-ben
    Account *account1 = new Account(0);
    cout << account1->getBalance() << endl;
    account1->deposit(1000);
    account1->print(cout);
    account1->withdraw(500);
    account1->print(cout);
    account1->withdraw(1000);
    account1->print(cout);

    Account *account2= new Account(1000);
    account2->print(cout);

    cout << "-----------------" << endl;

    Customer *customer = new Customer("Biro", "Tamas");
    customer->newAccount(0);
    customer->newAccount(1000);
    cout << *customer;

    cout << "-----------------" << endl;
    Bank bank("OTP Bank");
    vector<int> customerIds = bank.loadCustomers("customers.txt");

    cout << "Customers: " << endl;
    bank.printCustomers();

    for(int customerId : customerIds){
        Customer& customer1 = bank.getCustomer(customerId);
        cout << "Customer " << customer1.getFirstName() << " " << customer1.getLastName() <<": " <<endl;
        customer1[0].deposit(500);
        customer1[1].withdraw(200);
       // customer1[2].deposit(15000);
    }

    cout << "\nCustomers and Accounts after many operations: " << endl;
    bank.printCustomersAndAccounts();

    return 0;
}