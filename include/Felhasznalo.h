#ifndef FELHASZNALO_H
#define FELHASZNALO_H

#include <iostream>
#include "Adatok.h"

using namespace std;

class Felhasznalo
{
    public:
        Felhasznalo(const string& felhasznaloNev, const string& vezetekNev, const string& keresztNev);
        virtual ~Felhasznalo();

        virtual void menuMutat() = 0;
        virtual bool parancsFeldolgoz(int parancs, Adatok& adatok) = 0;
    protected:
        string felhasznaloNev;
        string vezetekNev;
        string keresztNev;
};

#endif // FELHASZNALO_H
