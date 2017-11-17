#include "Felhasznalo.h"

Felhasznalo::Felhasznalo(const string& felhasznaloNev, const string& vezetekNev, const string& keresztNev)
{
    this->felhasznaloNev = string(felhasznaloNev);
    this->vezetekNev = string(felhasznaloNev);
    this->keresztNev = string(felhasznaloNev);
}

Felhasznalo::~Felhasznalo() {}

const string& Felhasznalo::getFelhasznaloNev() const
{
    return felhasznaloNev;
}
