//
//  main.cpp
//  Double Cola
//
//  Created by Eren Özkacar on 24.12.20.
//
// Challenge: Sheldon, Leonard, Penny, Rajesh and Howard are in the queue for a "Double Cola" drink vending machine; there are no other people in the queue. The first one in the queue (Sheldon) buys a can, drinks it and doubles! The resulting two Sheldons go to the end of the queue. Then the next in the queue (Leonard) buys a can, drinks it and gets to the end of the queue as two Leonards, and so on. Write a program that will return the name of the person who will drink the n-th cola.

#include <iostream>
#include <string>
#include <vector>
using namespace std;

string who_is_next(vector<string> &names, long long int n) {
    vector<string> newQueue {names};
    while (newQueue.size() < n) {
        newQueue.push_back(newQueue.at(0));
        newQueue.push_back(newQueue.at(0));
        newQueue.erase(newQueue.begin());
    }
    return newQueue.at(n - 1);
}

int main(int argc, const char * argv[]) {
    vector<string> queue {"Sheldon", "Leonard", "Penny", "Rajesh", "Howard"};
    cout << who_is_next(queue, 1) << '\n';
    cout << who_is_next(queue, 52) << '\n';
    cout << who_is_next(queue, 10010) << '\n';
    return 0;
}
