#include "FuvarLista.h"

FuvarLista::FuvarLista()
{}

FuvarLista::~FuvarLista()
{}

void FuvarLista::beolvas()
{
    AdatFile file("fuvarlista.txt");
    for (auto& ertek : file.osszAdatLeker()) {
        Fuvar fuvar(atoi(ertek[0].c_str()),
                    ertek[1],
                    ertek[2],
                    ertek[3],
                    utils::to_double(ertek[4]),
                    ertek[5],
                    ertek[6],
                    utils::to_double(ertek[7]),
                    atoi(ertek[8].c_str()),
                    ertek[9],
                    ertek[14]);
        fuvar.setAllapot(atoi(ertek[10].c_str()));
        fuvar.setAtvevesIdeje(ertek[11]);
        fuvar.setAtvevoTeljesNeve(ertek[12]);
        fuvar.setAr(atoi(ertek[13].c_str()));
        fuvarok.push_back(fuvar);
    }
}

void FuvarLista::mentes()
{
    AdatFile file;
    for (Fuvar& fuvar : fuvarok) {
        file.ujSor();
        file.ujAdat(utils::to_string(fuvar.getId()));
        file.ujAdat(fuvar.getKamionosFelhasznaloNeve());
        file.ujAdat(fuvar.getFeladoCim());
        file.ujAdat(fuvar.getAruMegnevezes());
        file.ujAdat(utils::to_string(fuvar.getMennyiseg()));
        file.ujAdat(fuvar.getCelCim());
        file.ujAdat(fuvar.getSzallitasiDatum());
        file.ujAdat(utils::to_string(fuvar.getTavolsag()));
        file.ujAdat(utils::to_string(fuvar.getPrioritas()));
        file.ujAdat(fuvar.getSpecialisIgenyek());
        file.ujAdat(utils::to_string(fuvar.getAllapot()));
        file.ujAdat(fuvar.getAtvevesIdeje());
        file.ujAdat(fuvar.getAtvevoTeljesNeve());
        file.ujAdat(utils::to_string(fuvar.getAr()));
        file.ujAdat(fuvar.getMegjegyzesek());
    }
    file.mentes("fuvarlista.txt");
}

void FuvarLista::kiir()
{
    for (Fuvar& fuvar : fuvarok) {
        fuvar.kiir();
    }
}

void FuvarLista::kiirLeszurve(int keresId,
                              const string& kamionosFelhasznaloNeve,
                              const string& feladoCim,
                              const string& aruMegnevezes,
                              const string& celCim,
                              const string& szallitasiDatum,
                              int prioritas,
                              int allapot,
                              const string& atvevesIdeje,
                              const string& atvevoTeljesNeve)
{
    for (Fuvar& fuvar : fuvarok) {
        if (matchInt(keresId, fuvar.getId()) &&
            matchString(kamionosFelhasznaloNeve, fuvar.getKamionosFelhasznaloNeve()) &&
            matchString(feladoCim, fuvar.getFeladoCim()) &&
            matchString(aruMegnevezes, fuvar.getAruMegnevezes()) &&
            matchString(celCim, fuvar.getCelCim()) &&
            matchString(szallitasiDatum, fuvar.getSzallitasiDatum()) &&
            matchInt(prioritas, fuvar.getPrioritas()) &&
            matchInt(allapot, fuvar.getAllapot()) &&
            matchString(atvevesIdeje, fuvar.getAtvevesIdeje()) &&
            matchString(atvevoTeljesNeve, fuvar.getAtvevoTeljesNeve()))
        {
            fuvar.kiir();
        }
    }
}

void FuvarLista::kiirLeszurve(const string& kamionosFelhasznaloNeve)
{
    for (Fuvar& fuvar : fuvarok) {
        if (fuvar.getKamionosFelhasznaloNeve() == kamionosFelhasznaloNeve) {
            fuvar.kiir();
        }
    }
}

void FuvarLista::kiirAzonositokLeszurve(const string& kamionosFelhasznaloNeve)
{
    cout << "Lehetseges azonositok:" << endl;
    int i = 0;
    for (Fuvar& fuvar : fuvarok) {
        if (fuvar.getKamionosFelhasznaloNeve() == kamionosFelhasznaloNeve) {
            cout << fuvar.getId();
            if (i < 12) {
                cout << ", ";
            } else {
                i = 0;
                cout << endl;
            }
            i++;
        }
    }
    cout << endl;
}


bool FuvarLista::matchString(const string& str1, const string& str2)
{
    if (str1 == "")
        return true;
    else
        return str1 == str2;
}

