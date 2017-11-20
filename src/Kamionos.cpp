#include "Kamionos.h"

Kamionos::Kamionos(const string& aktivFelhasznaloNev, const string& aktivVezetekNev, const string& aktivKeresztNev) :
    AktivFelhasznalo(aktivFelhasznaloNev, aktivVezetekNev, aktivKeresztNev)
{}

Kamionos::~Kamionos()
{}

void Kamionos::menuMutat()
{
    cout << "> 1 : fuvarok celzott listazasa" << endl;
    cout << "> 2 : fuvar megtekintese" << endl;
    cout << "> 3 : fuvar allapotanak modositasa" << endl;
    cout << "> 4 : fuvar megjegyzesek modositasa" << endl;
    cout << "> 5 : kilepes" << endl;
}

bool Kamionos::parancsFeldolgoz(int parancs, Adatok& adatok)
{
    bool kilepes = false;
    switch (parancs) {
    case 1:
        fuvarokCelzottListazasa(adatok.getFuvarLista());
        break;
    case 2:
        fuvarMegtekintese(adatok.getFuvarLista());
        break;
    case 3:
        fuvarAllapotModositasa(adatok.getFuvarLista(), adatok.getFormaiEllenorzo());
        break;
    case 4:
        fuvarMegjegyzesekModositasa(adatok.getFuvarLista());
        break;
    case 5:
        kilepes = true;
        break;
    }
    return kilepes;
}

void Kamionos::fuvarokCelzottListazasa(FuvarLista& lista)
{
    lista.kiirLeszurve(aktivFelhasznaloNev);
}

void Kamionos::fuvarMegtekintese(FuvarLista& lista)
{
    int id;

    // INCLUDE
    fuvarAzonositokCelzottListazasa(lista);

    cin.ignore();
    cout << "Adja meg a fuvar azonositot: ";
    id = utils::getint();

    if (lista.fuvarLetezik(id)) {
        lista.getFuvarIdAlapjan(id)->kiir();
    } else {
        cout << "Nem letezik ilyen fuvar azonosito!" << endl;
    }
}

void Kamionos::fuvarAllapotModositasa(FuvarLista& lista, FormaiEllenorzo& formaiEllenorzo)
{
    int allapot;
    string atvevesIdeje;
    string atvevoTeljesNeve;

    fuvarAzonositokCelzottListazasa(lista);

    cin.ignore();
    cout << "Adja meg a fuvar azonositot: ";
    int id;
    id = utils::getint();

    if (lista.fuvarLetezik(id)) {
        cout << "[Ha az adatot nem adja meg, az nem kerul modositasra!!!]" << endl;
        cout << "Adja meg az uj allapotot (0=feldolgozas alatt, 1=sikeres, 2=sikertelen): ";
        allapot = utils::getint();
        cout << "Adja meg az uj atveves idejet (eeee.hh.nn): ";
        getline(cin, atvevesIdeje);
        cout << "Adja meg az uj atvevo teljes nevet: ";
        getline(cin, atvevoTeljesNeve);

        if (formaiEllenorzo.fuvarAllapotModositasa(atvevesIdeje, allapot)) {
            lista.fuvarModositasa(id, allapot, atvevesIdeje, atvevoTeljesNeve);
        } else {
            cout << "A megadott datum helytelen formatumu!" << endl;
        }

    } else {
        cout << "Nem letezik ilyen fuvar azonosito!" << endl;
    }
}

void Kamionos::fuvarMegjegyzesekModositasa(FuvarLista& lista)
{
    int id;
    string megjegyzesek;

    fuvarAzonositokCelzottListazasa(lista);

    cin.ignore();
    cout << "Adja meg a fuvar azonositot: ";
    id = utils::getint();

    if (lista.fuvarLetezik(id)) {
        cout << "[Ha az adatot nem adja meg, az nem kerul modositasra!!!]" << endl;
        cout << "Adja meg az uj megjegyzest: ";
        getline(cin, megjegyzesek);
        lista.fuvarModositasa(id, megjegyzesek);
    } else {
        cout << "Nem letezik ilyen fuvar azonosito!" << endl;
    }
}

void Kamionos::fuvarAzonositokCelzottListazasa(FuvarLista& lista)
{
    lista.kiirAzonositokLeszurve(aktivFelhasznaloNev);
}
