#include "Titkar.h"

Titkar::Titkar(const string& aktivFelhasznaloNev, const string& aktivVezetekNev,
               const string& aktivKeresztNev, FormaiEllenorzo* formaiEllenorzo) :
    AktivFelhasznalo(aktivFelhasznaloNev, aktivVezetekNev, aktivKeresztNev, formaiEllenorzo)
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

bool Titkar::parancsFeldolgoz(int parancs)
{
    bool kilepes = false;
    switch(parancs) {
    case 1:
        fuvarHozzaadasa();
        break;
    case 2:
        fuvarModositasa();
        break;
    case 3:
        fuvarokListazasa();
        break;
    case 4:
        fuvarokKeresese();
        break;
    case 5:
        kamionosFelhasznalokListazasa();
        break;
    case 6:
        cegekListazasa();
        break;
    case 7:
        kilepes = true;
        break;
    }
    return kilepes;
}

void Titkar::fuvarHozzaadasa()
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

    if (felhasznaloLista->kamionosFelhasznaloNevLetezik(kamionosFelhasznaloNeve)) {
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

        if (formaiEllenorzo->fuvarHozzaadasa(mennyiseg, tavolsag, prioritas, tervezettSzallitasiDatum)) {
            fuvarLista->fuvarHozzaadasa(kamionosFelhasznaloNeve, feladoCim, aruMegnevezes,
                                  mennyiseg, celCim, tervezettSzallitasiDatum, tavolsag,
                                  prioritas, specialisIgenyek, megjegyzesek);
        } else {
            cout << "HIBA: A megadott adatokban formai hiba van!" << endl;
        }
    } else {
        cout << "HIBA: Nem letezik ilyen kamionos!" << endl;
    }
}

void Titkar::fuvarModositasa()
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

    if (fuvarLista->fuvarLetezik(id)) {
        cout << "[Ha az adatot nem adja meg, az nem kerul modositasra!!!]" << endl;
        cout << "Adja meg az uj kamionos felhasznalonevet: ";
        getline(cin, kamionosFelhasznaloNeve);
        if (kamionosFelhasznaloNeve == "" || felhasznaloLista->kamionosFelhasznaloNevLetezik(kamionosFelhasznaloNeve)) {
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

            if (formaiEllenorzo->fuvarModositasa(mennyiseg, tavolsag, prioritas,
                                                ar, allapot,
                                                tervezettSzallitasiDatum, atvevesIdeje)) {
                // formailag helyes adatok megadva
                fuvarLista->fuvarModositasa(id, kamionosFelhasznaloNeve, feladoCim,
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

void Titkar::fuvarokListazasa()
{
    fuvarLista->kiir();
}

void Titkar::fuvarokKeresese()
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
    fuvarLista->kiirLeszurve(id, kamionosFelhasznaloNeve,
                       feladoCim, aruMegnevezes, celCim,
                       tervezettSzallitasiDatum, prioritas,
                       allapot, atvevesIdeje, atvevoTeljesNeve);
}

void Titkar::kamionosFelhasznalokListazasa()
{
    felhasznaloLista->kiirKamionosok();
}

void Titkar::cegekListazasa()
{
    cegLista->kiir();
}
