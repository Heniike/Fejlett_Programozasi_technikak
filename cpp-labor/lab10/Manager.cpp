//
// Created by asus on 11/27/2023.
//

#include "Manager.h"
#include <algorithm>
#include <iostream>

const string Manager::MANAGER_munkakor = "manager";

Manager::Manager(const string &vezeteknev, const string &keresztnev, int szuletesiEv) : Alkalmazott(
    vezeteknev, keresztnev, szuletesiEv, MANAGER_munkakor){}

void Manager::addAlkalmazott(Alkalmazott *beosztott) {
    beosztottak.push_back(beosztott);
}

void Manager::deleteAlkalmazott(Alkalmazott *alkalmazott) {
    auto it = find(beosztottak.begin(), beosztottak.end(), alkalmazott);
    if(it != beosztottak.end()){
        beosztottak.erase(it);
    }
}

void Manager::print(ostream &os) const {
    Alkalmazott::print(os);
    os << " " << MANAGER_munkakor << " beosztottjai:" << endl;
    for(const auto& beosztott : beosztottak){
        beosztott->print(os);
    }
}
void Manager::deleteAlkalmazottById(int id){
    auto it = find_if(beosztottak.begin(), beosztottak.end(), [id](const Alkalmazott* alkalmazott){
            return alkalmazott->getId() == id;
    });

    if(it != beosztottak.end()){
        beosztottak.erase(it);
    }
}

int Manager::numberOfBeosztottak(){
    return beosztottak.size();
}