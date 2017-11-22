#ifndef TITKAR_H
#define TITKAR_H

#include "AktivFelhasznalo.h"

class Titkar : public AktivFelhasznalo
{
    public:
        Titkar(const string& aktivFelhasznaloNev, const string& aktivVezetekNev,
               const string& aktivKeresztNev, FormaiEllenorzo* formaiEllenorzo);
        virtual ~Titkar();

        virtual void menuMutat();
        virtual bool parancsFeldolgoz(int parancs);

    private:
        // USE CASES
        void fuvarHozzaadasa(); // T1
        void fuvarModositasa(); // T2
        void fuvarokListazasa(); // T3
        void fuvarokKeresese(); // T4
        void kamionosFelhasznalokListazasa(); // T5
        void cegekListazasa(); // TA1

};

#endif // TITKAR_H
