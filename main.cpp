#include<iostream>
#include <cmath>
#include "mersenne.h"

using namespace std;

int main() {
    int number;
    do {
        cout << "Enter a number from 1 to 10: " << endl;
        cout << "(Enter 0 to terminate the program) " << endl;
        cin >> number;

        switch (number) {
        case 1:
            cout << "1. A function that checks whether a number is a Mersenne number. " << endl;
            testingFunctionIsMersenneNumber(); break;
        case 2:
            cout << "2. A function that checks whether a Mersenne number is prime. " << endl;
            testingFunctionIsMersenneNumberPrime(); break;
        case 3:
            cout << "3. A function that shows all divisors of a given number except 1 and the number itself. " << endl;
            testingFunctionFindDivisors(); break;
        case 4:
            cout << "4. A function that stores in an array all the prime divisors of a number. " << endl; 
            testingFunctionFindPrimeDivisors(); break;
        case 5:
            cout << "5. A function that stores in an array the difference of the sets of composite divisors of two numbers. " << endl; 
            testingFunctionCompositeDivisorsDifferenceOfTwoNumbers(); break;
        case 6:
            cout << "6. A function that shows all Mersenne numbers in a given range. " << endl; 
            testingFunctionMersenneNumbersInGivenRange(); break;
        case 7:
            cout << "7. A function that shows the first n Mersenne numbers. " << endl;
            testingFunctionFirstNMersenneNumbers(); break;
        case 8:
            cout << "8. A function that shows the first n Mersenne prime numbers. " << endl;
            testingFunctionDisplayFirstNMersennePrimes(); break;
        case 9:
            cout << "9. A function that stores in an array all found Mersenne prime numbers in a given range. " << endl;
            testingFunctionSaveMersennePrimeNumbersInRangeInArray(); break; 
        case 10:
            cout << "10. A function that stores in an array the first n Mersenne numbers that are perfect. " << endl; 
            testingFunctionSavePerfectMersenneNumbersInArray(); break;
        case 0:
            cout << "Terminating the program..." << endl;
            break;
        default:
            cout << "Invalid number. Try again." << endl;
        }
    } while (number != 0);

    return 0;
}