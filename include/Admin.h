#ifndef ADMIN_H
#define ADMIN_H

#include "AktivFelhasznalo.h"

class Admin : public AktivFelhasznalo
{
    public:
        Admin(const string& aktivFelhasznaloNev, const string& aktivVezetekNev, const string& aktivKeresztNev);
        virtual ~Admin();

        virtual void menuMutat();
        virtual bool parancsFeldolgoz(int parancs, Adatok& adatok);
    private:
        // USE CASES!
        void cegFelvetele(CegLista& lista); // A1
        void cegModositasa(CegLista& lista); // A2
        void cegekListazasa(CegLista& lista); // TA1
        void cegTorlese(CegLista& lista); // A3
        void felhasznaloFelvetele(FelhasznaloLista& lista); // A4
        void felhasznaloModositasa(FelhasznaloLista& lista); // A5
        void felhasznalokListazasa(FelhasznaloLista& lista); // A6
        void felhasznaloTorlese(FelhasznaloLista& lista); // A7

        // formai ellenorzesek
        bool felhasznaloAdataiFormaiEllenorzes(bool kihagyhato, int tipus);
        bool cegAdataiFormaiEllenorzes(bool kihagyhato, int meret);
};

#endif // ADMIN_H
