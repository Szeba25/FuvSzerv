#ifndef FELHASZNALO_H
#define FELHASZNALO_H

#include <iostream>
#include "Adatok.h"
#include "utilities.h"

using namespace std;

class AktivFelhasznalo
{
    public:
        AktivFelhasznalo(const string& aktivFelhasznaloNev, const string& aktivVezetekNev,
                         const string& aktivKeresztNev);
        virtual ~AktivFelhasznalo();

        virtual void menuMutat() = 0;
        virtual bool parancsFeldolgoz(int parancs, Adatok& adatok) = 0;
        const string& getAktivFelhasznaloNev() const;
    protected:
        string aktivFelhasznaloNev;
        string aktivVezetekNev;
        string aktivKeresztNev;
};

#endif // FELHASZNALO_H
