#include "std_lib_facilities.h"
#include "debuggerMain.hpp"

const map<string, string> capitalsMap {
    {"Norway", "Oslo"},
    {"Sweden", "Stockholm"},
    {"Denmark", "Copenhagen"}
};

string getCapital(const string& country) {
    return capitalsMap.at(country);
}

void debuggerMain() {
    cout << "Capitals:\n";
    for (auto& elem : capitalsMap) {
        cout << getCapital(elem.first) << endl;
    }
}