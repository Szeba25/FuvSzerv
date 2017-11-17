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

        bool fuvarAdatokFormaiHelyessege(double mennyiseg, double tavolsag, int prioritas);
};

#endif // TITKAR_H
