#include "AktivFelhasznalo.h"

AktivFelhasznalo::AktivFelhasznalo(const string& aktivFelhasznaloNev,
                                   const string& aktivVezetekNev,
                                   const string& aktivKeresztNev)
{
    this->aktivFelhasznaloNev = string(aktivFelhasznaloNev);
    this->aktivVezetekNev = string(aktivVezetekNev);
    this->aktivKeresztNev = string(aktivKeresztNev);
}

AktivFelhasznalo::~AktivFelhasznalo() {}

const string& AktivFelhasznalo::getAktivFelhasznaloNev() const
{
    return aktivFelhasznaloNev;
}
