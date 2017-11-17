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
        void felhasznaloFelvetele(FelhasznaloLista& lista); // A1
        void felhasznalokListazasa(FelhasznaloLista& lista); // A2
        void felhasznaloTorlese(FelhasznaloLista& lista); // A3
        void felhasznaloModositasa(FelhasznaloLista& lista); // A4
        void cegFelvetele(CegLista& lista); // A5
        void cegTorlese(CegLista& lista); // A6
        void cegModositasa(CegLista& lista); // A7
        void cegekListazasa(CegLista& lista); // TA1
};

#endif // ADMIN_H
