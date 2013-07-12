#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <string>
using namespace std;


// this function calculates the sum of all prime numbers
// up to the threshold.  This assumes that the threshold
// is greater than 2, since two is the first true prime 
// number. This function is Amortized O(n)
void getPrimes(const long long threshold, vector<long long> &primes);

// this function takes in a vector of integers and returns
// a sum of all of the integers.
// O(n)
long long sum2(vector<long long> &primes);

// this functions prints the primes in format [p1, p2, p3]
void printPrimes(vector<long long> &primes);


typedef struct argumentsStruct {
    bool verbose = false;
    bool showPrimes = false;
    long long threshold;
} argumentsType;

// gets command line arguments
argumentsType getArguments(int argc, char *argv[]);

// checks to see if argument is a number
bool isNumber(const string &s);


int main(int argc, char *argv[]) {
    argumentsType args = getArguments(argc, argv);
    vector<long long> primes;
    long long threshold = args.threshold;
    cout << "the threshold that you have entered is " << args.threshold << endl;
    getPrimes(threshold, primes);
    if (args.showPrimes) {
        printPrimes(primes);
    }
    if (args.verbose) {
        cout << "There are " << primes.size();
        cout << " prime numbers between 2 and " << threshold << endl;
        cout << "The smallest prime between 2 and " << threshold  << " is ";
        cout << primes.front() << endl;
        cout << "The largest prime between 2 and " << threshold << " is ";
        cout << primes.back() << endl;
    }

    cout << "The sum of all the primes less than " << threshold << " is ";
    cout << sum2(primes) << endl;
    return 0;
}

bool isNumber(const string &s)
{
    string::const_iterator it = s.begin();
    while (it != s.end() && isdigit(*it)) {
        ++it;
    } 
    return !s.empty() && it == s.end();
}

argumentsType getArguments(int argc, char *argv[]) {
    argumentsType data;
    if (argc < 2) {
        cerr << "Please enter a threshold argument." << endl;
        exit(1);
    } else if (!isNumber(argv[1])) {
        cerr << "Please enter a valid threshold as an argument" << endl;
        exit(1);
    }
    data.threshold = atol(argv[1]);
    for (int i = 2; i < argc; i++) {
        string arg(argv[i]);
        if (arg.compare("--verbose") == 0 || arg.compare("-v") == 0) {
            data.verbose = true;
        }
        if (arg.compare("--showPrimes") == 0 || arg.compare("-s") == 0) {
            data.showPrimes = true;
        }
        if (arg.compare("--help") == 0 || arg.compare("-h") == 0) {
            cout << "This function takes a mandatory number as an argument ";
            cout << "and returns all of the primes below that threshold added ";
            cout << "together.\n  Specifying --verbose or -v will give more ";
            cout << "information about the primes, such as largest, smallest ";
            cout << "and how many primes.\n Speficifying --showPrimes or -s ";
            cout << "will print an array of all of the prime numbers.\n";
            cout << "Speficify --help or -h for help.\n";
            exit(0);
        }
    }
    return data;
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