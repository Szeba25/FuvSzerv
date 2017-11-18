#include "Titkar.h"

Titkar::Titkar(const string& aktivFelhasznaloNev, const string& aktivVezetekNev, const string& aktivKeresztNev) :
    AktivFelhasznalo(aktivFelhasznaloNev, aktivVezetekNev, aktivKeresztNev)
{}

Titkar::~Titkar()
{}

void Titkar::menuMutat()
{
    cout << "> 1 : fuvar hozzaadasa" << endl;
    cout << "> 2 : fuvar modositasa" << endl;
    cout << "> 3 : fuvarok listazasa" << endl;
    cout << "> 4 : fuvarok keresese" << endl;
    cout << "> 5 : kamionos felhasznalok listazasa" << endl;
    cout << "> 6 : cegek listazasa" << endl;
    cout << "> 7 : kilepes" << endl;
}

bool Titkar::parancsFeldolgoz(int parancs, Adatok& adatok)
{
    bool kilepes = false;
    switch(parancs) {
    case 1:
        fuvarHozzaadasa(adatok.getFelhasznaloLista(), adatok.getFuvarLista());
        break;
    case 2:
        fuvarModositasa(adatok.getFelhasznaloLista(), adatok.getFuvarLista());
        break;
    case 3:
        fuvarokListazasa(adatok.getFuvarLista());
        break;
    case 4:
        fuvarokKeresese(adatok.getFuvarLista());
        break;
    case 5:
        kamionosFelhasznalokListazasa(adatok.getFelhasznaloLista());
        break;
    case 6:
        cegekListazasa(adatok.getCegLista());
        break;
    case 7:
        kilepes = true;
        break;
    }
    return kilepes;
}

void Titkar::fuvarHozzaadasa(FelhasznaloLista& felhLista, FuvarLista& lista)
{
    string feladoCim;
    string aruMegnevezes;
    double mennyiseg;
    string celCim;
    string tervezettSzallitasiDatum;
    double tavolsag;
    int prioritas;
    string specialisIgenyek;
    string megjegyzesek;

    cin.ignore();
    cout << "Adja meg a felelos kamionos felhasznalonevet: ";
    string kamionosFelhasznaloNeve;
    getline(cin, kamionosFelhasznaloNeve);

    if (felhLista.kamionosFelhasznaloNevLetezik(kamionosFelhasznaloNeve)) {
        cout << "Adja meg a felado cimet: ";
        getline(cin, feladoCim);
        cout << "Adja meg az aru megnevezeset: ";
        getline(cin, aruMegnevezes);
        cout << "Adja meg a mennyiseget (kg): ";
        mennyiseg = utils::getdouble();
        cout << "Adja meg a cel cimet: ";
        getline(cin, celCim);
        cout << "Adja meg a szallitas tervezett idejet (eeee.hh.nn): ";
        getline(cin, tervezettSzallitasiDatum);
        cout << "Adja meg a tavolsagot (km): ";
        tavolsag = utils::getdouble();
        cout << "Adja meg a prioritast [1-9]: ";
        prioritas = utils::getint();
        cout << "Adja meg a specialis igenyeket: ";
        getline(cin, specialisIgenyek);
        cout << "Adja meg a megjegyzeseket: ";
        getline(cin, megjegyzesek);

        if (fuvarAdatokFormaiHelyessege(false, mennyiseg, tavolsag, prioritas) &&
            fuvarAdatokFormaiHelyessege(false, tervezettSzallitasiDatum)) {

            lista.fuvarHozzaadasa(kamionosFelhasznaloNeve, feladoCim, aruMegnevezes,
                                  mennyiseg, celCim, tervezettSzallitasiDatum, tavolsag,
                                  prioritas, specialisIgenyek, megjegyzesek);
        } else {
            cout << "HIBA: A megadott adatokban formai hiba van!" << endl;
        }
    } else {
        cout << "HIBA: Nem letezik ilyen kamionos!" << endl;
    }
}

