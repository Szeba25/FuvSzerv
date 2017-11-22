#ifndef TULAJDONOS_H
#define TULAJDONOS_H

#include "AktivFelhasznalo.h"

class Tulajdonos : public AktivFelhasznalo
{
    public:
        Tulajdonos(const string& aktivFelhasznaloNev, const string& aktivVezetekNev,
                   const string& aktivKeresztNev, FormaiEllenorzo* formaiEllenorzo);
        virtual ~Tulajdonos();

        virtual void menuMutat();
        virtual bool parancsFeldolgoz(int parancs);
    private:
        // USE CASES
        void cegAdatokLekerese(); // B1
        void napiStatisztikaLekerese(); // B2
        void hatekonysagiStatisztikaLekerese(); // B3
};

#endif // TULAJDONOS_H
