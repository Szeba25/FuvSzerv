#include "Ceg.h"

Ceg::Ceg(int id, const string& nev, const string& cim, const string& tipus, int meret) :
    id(id),
    nev(nev),
    cim(cim),
    tipus(tipus),
    meret(meret)
{}

Ceg::~Ceg()
{}

int Ceg::getId() const
{
    return id;
}

const string& Ceg::getNev() const
{
    return nev;
}

const string& Ceg::getCim() const
{
    return cim;
}

const string& Ceg::getTipus() const
{
    return tipus;
}

int Ceg::getMeret() const
{
    return meret;
}

void Ceg::setNev(const string& nev)
{
    this->nev = nev;
}

void Ceg::setCim(const string& cim)
{
    this->cim = cim;
}

void Ceg::setTipus(const string& tipus)
{
    this->tipus = tipus;
}

void Ceg::setMeret(int meret)
{
    this->meret = meret;
}

void Ceg::kiir() const
{
    cout << "ID: " << id << endl;
    cout << "cegnev: " << nev << endl;
    cout << "cim: " << cim << endl;
    cout << "tipus: " << tipus << endl;
    cout << "meret: " << meret << endl << endl;
}

