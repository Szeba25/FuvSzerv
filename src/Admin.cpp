#include "Admin.h"

Admin::Admin(const string& felhasznaloNev, const string& vezetekNev, const string& keresztNev) :
    Felhasznalo(felhasznaloNev, vezetekNev, keresztNev)
{}

Admin::~Admin()
{}

void Admin::menuMutat()
{
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
        cegFelvetele(adatok.getCegLista());
        break;
    case 2:
        cegTorlese(adatok.getCegLista());
        break;
    case 3:
        cegModositasa(adatok.getCegLista());
        break;
    case 4:
        felhasznaloFelvetele(adatok.getFelhasznaloLista());
        break;
    case 5:
        felhasznalokListazasa(adatok.getFelhasznaloLista());
        break;
    case 6:
        felhasznaloTorlese(adatok.getFelhasznaloLista());
        break;
    case 7:
        felhasznaloModositasa(adatok.getFelhasznaloLista());
        break;
    case 8:
        cegekListazasa(adatok.getCegLista());
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
    string ujVezetekNev;
    string ujKeresztNev;
    int ujTipus;

    cin.ignore();
    cout << "Adja meg a felhasznalonevet: ";
    getline(cin, ujFelhasznaloNev);
    if (!lista.felhasznaloNevLetezik(ujFelhasznaloNev)) {
        cout << "Adjon meg egy jelszavat: ";
        getline(cin, ujJelszo);
        cout << "Adja meg a vezeteknevet: ";
        getline(cin, ujVezetekNev);
        cout << "Adja meg a keresztnevet: ";
        getline(cin, ujKeresztNev);
        cout << "Adja meg a felhasznalo tipusat (0=tulajdonos, 1=admin, 2=titkar, 3=kamionos)\n:";
        cin >> ujTipus;
        if (felhasznaloAdataiFormaiEllenorzes(ujTipus)) {
            lista.ujFelhasznalo(ujFelhasznaloNev,
                               ujJelszo,
                               ujVezetekNev,
                               ujKeresztNev,
                               ujTipus);
        } else {
            cout << "HIBA: A megadott tipus nem megengedett!" << endl;
        }
    } else {
        cout << "HIBA: A felhasznalonev mar letezik!" << endl;
    }
}

void Admin::felhasznalokListazasa(FelhasznaloLista& lista)
{
    lista.kiir();
}

void Admin::felhasznaloTorlese(FelhasznaloLista& lista)
{
    string delFelhasznaloNev;

    cin.ignore();
    cout << "Adjon meg egy felhasznalo nevet: ";
    getline(cin, delFelhasznaloNev);
    if (lista.felhasznaloNevLetezik(delFelhasznaloNev)) {
        lista.felhasznaloTorlese(delFelhasznaloNev);
    } else {
        cout << "HIBA: A felhasznalonev nem letezik!" << endl;
    }
}

void Admin::felhasznaloModositasa(FelhasznaloLista& lista)
{
    string modFelhasznaloNev;
    string ujJelszo;
    string ujVezetekNev;
    string ujKeresztNev;
    int ujTipus;

    cin.ignore();
    cout << "Adjon meg egy felhasznalo nevet: ";
    getline(cin, modFelhasznaloNev);
    if (lista.felhasznaloNevLetezik(modFelhasznaloNev)) {
        cout << "Adjon meg egy uj jelszot (* = nem valtozik): ";
        getline(cin, ujJelszo);
        cout << "Adjon meg egy uj vezeteknevet (* = nem valtozik): ";
        getline(cin, ujVezetekNev);
        cout << "Adjon meg egy uj keresztnevet (* = nem valtozik): ";
        getline(cin, ujKeresztNev);
        cout << "Adjon meg egy uj tipust (-1=nem valtozik, 0=tulajdonos, 1=admin, 2=titkar, 3=kamionos)\n:";
        cin >> ujTipus;
        if (ujTipus == -1 || felhasznaloAdataiFormaiEllenorzes(ujTipus)) {
            lista.felhasznaloModositasa(modFelhasznaloNev, ujJelszo, ujVezetekNev, ujKeresztNev, ujTipus);
        } else {
            cout << "HIBA: A megadott tipus nem megengedett!" << endl;
        }
    } else {
        cout << "HIBA: A felhasznalonev nem letezik!" << endl;
    }
}

void Admin::cegFelvetele(CegLista& lista)
{
    string nev;
    string cim;
    string tipus;
    int meret;

    cin.ignore();
    cout << "Adja meg a ceg nevet: ";
    getline(cin, nev);
    cout << "Adja meg a ceg cimet: ";
    getline(cin, cim);
    cout << "Adja meg a ceg tipusat: ";
    getline(cin, tipus);
    cout << "Adja meg a ceg meretet [1-9]: ";
    cin >> meret;
    if (cegAdataiFormaiEllenorzes(meret)) {
        lista.ujCeg(nev, cim, tipus, meret);
    } else {
        cout << "HIBA: A megadott meret nem megengedett!" << endl;
    }
}

void Admin::cegTorlese(CegLista& lista)
{
    int id;
    cout << "Adja meg a torolni kivant ceg azonositojat (szam): ";
    cin >> id;
    if (lista.cegLetezik(id)) {
        lista.cegTorlese(id);
    } else {
        cout << "HIBA: Nincs ilyen azonositoju ceg!" << endl;
    }
}

void Admin::cegModositasa(CegLista& lista)
{
    string ujNev;
    string ujCim;
    string ujTipus;
    int ujMeret;

    cout << "Adja meg a modositani kivant ceg azonositojat (szam): ";
    int id;
    cin >> id;
    if (lista.cegLetezik(id)) {
        cin.ignore();
        cout << "Adja meg az uj ceg nevet (* = nem valtozik): ";
        getline(cin, ujNev);
        cout << "Adja meg az uj ceg cimet (* = nem valtozik): ";
        getline(cin, ujCim);
        cout << "Adja meg az uj ceg tipusat (* = nem valtozik): ";
        getline(cin, ujTipus);
        cout << "Adja meg az uj ceg meretet ([1-9], -1 = nem valtozik!): ";
        cin >> ujMeret;
        if (ujMeret == -1 || cegAdataiFormaiEllenorzes(ujMeret)) {
            lista.cegModositasa(id, ujNev, ujCim, ujTipus, ujMeret);
        } else {
            cout << "HIBA: A megadott meret nem megengedett!" << endl;
        }
    } else {
        cout << "HIBA: Nincs ilyen azonositoju ceg!" << endl;
    }
}

void Admin::cegekListazasa(CegLista& lista)
{
    lista.kiir();
}

bool Admin::felhasznaloAdataiFormaiEllenorzes(int tipus)
{
    return (tipus >= 0 && tipus <= 3);
}

bool Admin::cegAdataiFormaiEllenorzes(int meret)
{
    return (meret >= 1 && meret <= 9);
}

