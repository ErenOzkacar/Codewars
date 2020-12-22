//
//  main.cpp
//  Duplicate Encoder
//
//  Created by Eren Özkacar on 22.12.20.
//
//  Challenge: The goal of this exercise is to convert a string to a new string where each character in the new string is "(" if that character appears only once in the original string, or ")" if that character appears more than once in the original string. Ignore capitalization when determining if a character is a duplicate.

#include <iostream>
#include <string>
using namespace std;

string duplicateEncoder(const string &text) {
    string encodedText;
    bool duplicate;
    
    for (int i = 0; i < text.length(); ++i) {
        duplicate = false;
        unsigned int ci = text.at(i);
        for (int j = 0; j < text.length(); ++j) {
            unsigned int cj = text.at(j);
            if (i != j && (ci == cj || (ci >= 65 && ci <= 90 && cj >= 97 && cj <= 122 && ci + 32 == cj) || (ci >= 97 && ci <= 122 && cj >= 65 && cj <= 90 && ci == cj + 32))) {
                duplicate = true;
                break;
            }
        }
        if (duplicate == false) {
            encodedText += '(';
        } else {
            encodedText += ')';
        }
    }
    return encodedText;
}

int main(int argc, const char * argv[]) {
    cout << duplicateEncoder("Success") << '\n';
    cout << duplicateEncoder("Hello") << '\n';
    cout << duplicateEncoder("(( @") << '\n';
    return 0;
}
