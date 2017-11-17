#ifndef ADMIN_H
#define ADMIN_H

#include "Felhasznalo.h"

class Admin : public Felhasznalo
{
    public:
        Admin(const string& felhasznaloNev, const string& vezetekNev, const string& keresztNev);
        virtual ~Admin();

        virtual void menuMutat();
        virtual void parancsFeldolgoz(int parancs, Adatok& adatok);
};

#endif // ADMIN_H
