#ifndef FELHASZNALOLISTA_H
#define FELHASZNALOLISTA_H

#include <stdlib.h>
#include <iostream>
#include <vector>
#include "AdatFile.h"
#include "FelhasznaloAdat.h"

using namespace std;

class FelhasznaloLista
{
    public:
        FelhasznaloLista();
        virtual ~FelhasznaloLista();

        void beolvas();
        FelhasznaloAdat* getFelhasznaloAdatLoginAlapjan(const string& felhasznaloNev, const string& jelszo);
    private:
        vector<FelhasznaloAdat> felhasznaloAdatok;
};

#endif // FELHASZNALOLISTA_H
