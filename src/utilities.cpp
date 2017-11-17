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

}
