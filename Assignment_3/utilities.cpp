#include "std_lib_facilities.h"
#include "utilities.hpp"


int psrand() {
    return rand();
}

int randomWithlimits(int lowerBound, int upperBound) {
    return (rand() % (upperBound - lowerBound +1 )) + lowerBound;
}









