#ifndef ADATOK_H
#define ADATOK_H

#include <iostream>
#include "FelhasznaloLista.h"
#include "CegLista.h"
#include "FuvarLista.h"
#include "CegAdatok.h"

using namespace std;

class Adatok
{
    public:
        Adatok();
        virtual ~Adatok();

        FelhasznaloLista& getFelhasznaloLista();
        CegLista& getCegLista();
        FuvarLista& getFuvarLista();
        CegAdatok& getCegAdatok();
    private:
        FelhasznaloLista felhasznaloLista;
        CegLista cegLista;
        FuvarLista fuvarLista;
        CegAdatok cegAdatok;
};

#endif // ADATOK_H
