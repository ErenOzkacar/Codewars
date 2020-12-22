//
//  main.cpp
//  Stop gninnipS My sdroW!
//
//  Created by Eren Özkacar on 15.12.20.
//
// Challenge: Write a function that takes in a string of one or more words, and returns the same string, but with all five or more letter words reversed (Just like the name of this Kata). Strings passed in will consist of only letters and spaces. Spaces will be included only when more than one word is present.

#include <iostream>
#include <string>
using namespace std;

string spinWords(string words) {
    string spinnedWords {};
    int start {0};
    int end {0};
    
    while (end < words.length()) {
        while (words[end] != ' ' && end < words.length()) {
            ++end;
        }
        if (end - start >= 5) {
            for (int i = end - 1; i >= start; --i) {
                spinnedWords += words[i];
            }
        } else {
            for (int i = start; i < end; ++i) {
                spinnedWords += words[i];
            }
        }
        if (end < words.length()) {
            spinnedWords += ' ';
        }
        ++end;
        start = end;
    }
    
    return spinnedWords;
}

int main(int argc, const char * argv[]) {
    cout << spinWords("Hey fellow warrior") << endl;
    cout << spinWords("This is a test") << endl;
    cout << spinWords("This is another test") << endl;
    return 0;
}
