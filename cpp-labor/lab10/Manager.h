//
// Created by asus on 11/27/2023.
//

#ifndef LAB10_MANAGER_H
#define LAB10_MANAGER_H


#include "Alkalmazott.h"
#include <iostream>
#include <vector>

using namespace std;

class Manager : public Alkalmazott{
    vector<Alkalmazott*> beosztottak;

public :
    static const string MANAGER_munkakor;
    Manager(const string &vezeteknev,const string &keresztnev, int szuletesiEv);
    void addAlkalmazott(Alkalmazott *alkalmazott);
    void deleteAlkalmazott(Alkalmazott *alkalmazott);
    void print(ostream &os) const override;
    void deleteAlkalmazottById(int id);
    int numberOfBeosztottak();



};



#endif //LAB10_MANAGER_H
