#ifndef MENU_H
#define MENU_H

#include <iostream>
#include "Adatok.h"
#include "Felhasznalo.h"

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
};

#endif // MENU_H
