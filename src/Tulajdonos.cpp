#include "Tulajdonos.h"

Tulajdonos::Tulajdonos(const string& aktivFelhasznaloNev, const string& aktivVezetekNev, const string& aktivKeresztNev) :
    AktivFelhasznalo(aktivFelhasznaloNev, aktivVezetekNev, aktivKeresztNev)
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

bool Tulajdonos::parancsFeldolgoz(int parancs, Adatok& adatok)
{
    bool kilepes = false;
    switch(parancs) {
    case 1:
        cegAdatokLekerese(adatok.getCegAdatok());
        break;
    case 2:
        napiStatisztikaLekerese(adatok.getFuvarLista());
        break;
    case 3:
        hatekonysagiStatisztikaLekerese(adatok.getFuvarLista());
        break;
    case 4:
        kilepes = true;
        break;
    }
    return kilepes;
}

void Tulajdonos::cegAdatokLekerese(CegAdatok& adatok)
{
    cout << "Ceg neve: " << adatok.getAdatok().adatLeker(0, 0) << endl;
    cout << "Ceg cime: " << adatok.getAdatok().adatLeker(1, 0) << endl;
    cout << "Foglalkoztatottak szama: " << adatok.getAdatok().adatLeker(2, 0) << endl;
    cout << "Fejlesztesekre szant osszeg iden: " << adatok.getAdatok().adatLeker(3, 0) << endl;
}

void Tulajdonos::napiStatisztikaLekerese(FuvarLista& lista)
{
    cout << "Mai osszes fuvarok szama: " << lista.getMaiFuvarokSzama() << endl;
    cout << "Ma sikeresen teljesitett fuvarok szama: " << lista.getMaiSikeresFuvarokSzama() << endl;
}

void Tulajdonos::hatekonysagiStatisztikaLekerese(FuvarLista& lista)
{
    int ossz = lista.getFuvarokSzama();
    int sikeres = lista.getSikeresFuvarokSzama();
    int sikertelen = lista.getSikertelenFuvarokSzama();
    cout << "Az osszes fuvarok szama: " << ossz << endl;
    cout << "Sikeres fuvarok ebbol: " << sikeres << ", " << 100*((double)sikeres / (double)ossz) << "%" << endl;
    cout << "Sikertelen fuvarok ebbol: " << sikertelen << ", " << 100*((double)sikertelen / (double)ossz) << "%" << endl;
}

