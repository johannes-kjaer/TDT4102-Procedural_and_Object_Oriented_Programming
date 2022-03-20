
#include "std_lib_facilities.h"

// Subtask a)
int maxOfTwo(int a, int b) {
    if (a > b) {
        cout << "A is greater than B\n";
        return a;
    } else {
        cout << "B is greater than or equal to A\n";
        return b;
    }
}

// Subtask b)
int main() {
    // Testcode for subtask a)
    cout << "Oppgave a)\n";
    cout << maxOfTwo(5,6) << "\n\n";


    // Testcode for subtask c)
    int fibonacci(int n);
    cout << "Oppgave c)\n" << fibonacci(10) << "\n\n";

    // Testcode for subtask d)
    int squareNumberSum(int n);
    cout << "Oppgave d)\n";
    squareNumberSum(10);
    cout << "\n\n";

    // Testcode for subtask e)
    void triangleNumbersBelow(int n);
    cout << "Oppgave e)\n\n";
    triangleNumbersBelow(30);

    // Testcode for subtask f)
    bool isPrime(int n);
    cout << "Oppgave f)\nTrue=1,False=0: " << isPrime(11) << "\n\n";

    // Testcode for subtask g)
    void naivePrimeNumberSearch(int n);
    cout << "Oppgave g)\n";
    naivePrimeNumberSearch(30);
    cout << "\n";


    // Testcode for subtask h)
    int findGreatestDivisor(int n);
    cout << "Oppgave h)\n" << "The greatest divisor of 24 is " << findGreatestDivisor(24) << "\n";
}

// Subtask c)
int fibonacci(int n) {
    int a = 0;
    int b = 1;
    cout << "Fibonacci numbers:\n";
    for (int i = 1; i <= n; ++i) {
        cout << i << ", " << b << "\n";
        int temp = b;
        b += a;
        a = temp;
    }
    cout << "----\n";
    return b; 
}

// Subtask d)
int squareNumberSum(int n) {
    int totalSum = 0;
    for (int i = 1; i <= n; ++i) {
        totalSum += i*i;
        cout << i*i << "\n";
    }
    cout << "The sum of the square numbers up to " << n << " is: " << totalSum << "\n";
    return totalSum;
}

// Subtask e)
void triangleNumbersBelow(int n) {
    int acc = 1;
    int num = 2;
    cout << "Triangle numbers below " << n << ":\n";
    while (acc < n) {
        cout << acc << "\n";
        acc += num;
        num += 1;
    }
    cout << "\n";
}

// Subtask f)
bool isPrime(int n) {
    for (int j = 2; j < n; ++j) {
        if (n%j == 0) {
            return 0;
        }
    }
    return 1;
}

// Subtask g)
void naivePrimeNumberSearch(int n) {
    for (int number = 2; number <= n; ++number) {
        if (isPrime(number) == 1) {
            cout << number << " is a prime\n";
        }
    }
}

// Subtask h)
int findGreatestDivisor(int n) {
    for (int divisor = n-1; divisor > 0; divisor -= 1) {
        if (n%divisor == 0) {
            return divisor;
        }
    }
    return n;
}
