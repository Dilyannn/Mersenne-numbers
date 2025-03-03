#ifndef MERSENNE_H    
#define MERSENNE_H  

//F (+ NUMBER) = function (+ number);
bool isMersenneNumber(unsigned long long int); //F1
bool isMersenneNumberPrime(unsigned long long int); //F2
unsigned long long int* findDivisors(unsigned long long int n, int&);//F3
void printDivisors(unsigned long long int*, int);
unsigned long long int* findPrimeDivisors(unsigned long long int, int&); //F4
void printPrimeDivisors(unsigned long long int*, int);
int* compositeDivisorsDifferenceOfTwoNumbers(unsigned long long int, unsigned long long int, int&); //F5
void mersenneNumbersInGivenRange(unsigned long long int, unsigned long long int); //F6
void firstNMersenneNumbers(unsigned int); //F7
void displayFirstNMersennePrimes(unsigned int); //F8
unsigned long long int* saveMersennePrimeNumbersInRangeInArray(unsigned long long int, unsigned long long int, int&); //F9
unsigned long long int* savePerfectMersenneNumbersInArray(int, int&); //F10
void printSavePerfectMersenneNumbersInArray(unsigned long long int*, int);


//functions2 for main.cpp
void testingFunctionIsMersenneNumber(); //1
void testingFunctionIsMersenneNumberPrime(); //2
void testingFunctionFindDivisors(); //3
void testingFunctionFindPrimeDivisors(); //4
void testingFunctionCompositeDivisorsDifferenceOfTwoNumbers(); //5
void testingFunctionMersenneNumbersInGivenRange(); //6
void testingFunctionFirstNMersenneNumbers(); //7
void testingFunctionDisplayFirstNMersennePrimes(); //8
void testingFunctionSaveMersennePrimeNumbersInRangeInArray(); //9
void testingFunctionSavePerfectMersenneNumbersInArray(); //10
#endif //MERSENNE_H 