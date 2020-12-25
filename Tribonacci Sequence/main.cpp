//
//  main.cpp
//  Tribonacci Sequence
//
//  Created by Eren Özkacar on 25.12.20.
//
//  Challenge: Well met with Fibonacci bigger brother, AKA Tribonacci. As the name may already reveal, it works basically like a Fibonacci, but summing the last 3 (instead of 2) numbers of the sequence to generate the next.

#include <iostream>
#include <vector>
using namespace std;

vector<int> tribonacci(vector<int> signature, int n) {
    vector<int> sequence;
    for (unsigned long i = 0; i < signature.size() && i < n; ++i) {
        sequence.push_back(signature.at(i));
    }
    for (unsigned long i = signature.size(); i < n; ++i) {
        sequence.push_back(sequence.at(i - 3) + sequence.at(i - 2) + sequence.at(i - 1));
    }
    return sequence;
}

int main(int argc, const char * argv[]) {
    vector<int> signature {1, 1, 1};
    int n {20};
    vector<int> sequence = tribonacci(signature, n);
    for (int i = 0; i < n - 1; ++i) {
        cout << sequence.at(i) << ", ";
    }
    cout << sequence.at(n - 1) << '\n';
    return 0;
}
