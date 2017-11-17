#ifndef FUVAR_H
#define FUVAR_H

#include <iostream>
using namespace std;

class Fuvar
{
    public:
        Fuvar(int id,
              const string& kamionosFelhasznaloNeve,
              const string& honnan,
              const string& aruMegnevezes,
              double mennyiseg,
              const string& cel,
              const string& mikor,
              double tavolsag,
              int prioritas,
              const string& specialisIgenyek,
              const string& megjegyzesek);
        virtual ~Fuvar();

        int getId() const;
        const string& getKamionosFelhasznaloNeve() const;
        const string& getHonnan() const;
        const string& getAruMegnevezes() const;
        double getMennyiseg() const;
        const string& getCel() const;
        const string& getMikor() const;
        double getTavolsag() const;
        int getPrioritas() const;
        const string& getSpecialisIgenyek() const;
        const string& getAllapot() const;
        const string& getAtvevesIdeje() const;
        const string& getAtvevoTeljesNeve() const;
        int getAr() const;
        const string& getMegjegyzesek() const;

        void setKamionosFelhasznaloNeve(const string& kamionosFelhasznaloNeve);
        void setHonnan(const string& honnan);
        void setAruMegnevezes(const string& mit);
        void setMennyiseg(double mennyiseg);
        void setCel(const string& cel);
        void setMikor(const string& mikor);
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
        string honnan;
        string aruMegnevezes;
        double mennyiseg; // kg-ban! > 0
        string cel;
        string mikor;
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
