# pragma once

// 1 //
// a)
double acclY();

// b)
double velY(double initVelocityY, double time);

// c)
double posX(double initPosition, double initVelocity, double time);

double posY(double initPosition, double initVelocity, double time);

// d)

void printTime(double time);

// e)
double flightTime(double initVelocityY);

// 4a //

// Asks user for an angle
double getUserInputTheta();

// Asks user for an absolute velocity
double getUserInputAbsVelocity();

// Converts from deegrees to radians
double degToRad(double deg);

// Returns the velocity of the x- or y-component
double getVelocityX(double theta, double absVelocity);
double getVelocityY(double theta, double absVelocity);

// Returns the velocity vector
vector<double> getVelocityVector(double theta, double absVelocity);

// 4b)

double getDistanceTraveled(double velocityX, double velocityY);


// 4c) 
double targetPractice(double distanceToTarget, double velocityX, double velocityY);


// 4e)

bool checkIfDistanceToTargetIsCorrect();

// 5d)

// Rewrite of getDistanceTraveled and targetPractice, see cannonball.cpp
double travelDistance(vector<double> velocityVector);
double targetMiss(double distanceToTarget, vector<double> velocityVector);

void playTargetPractice();

