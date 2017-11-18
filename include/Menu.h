#ifndef MENU_H
#define MENU_H

#include <iostream>
#include "Adatok.h"
#include "AktivFelhasznalo.h"
#include "Tulajdonos.h"
#include "Admin.h"
#include "Titkar.h"
#include "Kamionos.h"

using namespace std;

class Menu
{
    public:
        Menu();
        virtual ~Menu();
        bool mutat(Adatok& adatok);

    private:
        bool bejelentkezve;
        AktivFelhasznalo* felhasznalo;

        bool bejelentkezes(const string& felhasznaloNev, const string& jelszo, Adatok& adatok);
};

#endif // MENU_H
