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
    for (auto& fuvar : fuvarok) {
        fuvar.kiir();
    }
}

void FuvarLista::fuvarHozzaadasa(const string& kamionosFelhasznaloNev,
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
    Fuvar fuvar(id, kamionosFelhasznaloNev,
                honnan, aruMegnevezes, mennyiseg,
                cel, mikor, tavolsag, prioritas, specialisIgenyek, megjegyzesek);
    fuvar.setAr(ar);
    fuvar.setAllapot("feldolgozas alatt");
    fuvarok.push_back(fuvar);
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
