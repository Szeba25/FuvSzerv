#ifndef ADATOK_H
#define ADATOK_H

#include <iostream>
#include "FelhasznaloLista.h"
#include "CegLista.h"

using namespace std;

class Adatok
{
    public:
        Adatok();
        virtual ~Adatok();

        FelhasznaloLista& getFelhasznaloLista();
        CegLista& getCegLista();
    private:
        FelhasznaloLista felhasznaloLista;
        CegLista cegLista;
};

#endif // ADATOK_H
