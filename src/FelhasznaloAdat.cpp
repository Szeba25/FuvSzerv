#include "FelhasznaloAdat.h"

FelhasznaloAdat::FelhasznaloAdat(const string& felhasznaloNev, const string& jelszo,
        const string& vezetekNev, const string& keresztNev, int tipus) :
            felhasznaloNev(felhasznaloNev),
            jelszo(jelszo),
            vezetekNev(vezetekNev),
            keresztNev(keresztNev),
            tipus(tipus)
{}

FelhasznaloAdat::~FelhasznaloAdat()
{}

const string& FelhasznaloAdat::getFelhasznaloNev() const
{
    return felhasznaloNev;
}

const string& FelhasznaloAdat::getJelszo() const
{
    return jelszo;
}

const string& FelhasznaloAdat::getVezetekNev() const
{
    return vezetekNev;
}

const string& FelhasznaloAdat::getKeresztNev() const
{
    return keresztNev;
}

int FelhasznaloAdat::getTipus() const
{
    return tipus;
}

void FelhasznaloAdat::kiir() const
{
    string tipusStr;
    switch (tipus) {
    case 0:
        tipusStr = "Tulajdonos";
        break;
    case 1:
        tipusStr = "Admin";
        break;
    case 2:
        tipusStr = "Titkar";
        break;
    case 3:
        tipusStr = "Kamionos";
        break;
    }
    cout << "> felhasznalonev: " << felhasznaloNev << "\t" << endl;
    cout << "jelszo: " << jelszo << "\t" << endl;
    cout << "vezeteknev: " << vezetekNev << "\t" << endl;
    cout << "keresztnev: " << keresztNev << "\t" << endl;
    cout << "tipus: " << tipusStr << endl << endl;
}

