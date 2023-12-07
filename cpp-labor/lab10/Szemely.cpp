//
// Created by asus on 11/27/2023.
//

#include "Szemely.h"

#include <iostream>

void Szemely::print(ostream &os) const{
    os  <<"\t\tSzemely: "<<  vezetekNev << " " <<  keresztNev << ", " << szuletesiEv;
}

ostream& operator<<(ostream &os, const Szemely& szemely) {
    szemely.print(os);
    return os;
}


