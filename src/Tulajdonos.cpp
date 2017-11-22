#include "Tulajdonos.h"

Tulajdonos::Tulajdonos(const string& aktivFelhasznaloNev, const string& aktivVezetekNev,
                       const string& aktivKeresztNev, FormaiEllenorzo* formaiEllenorzo) :
    AktivFelhasznalo(aktivFelhasznaloNev, aktivVezetekNev, aktivKeresztNev, formaiEllenorzo)
{}

Tulajdonos::~Tulajdonos()
{}

void Tulajdonos::menuMutat()
{
    cout << "> 1 : ceg adatok lekerese" << endl;
    cout << "> 2 : napi statisztika lekerese" << endl;
    cout << "> 3 : hatekonysagi statisztika lekerese" << endl;
    cout << "> 4 : kilepes" << endl;
}

bool Tulajdonos::parancsFeldolgoz(int parancs)
{
    bool kilepes = false;
    switch(parancs) {
    case 1:
        cegAdatokLekerese();
        break;
    case 2:
        napiStatisztikaLekerese();
        break;
    case 3:
        hatekonysagiStatisztikaLekerese();
        break;
    case 4:
        kilepes = true;
        break;
    }
    return kilepes;
}

void Tulajdonos::cegAdatokLekerese()
{
    cout << "Ceg neve: " << cegAdatok->getAdatok().adatLeker(0, 0) << endl;
    cout << "Ceg cime: " << cegAdatok->getAdatok().adatLeker(1, 0) << endl;
    cout << "Foglalkoztatottak szama: " << cegAdatok->getAdatok().adatLeker(2, 0) << endl;
    cout << "Fejlesztesekre szant osszeg iden: " << cegAdatok->getAdatok().adatLeker(3, 0) << endl;
}

void Tulajdonos::napiStatisztikaLekerese()
{
    cout << "Mai osszes fuvarok szama: " << fuvarLista->getMaiFuvarokSzama() << endl;
    cout << "Ma sikeresen teljesitett fuvarok szama: " << fuvarLista->getMaiSikeresFuvarokSzama() << endl;
}

void Tulajdonos::hatekonysagiStatisztikaLekerese()
{
    int ossz = fuvarLista->getFuvarokSzama();
    int sikeres = fuvarLista->getSikeresFuvarokSzama();
    int sikertelen = fuvarLista->getSikertelenFuvarokSzama();
    cout << "Az osszes fuvarok szama: " << ossz << endl;
    cout << "Sikeres fuvarok ebbol: " << sikeres << ", " << 100*((double)sikeres / (double)ossz) << "%" << endl;
    cout << "Sikertelen fuvarok ebbol: " << sikertelen << ", " << 100*((double)sikertelen / (double)ossz) << "%" << endl;
}

