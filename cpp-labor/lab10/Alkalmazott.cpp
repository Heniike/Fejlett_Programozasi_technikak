//
// Created by asus on 11/27/2023.
//

#include "Alkalmazott.h"
#include <iostream>

int Alkalmazott::counter = 1;

Alkalmazott::Alkalmazott(const string& vezetekNev,const string& keresztNev, int szueltesiEv, const string& munkakor) :
Szemely(vezetekNev, keresztNev, szueltesiEv ), munkakor(munkakor){
    this->id = counter++;
}

void Alkalmazott::print(ostream &os) const{
    Szemely::print(os);
    os << "\tMunkakor: " << munkakor << endl;
}

int Alkalmazott::getId() const {
    return id;
}
