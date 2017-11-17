#include "Menu.h"

Menu::Menu() :
    bejelentkezve(false),
    felhasznalo(nullptr)
{}

Menu::~Menu()
{
    delete felhasznalo;
}

bool Menu::mutat(Adatok& adatok)
{
    cout << endl << "### Fuvarszervezo 2000 ###" << endl;
    cout << "Udvozoljuk!" << endl;
    int parancs;
    bool kilepes = false;

    if (bejelentkezve) {
        felhasznalo->menuMutat();
        cin >> parancs;
        kilepes = felhasznalo->parancsFeldolgoz(parancs, adatok);
    } else {
        cout << "> 1 : bejelentkezes" << endl;
        cout << "> 2 : kilepes" << endl;
        cin >> parancs;
        string felhasznaloNev, jelszo;
        switch (parancs) {
        case 1:
            cin.ignore();
            cout << "Adja meg a felhasznalonevet: ";
            getline(cin, felhasznaloNev);
            cout << "Adja meg a jelszot: ";
            getline(cin, jelszo);
            bejelentkezve = bejelentkezes(felhasznaloNev, jelszo, adatok);
            break;
        case 2:
            kilepes = true;
            break;
        }
    }
    return kilepes;
}

bool Menu::bejelentkezes(const string& felhasznaloNev, const string& jelszo, Adatok& adatok)
{
    FelhasznaloLista felhasznaloLista = adatok.getFelhasznaloLista();
    FelhasznaloAdat* adat = felhasznaloLista.getFelhasznaloAdatLoginAlapjan(felhasznaloNev, jelszo);
    if (adat != nullptr) {
        int tipus = adat->getTipus();
        switch(tipus) {
        case 0:
            felhasznalo = new Tulajdonos(adat->getFelhasznaloNev(),
                                         adat->getVezetekNev(),
                                         adat->getKeresztNev());
            break;
        case 1:
            felhasznalo = new Admin(adat->getFelhasznaloNev(),
                                    adat->getVezetekNev(),
                                    adat->getKeresztNev());
            break;
        case 2:
            felhasznalo = new Titkar(adat->getFelhasznaloNev(),
                                     adat->getVezetekNev(),
                                     adat->getKeresztNev());
            break;
        case 3:
            felhasznalo = new Kamionos(adat->getFelhasznaloNev(),
                                       adat->getVezetekNev(),
                                       adat->getKeresztNev());
            break;
        }
        return true;
    } else {
        cout << "HIBA: A felhasznalonev nem letezik, vagy rossz a jelszo!" << endl;
        return false;
    }
}

