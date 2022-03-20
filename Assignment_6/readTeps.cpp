#include "readTeps.hpp"

istream& operator>>(istream& is, Temps& t) {
    is >> t.min >> t.max;
    return is;
}



