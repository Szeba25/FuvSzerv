#ifndef FELHASZNALO_H
#define FELHASZNALO_H

#include <iostream>
#include "FormaiEllenorzo.h"
#include "FelhasznaloLista.h"
#include "CegLista.h"
#include "FuvarLista.h"
#include "CegAdatok.h"
#include "utilities.h"

using namespace std;

class AktivFelhasznalo
{
    public:
        AktivFelhasznalo(const string& aktivFelhasznaloNev, const string& aktivVezetekNev,
                         const string& aktivKeresztNev, FormaiEllenorzo* formaiEllenorzo);
        virtual ~AktivFelhasznalo();

        virtual void menuMutat() = 0;
        virtual bool parancsFeldolgoz(int parancs) = 0;
        const string& getAktivFelhasznaloNev() const;

        void setFelhasznaloLista(FelhasznaloLista* felhasznaloLista);
        void setCegLista(CegLista* cegLista);
        void setFuvarLista(FuvarLista* fuvarLista);
        void setCegAdatok(CegAdatok* cegAdatok);
    protected:
        string aktivFelhasznaloNev;
        string aktivVezetekNev;
        string aktivKeresztNev;

        FormaiEllenorzo* formaiEllenorzo;

        FelhasznaloLista* felhasznaloLista;
        CegLista* cegLista;
        FuvarLista* fuvarLista;
        CegAdatok* cegAdatok;
};

#endif // FELHASZNALO_H
