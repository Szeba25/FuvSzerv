#ifndef TITKAR_H
#define TITKAR_H

#include "Felhasznalo.h"

class Titkar : public Felhasznalo
{
    public:
        Titkar(const string& felhasznaloNev, const string& vezetekNev, const string& keresztNev);
        virtual ~Titkar();

        virtual void menuMutat();
        virtual void parancsFeldolgoz(int parancs, Adatok& adatok);
};

#endif // TITKAR_H