void Titkar::fuvarModositasa(FelhasznaloLista& felhLista, FuvarLista& lista)
{
    string kamionosFelhasznaloNeve;
    string feladoCim;
    string aruMegnevezes;
    double mennyiseg;
    string celCim;
    string tervezettSzallitasiDatum;
    double tavolsag;
    int prioritas;
    string specialisIgenyek;
    int allapot;
    string atvevesIdeje;
    string atvevoTeljesNeve;
    int ar;
    string megjegyzesek;

    cin.ignore();
    cout << "Adja meg a modositani kivant fuvar azonositojat: ";
    int id;
    id = utils::getint();

    if (lista.fuvarLetezik(id)) {
        cout << "[Ha az adatot nem adja meg, az nem kerul modositasra!!!]" << endl;
        cout << "Adja meg az uj kamionos felhasznalonevet: ";
        getline(cin, kamionosFelhasznaloNeve);
        if (kamionosFelhasznaloNeve == "" || felhLista.kamionosFelhasznaloNevLetezik(kamionosFelhasznaloNeve)) {
            cout << "Adja meg a felado uj cimet: ";
            getline(cin, feladoCim);
            cout << "Adja meg az aru uj megnevezeset: ";
            getline(cin, aruMegnevezes);
            cout << "Adja meg az uj mennyiseget: ";
            mennyiseg = utils::getdouble();
            cout << "Adja meg az uj cel cimet: ";
            getline(cin, celCim);
            cout << "Adja meg az uj szallitas tervezett idejet (eeee.hh.nn): ";
            getline(cin, tervezettSzallitasiDatum);
            cout << "Adja meg az uj tavolsagot (km): ";
            tavolsag = utils::getdouble();
            cout << "Adja meg az uj prioritast ([1-9]): ";
            prioritas = utils::getint();
            cout << "Adja meg az uj specialis igenyeket: ";
            getline(cin, specialisIgenyek);
            cout << "Adja meg az uj allapotot (0=feldolgozas alatt, 1=sikeres, 2=sikertelen): ";
            allapot = utils::getint();
            cout << "Adja meg az uj atveves idejet (eeee.hh.nn): ";
            getline(cin, atvevesIdeje);
            cout << "Adja meg az uj atvevo teljes nevet: ";
            getline(cin, atvevoTeljesNeve);
            cout << "Adja meg az uj arat (Ft): ";
            ar = utils::getint();
            cout << "Adja meg az uj megjegyzeseket: ";
            getline(cin, megjegyzesek);

            if (fuvarAdatokFormaiHelyessege(true, mennyiseg, tavolsag, prioritas) &&
                fuvarAdatokFormaiHelyessege(true, ar, allapot) &&
                fuvarAdatokFormaiHelyessege(true, tervezettSzallitasiDatum) &&
                fuvarAdatokFormaiHelyessege(true, atvevesIdeje)) {

                lista.fuvarModositasa(id, kamionosFelhasznaloNeve, feladoCim,
                                      aruMegnevezes, mennyiseg,
                                      celCim, tervezettSzallitasiDatum, tavolsag,
                                      prioritas, specialisIgenyek, allapot,
                                      atvevesIdeje, atvevoTeljesNeve, ar, megjegyzesek);
            } else {
                cout << "HIBA: A megadott adatokban formai hiba van!" << endl;
            }
        } else {
            cout << "HIBA: Nincs ilyen kamionos!" << endl;
        }
    } else {
        cout << "HIBA: Nincs ilyen fuvar azonosito!" << endl;
    }
}

void Titkar::fuvarokListazasa(FuvarLista& lista)
{
    lista.kiir();
}

void Titkar::fuvarokKeresese(FuvarLista& lista)
{
    int id;
    string kamionosFelhasznaloNeve;
    string feladoCim;
    string aruMegnevezes;
    string celCim;
    string tervezettSzallitasiDatum;
    int prioritas;
    int allapot;
    string atvevesIdeje;
    string atvevoTeljesNeve;

    cin.ignore();
    cout << "[Ha az adatot nem adja meg, arra az adatra nem szur le a kereses!!!]" << endl;
    cout << "Fuvar azonosito: ";
    id = utils::getint();
    cout << "Kamionos felhasznalo neve: ";
    getline(cin, kamionosFelhasznaloNeve);
    cout << "Arut honnan szallitottak: ";
    getline(cin, feladoCim);
    cout << "Aru megnevezese: ";
    getline(cin, aruMegnevezes);
    cout << "Cel cim: ";
    getline(cin, celCim);
    cout << "Szallitas tervezett ideje (eeee.hh.nn): ";
    getline(cin, tervezettSzallitasiDatum);
    cout << "Prioritas: ";
    prioritas = utils::getint();
    cout << "Allapot (0=feldolgozas alatt, 1=sikeres, 2=sikertelen): ";
    allapot = utils::getint();
    cout << "Atveves ideje (eeee.hh.nn): ";
    getline(cin, atvevesIdeje);
    cout << "Atvevo teljes neve: ";
    getline(cin, atvevoTeljesNeve);
    cout << endl;
    lista.kiirLeszurve(id, kamionosFelhasznaloNeve,
                       feladoCim, aruMegnevezes, celCim,
                       tervezettSzallitasiDatum, prioritas,
                       allapot, atvevesIdeje, atvevoTeljesNeve);
}

void Titkar::kamionosFelhasznalokListazasa(FelhasznaloLista& felhLista)
{
    felhLista.kiirKamionosok();
}

void Titkar::cegekListazasa(CegLista& cegLista)
{
    cegLista.kiir();
}

bool Titkar::fuvarAdatokFormaiHelyessege(bool kihagyhato, double mennyiseg, double tavolsag, int prioritas)
{
    return (
            ( (kihagyhato && mennyiseg == -1) || mennyiseg > 0) &&
            ( (kihagyhato && tavolsag == -1) || tavolsag > 0) &&
            ( (kihagyhato && prioritas == -1) || (prioritas >=1 && prioritas <= 9) )
           );
}

bool Titkar::fuvarAdatokFormaiHelyessege(bool kihagyhato, int ar, int allapot)
{
    return (
            ( (kihagyhato && ar == -1) || ar >= 1 ) &&
            ( (kihagyhato && allapot == -1) || (allapot >= 0 && allapot <= 2) )
            );
}

bool Titkar::fuvarAdatokFormaiHelyessege(bool kihagyhato, const string& datum)
{
    return ( ( (kihagyhato && datum == "") || utils::is_hundate(datum) ) );
}
