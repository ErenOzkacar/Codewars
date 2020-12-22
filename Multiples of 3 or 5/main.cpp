//
//  main.cpp
//  Multiples of 3 or 5
//
//  Created by Eren Özkacar on 22.12.20.
//
//  Challenge: If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23. Finish the solution so that it returns the sum of all the multiples of 3 or 5 below the number passed in.

#include <iostream>
using namespace std;

int sumOfMultiples(int number) {
    if ((number - 1) <= 0) {
        return 0;
    } else {
        if ((number - 1) % 3 == 0 || (number - 1) % 5 == 0) {
            return (number - 1) + sumOfMultiples(number - 1);
        } else {
            return sumOfMultiples(number - 1);
        }
    }
}

int main(int argc, const char * argv[]) {
    cout << sumOfMultiples(0) << '\n';
    cout << sumOfMultiples(10) << '\n';
    cout << sumOfMultiples(50) << '\n';
    return 0;
}
