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

