#include "Adatok.h"

Adatok::Adatok()
{
    felhasznaloLista.beolvas();
    cegLista.beolvas();
    fuvarLista.beolvas();
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

FuvarLista& Adatok::getFuvarLista()
{
    return fuvarLista;
}
