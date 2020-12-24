//
//  main.cpp
//  Unique In Order
//
//  Created by Eren Özkacar on 23.12.20.
//
//  Challenge: Implement the function unique_in_order which takes as argument a sequence and returns a list of items without any elements with the same value next to each other and preserving the original order of elements.

#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<char> unique_in_order(const string &iterable) {
    vector<char> uniqueInOrder;
    unsigned int counter {0};
    
    while (counter < iterable.length()) {
        uniqueInOrder.push_back(iterable.at(counter));
        ++counter;
        while (counter < iterable.length() && iterable.at(counter - 1) == iterable.at(counter)) {
            ++counter;
        }
    }
    return uniqueInOrder;
}

int main(int argc, const char * argv[]) {
    vector<char> uniqueInOrder;
    uniqueInOrder = unique_in_order("AABCC");
    for (int i = 0; i < uniqueInOrder.size(); ++i) {
        cout << uniqueInOrder[i];
    }
    return 0;
}
