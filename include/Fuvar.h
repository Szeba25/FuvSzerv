#ifndef FUVAR_H
#define FUVAR_H

#include <iostream>
using namespace std;

class Fuvar
{
    public:
        Fuvar(int id,
              const string& kamionosFelhasznaloNeve,
              const string& feladoCim,
              const string& aruMegnevezes,
              double mennyiseg,
              const string& celCim,
              const string& szallitasiDatum,
              double tavolsag,
              int prioritas,
              const string& specialisIgenyek,
              const string& megjegyzesek);
        virtual ~Fuvar();

        int getId() const;
        const string& getKamionosFelhasznaloNeve() const;
        const string& getFeladoCim() const;
        const string& getAruMegnevezes() const;
        double getMennyiseg() const;
        const string& getCelCim() const;
        const string& getSzallitasiDatum() const;
        double getTavolsag() const;
        int getPrioritas() const;
        const string& getSpecialisIgenyek() const;
        const string& getAllapot() const;
        const string& getAtvevesIdeje() const;
        const string& getAtvevoTeljesNeve() const;
        int getAr() const;
        const string& getMegjegyzesek() const;

        void setKamionosFelhasznaloNeve(const string& kamionosFelhasznaloNeve);
        void setFeladoCim(const string& feladoCim);
        void setAruMegnevezes(const string& aruMegnevezes);
        void setMennyiseg(double mennyiseg);
        void setCelCim(const string& celCim);
        void setSzallitasiDatum(const string& szallitasiDatum);
        void setTavolsag(double tavolsag);
        void setPrioritas(int prioritas);
        void setSpecialisIgenyek(const string& specialisIgenyek);
        void setAllapot(const string& allapot);
        void setAtvevesIdeje(const string& atvevesIdeje);
        void setAtvevoTeljesNeve(const string& atvevoTeljesNeve);
        void setAr(int ar);
        void setMegjegyzesek(const string& megjegyzesek);

        void kiir() const;
    private:
        int id;
        string kamionosFelhasznaloNeve;
        string feladoCim;
        string aruMegnevezes;
        double mennyiseg; // kg-ban! > 0
        string celCim;
        string szallitasiDatum; // (eeee.hh.nn)
        double tavolsag; // km-ben! > 0
        int prioritas; // [1-9]
        string specialisIgenyek;
        string allapot;
        string atvevesIdeje;
        string atvevoTeljesNeve;
        int ar; // Ft-ban! >= 1
        string megjegyzesek;
};

#endif // FUVAR_H
