#include "std_lib_facilities.h"
#include "cannonball.hpp"
#include "utilities.hpp"
#include "cannonball_viz.h"

// 2 //
// a)
double acclY() {
    return -9.81;
}

// b)

double velY(double initVelocityY, double time) {
    return initVelocityY + acclY() * time;
}

// c)
double posY(double initPosition, double initVelocity, double time) {
    return initPosition + initVelocity * time + acclY() * pow(time,2) /2.0;
}

double posX(double initPosition, double initVelocity, double time) {
    return initPosition + initVelocity * time;
}

// d)

void printTime(double time) {
    double decimals = time - static_cast<int>(time);
    int sec = static_cast<int>(time) % 60;
    int min = ((static_cast<int>(time) - sec)/60) % 60;
    int hours = ((static_cast<int>(time) - sec)/60 - min)/60;
    double dsec = sec + decimals;
    cout << hours << " hours, " << min << " minutes and " << dsec << "seconds.\n";
}



// e)
double flightTime(double initVelocityY) {
    return -2*initVelocityY/acclY();
}


// 4a //

// Asks user for an angle
double getUserInputTheta() {
    double theta;
    cout << "Please provide an angle between 0 and 360 deegrees: ";
    cin >> theta;
    return theta;
}

// Asks user for an absolute velocity
double getUserInputAbsVelocity() {
    double vel;
    cout << "Please provide an absolute velocity in meters per second: ";
    cin >> vel;
    return vel;
}

// Converts from deegrees to radians
double degToRad(double deg) {
    return deg*2*M_PI/360.0;
}

// Returns the velocity of the x- or y-component
double getVelocityX(double theta, double absVelocity) {
    return absVelocity*cos(theta);
}
double getVelocityY(double theta, double absVelocity) {
    return absVelocity*sin(theta);
}

// Returns the velocity vector
vector<double> getVelocityVector(double theta, double absVelocity) {
    vector<double> velVect{getVelocityX(theta,absVelocity),getVelocityY(theta,absVelocity)};
    return velVect;
}


double getDistanceTraveled(double velocityX, double velocityY) {
    return posX(0,velocityX,flightTime(velocityY));
}


double targetPractice(double distanceToTarget, double velocityX, double velocityY) {
    return abs(distanceToTarget - getDistanceTraveled(velocityX, velocityY));
}


// 4e)

bool checkIfDistanceToTargetIsCorrect() {
    double error = targetPractice(100,0,0);
    if(error == 0) {return true;} else {return false;}

}

// When calling the function the first time it gives a warning that non-void function does not return a value in all control paths. When calling the function with different parameters (rendering the distance traveled unequal to the distance to the target) it aborts and throws the error "Exception has occurred. - Illegal instruction". This is because the function is only instructed to return something if the statement is true. When it is not, it does not return anything, and consequently it is not possible to use any returned value in the code. Fixed by throwing in an else statement.


// 5d)

// Rewrite of getDistanceTraveled, to get it to use the vector
double travelDistance(vector<double> velocityVector) {
    return posX(0,velocityVector[0],flightTime(velocityVector[1]));
}
// Rewrite of targetPractice, to use the velocity vector
double targetMiss(double distanceToTarget, vector<double> velocityVector) {
    return travelDistance(velocityVector) - distanceToTarget;
}





void playTargetPractice() {
    int targetPosition = randomWithlimits(100,1000);
    for (int i = 0; i < 10; i++) {
        double theta = degToRad(getUserInputTheta());
        double absVel = getUserInputAbsVelocity();
        vector<double> velVect = getVelocityVector(theta, absVel);
        double result = targetMiss(targetPosition,velVect);

        cannonBallViz(targetPosition, 1000, velVect[0], velVect[1],1000);

        cout << "The cannonball flew for ";
        printTime(flightTime(velVect[1]));

        if (abs(result) < 5) {
            cout << "Congratulations, you hit the target and won!\n";
            break;
        } else {
            if (result > 0) {
            cout << "Sorry, you missed the target; The shot was " << abs(result) << " meters too long.\n";
            } else {
                cout << "Sorry, you missed the target; The shot was " << abs(result) << " meters too short.\n";
            }
        }
        cout << "\n";
    }
}


