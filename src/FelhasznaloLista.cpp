#include "FelhasznaloLista.h"

FelhasznaloLista::FelhasznaloLista()
{}

FelhasznaloLista::~FelhasznaloLista()
{}

void FelhasznaloLista::beolvas()
{
    AdatFile file("felhasznalolista.txt");
    for (auto& ertek : file.osszAdatLeker()) {
        FelhasznaloAdat felhasznaloAdat(ertek[0], ertek[1], ertek[2], ertek[3], atoi(ertek[4].c_str()));
        felhasznaloAdatok.push_back(felhasznaloAdat);
    }
}

void FelhasznaloLista::mentes()
{
    AdatFile file;
    for (auto& adat: felhasznaloAdatok) {
        file.ujSor();
        file.ujAdat(adat.getFelhasznaloNev());
        file.ujAdat(adat.getJelszo());
        file.ujAdat(adat.getVezetekNev());
        file.ujAdat(adat.getKeresztNev());
        file.ujAdat(utils::to_string(adat.getTipus()));
    }
    file.mentes("felhasznalolista.txt");
}


FelhasznaloAdat* FelhasznaloLista::getFelhasznaloAdatLoginAlapjan(const string& felhasznaloNev, const string& jelszo)
{
    for (auto& adat : felhasznaloAdatok) {
        if (adat.getFelhasznaloNev() == felhasznaloNev && adat.getJelszo() == jelszo) {
            return &adat;
        }
    }
    return nullptr;
}

FelhasznaloAdat* FelhasznaloLista::getFelhasznaloAdatFelhasznaloNevAlapjan(const string& felhasznaloNev)
{
    for (auto& adat : felhasznaloAdatok) {
        if (adat.getFelhasznaloNev() == felhasznaloNev) {
            return &adat;
        }
    }
    return nullptr;
}

bool FelhasznaloLista::felhasznaloNevLetezik(const string& felhasznaloNev)
{
    for (auto& adat : felhasznaloAdatok) {
        if (adat.getFelhasznaloNev() == felhasznaloNev) {
            return true;
        }
    }
    return false;
}

bool FelhasznaloLista::kamionosFelhasznaloNevLetezik(const string& kamionosFelhasznaloNev)
{
    for (FelhasznaloAdat& adat : felhasznaloAdatok) {
        if (adat.getFelhasznaloNev() == kamionosFelhasznaloNev && adat.getTipus() == 3) {
            return true;
        }
    }
    return false;
}


void FelhasznaloLista::ujFelhasznalo(const string& felhasznaloNev, const string& jelszo,
                                     const string& vezetekNev, const string& keresztNev, int tipus)
{
    felhasznaloAdatok.push_back(FelhasznaloAdat(felhasznaloNev,
                                                jelszo,
                                                vezetekNev,
                                                keresztNev,
                                                tipus));
    mentes();
}

void FelhasznaloLista::kiir() const
{
    for (auto& adat : felhasznaloAdatok) {
        adat.kiir();
    }
}

void FelhasznaloLista::felhasznaloTorlese(const string& felhasznaloNev)
{
    for (vector<FelhasznaloAdat>::iterator it = felhasznaloAdatok.begin(); it != felhasznaloAdatok.end(); ++it) {
        if ((*it).getFelhasznaloNev() == felhasznaloNev) {
            felhasznaloAdatok.erase(it);
            break;
        }
    }
    mentes();
}

void FelhasznaloLista::felhasznaloModositasa(const string& felhasznaloNev, const string& jelszo,
                                             const string& vezetekNev, const string& keresztNev, int tipus)
{
    FelhasznaloAdat* adat = getFelhasznaloAdatFelhasznaloNevAlapjan(felhasznaloNev);
    if (jelszo != "*") adat->setJelszo(jelszo);
    if (vezetekNev != "*") adat->setVezetekNev(vezetekNev);
    if (keresztNev != "*") adat->setKeresztNev(keresztNev);
    if (tipus != -1) adat->setTipus(tipus);
    mentes();
}
