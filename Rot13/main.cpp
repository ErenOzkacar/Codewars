//
//  main.cpp
//  Rot13
//
//  Created by Eren Özkacar on 31.12.20.
//
//  Challenge: ROT13 is a simple letter substitution cipher that replaces a letter with the letter 13 letters after it in the alphabet. ROT13 is an example of the Caesar cipher. Create a function that takes a string and returns the string ciphered with Rot13. If there are numbers or special characters included in the string, they should be returned as they are. Only letters from the latin/english alphabet should be shifted, like in the original Rot13 "implementation".

#include <iostream>
#include <string>
using namespace std;

string rot13(string letters) {
    string cipher;
    for (int i = 0; i < letters.size(); ++i) {
        if ((letters.at(i) >= 'A' && letters.at(i) <= 'M') || (letters.at(i) >= 'a' && letters.at(i) <= 'm')) {
            cipher.push_back(letters.at(i) + 13);
        } else if ((letters.at(i) > 'M' && letters.at(i) <= 'Z') || (letters.at(i) > 'm' && letters.at(i) <= 'z')) {
            cipher.push_back(letters.at(i) - 13);
        } else {
            cipher.push_back(letters.at(i));
        }
    }
    return cipher;
}

int main(int argc, const char * argv[]) {
    cout << rot13("test") << '\n';
    cout << rot13("Test") << '\n';
    cout << rot13("AbCd") << '\n';
    return 0;
}
