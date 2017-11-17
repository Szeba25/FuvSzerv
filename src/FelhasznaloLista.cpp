#include "FelhasznaloLista.h"

FelhasznaloLista::FelhasznaloLista()
{}

FelhasznaloLista::~FelhasznaloLista()
{}

void FelhasznaloLista::beolvas()
{
    AdatFile file("felhasznalolista.txt");
    for (auto ertek : file.osszAdatLeker()) {
        FelhasznaloAdat felhasznaloAdat(ertek[0], ertek[1], ertek[2], ertek[3], atoi(ertek[4].c_str()));
        felhasznaloAdatok.push_back(felhasznaloAdat);
    }
}

FelhasznaloAdat* FelhasznaloLista::getFelhasznaloAdatLoginAlapjan(const string& felhasznaloNev, const string& jelszo)
{
    for (auto& adat : felhasznaloAdatok) {
        if (adat.getFelhasznaloNev() == felhasznaloNev && adat.getJelszo() == jelszo) {
            return &adat;
        }
    }
    return nullptr;
}
