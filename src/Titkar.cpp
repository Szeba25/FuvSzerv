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
        break;
    case 4:
        break;
    case 5:
        break;
    case 6:
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
    string kamionosFelhasznaloNev;
    getline(cin, kamionosFelhasznaloNev);

    string honnan;
    string aruMegnevezes;
    double mennyiseg;
    string cel;
    string mikor;
    double tavolsag;
    int prioritas;
    string specialisIgenyek;
    string megjegyzesek;

    if (felhLista.kamionosFelhasznaloNevLetezik(kamionosFelhasznaloNev)) {
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
        if (fuvarAdatokFormaiHelyessege(mennyiseg, tavolsag, prioritas)) {
            lista.fuvarHozzaadasa(kamionosFelhasznaloNev, honnan, aruMegnevezes,
                                  mennyiseg, cel, mikor, tavolsag,
                                  prioritas, specialisIgenyek, megjegyzesek);
        } else {
            cout << "A megadott adatokban formai hiba van!" << endl;
        }
    } else {
        cout << "Nem letezik ilyen kamionos!" << endl;
    }
}

void Titkar::fuvarokListazasa(FuvarLista& lista)
{
    lista.kiir();
}


bool Titkar::fuvarAdatokFormaiHelyessege(double mennyiseg, double tavolsag, int prioritas)
{
    return ((mennyiseg > 0) && (tavolsag > 0) && (prioritas >=1 && prioritas <= 9));
}

