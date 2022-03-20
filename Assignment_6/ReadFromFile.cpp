
#include "ReadFromFile.hpp"

void saveToFile(string filename) {
    fstream SomeFile;
    SomeFile.open(filename,ios::app);
    string usrStr = "---";
    while (usrStr != "quit") {
        cout << "Give a word to save: ";
        cin >> usrStr;
        if (usrStr != "quit") {
            SomeFile << usrStr << "\n";
            cout << "\n";
        }
    }
    SomeFile.close();
}

void includeLineNumbers(string file) {
    fstream orgFile;
    orgFile.open(file,ios::in);
    if (orgFile.is_open()) {
        fstream newFile;
        newFile.open("new_"+file,ios::out);
        if (newFile.is_open()) {
            string line;
            int lineNumber = 0;
            while (getline(orgFile,line)) {
                lineNumber +=1;
                newFile << lineNumber << " " << line << "\n";
            }
            newFile.close();
            orgFile.close();
        } else {
            cout << "Was not able to open/create new file.\n";
        }
    } else {
        cout << "Was not able to open file.\n";
    }
}










