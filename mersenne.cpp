#include <iostream>
#include <cmath>
#include "mersenne.h"

using namespace std;

//********************************************************************************************//
/*  
bool isPrime(int n) {
	if (n < 2) {
		return false;
	}
	
	for (int i = 2; i <= sqrt(n); ++i) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}
*/  //additional function to chech if a number is prime;
static bool isPrime(unsigned long long int n) {
    if (n <= 1) { // not prime
         return false;   
    }            
    if (n <= 3) { // 2 and 3 are prime
        return true; 
    }           
    if (n % 2 == 0 || n % 3 == 0) { // Divisible by 2 or 3
        return false;
    } 

    for (unsigned long long int i = 5; i * i <= n; i += 6) { // vseki prime number > 3 e vinagi pod formata 6k +- 1
        if (n % i == 0 || n % (i + 2) == 0) {
            return false;
        }
    }
    return true; // if no divisors found; togava n = prime number
}
static bool isPerfect(unsigned long long int n) {
    // Extract p from the perfect number formula (2^(p-1)) * ((2^p) - 1)
    for (unsigned long long int p = 2; (1ULL << (p - 1)) * ((1ULL << p) - 1) <= n; ++p) {
        unsigned long long int perfectNumber = (1ULL << (p - 1)) * ((1ULL << p) - 1);
        if (perfectNumber == n) {
            return true; // The number matches the perfect number formula
        }
    }
    return false; // The number is not perfect
}
//********************************************************************************************//

//Function 1
bool isMersenneNumber(unsigned long long int n) {
	if (n <= 0) { // Mersenne numbers must be positive
		return false;
	}

	for (int p = 2; pow(2, p) - 1 <= n; ++p) {
		if (pow(2, p) - 1 == n) {
			return true; // n suvpada s (2^p) - 1, which makes it mersenne number
		}
	}
    return false; // ako nqma suvpadenie ==> not a mersenne number
}

//Function 2
bool isMersenneNumberPrime(unsigned long long int n) {
	if (!isMersenneNumber(n)) {
		return false; // Not a Mersenne number
	}
	return isPrime(n); // proverka dali chisloto e prime
}

//Function 3
unsigned long long int* findDivisors(unsigned long long int n, int& countDivisors) {
    int MAX_SIZE = 10; 
    unsigned long long int* divisors1 = new unsigned long long int[MAX_SIZE];
    countDivisors = 0;

    for (unsigned long long int i = 2; i <= sqrt(n); ++i) {
        if (n % i == 0) { // po-malkiq divisor e i
            if (countDivisors == MAX_SIZE) {
                MAX_SIZE *= 2;
                unsigned long long int* divisors2 = new unsigned long long int[MAX_SIZE]; // temporary array koito kopira segashnite divisori
                for (int j = 0; j < countDivisors; ++j) {
                    divisors2[j] = divisors1[j];
                }
                delete[] divisors1; 
                divisors1 = divisors2;
            }
            divisors1[countDivisors++] = i;

            // po-golemiq divisor e ii
            unsigned long long int ii = n / i;   //nadolu se polzva sushtata logika za noviq temporary array(divisors2)
            if (i != ii) {
                if (countDivisors == MAX_SIZE) {
                    MAX_SIZE *= 2;
                    unsigned long long int* divisors2 = new unsigned long long int[MAX_SIZE];
                    for (int j = 0; j < countDivisors; ++j) {
                        divisors2[j] = divisors1[j];
                    }
                    delete[] divisors1; 
                    divisors1 = divisors2;
                }
                divisors1[countDivisors++] = ii;
            }
        }
    }
    return divisors1;
}
void printDivisors(unsigned long long int* divisors, int countDivisors) {
    if (countDivisors == 0) {
        cout << "No divisors (other than 1 and n)." << endl;
    }
    else {
        cout << "Divisors: ";
        for (int i = 0; i < countDivisors; ++i) {
            cout << divisors[i] << " ";
        }
        cout << endl;
    }
}

