#include "std_lib_facilities.h"
#include "utilities.hpp"


// Problem 1b)

int incrementByValueNumTimes(int startValue, int increment, int numTimes) {
    for (int i = 0; i < numTimes; i++) {
        startValue += increment;
    }
    return startValue;
}



void incrementByValueNumTimesRef(int& startValue, int increment, int numTimes) {
    for (int i = 0; i < numTimes; i++) {
        startValue += increment;
    }
}

void swapNumbers(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}
// Funksjonen bør bruke referanser, da den skal bytte om på variablenes verdi, og ikke gi to nye variabler med verdiene de gitte variablene hadde

// 2a)



// 2b)

void printStudent(Student student) {
    cout << "Name of student: " << student.name << "\nThe students program of study: " << student.studyProgram << "\nThe age of the student: " << student.age << "\n";
}

// 2c)

bool isInProgram(Student student, string program) {
    if (student.studyProgram == program) {
        return true;
    } else {
        return false;
    }
}

string randomizeString(int n, string iC, string fC) {
    string randstring = "";
    int range = (int)(fC[0]) - (int)(iC[0]) +1;
    for (int i = 0; i < n; i++) {
        int randint = rand()%(range) + (int)(iC[0]);
        randstring = randstring + (char)(randint);
    }
    return randstring;
}



string readInputToString(int n, string lC, string uC) {
    string usrinput;
    string testinput;
    while (true) {
        cout << "Please provide a string of length " << n << " containing only characters in the interval " << lC << " to " << uC << "\n";
        cin >> usrinput;
        testinput = usrinput;

        for (int i = 0; i < usrinput.length(); i++) {
            if (testinput[i] >= int("a"[0])) {
                testinput[i] = char(testinput[i] - 32);
            }
        }

        if (usrinput.length() == n) {
            int n_valid_chars = 0;
            for (int i = 0; i < usrinput.length(); i++) {
                if (int(testinput[i]) < int(lC[0]) or int(testinput[i]) > int(uC[0])) {
                    break;
                } else {
                    n_valid_chars += 1;
                }
            }
            if (n_valid_chars == usrinput.length()) {
                return usrinput;
            }
        }
        cout << "Requirements were not met.\n";
    }
    return "Task failed sucessfully.";
}

int countChar(string countThis, char Chimchar) {
    int count = 0;
    for (int i = 0; i < countThis.length(); i++) {
        if (countThis[i] == Chimchar) {
            count += 1;
        }
    }
    return count;
}

