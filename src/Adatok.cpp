#include "Adatok.h"

Adatok::Adatok()
{
    felhasznaloLista.beolvas();
}

Adatok::~Adatok()
{

}

FelhasznaloLista& Adatok::getFelhasznaloLista()
{
    return felhasznaloLista;
}
