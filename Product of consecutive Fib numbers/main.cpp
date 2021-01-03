//
//  main.cpp
//  Product of consecutive Fib numbers
//
//  Created by Eren Özkacar on 03.01.21.
//
//  Challenge: The Fibonacci numbers are the numbers in the following integer sequence (Fn): 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, ... such as F(n) = F(n-1) + F(n-2) with F(0) = 0 and F(1) = 1. Given a number, say prod (for product), we search two Fibonacci numbers F(n) and F(n+1) verifying F(n) * F(n+1) = prod. Your function productFib takes an integer (prod) and returns an array: [F(n), F(n+1), true] or {F(n), F(n+1), 1} or (F(n), F(n+1), True) depending on the language if F(n) * F(n+1) = prod. If you don't find two consecutive F(m) verifying F(m) * F(m+1) = prodyou will return [F(m), F(m+1), false] or {F(n), F(n+1), 0} or (F(n), F(n+1), False) F(m) being the smallest one such as F(m) * F(m+1) > prod.

#include <iostream>
#include <vector>
using namespace std;

vector<int> productFib(unsigned long prod) {
    vector<int> output {1, 1, 2};
    while (output.at(0) * output.at(1) < prod) {
        output.at(0) = output.at(1);
        output.at(1) = output.at(2);
        output.at(2) = output.at(0) + output.at(1);
    }
    if (output.at(0) * output.at(1) == prod) {
        output.at(2) = 1;
    } else {
        output.at(2) = 0;
    }
    return output;
}

int main(int argc, const char * argv[]) {
    vector<int> factors {productFib(84049690)};
    for (auto f : factors) {
        cout << f << " ";
    }
    return 0;
}
