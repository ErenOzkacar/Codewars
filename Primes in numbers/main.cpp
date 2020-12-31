//
//  main.cpp
//  Primes in numbers
//
//  Created by Eren Özkacar on 31.12.20.
//
//  Challenge: Given a positive number n > 1 find the prime factor decomposition of n. The result will be a string with the following form: "(p1**n1)(p2**n2)...(pk**nk)" where a ** b means a to the power of b with the p(i) in increasing order and n(i) empty if n(i) is 1.

#include <iostream>
#include <string>
#include <vector>
#include <math.h>
using namespace std;

vector<int> primeNumbers {2};

int nextPrime(int n) {
    bool isPrime;
    for (int i = n + 1; ; ++i) {
        int counter {0};
        isPrime = true;
        for (int j = primeNumbers.at(counter); j <= static_cast<int>(sqrt(i)); j = primeNumbers.at(++counter)) {
            if (i % j == 0) {
                isPrime = false;
            }
        }
        if (isPrime == true) {
            primeNumbers.push_back(i);
            return i;
        }
    }
    return 0;
}

string factors(int lst) {
    int n {lst};
    int exponent;
    string primeFactorDecomposition;
    for (int i = 2; i <= n; i = nextPrime(i)) {
        exponent = 0;
        while (n % i == 0) {
            n /= i;
            ++exponent;
        }
        if (exponent == 1) {
            primeFactorDecomposition += '(' + to_string(i) + ')';
        } else if (exponent > 1) {
            primeFactorDecomposition += '(' + to_string(i) + "**" + to_string(exponent) + ')';
        }
    }
    return primeFactorDecomposition;
}

int main(int argc, const char * argv[]) {
    cout << factors(7775460) << '\n';
    cout << factors(7919) << '\n';
    return 0;
}
