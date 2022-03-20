#pragma once
#include "std_lib_facilities.h"

int incrementByValueNumTimes(int startValue, int increment, int numTimes);

void incrementByValueNumTimesRef(int& startValue, int increment, int numTimes);

void swapNumbers(int& a, int& b);

struct Student{
    string name;
    string studyProgram;
    int age;
};

void printStudent(Student student);

bool isInProgram(Student student, string program);

string randomizeString(int n, string iC, string fC);

string readInputToString(int n, string lC, string uC);

int countChar(string countThis, char Chimchar);
