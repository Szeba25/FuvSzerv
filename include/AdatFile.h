#ifndef ADATFILE_H
#define ADATFILE_H

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

class AdatFile
{
    public:
        AdatFile();
        AdatFile(const string& utvonal);
        virtual ~AdatFile();

        string adatLeker(int sor, int oszlop);
        vector<vector<string>>& osszAdatLeker();
        void ujSor();
        void ujAdat(const string& uj);
        void mentes();
        void mentes(const string& masikUtvonal);
    private:
        vector<string> vag(const string& str, char elvalaszto);
        string utvonal;
        vector<vector<string>> adat;
};

#endif // ADATFILE_H
