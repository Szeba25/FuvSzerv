#include "CegLista.h"

CegLista::CegLista()
{}

CegLista::~CegLista()
{}

void CegLista::beolvas()
{
    AdatFile file("ceglista.txt");
    for (auto& ertek : file.osszAdatLeker()) {
        Ceg ceg(atoi(ertek[0].c_str()), ertek[1], ertek[2], ertek[3], atoi(ertek[4].c_str()));
        cegek.push_back(ceg);
    }
}

void CegLista::mentes()
{
    AdatFile file;
    for (auto& ceg : cegek) {
        file.ujSor();
        file.ujAdat(utils::to_string(ceg.getId()));
        file.ujAdat(ceg.getNev());
        file.ujAdat(ceg.getCim());
        file.ujAdat(ceg.getTipus());
        file.ujAdat(utils::to_string(ceg.getMeret()));
    }
    file.mentes("ceglista.txt");
}

void CegLista::kiir() const
{
    for (auto& ceg : cegek) {
        ceg.kiir();
    }
}

bool CegLista::cegLetezik(int id)
{
    for (auto& ceg : cegek) {
        if (ceg.getId() == id) {
            return true;
        }
    }
    return false;
}

void CegLista::ujCeg(const string& nev, const string& cim, const string& tipus, int meret)
{
    cegek.push_back(Ceg(idGen(), nev, cim, tipus, meret));
    mentes();
}

void CegLista::cegTorlese(int id)
{
    for (vector<Ceg>::iterator it = cegek.begin(); it != cegek.end(); ++it) {
        if ((*it).getId() == id) {
            cegek.erase(it);
            break;
        }
    }
    mentes();
}

int CegLista::idGen() const
{
    int maxId = 0;
    for (auto& ceg : cegek) {
        if (ceg.getId() > maxId)
            maxId = ceg.getId();
    }
    return maxId+1;
}

void CegLista::cegModositasa(int id, const string& nev, const string& cim, const string& tipus, int meret)
{
    Ceg* modositandoCeg = getCegIdAlapjan(id);
    if (nev != "") modositandoCeg->setNev(nev);
    if (cim != "") modositandoCeg->setCim(cim);
    if (tipus != "") modositandoCeg->setTipus(tipus);
    if (meret != -1) modositandoCeg->setMeret(meret);
    mentes();
}

Ceg* CegLista::getCegIdAlapjan(int id)
{
    for (auto& ceg : cegek) {
        if (ceg.getId() == id) {
            return &ceg;
        }
    }
    return nullptr;
}
