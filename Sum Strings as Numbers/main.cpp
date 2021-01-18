//
//  main.cpp
//  Sum Strings as Numbers
//
//  Created by Eren Özkacar on 18.01.21.
//
//  Challenge: Given the string representations of two integers, return the string representation of the sum of those integers.

#include <iostream>
#include <string>
using namespace std;

int exponent(long a, unsigned long b) {
    int c {1};
    for (unsigned int i = 1; i <= b; ++i) {
        c *= a;
    }
    return c;
}

string sum_strings(const string& a, const string& b) {
    int aInt {0};
    for (unsigned int i = 1; i <= a.size(); ++i) {
        aInt += exponent(10, a.size() - i) * (a.at(i - 1) - '0');
    }
    int bInt {0};
    for (unsigned int i = 1; i <= b.size(); ++i) {
        bInt += exponent(10, b.size() - i) * (b.at(i - 1) - '0');
    }
    int cInt = aInt + bInt;
    string c = to_string(cInt);
    return c;
}

int main(int argc, const char * argv[]) {
    string a {"123"}, b {"456"};
    string c = sum_strings(a, b);
    cout << c << '\n';
    return 0;
}
