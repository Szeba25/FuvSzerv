#ifndef KAMIONOS_H
#define KAMIONOS_H

#include "AktivFelhasznalo.h"

class Kamionos : public AktivFelhasznalo
{
    public:
        Kamionos(const string& aktivFelhasznaloNev, const string& aktivVezetekNev,
                 const string& aktivKeresztNev, FormaiEllenorzo* formaiEllenorzo);
        virtual ~Kamionos();

        virtual void menuMutat();
        virtual bool parancsFeldolgoz(int parancs);
    private:
        // USE CASES
        void fuvarokCelzottListazasa(); // K1
        void fuvarMegtekintese(); // K3
        void fuvarAllapotModositasa(); // K4
        void fuvarMegjegyzesekModositasa(); // K5

        // INCLUDE
        void fuvarAzonositokCelzottListazasa(); // K2

};

#endif // KAMIONOS_H
