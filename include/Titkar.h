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
        void fuvarHozzaadasa(FelhasznaloLista& felhLista, FuvarLista& lista); // T1
        void fuvarokListazasa(FuvarLista& lista); // T2
        void fuvarModositasa(FelhasznaloLista& felhLista, FuvarLista& lista); // T3
        void kamionosFelhasznalokListazasa(FelhasznaloLista& felhLista); // T4
        void fuvarokKeresese(FuvarLista& lista); // T5
        void cegekListazasa(CegLista& cegLista); // TA1

        bool fuvarAdatokFormaiHelyessege(bool kihagyhato,
                                         double mennyiseg,
                                         double tavolsag,
                                         int prioritas);

        bool fuvarAdatokFormaiHelyessege(bool kihagyhato, int ar, int allapot);
        bool fuvarAdatokFormaiHelyessege(bool kihagyhato, const string& datum);
};

#endif // TITKAR_H
