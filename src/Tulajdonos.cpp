#include "Tulajdonos.h"

Tulajdonos::Tulajdonos(const string& felhasznaloNev, const string& vezetekNev, const string& keresztNev) :
    Felhasznalo(felhasznaloNev, vezetekNev, keresztNev)
{}

Tulajdonos::~Tulajdonos()
{}

void Tulajdonos::menuMutat()
{
    cout << "> 1 : napi statisztika lekerese" << endl;
    cout << "> 2 : ceg adatok lekerese" << endl;
    cout << "> 3 : hatekonysagi statisztika lekerese" << endl;
}

void Tulajdonos::parancsFeldolgoz(int parancs, Adatok& adatok)
{

}
