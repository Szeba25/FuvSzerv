#ifndef TULAJDONOS_H
#define TULAJDONOS_H

#include "Felhasznalo.h"

class Tulajdonos : public Felhasznalo
{
    public:
        Tulajdonos(const string& felhasznaloNev, const string& vezetekNev, const string& keresztNev);
        virtual ~Tulajdonos();

        virtual void menuMutat();
        virtual bool parancsFeldolgoz(int parancs, Adatok& adatok);
};

#endif // TULAJDONOS_H
