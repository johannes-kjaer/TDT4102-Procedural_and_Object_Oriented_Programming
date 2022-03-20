// Written by Johannes A. Kjær
#include "std_lib_facilities.h"
#include "cannonball.hpp"
#include "utilities.hpp"



void testDeviation(double compareOperand, double toOperand, double maxError, string name);
void testDistanceTraveled(double velocityX, double velocityY);
void testTargetPractice(double distanceToTarget, double velocityX, double velocityY);
void testRWL(int lB, int uB, int n);


int main() {
	srand(unsigned(time(nullptr)));

	// Calling test functions:
	//testDeviation(posX(0.0,50.0,5.0),250.0,0.00001,"posX(0.0,50.0,5.0)");
	//testDistanceTraveled(5,5);
	//testTargetPractice(4.5,5,5);
	//cout << checkIfDistanceToTargetIsCorrect() << "\n";
	//testRWL(5,10, 10);

	playTargetPractice();
}


void testDeviation(double compareOperand, double toOperand, double maxError, string name) {
	if (abs(compareOperand - toOperand) < maxError) {
		cout << "Test passed - Function returned value less than the maximum allowed error.";
	} else {
		cout << "Test failed sucessfuly - Function returned error greater than the maximum allowed error.";
	}
}


void testDistanceTraveled(double velocityX, double velocityY) {
	cout << "The cannonball traveled " << getDistanceTraveled(velocityX,velocityY) << "meters \n";
}

void testTargetPractice(double distanceToTarget, double velocityX, double velocityY) {
	cout << "The shot was off by " << targetPractice(distanceToTarget, velocityX, velocityY) << " meters.\n";
}

void testRWL(int lB, int uB, int n) {
	for (int i = 0; i < n; i++) {
		cout << randomWithlimits(lB,uB) << endl;
	}
}
