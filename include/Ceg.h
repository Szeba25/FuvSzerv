#ifndef CEG_H
#define CEG_H

#include <iostream>
using namespace std;

class Ceg
{
    public:
        Ceg(int id, const string& nev, const string& cim, const string& tipus, int meret);
        virtual ~Ceg();

        int getId() const;
        const string& getNev() const;
        const string& getCim() const;
        const string& getTipus() const;
        int getMeret() const;
        void setNev(const string& nev);
        void setCim(const string& cim);
        void setTipus(const string& tipus);
        void setMeret(int meret);

        void kiir() const;
    private:
        int id;
        string nev;
        string cim;
        string tipus;
        int meret;
};

#endif // CEG_H
