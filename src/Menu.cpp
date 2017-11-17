#include "Menu.h"

Menu::Menu() :
    bejelentkezve(false)
{
    //ctor
}

Menu::~Menu()
{
    //dtor
}

bool Menu::mutat(Adatok& adatok)
{
    cout << "### Fuvarszervezo 2000 ###" << endl;
    cout << "Udvozoljuk!" << endl;
    int parancs;

    if (bejelentkezve) {
        felhasznalo->menuMutat();
        cin >> parancs;
        felhasznalo->parancsFeldolgoz(parancs, adatok);
    } else {
        cout << "> 1 : bejelentkezes" << endl;
        cout << "> 2 : kilepes" << endl;
        cin >> parancs;
        switch (parancs) {
        case 1:

            break;
        case 2:
            return true;
            break;
        }
    }
    return false;
}
