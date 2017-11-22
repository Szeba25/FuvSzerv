#include "Kamionos.h"

Kamionos::Kamionos(const string& aktivFelhasznaloNev, const string& aktivVezetekNev,
                   const string& aktivKeresztNev, FormaiEllenorzo* formaiEllenorzo) :
    AktivFelhasznalo(aktivFelhasznaloNev, aktivVezetekNev, aktivKeresztNev, formaiEllenorzo)
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

bool Kamionos::parancsFeldolgoz(int parancs)
{
    bool kilepes = false;
    switch (parancs) {
    case 1:
        fuvarokCelzottListazasa();
        break;
    case 2:
        fuvarMegtekintese();
        break;
    case 3:
        fuvarAllapotModositasa();
        break;
    case 4:
        fuvarMegjegyzesekModositasa();
        break;
    case 5:
        kilepes = true;
        break;
    }
    return kilepes;
}

void Kamionos::fuvarokCelzottListazasa()
{
    fuvarLista->kiirLeszurve(aktivFelhasznaloNev);
}

void Kamionos::fuvarMegtekintese()
{
    int id;

    // INCLUDE
    fuvarAzonositokCelzottListazasa();

    cin.ignore();
    cout << "Adja meg a fuvar azonositot: ";
    id = utils::getint();

    if (fuvarLista->fuvarLetezik(id)) {
        fuvarLista->getFuvarIdAlapjan(id)->kiir();
    } else {
        cout << "Nem letezik ilyen fuvar azonosito!" << endl;
    }
}

void Kamionos::fuvarAllapotModositasa()
{
    int allapot;
    string atvevesIdeje;
    string atvevoTeljesNeve;

    fuvarAzonositokCelzottListazasa();

    cin.ignore();
    cout << "Adja meg a fuvar azonositot: ";
    int id;
    id = utils::getint();

    if (fuvarLista->fuvarLetezik(id)) {
        cout << "[Ha az adatot nem adja meg, az nem kerul modositasra!!!]" << endl;
        cout << "Adja meg az uj allapotot (0=feldolgozas alatt, 1=sikeres, 2=sikertelen): ";
        allapot = utils::getint();
        cout << "Adja meg az uj atveves idejet (eeee.hh.nn): ";
        getline(cin, atvevesIdeje);
        cout << "Adja meg az uj atvevo teljes nevet: ";
        getline(cin, atvevoTeljesNeve);

        if (formaiEllenorzo->fuvarAllapotModositasa(atvevesIdeje, allapot)) {
            fuvarLista->fuvarModositasa(id, allapot, atvevesIdeje, atvevoTeljesNeve);
        } else {
            cout << "A megadott datum helytelen formatumu!" << endl;
        }

    } else {
        cout << "Nem letezik ilyen fuvar azonosito!" << endl;
    }
}

void Kamionos::fuvarMegjegyzesekModositasa()
{
    int id;
    string megjegyzesek;

    fuvarAzonositokCelzottListazasa();

    cin.ignore();
    cout << "Adja meg a fuvar azonositot: ";
    id = utils::getint();

    if (fuvarLista->fuvarLetezik(id)) {
        cout << "[Ha az adatot nem adja meg, az nem kerul modositasra!!!]" << endl;
        cout << "Adja meg az uj megjegyzest: ";
        getline(cin, megjegyzesek);
        fuvarLista->fuvarModositasa(id, megjegyzesek);
    } else {
        cout << "Nem letezik ilyen fuvar azonosito!" << endl;
    }
}

void Kamionos::fuvarAzonositokCelzottListazasa()
{
    fuvarLista->kiirAzonositokLeszurve(aktivFelhasznaloNev);
}
