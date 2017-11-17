#include "Utilities.h"

namespace utils {

string to_string(int i) {
    stringstream ss;
    ss << i;
    return ss.str();
}

}
