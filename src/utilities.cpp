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

bool is_hundate(const string& str) {
    return ((str.size() == 10) &&
        (str.at(0) >= '0' && str.at(0) <= '9') &&
        (str.at(1) >= '0' && str.at(1) <= '9') &&
        (str.at(2) >= '0' && str.at(2) <= '9') &&
        (str.at(3) >= '0' && str.at(3) <= '9') &&
        (str.at(4) == '.') &&
        (str.at(5) >= '0' && str.at(5) <= '9') &&
        (str.at(6) >= '0' && str.at(6) <= '9') &&
        (str.at(7) == '.') &&
        (str.at(8) >= '0' && str.at(8) <= '9') &&
        (str.at(9) >= '0' && str.at(9) <= '9'));
}

string getdate() {
    auto now = chrono::system_clock::now();
    time_t now_c = chrono::system_clock::to_time_t(now);
    struct tm* parts = localtime(&now_c);

    int year = 1900 + parts->tm_year;
    int month = 1 + parts->tm_mon;
    int day = parts->tm_mday;

    stringstream ss;
    ss << year << ".";
    if (month < 10)
        ss << "0";
    ss << month << ".";
    if (day < 10)
        ss << "0";
    ss << day;

    return ss.str();
}

}
