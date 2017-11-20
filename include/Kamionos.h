#ifndef KAMIONOS_H
#define KAMIONOS_H

#include "AktivFelhasznalo.h"

class Kamionos : public AktivFelhasznalo
{
    public:
        Kamionos(const string& aktivFelhasznaloNev, const string& aktivVezetekNev, const string& aktivKeresztNev);
        virtual ~Kamionos();

        virtual void menuMutat();
        virtual bool parancsFeldolgoz(int parancs, Adatok& adatok);
    private:
        // USE CASES
        void fuvarokCelzottListazasa(FuvarLista& lista); // K1
        void fuvarMegtekintese(FuvarLista& lista); // K3
        void fuvarAllapotModositasa(FuvarLista& lista, FormaiEllenorzo& formaiEllenorzo); // K4
        void fuvarMegjegyzesekModositasa(FuvarLista& lista); // K5

        // INCLUDE
        void fuvarAzonositokCelzottListazasa(FuvarLista& lista); // K2

};

#endif // KAMIONOS_H
