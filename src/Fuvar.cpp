#include "Fuvar.h"

Fuvar::Fuvar(int id,
             const string& kamionosFelhasznaloNeve,
             const string& honnan,
             const string& aruMegnevezes,
             double mennyiseg,
             const string& cel,
             const string& mikor,
             double tavolsag,
             int prioritas,
             const string& specialisIgenyek,
             const string& megjegyzesek) :
    id(id),
    kamionosFelhasznaloNeve(kamionosFelhasznaloNeve),
    honnan(honnan),
    aruMegnevezes(aruMegnevezes),
    mennyiseg(mennyiseg),
    cel(cel),
    mikor(mikor),
    tavolsag(tavolsag),
    prioritas(prioritas),
    specialisIgenyek(specialisIgenyek),
    allapot(""),
    atvevesIdeje(""),
    atvevoTeljesNeve(""),
    ar(0),
    megjegyzesek(megjegyzesek)
{
}


Fuvar::~Fuvar()
{
}

int Fuvar::getId() const
{
    return id;
}

const string& Fuvar::getKamionosFelhasznaloNeve() const
{
    return kamionosFelhasznaloNeve;
}

const string& Fuvar::getHonnan() const
{
    return honnan;
}

const string& Fuvar::getAruMegnevezes() const
{
    return aruMegnevezes;
}

double Fuvar::getMennyiseg() const
{
    return mennyiseg;
}

const string& Fuvar::getCel() const
{
    return cel;
}

const string& Fuvar::getMikor() const
{
    return mikor;
}

double Fuvar::getTavolsag() const
{
    return tavolsag;
}

int Fuvar::getPrioritas() const
{
    return prioritas;
}

const string& Fuvar::getSpecialisIgenyek() const
{
    return specialisIgenyek;
}

const string& Fuvar::getAllapot() const
{
    return allapot;
}

const string& Fuvar::getAtvevesIdeje() const
{
    return atvevesIdeje;
}

const string& Fuvar::getAtvevoTeljesNeve() const
{
    return atvevoTeljesNeve;
}

int Fuvar::getAr() const
{
    return ar;
}

const string& Fuvar::getMegjegyzesek() const
{
    return megjegyzesek;
}

void Fuvar::setKamionosFelhasznaloNeve(const string& kamionosFelhasznaloNeve)
{
    this->kamionosFelhasznaloNeve = kamionosFelhasznaloNeve;
}

void Fuvar::setHonnan(const string& honnan)
{
    this->honnan = honnan;
}

void Fuvar::setAruMegnevezes(const string& aruMegnevezes)
{
    this->aruMegnevezes = aruMegnevezes;
}

void Fuvar::setMennyiseg(double mennyiseg)
{
    this->mennyiseg = mennyiseg;
}

void Fuvar::setCel(const string& cel)
{
    this->cel = cel;
}

void Fuvar::setMikor(const string& mikor)
{
    this->mikor = mikor;
}

void Fuvar::setTavolsag(double tavolsag)
{
    this->tavolsag = tavolsag;
}

void Fuvar::setPrioritas(int prioritas)
{
    this->prioritas = prioritas;
}

void Fuvar::setSpecialisIgenyek(const string& specialisIgenyek)
{
    this->specialisIgenyek = specialisIgenyek;
}

void Fuvar::setAllapot(const string& allapot)
{
    this->allapot = allapot;
}

void Fuvar::setAtvevesIdeje(const string& atvevesIdeje)
{
    this->atvevesIdeje = atvevesIdeje;
}

void Fuvar::setAtvevoTeljesNeve(const string& atvevoTeljesNeve)
{
    this->atvevoTeljesNeve = atvevoTeljesNeve;
}

void Fuvar::setAr(int ar)
{
    this->ar = ar;
}

void Fuvar::setMegjegyzesek(const string& megjegyzesek)
{
    this->megjegyzesek = megjegyzesek;
}

void Fuvar::kiir() const
{
    cout << "> ID: " << id << endl;
    cout << "Kamionos: " << kamionosFelhasznaloNeve << endl;
    cout << "Honnan: " << honnan << endl;
    cout << "Aru megnevezes: " << aruMegnevezes << endl;
    cout << "Mennyiseg: " << mennyiseg << " kg" << endl;
    cout << "Cel: " << cel << endl;
    cout << "Mikor: " << mikor << endl;
    cout << "Tavolsag: " << tavolsag << " km" << endl;
    cout << "Prioritas: " << prioritas << "/9" << endl;
    cout << "Spec. igenyek: " << specialisIgenyek << endl;
    cout << "Allapot: " << allapot << endl;
    cout << "Atveves ideje: " << atvevesIdeje << endl;
    cout << "Atvevo teljes neve: " << atvevoTeljesNeve << endl;
    cout << "Fuva ara: " << ar << " Ft" << endl;
    cout << "Megjegyzesek: " << megjegyzesek << endl << endl;
}
