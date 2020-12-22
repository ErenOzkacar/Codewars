//
//  main.cpp
//  A square of squares
//
//  Created by Eren Özkacar on 22.12.20.
//
//  Challenge: Given an integral number, determine if it's a square number.

#include <iostream>
using namespace std;

bool isSquare(int n) {
    int firstDigit = n % 10;
    if (firstDigit == 0 || firstDigit == 1 || firstDigit == 4 || firstDigit == 5 || firstDigit == 6 || firstDigit == 9) {
        for (int i = 0; i <= n / 2; ++i) {
            if (i * i == n) {
                return true;
            }
        }
    }
    return false;
}

int main(int argc, const char * argv[]) {
    cout << isSquare(0) << '\n';
    cout << isSquare(3) << '\n';
    cout << isSquare(1000000) << '\n';
    return 0;
}
