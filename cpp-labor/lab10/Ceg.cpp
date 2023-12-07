//
// Created by asus on 12/3/2023.
//

#include "Ceg.h"
#include "Alkalmazott.h"
#include <algorithm>

Ceg::Ceg(const string &name) : name(name){}

void Ceg::addAlklalmazott(Alkalmazott *ujAlkalmazott) {
    alkalmzottak.push_back(ujAlkalmazott);
}

void Ceg::deleteAlkalmazottById(int id) {
    auto it = find_if(alkalmzottak.begin(), alkalmzottak.end(), [id](const Alkalmazott *alkalmazott){
        return alkalmazott->getId() == id;
    });
    if(it != alkalmzottak.end()){
        alkalmzottak.erase(it);
    }
}

void Ceg::alkalmazottHozzaredneleseManagerhez(Manager *manager, Alkalmazott *hAlkalmazott) {
    manager->addAlkalmazott(hAlkalmazott);

}

void Ceg::alkalmazottLevalasztasaManagertol(Manager *manager, Alkalmazott *lAlklamazott) {
    manager->deleteAlkalmazott(lAlklamazott);
}

void Ceg::printAlkalmazottak(ostream &os) {
    os << "A " << name <<"ceg alkalmazottai: " << endl;
    for_each(alkalmzottak.begin(), alkalmzottak.end(),[&os](Alkalmazott *alkalmazott){
        alkalmazott->print(os);
    });
}

void Ceg::printManagers(ostream &os) {
    os << "A " << name <<" ceg managerei: " << endl;
    for_each(alkalmzottak.begin(), alkalmzottak.end(),[&os](Alkalmazott *alkalmazott){
        if(Manager *manager = dynamic_cast<Manager *>(alkalmazott)){
            manager->print(os);
        }
    });
}

