//
// Created by asus on 11/27/2023.
//

#ifndef LAB10_ALKALMAZOTT_H
#define LAB10_ALKALMAZOTT_H

#include <string>
#include "Szemely.h"
using namespace std;

class Alkalmazott : public Szemely {

protected:
    string munkakor;
    int id;
    static int counter;

public:
    Alkalmazott(const string& vezetekNev,const string& csaladNev, int szuletesiEv,const string& munkakor);
    int getId() const;
    virtual void print(ostream &os)const override;
};


#endif //LAB10_ALKALMAZOTT_H
