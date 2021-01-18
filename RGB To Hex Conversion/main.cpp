//
//  main.cpp
//  RGB To Hex Conversion
//
//  Created by Eren Özkacar on 18.01.21.
//
//  Challenge: The rgb function is incomplete. Complete it so that passing in RGB decimal values will result in a hexadecimal representation being returned. Valid decimal values for RGB are 0 - 255. Any values that fall out of that range must be rounded to the closest valid value. Note: Your answer should always be 6 characters long, the shorthand with 3 will not work here.

#include <iostream>
#include <string>
using namespace std;

string decToHex(int dec) {
    string hex;
    if (dec > 255) {
        return "FF";
    } else if (dec <= 0) {
        return "00";
    }
    unsigned int rest;
    while (dec > 0) {
        rest = dec % 16;
        switch (rest) {
            case 10:
                hex.insert(0, "A");
                break;
            case 11:
                hex.insert(0, "B");
                break;
            case 12:
                hex.insert(0, "C");
                break;
            case 13:
                hex.insert(0, "D");
                break;
            case 14:
                hex.insert(0, "E");
                break;
            case 15:
                hex.insert(0, "F");
                break;
            default:
                hex.insert(0, to_string(rest));
                break;
        }
        dec /= 16;
    }
    if (hex.size() == 1) {
        hex.insert(0, "0");
    }
    return hex;
}

string rgb(int r, int g, int b) {
    return decToHex(r) + decToHex(g) + decToHex(b);
}

int main(int argc, const char * argv[]) {
    cout << rgb(-20, 275, 125) << '\n';
    return 0;
}
