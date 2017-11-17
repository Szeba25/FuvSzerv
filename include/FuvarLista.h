#ifndef FUVARLISTA_H
#define FUVARLISTA_H

#include <stdlib.h>
#include <iostream>
#include <vector>
#include "Fuvar.h"
#include "AdatFile.h"
#include "utilities.h"
using namespace std;

class FuvarLista
{
    public:
        FuvarLista();
        virtual ~FuvarLista();

        void beolvas();
        void mentes();
        void kiir();

        void fuvarHozzaadasa(const string& kamionosFelhasznaloNev,
                             const string& honnan,
                             const string& aruMegnevezes,
                             double mennyiseg,
                             const string& cel,
                             const string& mikor,
                             double tavolsag,
                             int prioritas,
                             const string& specialisIgenyek,
                             const string& megjegyzesek);
        int genId();
    private:
        vector<Fuvar> fuvarok;
};

#endif // FUVARLISTA_H
