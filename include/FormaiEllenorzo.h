#ifndef FORMAIELLENORZO_H
#define FORMAIELLENORZO_H

#include <iostream>
#include "utilities.h"

using namespace std;

class FormaiEllenorzo
{
    public:
        FormaiEllenorzo();
        virtual ~FormaiEllenorzo();

        // Formai Ellenorzes EXTEND

        // Admin
        bool felhasznaloFelvetele(int tipus);
        bool felhasznaloModositasa(int tipus);
        bool cegFelvetele(int meret);
        bool cegModositasa(int meret);

        // Titkar
        bool fuvarHozzaadasa(double mennyiseg, double tavolsag, int prioritas,
                             const string& tervezettSzallitasiDatum);
        bool fuvarModositasa(double mennyiseg, double tavolsag, int prioritas, int ar, int allapot,
                             const string& tervezettSzallitasiDatum, const string& atvevesIdeje);

        // Kamionos
        bool fuvarAllapotModositasa(const string& atvevesIdeje, int allapot);

    private:

};

#endif // FORMAIELLENORZO_H