bool FuvarLista::matchInt(int i, int j)
{
    if (i == -1)
        return true;
    else
        return i == j;
}


void FuvarLista::fuvarHozzaadasa(const string& kamionosFelhasznaloNeve,
                                 const string& feladoCim,
                                 const string& aruMegnevezes,
                                 double mennyiseg,
                                 const string& celCim,
                                 const string& szallitasiDatum,
                                 double tavolsag,
                                 int prioritas,
                                 const string& specialisIgenyek,
                                 const string& megjegyzesek)
{
    int id = genId();
    int ar = prioritas * mennyiseg * tavolsag;
    Fuvar fuvar(id, kamionosFelhasznaloNeve,
                feladoCim, aruMegnevezes, mennyiseg,
                celCim, szallitasiDatum, tavolsag, prioritas, specialisIgenyek, megjegyzesek);
    fuvar.setAr(ar);
    fuvar.setAllapot(0);
    fuvarok.push_back(fuvar);
    mentes();
}

void FuvarLista::fuvarModositasa(int id,
                                 const string& kamionosFelhasznaloNeve,
                                 const string& feladoCim,
                                 const string& aruMegnevezes,
                                 double mennyiseg,
                                 const string& celCim,
                                 const string& szallitasiDatum,
                                 double tavolsag,
                                 int prioritas,
                                 const string& specialisIgenyek,
                                 int allapot,
                                 const string& atvevesIdeje,
                                 const string& atvevoTeljesNeve,
                                 int ar,
                                 const string& megjegyzesek)
{
    Fuvar* fuvar = getFuvarIdAlapjan(id);
    if (kamionosFelhasznaloNeve != "") fuvar->setKamionosFelhasznaloNeve(kamionosFelhasznaloNeve);
    if (feladoCim != "") fuvar->setFeladoCim(feladoCim);
    if (aruMegnevezes != "") fuvar->setAruMegnevezes(aruMegnevezes);
    if (mennyiseg != -1) fuvar->setMennyiseg(mennyiseg);
    if (celCim != "") fuvar->setCelCim(celCim);
    if (szallitasiDatum != "") fuvar->setSzallitasiDatum(szallitasiDatum);
    if (tavolsag != -1) fuvar->setTavolsag(tavolsag);
    if (prioritas != -1) fuvar->setPrioritas(prioritas);
    if (specialisIgenyek != "") fuvar->setSpecialisIgenyek(specialisIgenyek);
    if (allapot != -1) fuvar->setAllapot(allapot);
    if (atvevesIdeje != "") fuvar->setAtvevesIdeje(atvevesIdeje);
    if (atvevoTeljesNeve != "") fuvar->setAtvevoTeljesNeve(atvevoTeljesNeve);
    if (ar != -1) fuvar->setAr(ar);
    if (megjegyzesek != "") fuvar->setMegjegyzesek(megjegyzesek);

    mentes();
}

void FuvarLista::fuvarModositasa(int id, int allapot, const string& atvevesIdeje,
                                 const string& atvevoTeljesNeve)
{
    Fuvar* fuvar = getFuvarIdAlapjan(id);
    if (fuvar != nullptr) {
        if (allapot != -1) fuvar->setAllapot(allapot);
        if (atvevesIdeje != "") fuvar->setAtvevesIdeje(atvevesIdeje);
        if (atvevoTeljesNeve != "") fuvar->setAtvevoTeljesNeve(atvevoTeljesNeve);
    }
    mentes();
}

void FuvarLista::fuvarModositasa(int id, const string& megjegyzesek)
{
    Fuvar* fuvar = getFuvarIdAlapjan(id);
    if (fuvar != nullptr) {
        if (megjegyzesek != "") fuvar->setMegjegyzesek(megjegyzesek);
    }
    mentes();
}


int FuvarLista::genId()
{
    int maxId = 0;
    for (Fuvar& fuvar : fuvarok) {
        if (fuvar.getId() > maxId) {
            maxId = fuvar.getId();
        }
    }
    return maxId + 1;
}

bool FuvarLista::fuvarLetezik(int id)
{
    for (Fuvar& f : fuvarok) {
        if (f.getId() == id) {
            return true;
        }
    }
    return false;
}

Fuvar* FuvarLista::getFuvarIdAlapjan(int id)
{
    for (Fuvar& f : fuvarok) {
        if (f.getId() == id) {
            return &f;
        }
    }
    return nullptr;
}

int FuvarLista::getMaiFuvarokSzama()
{
    return 0;
}

int FuvarLista::getMaiTeljesitettFuvarokSzama()
{
    return 0;
}

