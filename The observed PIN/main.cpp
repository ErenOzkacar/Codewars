//
//  main.cpp
//  The observed PIN
//
//  Created by Eren Özkacar on 18.01.21.
//
//  Challenge: Alright, detective, one of our colleagues successfully observed our target person, Robby the robber. We followed him to a secret warehouse, where we assume to find all the stolen stuff. The door to this warehouse is secured by an electronic combination lock. Unfortunately our spy isn't sure about the PIN he saw, when Robby entered it. He noted the PIN 1357, but he also said, it is possible that each of the digits he saw could actually be another adjacent digit (horizontally or vertically, but not diagonally). E.g. instead of the 1 it could also be the 2 or 4. And instead of the 5 it could also be the 2, 4, 6 or 8. He also mentioned, he knows this kind of locks. You can enter an unlimited amount of wrong PINs, they never finally lock the system or sound the alarm. That's why we can try out all possible (*) variations. * possible in sense of: the observed PIN itself and all variations considering the adjacent digits. Can you help us to find all those variations? It would be nice to have a function, that returns an array (or a list in Java and C#) of all variations for an observed PIN with a length of 1 to 8 digits. We could name the function getPINs (get_pins in python, GetPINs in C#). But please note that all PINs, the observed one and also the results, must be strings, because of potentially leading '0's. We already prepared some test cases for you. Detective, we are counting on you!

#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> get_pins(string observed) {
    vector<vector<char>> adjacentNumbers(observed.size(), vector<char>());
    unsigned long i, j, k, l;
    for (i = 0; i < observed.size(); ++i) {
        switch (observed.at(i)) {
            case '1':
                adjacentNumbers[i].push_back('1');
                adjacentNumbers[i].push_back('2');
                adjacentNumbers[i].push_back('4');
                break;
            case '2':
                adjacentNumbers[i].push_back('2');
                adjacentNumbers[i].push_back('3');
                adjacentNumbers[i].push_back('5');
                adjacentNumbers[i].push_back('1');
                
                break;
            case '3':
                adjacentNumbers[i].push_back('3');
                adjacentNumbers[i].push_back('6');
                adjacentNumbers[i].push_back('2');
                
                break;
            case '4':
                adjacentNumbers[i].push_back('4');
                adjacentNumbers[i].push_back('1');
                adjacentNumbers[i].push_back('5');
                adjacentNumbers[i].push_back('7');
                
                break;
            case '5':
                adjacentNumbers[i].push_back('5');
                adjacentNumbers[i].push_back('2');
                adjacentNumbers[i].push_back('6');
                adjacentNumbers[i].push_back('8');
                adjacentNumbers[i].push_back('4');
                break;
            case '6':
                adjacentNumbers[i].push_back('6');
                adjacentNumbers[i].push_back('3');
                adjacentNumbers[i].push_back('9');
                adjacentNumbers[i].push_back('5');
                break;
            case '7':
                adjacentNumbers[i].push_back('7');
                adjacentNumbers[i].push_back('4');
                adjacentNumbers[i].push_back('8');
                break;
            case '8':
                adjacentNumbers[i].push_back('8');
                adjacentNumbers[i].push_back('5');
                adjacentNumbers[i].push_back('9');
                adjacentNumbers[i].push_back('0');
                adjacentNumbers[i].push_back('7');
                break;
            case '9':
                adjacentNumbers[i].push_back('9');
                adjacentNumbers[i].push_back('6');
                adjacentNumbers[i].push_back('8');
                break;
            case '0':
                adjacentNumbers[i].push_back('0');
                adjacentNumbers[i].push_back('8');
                break;
            default:
                break;
        }
    }
    vector<unsigned long> cycleLength(observed.size());
    for (i = 0; i < observed.size(); ++i) {
        cycleLength[i] = 1;
        for (unsigned long j = i + 1; j < observed.size(); ++j) {
            cycleLength[i] *= adjacentNumbers[j].size();
        }
    }
    unsigned long amountOfPossiblePINS {1};
    for (i = 0; i < observed.size(); ++i) {
        amountOfPossiblePINS *= adjacentNumbers[i].size();
    }
    vector<string> possiblePINS(amountOfPossiblePINS);
    for (i = 0; i < observed.size(); ++i) {
        for (j = 0, k = 0, l = 0; j < amountOfPossiblePINS; ++j) {
            if (k >= cycleLength[i]) {
                k = 0;
                ++l;
            }
            if (l >= adjacentNumbers[i].size()) {
                l = 0;
            }
            possiblePINS[j].push_back(adjacentNumbers[i][l]);
            ++k;
        }
    }
    return possiblePINS;
}

int main(int argc, const char * argv[]) {
    vector<string> possiblePINS {get_pins("1678")};
    for (unsigned int i = 0; i < possiblePINS.size(); ++i) {
        cout << possiblePINS[i] << '\n';
    }
    return 0;
}
