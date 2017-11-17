#include "Adatok.h"

Adatok::Adatok()
{
    felhasznaloLista.beolvas();
    cegLista.beolvas();
}

Adatok::~Adatok()
{

}

FelhasznaloLista& Adatok::getFelhasznaloLista()
{
    return felhasznaloLista;
}

CegLista& Adatok::getCegLista()
{
    return cegLista;
}
