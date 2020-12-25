//
//  main.cpp
//  Playing with digits
//
//  Created by Eren Özkacar on 25.12.20.
//
//  Challenge: Some numbers have funny properties. For example: 89 --> 8¹ + 9² = 89 * 1, 695 --> 6² + 9³ + 5⁴= 1390 = 695 * 2, 46288 --> 4³ + 6⁴+ 2⁵ + 8⁶ + 8⁷ = 2360688 = 46288 * 51. Given a positive integer n written as abcd... (a, b, c, d... being digits) and a positive integer p, we want to find a positive integer k, if it exists, such as the sum of the digits of n taken to the successive powers of p is equal to k * n. In other words: Is there an integer k such as : (a ^ p + b ^ (p+1) + c ^(p+2) + d ^ (p+3) + ...) = n * k. If it is the case we will return k, if not return -1.

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int digPow(int n, int p) {
    vector<int> digits;
    int number {n};
    digits.push_back(number % 10);
    number /= 10;
    while (number > 0) {
        digits.insert(digits.begin(), number % 10);
        number /= 10;
    }
    int sumOfDigitsPowN {0};
    for (int i = 0; i < digits.size(); ++i) {
        sumOfDigitsPowN += pow(digits.at(i), p + i);
    }
    int k = sumOfDigitsPowN / n;
    if (k * n == sumOfDigitsPowN) {
        return k;
    }
    return -1;
}

int main(int argc, const char * argv[]) {
    cout << digPow(89, 1) << '\n';
    cout << digPow(695, 2) << '\n';
    cout << digPow(46288, 3) << '\n';
    cout << digPow(23, 1) << '\n';
    return 0;
}
