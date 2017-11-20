#ifndef ADATOK_H
#define ADATOK_H

#include <iostream>
#include "FelhasznaloLista.h"
#include "CegLista.h"
#include "FuvarLista.h"
#include "CegAdatok.h"
#include "FormaiEllenorzo.h"

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
        FormaiEllenorzo& getFormaiEllenorzo();
    private:
        FelhasznaloLista felhasznaloLista;
        CegLista cegLista;
        FuvarLista fuvarLista;
        CegAdatok cegAdatok;
        FormaiEllenorzo formaiEllenorzo;
};

#endif // ADATOK_H
