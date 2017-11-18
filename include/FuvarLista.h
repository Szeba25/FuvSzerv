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
                          const string& kamionosFelhasznaloNeve,
                          const string& honnan,
                          const string& aruMegnevezes,
                          const string& cel,
                          const string& mikor,
                          int prioritas,
                          const string& allapot,
                          const string& atvevesIdeje,
                          const string& atvevoTeljesNeve);

        void kiirLeszurve(const string& kamionosFelhasznaloNeve);
        void kiirAzonositokLeszurve(const string& kamionosFelhasznaloNeve);

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
        void fuvarModositasa(int id,
                             const string& allapot,
                             const string& atvevesIdeje,
                             const string& atvevoTeljesNeve);
        void fuvarModositasa(int id,
                             const string& megjegyzesek);
        int genId();
        bool fuvarLetezik(int id);
        Fuvar* getFuvarIdAlapjan(int id);
    private:
        vector<Fuvar> fuvarok;
        bool matchString(const string& str1, const string& str2);
        bool matchInt(int i, int j);
};

#endif // FUVARLISTA_H
