#include "Admin.h"

Admin::Admin(const string& felhasznaloNev, const string& vezetekNev, const string& keresztNev) :
    Felhasznalo(felhasznaloNev, vezetekNev, keresztNev)
{
}

Admin::~Admin()
{}

void Admin::menuMutat()
{
    cout << "Bejelentkezve mint: " << felhasznaloNev << endl;
    cout << "> 1 : ceg felvetele" << endl;
    cout << "> 2 : ceg torlese" << endl;
    cout << "> 3 : ceg modositasa" << endl;
    cout << "> 4 : felhasznalo felvetele" << endl;
    cout << "> 5 : felhasznalok listazasa" << endl;
    cout << "> 6 : felhasznalo torlese" << endl;
    cout << "> 7 : felhasznalo modositasa" << endl;
    cout << "> 8 : cegek listazasa" << endl;
    cout << "> 9 : kilepes" << endl;
}

bool Admin::parancsFeldolgoz(int parancs, Adatok& adatok)
{
    bool kilepes = false;
    switch(parancs) {
    case 1:
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        felhasznaloFelvetele(adatok.getFelhasznaloLista());
        break;
    case 5:
        felhasznalokListazasa(adatok.getFelhasznaloLista());
        break;
    case 6:
        break;
    case 7:
        break;
    case 8:
        break;
    case 9:
        kilepes = true;
        break;
    }
    return kilepes;
}

void Admin::felhasznaloFelvetele(FelhasznaloLista& lista)
{
    string ujFelhasznaloNev;
    string ujJelszo;
    string ujKeresztNev;
    string ujVezetekNev;
    int ujTipus;

    cout << "Adja meg a felhasznalonevet: ";
    cin >> ujFelhasznaloNev;
    if (!lista.felhasznaloNevLetezik(ujFelhasznaloNev)) {
        cout << "Adjon meg egy jelszavat: ";
        cin >> ujJelszo;
        cout << "Adja meg a vezeteknevet: ";
        cin >> ujVezetekNev;
        cout << "Adja meg a keresztnevet: ";
        cin >> ujKeresztNev;
        cout << "Adja meg a felhasznalo tipusat: 0: tulajdonos, 1: admin, 2: titkar, 3: kamionos\n:";
        cin >> ujTipus;
        lista.ujFelhasznalo(ujFelhasznaloNev,
                               ujJelszo,
                               ujVezetekNev,
                               ujKeresztNev,
                               ujTipus);
    } else {
        cout << "A felhasznalonev mar letezik!" << endl;
    }
}

void Admin::felhasznalokListazasa(FelhasznaloLista& lista)
{
    lista.kiir();
}

