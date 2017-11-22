#ifndef ADMIN_H
#define ADMIN_H

#include "AktivFelhasznalo.h"

class Admin : public AktivFelhasznalo
{
    public:
        Admin(const string& aktivFelhasznaloNev, const string& aktivVezetekNev,
              const string& aktivKeresztNev, FormaiEllenorzo* formaiEllenorzo);
        virtual ~Admin();

        virtual void menuMutat();
        virtual bool parancsFeldolgoz(int parancs);
    private:
        // USE CASES!
        void cegFelvetele(); // A1
        void cegModositasa(); // A2
        void cegekListazasa(); // TA1
        void cegTorlese(); // A3
        void felhasznaloFelvetele(); // A4
        void felhasznaloModositasa(); // A5
        void felhasznalokListazasa(); // A6
        void felhasznaloTorlese(); // A7

};

#endif // ADMIN_H
