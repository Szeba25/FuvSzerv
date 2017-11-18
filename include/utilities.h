#ifndef UTILITIES_H
#define UTILITIES_H

#include <iostream>
#include <sstream>
using namespace std;

namespace utils {

string to_string(int i);
string to_string(double d);
double to_double(const string& str);
double getdouble();
int to_int(const string& str);
int getint();
bool is_hundate(const string& str);

}

#endif // UTILITIES_H
