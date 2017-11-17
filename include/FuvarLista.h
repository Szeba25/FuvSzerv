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
        void kiirLeszurve(int keresId,
                          const string& keresKamionosFelhasznaloNeve,
                          const string& keresHonnan,
                          const string& keresAruMegnevezes,
                          const string& keresCel,
                          const string& keresMikor,
                          int keresPrioritas,
                          const string& keresAllapot,
                          const string& keresAtvevesIdeje,
                          const string& keresAtvevoTeljesNeve);

        void fuvarHozzaadasa(const string& kamionosFelhasznaloNeve,
                             const string& honnan,
                             const string& aruMegnevezes,
                             double mennyiseg,
                             const string& cel,
                             const string& mikor,
                             double tavolsag,
                             int prioritas,
                             const string& specialisIgenyek,
                             const string& megjegyzesek);

        void fuvarModositasa(int id,
                             const string& kamionosFelhasznaloNeve,
                             const string& honnan,
                             const string& aruMegnevezes,
                             double mennyiseg,
                             const string& cel,
                             const string& mikor,
                             double tavolsag,
                             int prioritas,
                             const string& specialisIgenyek,
                             const string& allapot,
                             const string& atvevesIdeje,
                             const string& atvevoTeljesNeve,
                             int ar,
                             const string& megjegyzesek);
        int genId();
        bool fuvarLetezik(int id);
    private:
        vector<Fuvar> fuvarok;
        Fuvar* getFuvarIdAlapjan(int id);
        bool matchString(const string& str1, const string& str2);
        bool matchInt(int i, int j);
};

#endif // FUVARLISTA_H
