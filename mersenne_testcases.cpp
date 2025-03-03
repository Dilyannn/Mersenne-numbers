#include<iostream>
#include <cmath>
#include "mersenne.h"

using namespace std;

void testingFunctionIsMersenneNumber() {
    unsigned long long int number;

    cout << "Enter a number to check if it's a Mersenne number: ";
    cin >> number;

    if (isMersenneNumber(number)) {
        cout << number << " is a Mersenne number." << endl;
    }
    else {
        cout << number << " is not a Mersenne number." << endl;
    }
} //1
void testingFunctionIsMersenneNumberPrime() {
    unsigned long long int number;

    cout << "Enter a number to check if it's a Mersenne prime number: ";
    cin >> number;

    if (isMersenneNumberPrime(number)) {
        cout << number << " is a Mersenne prime number." << endl;
    }
    else {
        cout << number << " is not a Mersenne prime number." << endl;
    }
} //2
void testingFunctionFindDivisors() {
    unsigned long long int number;
    int countDivisors;

    cout << "Enter a number to find its divisors: ";
    cin >> number;

    unsigned long long int* divisors = findDivisors(number, countDivisors);

    printDivisors(divisors, countDivisors);

    delete[] divisors;
} //3
void testingFunctionFindPrimeDivisors() {
    unsigned long long int number;
    int countDivisors;

    cout << "Enter a number to find its prime divisors: ";
    cin >> number;

    unsigned long long int* primeDivisors = findPrimeDivisors(number, countDivisors);

    printPrimeDivisors(primeDivisors, countDivisors);

    delete[] primeDivisors;
} //4
void testingFunctionCompositeDivisorsDifferenceOfTwoNumbers() {
    unsigned long long int number1, number2;
    int count;

    cout << "Enter the first number: ";
    cin >> number1;

    cout << "Enter the second number: ";
    cin >> number2;

    int* arr = compositeDivisorsDifferenceOfTwoNumbers(number1, number2, count);

    if (count == 0) {
        cout << "No different composite divisors found." << endl;
    }
    else {
        cout << "Here are the different composite divisors: ";
        for (int i = 0; i < count; ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    delete[] arr;
}
void testingFunctionMersenneNumbersInGivenRange() {
    unsigned long long int lowerLimit = 0, upperLimit = 0;
    
    cin.ignore();
    cout << "Enter the lower limit: ";
    cin >> lowerLimit;

    cout << "Enter the upper limit: ";
    cin >> upperLimit;

    mersenneNumbersInGivenRange(lowerLimit, upperLimit); 
}
void testingFunctionFirstNMersenneNumbers() {
    unsigned int n;

    cout << "Enter the number of Mersenne numbers you want to see: ";
    cin >> n;

    firstNMersenneNumbers(n);
}
void testingFunctionDisplayFirstNMersennePrimes() {
    unsigned int n;

    cout << "Enter the number of Mersenne prime numbers you want to see: ";
    cin >> n;

    displayFirstNMersennePrimes(n); 
}
void testingFunctionSaveMersennePrimeNumbersInRangeInArray() {
    unsigned long long int lowerLimit, upperLimit;
    int count;

    cout << "Enter the lower limit: ";
    cin >> lowerLimit;
    cout << "Enter the upper limit: ";
    cin >> upperLimit;

    unsigned long long int* arr = saveMersennePrimeNumbersInRangeInArray(lowerLimit, upperLimit, count); 

    if (count == 0) {
        cout << "No Mersenne prime numbers are found in the range [" << lowerLimit << ", " << upperLimit << "]." << endl;
    }
    else {
        cout << "Mersenne prime numbers in the range [" << lowerLimit << ", " << upperLimit << "] are: " << endl;
        for (int i = 0; i < count; ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    delete[] arr;
}
void testingFunctionSavePerfectMersenneNumbersInArray() {
        int n, count;

        cout << "Enter a number: ";
        cin >> n;

        unsigned long long int* perfectNumbers = savePerfectMersenneNumbersInArray(n, count); 

        if (perfectNumbers != nullptr) {
            printSavePerfectMersenneNumbersInArray(perfectNumbers, count);
            delete[] perfectNumbers;
        }
        else {
            cout << "No valid output (either invalid or no result found)!" << endl; // (either invalid input or there are not any perfect Mersenne numbers that are found)
        }
}