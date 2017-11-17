#include "Titkar.h"

Titkar::Titkar(const string& felhasznaloNev, const string& vezetekNev, const string& keresztNev) :
    Felhasznalo(felhasznaloNev, vezetekNev, keresztNev)
{}

Titkar::~Titkar()
{}

void Titkar::menuMutat()
{
    cout << "> 1 : fuvar hozzaadasa" << endl;
    cout << "> 2 : fuvarok listazasa" << endl;
    cout << "> 3 : fuvar modositasa" << endl;
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
        fuvarokListazasa(adatok.getFuvarLista());
        break;
    case 3:
        fuvarModositasa(adatok.getFelhasznaloLista(), adatok.getFuvarLista());
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
    cin.ignore();
    cout << "Adja meg a felelos kamionos felhasznalonevet: ";
    string kamionosFelhasznaloNeve;
    getline(cin, kamionosFelhasznaloNeve);

    string honnan;
    string aruMegnevezes;
    double mennyiseg;
    string cel;
    string mikor;
    double tavolsag;
    int prioritas;
    string specialisIgenyek;
    string megjegyzesek;

    if (felhLista.kamionosFelhasznaloNevLetezik(kamionosFelhasznaloNeve)) {
        cout << "Adja meg, hogy honnan szallitjuk (cim): ";
        getline(cin, honnan);
        cout << "Adja meg az aru megnevezeset: ";
        getline(cin, aruMegnevezes);
        cout << "Adja meg a mennyiseget (kg): ";
        cin >> mennyiseg;
        cin.ignore();
        cout << "Adja meg a celallomast: ";
        getline(cin, cel);
        cout << "Adja meg a szallitas idejet: ";
        getline(cin, mikor);
        cout << "Adja meg a tavolsagot (km): ";
        cin >> tavolsag;
        cout << "Adja meg a prioritast [1-9]: ";
        cin >> prioritas;
        cin.ignore();
        cout << "Specialis igenyek: ";
        getline(cin, specialisIgenyek);
        cout << "Megjegyzesek: ";
        getline(cin, megjegyzesek);
        if (fuvarAdatokFormaiHelyessege(false, mennyiseg, tavolsag, prioritas)) {
            lista.fuvarHozzaadasa(kamionosFelhasznaloNeve, honnan, aruMegnevezes,
                                  mennyiseg, cel, mikor, tavolsag,
                                  prioritas, specialisIgenyek, megjegyzesek);
        } else {
            cout << "HIBA: A megadott adatokban formai hiba van!" << endl;
        }
    } else {
        cout << "HIBA: Nem letezik ilyen kamionos!" << endl;
    }
}

void Titkar::fuvarokListazasa(FuvarLista& lista)
{
    lista.kiir();
}

