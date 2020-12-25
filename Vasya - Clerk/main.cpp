//
//  main.cpp
//  Vasya - Clerk
//
//  Created by Eren Özkacar on 25.12.20.
//
//  Challenge: The new "Avengers" movie has just been released! There are a lot of people at the cinema box office standing in a huge line. Each of them has a single 100, 50 or 25 dollar bill. An "Avengers" ticket costs 25 dollars. Vasya is currently working as a clerk. He wants to sell a ticket to every single person in this line. Can Vasya sell a ticket to every person and give change if he initially has no money and sells the tickets strictly in the order people queue? Return YES, if Vasya can sell a ticket to every person and give change with the bills he has at hand at that moment. Otherwise return NO.

#include <iostream>
#include <string>
#include <vector>
using namespace std;

string tickets(vector<int> &peopleInLine) {
    vector<int> availableBills;
    for (int i = 0; i < peopleInLine.size(); ++i) {
        switch (peopleInLine.at(i)) {
            case 25:
                availableBills.push_back(25);
                break;
            case 50: {
                int position25 {-1};
                for (int j = 0; j < availableBills.size(); ++j) {
                    if (availableBills.at(j) == 25) {
                        ++position25;
                        availableBills.at(j) = 50;
                        break;
                    }
                }
                if (position25 == -1) {
                    return "NO";
                }
                break;
            }
            case 100: {
                vector<int> positions25;
                int position50 {-1};
                for (int j = 0; j < availableBills.size(); ++j) {
                    if (availableBills.at(j) == 25 && positions25.size() < 3) {
                        positions25.push_back(j);
                    }
                    if (availableBills.at(j) == 50 && position50 == -1) {
                        position50 = j;
                    }
                }
                if (position50 != -1 && positions25.size() > 0) {
                    if (positions25.at(0) <= position50) {
                        availableBills.at(positions25.at(0)) = 100;
                        availableBills.erase(availableBills.begin() + position50);
                    } else {
                        availableBills.at(position50) = 100;
                        availableBills.erase(availableBills.begin() + positions25.at(0));
                    }
                } else if (positions25.size() == 3) {
                    availableBills.at(positions25.at(0)) = 100;
                    availableBills.erase(availableBills.begin() + positions25.at(1));
                    availableBills.erase(availableBills.begin() + positions25.at(2));
                } else {
                    return "NO";
                }
                break;
            }
            default:
                break;
        }
    }
    return "YES";
}

int main(int argc, const char * argv[]) {
    vector<int> line {25, 25, 50};
    cout << tickets(line) << '\n';
    line = {25, 100};
    cout << tickets(line) << '\n';
    line = {25, 25, 50, 50, 25};
    cout << tickets(line) << '\n';
    return 0;
}
