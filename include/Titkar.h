#ifndef TITKAR_H
#define TITKAR_H

#include "Felhasznalo.h"
#include "FuvarLista.h"

class Titkar : public Felhasznalo
{
    public:
        Titkar(const string& felhasznaloNev, const string& vezetekNev, const string& keresztNev);
        virtual ~Titkar();

        virtual void menuMutat();
        virtual bool parancsFeldolgoz(int parancs, Adatok& adatok);

        // USE CASES
        void fuvarHozzaadasa(FelhasznaloLista& felhLista, FuvarLista& lista);
        void fuvarokListazasa(FuvarLista& lista);
        void fuvarModositasa(FelhasznaloLista& felhLista, FuvarLista& lista);
        void fuvarokKeresese(FuvarLista& lista);
        void kamionosFelhasznalokListazasa(FelhasznaloLista& felhLista);
        void cegekListazasa(CegLista& cegLista);

        bool fuvarAdatokFormaiHelyessege(bool maradFlag, double mennyiseg, double tavolsag, int prioritas, int ar = -1);
};

#endif // TITKAR_H
