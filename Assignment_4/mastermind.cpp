#include "std_lib_facilities.h"
#include "utilities.hpp"
#include "mastermind.hpp"
#include "masterVisual.h"

// 4a)
bool playMastermind() {
    constexpr int size = 4;
    constexpr int letters = 6;
    constexpr int number_of_guesses = 7;

    
    string uC = string(1,char(int("A"[0])+letters-1));
    string code = randomizeString(size,"A",uC);
    //cout << "Code: " << code << "\n\n"; // Print of the code, for debug purposes only


    //MastermindWindow mwin{900, 20, winW, winH, size, "Mastermind"};


    int guess_count = 0;
    int guess_quality = 0;
    while (guess_quality != size and guess_count < number_of_guesses) {
        string guess = readInputToString(size,"A",uC);
        //string guess = mwin.getInput(size,"A"[0],"F"[0]);
        guess_count += 1;

        // The following code converts any uncapitalized letters to capitalized ones, so as to make sure the code following does not have to have excessive exception handling of uncapitalized letters
        string testguess = guess;
        for (int i = 0; i < guess.length(); i++) {
            if (testguess[i] >= int("a"[0])) {
                testguess[i] = char(testguess[i] - 32);
            }
        }

        guess_quality = checkPositions(code, testguess);
        if (guess_quality < size) {
            cout << "You guessed " << checkCharacters(code, testguess) << " correct characters, of which " << guess_quality << " were correctly placed." << "\n\n";
        } else {
            cout << "Congratulations, you won!\n";
            return true;
        }
    }
    cout << "Sorry, you lost. The correct solution was: " << code << "\n";
    return false;
}

int checkCharacters(string code, string guess) {
    int count = 0;
    for (int i = 0; i < code.length(); i++) {
        for (int j = 0; j < guess.length(); j++) {
            if (code[i] == guess[j]) {
                count += 1;
                guess[j] = "-"[0]; // Removes the correct guess, so as to make sure the guess won't be doublecounted
                j = guess.length(); // Stops the for loop from iterating further
            }
        }
    }
    return count;
}

int checkPositions(string code,string guess) {
    int count = 0;
    for (int i = 0; i < guess.length(); i++) {
        if (code[i] == guess[i]) {
            count += 1;
        }
    }
    return count;
}

