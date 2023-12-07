#include <iostream>
#include "Szemely.h"
#include "Alkalmazott.h"
#include "Manager.h"
#include "Ceg.h"

int main() {
//    Szemely sz1("Szabo", "Nikoletta", 2003);
//    cout << sz1 << endl;

    Alkalmazott a1("Baka", "Balint", 2003, "IT");
    cout << a1 << endl;
    Alkalmazott a2("Nagy", "Kinga", 2003, "IT");
    Alkalmazott a3("Nagy", "Alpar", 2003, "IT");


    Manager m1("Nagy", "Henrietta", 2003);
    m1.addAlkalmazott(&a1);
    m1.addAlkalmazott(&a2);
    m1.addAlkalmazott(&a3);

    cout << "************************" << endl;
    m1.print(cout);
    cout << "************************" << endl;

    m1.deleteAlkalmazott(&a1);
    m1.deleteAlkalmazottById(2);
    m1.print(cout);
    cout << "************************" << endl;

    Ceg ceg("CodeSpring");
    Alkalmazott a4("Fulop", "Bernadett", 2003, "IT");
    Alkalmazott a5("Kadar", "Akos", 2002, "IT");
    Alkalmazott a6("Fulop", "Pistike", 1989, "IT");
    Alkalmazott a7("Nagy", "Alpar", 2002, "IT");
    Manager m2("Oltean", "Boroka", 1998);
    Manager m3("Osztian", "Palma", 1998);

    ceg.addAlklalmazott(&a1);
    ceg.addAlklalmazott(&a2);
    ceg.addAlklalmazott(&a3);
    ceg.addAlklalmazott(&a4);
    ceg.addAlklalmazott(&a5);
    ceg.addAlklalmazott(&a6);
    ceg.addAlklalmazott(&a7);
    ceg.addAlklalmazott(&m1);
    ceg.addAlklalmazott(&m2);
    ceg.addAlklalmazott(&m3);

    ceg.alkalmazottHozzaredneleseManagerhez(&m2, &a4);
    ceg.alkalmazottHozzaredneleseManagerhez(&m2, &a5);
    ceg.alkalmazottHozzaredneleseManagerhez(&m3, &a6);
    ceg.alkalmazottHozzaredneleseManagerhez(&m3, &a7);


    cout << endl;
    ceg.printManagers(cout);

    cout << "************************" << endl;

    ceg.alkalmazottLevalasztasaManagertol(&m2, &a4);

    cout << endl;
    ceg.printManagers(cout);

    return 0;
}