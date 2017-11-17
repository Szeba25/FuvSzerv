#include "Utilities.h"

namespace utils {

string to_string(int i) {
    stringstream ss;
    ss << i;
    return ss.str();
}

string to_string(double d) {
    stringstream ss;
    ss << d;
    return ss.str();
}

double to_double(const string& str) {
    stringstream ss;
    ss << str;
    double d;
    ss >> d;
    return d;
}

double getdouble() {
    string str;
    getline(cin, str);
    double d = -1;
    if (str != "") {
        d = to_double(str);
    }
    return d;
}

int to_int(const string& str) {
    stringstream ss;
    ss << str;
    int i;
    ss >> i;
    return i;
}

int getint() {
    string str;
    getline(cin, str);
    int i = -1;
    if (str != "") {
        i = to_int(str);
    }
    return i;
}

}
