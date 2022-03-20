#include "countLetters.hpp"

vector<int> countLetters(string filename) {
    vector<int> frequencies(26);
    fstream evalFile;
    evalFile.open(filename,ios::in);
    if (evalFile.is_open()) {
        string fileContents;

        while (evalFile >> fileContents) {
            for (int i = 0; i < fileContents.length(); i++) {
                frequencies[tolower(fileContents[i])-tolower('a')] += 1; 
            }
        }
    } else {
        cout << "Could not open specified file.\n";
    }
    return frequencies;
}


void printFrequencies(vector<int> freq) {
    vector<string> letters = {
        "a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"
    };
    for (int i = 0; i < freq.size(); i++) {
        cout << letters[i] << ": " << freq[i] << "\n";
    }
}


