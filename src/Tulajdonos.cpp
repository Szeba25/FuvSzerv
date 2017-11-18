#include "Tulajdonos.h"

Tulajdonos::Tulajdonos(const string& aktivFelhasznaloNev, const string& aktivVezetekNev, const string& aktivKeresztNev) :
    AktivFelhasznalo(aktivFelhasznaloNev, aktivVezetekNev, aktivKeresztNev)
{}

Tulajdonos::~Tulajdonos()
{}

void Tulajdonos::menuMutat()
{
    cout << "> 1 : napi statisztika lekerese" << endl;
    cout << "> 2 : ceg adatok lekerese" << endl;
    cout << "> 3 : hatekonysagi statisztika lekerese" << endl;
    cout << "> 4 : kilepes" << endl;
}

bool Tulajdonos::parancsFeldolgoz(int parancs, Adatok& adatok)
{
    bool kilepes = false;
    switch(parancs) {
    case 1:
        napiStatisztikaLekerese(adatok.getFuvarLista());
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        kilepes = true;
        break;
    }
    return kilepes;
}

void Tulajdonos::napiStatisztikaLekerese(FuvarLista& lista)
{

}

