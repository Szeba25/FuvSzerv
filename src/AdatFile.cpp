#include "AdatFile.h"

AdatFile::AdatFile(const string& utvonal) :
    utvonal(utvonal)
{
    ifstream input;
    input.open(utvonal.c_str());
    string sor;
    while (getline(input, sor)) {
        adat.push_back(vag(sor, '\t'));
    }
}

AdatFile::~AdatFile()
{

}
vector<string> AdatFile::vag(const string& str, char elvalaszto)
{
    vector<string> sor;
    stringstream ss;
    ss.str(str);
    string obj;
    while (getline(ss, obj, elvalaszto)) {
        sor.push_back(obj);
    }
    return sor;
}

string AdatFile::adatLeker(int sor, int oszlop)
{
    return adat[sor][oszlop];
}

vector<vector<string>>& AdatFile::osszAdatLeker()
{
    return adat;
}
