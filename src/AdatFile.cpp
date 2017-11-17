#include "AdatFile.h"

AdatFile::AdatFile() :
    utvonal("")
{

}

AdatFile::AdatFile(const string& utvonal) :
    utvonal(utvonal)
{
    ifstream input;
    input.open(utvonal.c_str());
    string sor;
    while (getline(input, sor)) {
        adat.push_back(vag(sor, '\t'));
    }
    input.close();
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

void AdatFile::ujSor()
{
    adat.push_back(vector<string>());
}

void AdatFile::ujAdat(const string& uj)
{
    adat.back().push_back(uj);
}

void AdatFile::mentes()
{
    if (utvonal != "") {
        mentes(utvonal);
    }
}

void AdatFile::mentes(const string& masikUtvonal)
{
    ofstream output(masikUtvonal.c_str());
    for (auto& val : adat) {
        int i = 0;
        for (auto& str : val) {
            if (str == "")
                output << "null";
            else
                output << str;
            if (i != val.size()-1)
                output << "\t";
            i++;
        }
        output << "\n";
    }
    output.close();
}
