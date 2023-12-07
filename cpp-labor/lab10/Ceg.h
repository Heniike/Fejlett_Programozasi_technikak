//
// Created by asus on 12/3/2023.
//

#ifndef LAB10_CEG_H
#define LAB10_CEG_H

#include <vector>
#include "Szemely.h"
#include "Manager.h"
#include "Alkalmazott.h"
using namespace std;

class Ceg {
private:
    string name;
    vector<Alkalmazott*> alkalmzottak;
public:
    Ceg(const string &name);
    void addAlklalmazott(Alkalmazott *ujAlkalmazott);
    void deleteAlkalmazottById(int id);
    void alkalmazottHozzaredneleseManagerhez(Manager *manager, Alkalmazott *hAlkalmazott);
    void alkalmazottLevalasztasaManagertol(Manager *manager, Alkalmazott *lAlklamazott);
    void printAlkalmazottak(ostream &os);
    void printManagers(ostream &os);
};


#endif //LAB10_CEG_H
