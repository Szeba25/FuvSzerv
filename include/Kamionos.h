#ifndef KAMIONOS_H
#define KAMIONOS_H

#include "Felhasznalo.h"

class Kamionos : public Felhasznalo
{
    public:
        Kamionos(const string& felhasznaloNev, const string& vezetekNev, const string& keresztNev);
        virtual ~Kamionos();

        virtual void menuMutat();
        virtual bool parancsFeldolgoz(int parancs, Adatok& adatok);
    private:
        void fuvarokCelzottListazasa(FuvarLista& lista);
        void fuvarMegtekintese(FuvarLista& lista);
        void fuvarAllapotModositasa(FuvarLista& lista);
        void fuvarMegjegyzesekModositasa(FuvarLista& lista);

        // include
        void fuvarAzonositokCelzottListazasa(FuvarLista& lista);
};

#endif // KAMIONOS_H
