#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
using namespace std;

#define kPrintPrimes 0

// this function calculates the sum of all prime numbers
// up to the threshold.  This assumes that the threshold
// is greater than 2, since two is the first true prime 
// number. This function is Amortized O(n)
void getPrimes(long long threshold, vector<long long> &primes);

// this function takes in a vector of integers and returns
// a sum of all of the integers.
// O(n)
long long sum2(vector<long long> &primes);

// this functions prints the primes in format [p1, p2, p3]
void printPrimes(vector<long long> &primes);


int main(void) {
    long long threshold = 2000000;
    vector<long long> primes;
    getPrimes(threshold, primes);
    if (kPrintPrimes) {
        printPrimes(primes);
    }
    cout << "There are " << primes.size();
    cout << " prime numbers between 2 and " << threshold << endl;
    cout << "The smallest prime between 2 and " << threshold  << " is ";
    cout << primes.front() << endl;
    cout << "The largest prime between 2 and " << threshold << " is ";
    cout << primes.back() << endl;
    cout << "The sum of all the primes less than 2,000,000 is ";
    cout << sum2(primes) << endl;
    return 0;
}

void printPrimes(vector<long long> &primes) {
    cout << "[" << primes.front();
    for (int i = 1; i < primes.size(); ++i) {
        cout << ", " << primes.at(i);
    }
    cout << "]" << endl;
}

long long sum2(vector<long long> &primes) {
    long long total = 0;
    for (int i = 0; i < primes.size(); ++i) {
        total += primes.at(i);
    }
    return total;
}

// the sum of all primes is 142,913,828,922.
void getPrimes(long long threshold, vector<long long> &primes) {
    // it is known that prime numbers are divisible only by 1 and themselve
    // it is known that the nuber any number that will make a number 'not prime'
    // must be smaller than sqrt(number)
    primes.push_back(2); // this is the smallest prime number
    for (int i = 3; i < threshold; i+=2) {
        bool isPrime = true;
        for (int j = 2; j < sqrt(i) + 1; ++j) {
            if (i % j == 0) {
                isPrime = false;
                break;
            }
        }
        if (isPrime) {
            primes.push_back(i);
        }
    }
}