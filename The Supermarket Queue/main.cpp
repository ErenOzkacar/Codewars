//
//  main.cpp
//  The Supermarket Queue
//
//  Created by Eren Özkacar on 24.12.20.
//
//  Challenge: There is a queue for the self-checkout tills at the supermarket. Your task is write a function to calculate the total time required for all the customers to check out! Customers: an array of positive integers representing the queue. Each integer represents a customer, and its value is the amount of time they require to check out. n: a positive integer, the number of checkout tills.

#include <iostream>
#include <vector>
using namespace std;

long queueTime(vector<int> customers, int n) {
    vector<int> tillTimes(n);
    int shortestTill {0};
    
    for (int i = 0; i < customers.size(); ++i) {
        for (int j = 0; j < n; ++j) {
            if (tillTimes.at(j) < tillTimes.at(shortestTill)) {
                shortestTill = j;
            }
        }
        tillTimes.at(shortestTill) += customers.at(i);
    }
    return tillTimes.at(shortestTill);
}

int main(int argc, const char * argv[]) {
    cout << queueTime(vector<int> {}, 1) << '\n';
    cout << queueTime(vector<int> {1, 2, 3, 4}, 1) << '\n';
    cout << queueTime(vector<int> {2, 2, 3, 3, 4, 4}, 2) << '\n';
    cout << queueTime(vector<int> {1, 2, 3, 4, 5}, 100) << '\n';
}