// Function 4 
unsigned long long int* findPrimeDivisors(unsigned long long int n, int& countDivisors) {
    if (n <= 1) { 
        countDivisors = 0;
        return nullptr;
    }

    int MAX_SIZE = 10;
    unsigned long long int* primeDivisors1 = new unsigned long long int[MAX_SIZE];
    countDivisors = 0;

    for (unsigned long long int i = 2; i <= sqrt(n); ++i) {
        if (n % i == 0) { // po-malkiq divisor e i
            if (isPrime(i)) {
                if (countDivisors == MAX_SIZE) {
// resizing na masiva kato predishniq max_size se udvoqva i se pravi nov dynamic array koito kopira segashnite divisori
                    MAX_SIZE *= 2;
                    unsigned long long int* primeDivisors2 = new unsigned long long int[MAX_SIZE];
                    for (int j = 0; j < countDivisors; ++j) { 
                        primeDivisors2[j] = primeDivisors1[j];  
                    }
                    delete[] primeDivisors1;
                    primeDivisors1 = primeDivisors2; 
                }
                primeDivisors1[countDivisors++] = i; 
            }

            // po-golemiq delitel e ii
            unsigned long long int ii = n / i;
            if (i != ii && isPrime(ii)) {
                if (countDivisors == MAX_SIZE) {
// resizing na masiva kato predishniq max_size se udvoqva i se pravi nov dynamic array koito kopira segashnite divisori
                    MAX_SIZE *= 2;
                    unsigned long long int* primeDivisors2 = new unsigned long long int[MAX_SIZE];
                    for (int j = 0; j < countDivisors; ++j) {
                        primeDivisors2[j] = primeDivisors1[j];
                    }
                    delete[] primeDivisors1;
                    primeDivisors1 = primeDivisors2;
                }
                primeDivisors1[countDivisors++] = ii;
            }
        }
    }
    return primeDivisors1; 
}
void printPrimeDivisors(unsigned long long int* primeDivisors, int countDivisors) {
    if (countDivisors == 0) {
        cout << "No prime divisors found." << endl;
    }
    else {
        cout << "Prime Divisors: ";
        for (int i = 0; i < countDivisors; ++i) {
            cout << primeDivisors[i] << " ";
        }
        cout << endl;
    }
}

//Function 5                                                                                       // cnt3 e counter za finalniq resultat
int* compositeDivisorsDifferenceOfTwoNumbers(unsigned long long int a, unsigned long long int b, int& cnt3) { // ot sustavnite deliteli na 2 chisla 
    int countA, countB;  //cnt1 e counter za purvoto chislo; cnt2 e counter za vtoroto chislo
    unsigned long long int* divisersA = findDivisors(a, countA);
    unsigned long long int* divisersB = findDivisors(b, countB);

    int MAX_SIZE = 10;
    int* result1 = new int[MAX_SIZE];
    cnt3 = 0;

    for (int i = 0; i < countA; ++i) { // Check if divisorsA[i] is composite and not in divisorsB
        if (!isPrime(divisersA[i])) {
            bool foundB = false; //proverqva dali delitelq go ima v dvata masiva; ako e svalen e samo v 1viq masiv
            for (int j = 0; j < countB; ++j) {
                if (divisersA[i] == divisersB[j]) {
                    foundB = true;
                    break;
                }
            }
            if (!foundB) {
                if (cnt3 == MAX_SIZE) {
                    MAX_SIZE *= 2;
                    int* result2 = new int[MAX_SIZE];
                    for (int k = 0; k < cnt3; ++k) {
                        result2[k] = result1[k];
                    }
                    delete[] result1;
                    result1 = result2; 
                }
                result1[cnt3++] = divisersA[i];
            }
        }
    }

    delete[] divisersA;
    delete[] divisersB;
    return result1;
}

