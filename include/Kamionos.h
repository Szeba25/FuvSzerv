#ifndef KAMIONOS_H
#define KAMIONOS_H

#include "Felhasznalo.h"

class Kamionos : public Felhasznalo
{
    public:
        Kamionos(const string& felhasznaloNev, const string& vezetekNev, const string& keresztNev);
        virtual ~Kamionos();

        virtual void menuMutat();
        virtual void parancsFeldolgoz(int parancs, Adatok& adatok);
};

#endif // KAMIONOS_H
