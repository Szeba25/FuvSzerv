#ifndef FELHASZNALOADAT_H
#define FELHASZNALOADAT_H

#include <iostream>
using namespace std;

class FelhasznaloAdat
{
    public:
        FelhasznaloAdat(const string& felhasznaloNev, const string& jelszo,
                        const string& vezetekNev, const string& keresztNev, int tipus);
        virtual ~FelhasznaloAdat();

        const string& getFelhasznaloNev() const;
        const string& getJelszo() const;
        const string& getVezetekNev() const;
        const string& getKeresztNev() const;
        int getTipus() const;
        void setJelszo(const string& jelszo);
        void setVezetekNev(const string& vezetekNev);
        void setKeresztNev(const string& keresztNev);
        void setTipus(int tipus);
        void kiir() const;
    private:
        string felhasznaloNev;
        string jelszo;
        string vezetekNev;
        string keresztNev;
        int tipus;
};

#endif // FELHASZNALOADAT_H