//Function 6
void mersenneNumbersInGivenRange(unsigned long long int lowerLimit, unsigned long long int upperLimit) {
    if (lowerLimit > upperLimit) {
        unsigned long long int tmp = upperLimit;
        upperLimit = lowerLimit;
        lowerLimit = tmp; 
    }

    if (upperLimit > 2305843009213693952) {
        cout << "Error! You exceeded the limits" << endl;
        return;
    }

    if (lowerLimit == 0 && upperLimit == 0) {
        cout << "Error! Limits cannot be zero." << endl;
        return;
    }

    cout << "Mersenne numbers in range [" << lowerLimit << ", " << upperLimit << "]:" << endl;


    bool flag = false;
    for (unsigned long long int p = 2; ; ++p) {
        unsigned long long int number = (1ULL << p) - 1;
        if (number > upperLimit) {
            break;
        }
        if (number >= lowerLimit && isMersenneNumber(number)) {
            cout << number << " ";
            flag = true;
        }
    }

    if (!flag) {
        cout << "No Mersenne numbers in the given range." << endl;
    }
    else {
        cout << endl;
    }
}

//Function 7
void firstNMersenneNumbers(unsigned int n) {
    if (n <= 0) {
        cout << "Invalid input. Please enter a positive integer." << endl;
        return;
    }

    if (n > 50) {
        cout << "Error! Please enter a reasonable number." << endl;
        return;
    }

    cout << "First " << n << " Mersenne numbers:" << endl;

    int count = 0;
    for (unsigned long long int p = 2; count < n; ++p) {
        unsigned long long int number = (1ULL << p) - 1;
        if (isMersenneNumber(number)) {
            cout << number << " ";
            count++;
        }
    }
    cout << endl;
}

//Function 8
void displayFirstNMersennePrimes(unsigned int n) {
    if (n <= 0 && n > 9) {
        cout << "Invalid input." << endl;
        return;
    }

    cout << "First " << n << " Mersenne prime numbers:" << endl;

    int count = 0;
    for (unsigned long long int p = 2; count < n; ++p) {
        unsigned long long int number = (1ULL << p) - 1;
        if (isMersenneNumber(number) && isPrime(number)) {
            cout << number << " ";
            count++;
        }
    }
    cout << endl;
}

//Function 9
unsigned long long int* saveMersennePrimeNumbersInRangeInArray(unsigned long long int lowerLimit, unsigned long long int upperLimit, int& count) {
    count = 0; // kolko mersenovi chisla sme namerili
    int MAX_SIZE = 10;  
    unsigned long long int* array1 = new unsigned long long int[MAX_SIZE]; //masiv zapzvasht mersenovite chisla

    for (unsigned long long int p = 2; ; ++p) {
        unsigned long long int number = (1ULL << p) - 1; // << p == 1 * 2^p
        if (number > upperLimit) {
            break; 
        }
        if (number >= lowerLimit && isMersenneNumber(number) && isPrime(number)) {
            if (count == MAX_SIZE) { 
                MAX_SIZE *= 2;
                unsigned long long int* array2 = new unsigned long long int[MAX_SIZE];
                for (int i = 0; i < count; ++i) {
                    array2[i] = array1[i];
                }
                delete[] array1; 
                array1 = array2;
            }
            array1[count++] = number;
        }
    }
    return array1; // vrushta ni pointer kum originalniq masiv kudeto e zapazen rezultata; 
}

//Function 10
unsigned long long int* savePerfectMersenneNumbersInArray(int n, int& count) {
    if (n <= 0 && n > 9) {
        cout << "Invalid input" << endl;
        return nullptr;
    }

    unsigned long long int* array = new unsigned long long int[n];
    count = 0;

    for (int p = 2; count < n; ++p) {
        if (!isPrime(p)) {
            continue;
        }
        if ((1ULL << p) == 0 || (1ULL << (p - 1)) == 0) {
            break;
        } 
        unsigned long long int mersenneNumber = (1ULL << p) - 1; // (2^p) - 1
        unsigned long long int perfectNumber = (1ULL << (p - 1)) * mersenneNumber; // (2^(p - 1)) * ((2^p) - 1
        if (isMersenneNumber(mersenneNumber) && isPerfect(perfectNumber) && isPrime(mersenneNumber)) {
            array[count++] = perfectNumber;
        }
        
    }
    return array;
}
void printSavePerfectMersenneNumbersInArray(unsigned long long int* n, int count) {
    if (count == 0) {
        cout << "No perfect Mersenne numbers found." << endl;
    }
    else {
        cout << "Perfect Mersenne Numbers: ";
        for (int i = 0; i < count; ++i) {
            cout << n[i] << " ";
        }
    cout << endl;
    }
}