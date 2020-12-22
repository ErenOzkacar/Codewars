//
//  main.cpp
//  Bit Counting
//
//  Created by Eren Özkacar on 22.12.20.
//
//  Challenge: Write a function that takes an integer as input, and returns the number of bits that are equal to one in the binary representation of that number. You can guarantee that input is non-negative.

#include <iostream>
using namespace std;

unsigned int bitCounter(unsigned int decimal) {
    unsigned int ones {0};
    unsigned int rest = decimal;
    
    while (rest != 0) {
        ones += rest % 2;
        rest /= 2;
    }
    return ones;
}

int main(int argc, const char * argv[]) {
    cout << bitCounter(0) << '\n';
    cout << bitCounter(10) << '\n';
    cout << bitCounter(300) << '\n';
    return 0;
}
