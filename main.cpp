#include <iostream>
#include "Menu.h"
#include "Adatok.h"

using namespace std;

int main()
{
    Menu menu;
    Adatok adatok;
    bool kilepes = false;
    while (!kilepes) {
        kilepes = menu.mutat(adatok);
    }
    return 0;
}
