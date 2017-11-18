#include "Admin.h"

Admin::Admin(const string& aktivFelhasznaloNev, const string& aktivVezetekNev, const string& aktivKeresztNev) :
    AktivFelhasznalo(aktivFelhasznaloNev, aktivVezetekNev, aktivKeresztNev)
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
    meret = utils::getint();

    if (cegAdataiFormaiEllenorzes(false, meret)) {
        lista.ujCeg(nev, cim, tipus, meret);
    } else {
        cout << "HIBA: A megadott meret nem megengedett!" << endl;
    }
}

void Admin::cegTorlese(CegLista& lista)
{
    int id;
    cout << "Adja meg a torolni kivant ceg azonositojat (szam): ";
    id = utils::getint();

    if (lista.cegLetezik(id)) {
        lista.cegTorlese(id);
    } else {
        cout << "HIBA: Nincs ilyen azonositoju ceg!" << endl;
    }
}

void Admin::cegModositasa(CegLista& lista)
{
    string nev;
    string cim;
    string tipus;
    int meret;

    cin.ignore();
    cout << "Adja meg a modositani kivant ceg azonositojat: ";
    int id;
    id = utils::getint();

    if (lista.cegLetezik(id)) {
        cout << "[Ha az adatot nem adja meg, az nem kerul modositasra!!!]" << endl;
        cout << "Adja meg az uj ceg nevet: ";
        getline(cin, nev);
        cout << "Adja meg az uj ceg cimet: ";
        getline(cin, cim);
        cout << "Adja meg az uj ceg tipusat: ";
        getline(cin, tipus);
        cout << "Adja meg az uj ceg meretet [1-9]: ";
        meret = utils::getint();

        if (cegAdataiFormaiEllenorzes(true, meret)) {
            lista.cegModositasa(id, nev, cim, tipus, meret);
        } else {
            cout << "HIBA: A megadott meret nem megengedett!" << endl;
        }
    } else {
        cout << "HIBA: Nincs ilyen azonositoju ceg!" << endl;
    }
}

void Admin::felhasznaloFelvetele(FelhasznaloLista& lista)
{
    string felhasznaloNev;
    string jelszo;
    string vezetekNev;
    string keresztNev;
    int tipus;

    cin.ignore();
    cout << "Adja meg a felhasznalonevet: ";
    getline(cin, felhasznaloNev);
    if (!lista.felhasznaloNevLetezik(felhasznaloNev)) {
        cout << "Adjon meg egy jelszavat: ";
        getline(cin, jelszo);
        cout << "Adja meg a vezeteknevet: ";
        getline(cin, vezetekNev);
        cout << "Adja meg a keresztnevet: ";
        getline(cin, keresztNev);
        cout << "Adja meg a felhasznalo tipusat (0=tulajdonos, 1=admin, 2=titkar, 3=kamionos)\n:";
        tipus = utils::getint();

        if (felhasznaloAdataiFormaiEllenorzes(false, tipus)) {
            lista.ujFelhasznalo(felhasznaloNev,
                               jelszo,
                               vezetekNev,
                               keresztNev,
                               tipus);
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
    string felhasznaloNev;

    cin.ignore();
    cout << "Adjon meg egy felhasznalo nevet: ";
    getline(cin, felhasznaloNev);
    if (lista.felhasznaloNevLetezik(felhasznaloNev)) {
        lista.felhasznaloTorlese(felhasznaloNev);
    } else {
        cout << "HIBA: A felhasznalonev nem letezik!" << endl;
    }
}

void Admin::felhasznaloModositasa(FelhasznaloLista& lista)
{
    string felhasznaloNev;
    string jelszo;
    string vezetekNev;
    string keresztNev;
    int tipus;

    cin.ignore();
    cout << "Adjon meg egy felhasznalo nevet: ";
    getline(cin, felhasznaloNev);

    if (lista.felhasznaloNevLetezik(felhasznaloNev)) {
        cout << "[Ha az adatot nem adja meg, az nem kerul modositasra!!!]" << endl;
        cout << "Adjon meg egy uj jelszot: ";
        getline(cin, jelszo);
        cout << "Adjon meg egy uj vezeteknevet: ";
        getline(cin, vezetekNev);
        cout << "Adjon meg egy uj keresztnevet: ";
        getline(cin, keresztNev);
        cout << "Adjon meg egy uj tipust (0=tulajdonos, 1=admin, 2=titkar, 3=kamionos)\n:";
        tipus = utils::getint();

        if (felhasznaloAdataiFormaiEllenorzes(true, tipus)) {
            lista.felhasznaloModositasa(felhasznaloNev, jelszo, vezetekNev, keresztNev, tipus);
        } else {
            cout << "HIBA: A megadott tipus nem megengedett!" << endl;
        }
    } else {
        cout << "HIBA: A felhasznalonev nem letezik!" << endl;
    }
}

void Admin::cegekListazasa(CegLista& lista)
{
    lista.kiir();
}

bool Admin::felhasznaloAdataiFormaiEllenorzes(bool kihagyhato, int tipus)
{
    return ( (kihagyhato && tipus == -1) || (tipus >= 0 && tipus <= 3) );
}

bool Admin::cegAdataiFormaiEllenorzes(bool kihagyhato, int meret)
{
    return ( (kihagyhato && meret == -1) || (meret >= 1 && meret <= 9) );
}

