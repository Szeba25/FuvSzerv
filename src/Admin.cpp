#include "Admin.h"

Admin::Admin(const string& aktivFelhasznaloNev, const string& aktivVezetekNev,
             const string& aktivKeresztNev, FormaiEllenorzo* formaiEllenorzo) :
    AktivFelhasznalo(aktivFelhasznaloNev, aktivVezetekNev, aktivKeresztNev, formaiEllenorzo)
{}

Admin::~Admin()
{}

void Admin::menuMutat()
{
    cout << "> 1 : ceg felvetele" << endl;
    cout << "> 2 : ceg modositasa" << endl;
    cout << "> 3 : cegek listazasa" << endl;
    cout << "> 4 : ceg torlese" << endl;
    cout << "> 5 : felhasznalo felvetele" << endl;
    cout << "> 6 : felhasznalo modositasa" << endl;
    cout << "> 7 : felhasznalok listazasa" << endl;
    cout << "> 8 : felhasznalo torlese" << endl;
    cout << "> 9 : kilepes" << endl;
}

bool Admin::parancsFeldolgoz(int parancs)
{
    bool kilepes = false;
    switch(parancs) {
    case 1:
        cegFelvetele();
        break;
    case 2:
        cegModositasa();
        break;
    case 3:
        cegekListazasa();
        break;
    case 4:
        cegTorlese();
        break;
    case 5:
        felhasznaloFelvetele();
        break;
    case 6:
        felhasznaloModositasa();
        break;
    case 7:
        felhasznalokListazasa();
        break;
    case 8:
        felhasznaloTorlese();
        break;
    case 9:
        kilepes = true;
        break;
    }
    return kilepes;
}

void Admin::cegFelvetele()
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

    if (formaiEllenorzo->cegFelvetele(meret)) {
        cegLista->ujCeg(nev, cim, tipus, meret);
    } else {
        cout << "HIBA: A megadott meret nem megengedett!" << endl;
    }
}

void Admin::cegModositasa()
{
    string nev;
    string cim;
    string tipus;
    int meret;

    cin.ignore();
    cout << "Adja meg a modositani kivant ceg azonositojat: ";
    int id;
    id = utils::getint();

    if (cegLista->cegLetezik(id)) {
        cout << "[Ha az adatot nem adja meg, az nem kerul modositasra!!!]" << endl;
        cout << "Adja meg az uj ceg nevet: ";
        getline(cin, nev);
        cout << "Adja meg az uj ceg cimet: ";
        getline(cin, cim);
        cout << "Adja meg az uj ceg tipusat: ";
        getline(cin, tipus);
        cout << "Adja meg az uj ceg meretet [1-9]: ";
        meret = utils::getint();

        if (formaiEllenorzo->cegModositasa(meret)) {
            cegLista->cegModositasa(id, nev, cim, tipus, meret);
        } else {
            cout << "HIBA: A megadott meret nem megengedett!" << endl;
        }
    } else {
        cout << "HIBA: Nincs ilyen azonositoju ceg!" << endl;
    }
}

void Admin::cegekListazasa()
{
    cegLista->kiir();
}

void Admin::cegTorlese()
{
    int id;
    cin.ignore();
    cout << "Adja meg a torolni kivant ceg azonositojat (szam): ";
    id = utils::getint();

    if (cegLista->cegLetezik(id)) {
        cegLista->cegTorlese(id);
    } else {
        cout << "HIBA: Nincs ilyen azonositoju ceg!" << endl;
    }
}

void Admin::felhasznaloFelvetele()
{
    string felhasznaloNev;
    string jelszo;
    string vezetekNev;
    string keresztNev;
    int tipus;

    cin.ignore();
    cout << "Adja meg a felhasznalonevet: ";
    getline(cin, felhasznaloNev);
    if (!felhasznaloLista->felhasznaloNevLetezik(felhasznaloNev)) {
        cout << "Adjon meg egy jelszavat: ";
        getline(cin, jelszo);
        cout << "Adja meg a vezeteknevet: ";
        getline(cin, vezetekNev);
        cout << "Adja meg a keresztnevet: ";
        getline(cin, keresztNev);
        cout << "Adja meg a felhasznalo tipusat (0=tulajdonos, 1=admin, 2=titkar, 3=kamionos)\n:";
        tipus = utils::getint();

        if (formaiEllenorzo->felhasznaloFelvetele(tipus)) {
            felhasznaloLista->ujFelhasznalo(felhasznaloNev,
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

void Admin::felhasznaloModositasa()
{
    string felhasznaloNev;
    string jelszo;
    string vezetekNev;
    string keresztNev;
    int tipus;

    cin.ignore();
    cout << "Adjon meg egy felhasznalo nevet: ";
    getline(cin, felhasznaloNev);

    if (felhasznaloLista->felhasznaloNevLetezik(felhasznaloNev)) {
        cout << "[Ha az adatot nem adja meg, az nem kerul modositasra!!!]" << endl;
        cout << "Adjon meg egy uj jelszot: ";
        getline(cin, jelszo);
        cout << "Adjon meg egy uj vezeteknevet: ";
        getline(cin, vezetekNev);
        cout << "Adjon meg egy uj keresztnevet: ";
        getline(cin, keresztNev);
        cout << "Adjon meg egy uj tipust (0=tulajdonos, 1=admin, 2=titkar, 3=kamionos)\n:";
        tipus = utils::getint();

        if (formaiEllenorzo->felhasznaloModositasa(tipus)) {
            felhasznaloLista->felhasznaloModositasa(felhasznaloNev, jelszo, vezetekNev, keresztNev, tipus);
        } else {
            cout << "HIBA: A megadott tipus nem megengedett!" << endl;
        }
    } else {
        cout << "HIBA: A felhasznalonev nem letezik!" << endl;
    }
}

void Admin::felhasznalokListazasa()
{
    felhasznaloLista->kiir();
}

void Admin::felhasznaloTorlese()
{
    string felhasznaloNev;

    cin.ignore();
    cout << "Adjon meg egy felhasznalo nevet: ";
    getline(cin, felhasznaloNev);
    if (felhasznaloLista->felhasznaloNevLetezik(felhasznaloNev)) {
        felhasznaloLista->felhasznaloTorlese(felhasznaloNev);
    } else {
        cout << "HIBA: A felhasznalonev nem letezik!" << endl;
    }
}