void Titkar::fuvarModositasa(FelhasznaloLista& felhLista, FuvarLista& lista)
{
    cout << "Adja meg a modositani kivant fuvar azonositojat: ";
    int id;
    cin >> id;

    string kamionosFelhasznaloNeve;
    string honnan;
    string aruMegnevezes;
    double mennyiseg;
    string cel;
    string mikor;
    double tavolsag;
    int prioritas;
    string specialisIgenyek;
    string allapot;
    string atvevesIdeje;
    string atvevoTeljesNeve;
    int ar;
    string megjegyzesek;

    if (lista.fuvarLetezik(id)) {
        cin.ignore();
        cout << "Adja meg az uj kamionos felhasznalonevet (\"\" = nem valtozik): ";
        getline(cin, kamionosFelhasznaloNeve);
        if (kamionosFelhasznaloNeve == "" || felhLista.kamionosFelhasznaloNevLetezik(kamionosFelhasznaloNeve)) {
            cout << "Adja meg az uj cimet ahonnan szallitunk (\"\" = nem valtozik): ";
            getline(cin, honnan);
            cout << "Adja meg az aru uj megnevezeset (\"\" = nem valtozik): ";
            getline(cin, aruMegnevezes);
            cout << "Adja meg az uj mennyiseget (kg, -1 = nem valtozik): ";
            cin >> mennyiseg;
            cin.ignore();
            cout << "Adja meg az uj celallomast (\"\" = nem valtozik): ";
            getline(cin, cel);
            cout << "Adja meg az uj szallitas idejet (\"\" = nem valtozik): ";
            getline(cin, mikor);
            cout << "Adja meg az uj tavolsagot (km, -1 = nem valtozik): ";
            cin >> tavolsag;
            cout << "Adja meg az uj prioritast ([1-9] -1 = nem valtozik): ";
            cin >> prioritas;
            cin.ignore();
            cout << "Specialis igenyek (\"\" = nem valtozik): ";
            getline(cin, specialisIgenyek);
            cout << "Allapot (\"\" = nem valtozik): ";
            getline(cin, allapot);
            cout << "Atveves ideje (\"\" = nem valtozik): ";
            getline(cin, atvevesIdeje);
            cout << "Atvevo teljes neve (\"\" = nem valtozik): ";
            getline(cin, atvevoTeljesNeve);
            cout << "Adja meg az uj arat (Ft) (-1 = nem valtozik): ";
            cin >> ar;
            cin.ignore();
            cout << "Megjegyzesek (\"\" = nem valtozik): ";
            getline(cin, megjegyzesek);

            if (fuvarAdatokFormaiHelyessege(true, mennyiseg, tavolsag, prioritas, ar)) {
                lista.fuvarModositasa(id, kamionosFelhasznaloNeve, honnan, aruMegnevezes, mennyiseg,
                                      cel, mikor, tavolsag, prioritas, specialisIgenyek, allapot, atvevesIdeje,
                                      atvevoTeljesNeve, ar, megjegyzesek);
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

void Titkar::fuvarokKeresese(FuvarLista& lista)
{
    int keresId;
    string keresKamionosFelhasznaloNeve;
    string keresHonnan;
    string keresAruMegnevezes;
    string keresCel;
    string keresMikor;
    int keresPrioritas;
    string keresAllapot;
    string keresAtvevesIdeje;
    string keresAtvevoTeljesNeve;
    cout << "Fuvar azonosito (-1 = kihagyas): ";
    cin >> keresId;
    cin.ignore();
    cout << "Kamionos felhasznalo neve (\"\" = kihagyas): ";
    getline(cin, keresKamionosFelhasznaloNeve);
    cout << "Arut honnan szallitottak (\"\" = kihagyas): ";
    getline(cin, keresHonnan);
    cout << "Aru megnevezese (\"\" = kihagyas): ";
    getline(cin, keresAruMegnevezes);
    cout << "Celallomas (\"\" = kihagyas): ";
    getline(cin, keresCel);
    cout << "Szallitas ideje (\"\" = kihagyas): ";
    getline(cin, keresMikor);
    cout << "Prioritas (-1 = kihagyas): ";
    cin >> keresPrioritas;
    cin.ignore();
    cout << "Allapot (\"\" = kihagyas): ";
    getline(cin, keresAllapot);
    cout << "Atveves ideje (\"\" = kihagyas): ";
    getline(cin, keresAtvevesIdeje);
    cout << "Atvevo teljes neve (\"\" = kihagyas): ";
    getline(cin, keresAtvevoTeljesNeve);
    cout << endl;
    lista.kiirLeszurve(keresId, keresKamionosFelhasznaloNeve,
                          keresHonnan, keresAruMegnevezes, keresCel, keresMikor, keresPrioritas,
                          keresAllapot, keresAtvevesIdeje, keresAtvevoTeljesNeve);
}


void Titkar::kamionosFelhasznalokListazasa(FelhasznaloLista& felhLista)
{
    felhLista.kiirKamionosok();
}

void Titkar::cegekListazasa(CegLista& cegLista)
{
    cegLista.kiir();
}

bool Titkar::fuvarAdatokFormaiHelyessege(bool maradFlag, double mennyiseg, double tavolsag, int prioritas, int ar)
{
    return (( (maradFlag && mennyiseg == -1) || mennyiseg > 0) &&
            ( (maradFlag && tavolsag == -1) || tavolsag > 0) &&
            ( (maradFlag && prioritas == -1) || (prioritas >=1 && prioritas <= 9)) &&
            ( (maradFlag && ar == -1) || ar >= 1));
}

