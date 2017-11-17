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
        AdatFile(const string& utvonal);
        virtual ~AdatFile();

        string adatLeker(int sor, int oszlop);
        vector<vector<string>>& osszAdatLeker();
    private:
        vector<string> vag(const string& str, char elvalaszto);
        string utvonal;
        vector<vector<string>> adat;
};

#endif // ADATFILE_H
