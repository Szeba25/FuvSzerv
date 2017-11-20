#include "FormaiEllenorzo.h"

FormaiEllenorzo::FormaiEllenorzo()
{}

FormaiEllenorzo::~FormaiEllenorzo()
{}

bool FormaiEllenorzo::felhasznaloFelvetele(int tipus)
{
    return (tipus >= 0 && tipus <= 3);
}

bool FormaiEllenorzo::felhasznaloModositasa(int tipus)
{
    return (tipus == -1) || (tipus >= 0 && tipus <= 3);
}

bool FormaiEllenorzo::cegFelvetele(int meret)
{
    return (meret >= 1 && meret <= 9);
}

bool FormaiEllenorzo::cegModositasa(int meret)
{
    return (meret == -1) || (meret >= 1 && meret <= 9);
}

bool FormaiEllenorzo::fuvarHozzaadasa(double mennyiseg, double tavolsag, int prioritas,
                                      const string& tervezettSzallitasiDatum)
{
    return (
            (mennyiseg > 0) &&
            (tavolsag > 0) &&
            (prioritas >= 1 && prioritas <= 9) &&
            (utils::is_hundate(tervezettSzallitasiDatum))
            );
}

bool FormaiEllenorzo::fuvarModositasa(double mennyiseg, double tavolsag, int prioritas, int ar, int allapot,
                                      const string& tervezettSzallitasiDatum, const string& atvevesIdeje)
{
    return (
            ((mennyiseg == -1) || (mennyiseg > 0)) &&
            ((tavolsag == -1) || (tavolsag > 0)) &&
            ((prioritas == -1) || (prioritas >= 1 && prioritas <= 9)) &&
            ((ar == -1) || (ar >= 1)) &&
            ((allapot == -1) || (allapot >= 0 && allapot <= 2)) &&
            ((tervezettSzallitasiDatum == "") || (utils::is_hundate(tervezettSzallitasiDatum))) &&
            ((atvevesIdeje == "") || (utils::is_hundate(atvevesIdeje)))
            );
}

bool FormaiEllenorzo::fuvarAllapotModositasa(const string& atvevesIdeje, int allapot)
{
    return (
            ((atvevesIdeje == "") || utils::is_hundate(atvevesIdeje)) &&
            ((allapot == -1) || (allapot >= 0 && allapot <= 2))
            );
}

