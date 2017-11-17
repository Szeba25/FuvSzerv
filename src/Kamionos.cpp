#include "Kamionos.h"

Kamionos::Kamionos(const string& felhasznaloNev, const string& vezetekNev, const string& keresztNev) :
    Felhasznalo(felhasznaloNev, vezetekNev, keresztNev)
{}

Kamionos::~Kamionos()
{}

void Kamionos::menuMutat()
{
    cout << "> 1 : fuvarok celzott listazasa" << endl;
    cout << "> 2 : fuvar allapotanak modositasa" << endl;
    cout << "> 3 : fuvar megjegyzesek modositasa" << endl;
    cout << "> 4 : fuvarok keresese" << endl;
    cout << "> 5 : kilepes" << endl;
}

bool Kamionos::parancsFeldolgoz(int parancs, Adatok& adatok)
{
    return true;
}
