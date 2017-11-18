#ifndef TULAJDONOS_H
#define TULAJDONOS_H

#include "AktivFelhasznalo.h"

class Tulajdonos : public AktivFelhasznalo
{
    public:
        Tulajdonos(const string& aktivFelhasznaloNev, const string& aktivVezetekNev, const string& aktivKeresztNev);
        virtual ~Tulajdonos();

        virtual void menuMutat();
        virtual bool parancsFeldolgoz(int parancs, Adatok& adatok);
    private:
        // USE CASES
        void cegAdatokLekerese(CegAdatok& adatok); // B1
        void napiStatisztikaLekerese(FuvarLista& lista); // B2
        void hatekonysagiStatisztikaLekerese(FuvarLista& lista); // B3
};

#endif // TULAJDONOS_H
