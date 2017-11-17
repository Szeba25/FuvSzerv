#ifndef CEGLISTA_H
#define CEGLISTA_H

#include <stdlib.h>
#include <iostream>
#include <vector>
#include "Ceg.h"
#include "AdatFile.h"
#include "utilities.h"
using namespace std;

class CegLista
{
    public:
        CegLista();
        virtual ~CegLista();

        void beolvas();
        void mentes();
        void kiir() const;
        bool cegLetezik(int id);

        void ujCeg(const string& nev, const string& cim, const string& tipus, int meret);
        void cegTorlese(int id);
    private:
        vector<Ceg> cegek;
        int idGen() const;

};

#endif // CEGLISTA_H
