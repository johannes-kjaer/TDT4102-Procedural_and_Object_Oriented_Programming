#include "std_lib_facilities.h"
#include "utilities.hpp"
#include "tests.hpp"
#include "mastermind.hpp"


// Problem 1a)
// v0 = 5

// Problem 2e)
// Include copies and pastes the file specified, so when the main file includes utilities and test - which again includes utilities - the utilities file is included doubly, and Student is defined twice

int main() {
	srand(unsigned(time(nullptr)));
	//testCallByValue();
	//testCallByReference();
	//testSwapNumbers(10,12);
	//testStudentStruct();
	//testString();
	//testReadInput();
	//cout << countChar("The big, white buffoon stumbles into and down the elevator shaft at a riveting speed.","e"[0]) << "\n";
	playMastermind();
}










