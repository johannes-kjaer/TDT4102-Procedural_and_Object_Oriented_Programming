#include "std_lib_facilities.h"
#include "utilities.hpp"
#include "tests.hpp"



void testCallByValue() {
    int v0 = 5;
    int increment = 2;
    int iterations = 10;
    int result = incrementByValueNumTimes(v0, increment, iterations);
    cout << "v0: " << v0
        << " increment: " << increment
        << " iterations: " << iterations
        << " result: " << result << endl;
}

void testCallByReference() {
    int v0 = 5;
    int increment = 2;
    int iterations = 10;
    incrementByValueNumTimesRef(v0, increment, iterations);
    cout << "v0: " << v0
        << " increment: " << increment
        << " iterations: " << iterations << endl;
}

void testSwapNumbers(int a, int b) {
    cout << "a: " << a << ", b: " << b << "\n";
    swapNumbers(a,b);
    cout << "a: " << a << ", b: " << b << "\n"; 
}


void testStudentStruct() {
    Student student {"Peter", "Data", 20};
    if (isInProgram(student, "Data")) {
        printStudent(student);
    }
}

void testString() {
    string grades = randomizeString(100,"A","F"); // Gets grades
    cout << grades << "\n"; // Prints grades

    vector<int> gradeCount(0); // Storage for counted grades
    for (int i = 0; i < 6; i++) {
        gradeCount.push_back(countChar(grades,char(int("A"[0])+i))); // Counts grades
    }

    double average = 0;
    vector<double> gradeInts = {5,4,3,2,1,0};
    for (int i = 0; i < 6; i++) {
        average += gradeCount[i]*gradeInts[i]/grades.size();
    }
    cout << "The average grade is: " << average << "\n";
}

void testReadInput() {
    cout << readInputToString(5,"B","F") <<"\n";
}
