#ifndef FUVAR_H
#define FUVAR_H

#include <iostream>
using namespace std;

class Fuvar
{
    public:
        Fuvar(const string& kamionosFelhasznaloNeve,
              const string& honnan,
              const string& mit,
              double mennyit,
              const string& hova,
              const string& mikor,
              int tavolsag,
              int prioritas,
              const string& specialisIgenyek,
              const string& megjegyzesek);
        virtual ~Fuvar();

        const string& getKamionosFelhasznaloNeve() const;
        const string& getHonnan() const;
        // TODO
    private:
        int id;
        string kamionosFelhasznaloNeve;
        string honnan;
        string mit;
        double mennyit; // kg-ban!
        string hova;
        string mikor;
        int tavolsag; // km-ben!
        int prioritas; // 0-9
        string specialisIgenyek;
        string allapot;
        string atvevesIdeje;
        string atvevoTeljesNeve;
        int fuvarAra; // Ft-ban!
        string megjegyzesek;
};

#endif // FUVAR_H
