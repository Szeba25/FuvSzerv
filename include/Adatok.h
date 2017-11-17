#ifndef ADATOK_H
#define ADATOK_H

#include <iostream>
#include "FelhasznaloLista.h"

using namespace std;

class Adatok
{
    public:
        Adatok();
        virtual ~Adatok();

        FelhasznaloLista& getFelhasznaloLista();
    private:
        FelhasznaloLista felhasznaloLista;
};

#endif // ADATOK_H
