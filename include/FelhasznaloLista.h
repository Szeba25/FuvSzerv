#ifndef FELHASZNALOLISTA_H
#define FELHASZNALOLISTA_H

#include <stdlib.h>
#include <iostream>
#include <vector>
#include "utilities.h"
#include "AdatFile.h"
#include "FelhasznaloAdat.h"

using namespace std;

class FelhasznaloLista
{
    public:
        FelhasznaloLista();
        virtual ~FelhasznaloLista();

        void beolvas();
        void mentes();
        FelhasznaloAdat* getFelhasznaloAdatLoginAlapjan(const string& felhasznaloNev, const string& jelszo);
        bool felhasznaloNevLetezik(const string& felhasznaloNev);
        void ujFelhasznalo(const string& felhasznaloNev, const string& jelszo,
                           const string& vezetekNev, const string& keresztNev, int tipus);
        void kiir() const;
    private:
        vector<FelhasznaloAdat> felhasznaloAdatok;
};

#endif // FELHASZNALOLISTA_H
