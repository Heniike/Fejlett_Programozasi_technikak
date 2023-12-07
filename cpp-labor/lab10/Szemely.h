//
// Created by asus on 11/27/2023.
//

#ifndef LAB9_SZEMELY_H
#define LAB9_SZEMELY_H


#include <string>

using namespace std;

class Szemely {
protected:
    string vezetekNev;
    string keresztNev;
    int szuletesiEv;

public:
    Szemely (const string& vezetekNev,const string& keresztNev, int szuletesiEv) :
        vezetekNev(vezetekNev), keresztNev(keresztNev), szuletesiEv(szuletesiEv){}

    virtual void print(ostream& os)const;

};

ostream &operator<<(ostream& os, const Szemely& szemely);

#endif //LAB9_SZEMELY_H
