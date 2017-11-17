#ifndef MENU_H
#define MENU_H

#include <iostream>
#include "Adatok.h"
#include "Felhasznalo.h"
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
        Felhasznalo* felhasznalo;

        bool bejelentkezes(const string& felhasznaloNev, const string& jelszo, Adatok& adatok);
};

#endif // MENU_H
