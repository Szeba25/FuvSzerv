#include "FuvarLista.h"

FuvarLista::FuvarLista()
{
    //ctor
}

FuvarLista::~FuvarLista()
{
    //dtor
}

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
        fuvar.setAllapot(ertek[10]);
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
        file.ujAdat(fuvar.getHonnan());
        file.ujAdat(fuvar.getAruMegnevezes());
        file.ujAdat(utils::to_string(fuvar.getMennyiseg()));
        file.ujAdat(fuvar.getCel());
        file.ujAdat(fuvar.getMikor());
        file.ujAdat(utils::to_string(fuvar.getTavolsag()));
        file.ujAdat(utils::to_string(fuvar.getPrioritas()));
        file.ujAdat(fuvar.getSpecialisIgenyek());
        file.ujAdat(fuvar.getAllapot());
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
                              const string& keresKamionosFelhasznaloNeve,
                              const string& keresHonnan,
                              const string& keresAruMegnevezes,
                              const string& keresCel,
                              const string& keresMikor,
                              int keresPrioritas,
                              const string& keresAllapot,
                              const string& keresAtvevesIdeje,
                              const string& keresAtvevoTeljesNeve)
{
    for (Fuvar& fuvar : fuvarok) {
        if (matchInt(keresId, fuvar.getId()) &&
            matchString(keresKamionosFelhasznaloNeve, fuvar.getKamionosFelhasznaloNeve()) &&
            matchString(keresHonnan, fuvar.getHonnan()) &&
            matchString(keresAruMegnevezes, fuvar.getAruMegnevezes()) &&
            matchString(keresCel, fuvar.getCel()) &&
            matchString(keresMikor, fuvar.getMikor()) &&
            matchInt(keresPrioritas, fuvar.getPrioritas()) &&
            matchString(keresAllapot, fuvar.getAllapot()) &&
            matchString(keresAtvevesIdeje, fuvar.getAtvevesIdeje()) &&
            matchString(keresAtvevoTeljesNeve, fuvar.getAtvevoTeljesNeve()))
        {
            fuvar.kiir();
        }
    }
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
                                 const string& honnan,
                                 const string& aruMegnevezes,
                                 double mennyiseg,
                                 const string& cel,
                                 const string& mikor,
                                 double tavolsag,
                                 int prioritas,
                                 const string& specialisIgenyek,
                                 const string& megjegyzesek)
{
    int id = genId();
    int ar = prioritas * mennyiseg * tavolsag;
    Fuvar fuvar(id, kamionosFelhasznaloNeve,
                honnan, aruMegnevezes, mennyiseg,
                cel, mikor, tavolsag, prioritas, specialisIgenyek, megjegyzesek);
    fuvar.setAr(ar);
    fuvar.setAllapot("feldolgozas alatt");
    fuvarok.push_back(fuvar);
    mentes();
}

void FuvarLista::fuvarModositasa(int id,
                                 const string& kamionosFelhasznaloNeve,
                                 const string& honnan,
                                 const string& aruMegnevezes,
                                 double mennyiseg,
                                 const string& cel,
                                 const string& mikor,
                                 double tavolsag,
                                 int prioritas,
                                 const string& specialisIgenyek,
                                 const string& allapot,
                                 const string& atvevesIdeje,
                                 const string& atvevoTeljesNeve,
                                 int ar,
                                 const string& megjegyzesek)
{
    Fuvar* fuvar = getFuvarIdAlapjan(id);
    if (kamionosFelhasznaloNeve != "") fuvar->setKamionosFelhasznaloNeve(kamionosFelhasznaloNeve);
    if (honnan != "") fuvar->setHonnan(honnan);
    if (aruMegnevezes != "") fuvar->setAruMegnevezes(aruMegnevezes);
    if (mennyiseg != -1) fuvar->setMennyiseg(mennyiseg);
    if (cel != "") fuvar->setCel(cel);
    if (mikor != "") fuvar->setMikor(mikor);
    if (tavolsag != -1) fuvar->setTavolsag(tavolsag);
    if (prioritas != -1) fuvar->setPrioritas(prioritas);
    if (specialisIgenyek != "") fuvar->setSpecialisIgenyek(specialisIgenyek);
    if (allapot != "") fuvar->setAllapot(allapot);
    if (atvevesIdeje != "") fuvar->setAtvevesIdeje(atvevesIdeje);
    if (atvevoTeljesNeve != "") fuvar->setAtvevoTeljesNeve(atvevoTeljesNeve);
    if (ar != -1) fuvar->setAr(ar);
    if (megjegyzesek != "") fuvar->setMegjegyzesek(megjegyzesek);
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

