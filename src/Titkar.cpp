#include "Titkar.h"

Titkar::Titkar(const string& felhasznaloNev, const string& vezetekNev, const string& keresztNev) :
    Felhasznalo(felhasznaloNev, vezetekNev, keresztNev)
{}

Titkar::~Titkar()
{}

void Titkar::menuMutat()
{
    cout << "> 1 : fuvar hozzaadasa" << endl;
    cout << "> 2 : fuvarok listazasa" << endl;
    cout << "> 3 : fuvar modositasa" << endl;
    cout << "> 4 : fuvarok keresese" << endl;
    cout << "> 5 : kamionos felhasznalok listazasa" << endl;
    cout << "> 6 : cegek listazasa" << endl;
}

void Titkar::parancsFeldolgoz(int parancs, Adatok& adatok)
{

}
