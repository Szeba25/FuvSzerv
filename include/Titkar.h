#ifndef TITKAR_H
#define TITKAR_H

#include "AktivFelhasznalo.h"

class Titkar : public AktivFelhasznalo
{
    public:
        Titkar(const string& aktivFelhasznaloNev, const string& aktivVezetekNev, const string& aktivKeresztNev);
        virtual ~Titkar();

        virtual void menuMutat();
        virtual bool parancsFeldolgoz(int parancs, Adatok& adatok);

    private:
        // USE CASES
        void fuvarHozzaadasa(FelhasznaloLista& felhLista, FuvarLista& lista, FormaiEllenorzo& formaiEllenorzo); // T1
        void fuvarModositasa(FelhasznaloLista& felhLista, FuvarLista& lista, FormaiEllenorzo& formaiEllenorzo); // T2
        void fuvarokListazasa(FuvarLista& lista); // T3
        void fuvarokKeresese(FuvarLista& lista); // T4
        void kamionosFelhasznalokListazasa(FelhasznaloLista& felhLista); // T5
        void cegekListazasa(CegLista& cegLista); // TA1

};

#endif // TITKAR_H
