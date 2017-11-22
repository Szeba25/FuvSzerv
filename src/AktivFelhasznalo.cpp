#include "AktivFelhasznalo.h"

AktivFelhasznalo::AktivFelhasznalo(const string& aktivFelhasznaloNev,
                                   const string& aktivVezetekNev,
                                   const string& aktivKeresztNev,
                                   FormaiEllenorzo* formaiEllenorzo)
{
    this->aktivFelhasznaloNev = string(aktivFelhasznaloNev);
    this->aktivVezetekNev = string(aktivVezetekNev);
    this->aktivKeresztNev = string(aktivKeresztNev);
    this->formaiEllenorzo = formaiEllenorzo;
    this->felhasznaloLista = nullptr;
    this->cegLista = nullptr;
    this->fuvarLista = nullptr;
}

AktivFelhasznalo::~AktivFelhasznalo() {}

const string& AktivFelhasznalo::getAktivFelhasznaloNev() const
{
    return aktivFelhasznaloNev;
}

void AktivFelhasznalo::setFelhasznaloLista(FelhasznaloLista* felhasznaloLista)
{
    this->felhasznaloLista = felhasznaloLista;
}

void AktivFelhasznalo::setCegLista(CegLista* cegLista)
{
    this->cegLista = cegLista;
}

void AktivFelhasznalo::setFuvarLista(FuvarLista* fuvarLista)
{
    this->fuvarLista = fuvarLista;
}

void AktivFelhasznalo::setCegAdatok(CegAdatok* cegAdatok)
{
    this->cegAdatok = cegAdatok;
}
