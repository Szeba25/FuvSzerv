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

    cout << "Adja meg a felhasznalonevet: ";
    cin >> ujFelhasznaloNev;
    if (!lista.felhasznaloNevLetezik(ujFelhasznaloNev)) {
        cout << "Adjon meg egy jelszavat: ";
        cin >> ujJelszo;
        cout << "Adja meg a vezeteknevet: ";
        cin >> ujVezetekNev;
        cout << "Adja meg a keresztnevet: ";
        cin >> ujKeresztNev;
        cout << "Adja meg a felhasznalo tipusat 0: tulajdonos, 1: admin, 2: titkar, 3: kamionos\n:";
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

void Admin::felhasznaloTorlese(FelhasznaloLista& lista)
{
    string delFelhasznaloNev;
    cout << "Adjon meg egy felhasznalo nevet: ";
    cin >> delFelhasznaloNev;
    if (lista.felhasznaloNevLetezik(delFelhasznaloNev)) {
        lista.felhasznaloTorlese(delFelhasznaloNev);
    } else {
        cout << "A felhasznalonev nem letezik!" << endl;
    }
}

void Admin::felhasznaloModositasa(FelhasznaloLista& lista)
{
    string modFelhasznaloNev;
    string ujJelszo;
    string ujVezetekNev;
    string ujKeresztNev;
    int ujTipus;

    cout << "Adjon meg egy felhasznalo nevet: ";
    cin >> modFelhasznaloNev;
    if (lista.felhasznaloNevLetezik(modFelhasznaloNev)) {
        cout << "Adjon meg egy uj jelszot (* = nem valtozik): ";
        cin >> ujJelszo;
        cout << "Adjon meg egy uj vezeteknevet (* = nem valtozik): ";
        cin >> ujVezetekNev;
        cout << "Adjon meg egy uj keresztnevet (* = nem valtozik): ";
        cin >> ujKeresztNev;
        cout << "Adjon meg egy uj tipust -1: nem valtozik, 0: tulajdonos, 1: admin, 2: titkar, 3: kamionos\n:";
        cin >> ujTipus;
        lista.felhasznaloModositasa(modFelhasznaloNev, ujJelszo, ujVezetekNev, ujKeresztNev, ujTipus);
    } else {
        cout << "A felhasznalonev nem letezik!" << endl;
    }
}

void Admin::cegFelvetele(CegLista& lista)
{
    string nev;
    string cim;
    string tipus;
    int meret;

    cin.ignore();
    cout << "Adja meg a ceg nevet (szokozoket tartalmazhat!): ";
    getline(cin, nev);
    cout << "Adja meg a ceg cimet (szokozoket tartalmazhat!): ";
    getline(cin, cim);
    cout << "Adja meg a ceg tipusat (szokozoket tartalmazhat!): ";
    getline(cin, tipus);
    cout << "Adja meg a ceg meretet (1-9): ";
    cin >> meret;
    lista.ujCeg(nev, cim, tipus, meret);
}

void Admin::cegTorlese(CegLista& lista)
{
    int id;
    cout << "Adja meg a torolni kivant ceg azonositojat: ";
    cin >> id;
    if (lista.cegLetezik(id)) {
        lista.cegTorlese(id);
    } else {
        cout << "Nincs ilyen azonositoju ceg!" << endl;
    }
}

void Admin::cegModositasa(CegLista& lista)
{
    string ujNev;
    string ujCim;
    string ujTipus;
    int ujMeret;

    cout << "Adja meg a modositani kivant ceg azonositojat: ";
    int id;
    cin >> id;
    if (lista.cegLetezik(id)) {
        cin.ignore();
        cout << "Adja meg az uj ceg nevet (szokozoket tartalmazhat! * = nem valtozik): ";
        getline(cin, ujNev);
        cout << "Adja meg az uj ceg cimet (szokozoket tartalmazhat! * = nem valtozik): ";
        getline(cin, ujCim);
        cout << "Adja meg az uj ceg tipusat (szokozoket tartalmazhat! * = nem valtozik): ";
        getline(cin, ujTipus);
        cout << "Adja meg az uj ceg meretet (1-9, -1 = nem valtozik!): ";
        cin >> ujMeret;
        lista.cegModositasa(id, ujNev, ujCim, ujTipus, ujMeret);
    } else {
        cout << "Nincs ilyen azonositoju ceg!" << endl;
    }
}

void Admin::cegekListazasa(CegLista& lista)
{
    lista.kiir();
}

