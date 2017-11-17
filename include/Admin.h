#ifndef ADMIN_H
#define ADMIN_H

#include "Felhasznalo.h"

class Admin : public Felhasznalo
{
    public:
        Admin(const string& felhasznaloNev, const string& vezetekNev, const string& keresztNev);
        virtual ~Admin();

        virtual void menuMutat();
        virtual bool parancsFeldolgoz(int parancs, Adatok& adatok);
    private:
        // USE CASES!
        void felhasznaloFelvetele(FelhasznaloLista& lista);
        void felhasznalokListazasa(FelhasznaloLista& lista);
        void felhasznaloTorlese(FelhasznaloLista& lista);
        void felhasznaloModositasa(FelhasznaloLista& lista);
};

#endif // ADMIN_H
