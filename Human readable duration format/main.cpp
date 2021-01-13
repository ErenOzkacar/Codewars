//
//  main.cpp
//  Human readable duration format
//
//  Created by Eren Özkacar on 13.01.21.
//
//  Challenge: Your task in order to complete this Kata is to write a function which formats a duration, given as a number of seconds, in a human-friendly way. The function must accept a non-negative integer. If it is zero, it just returns "now". Otherwise, the duration is expressed as a combination of years, days, hours, minutes and seconds.

#include <iostream>
#include <string>
#include <vector>
using namespace std;

string format_duration(int seconds) {
    vector<int> timesInt(6);
    timesInt.at(0) = seconds / 31'536'000; // years
    seconds %= 31'536'000;
    timesInt.at(1) = seconds / 86'400; // days
    seconds %= 86'400;
    timesInt.at(2) = seconds / 3'600; // hours
    seconds %= 3'600;
    timesInt.at(3) = seconds / 60; // minutes
    seconds %= 60;
    timesInt.at(4) = seconds; // seconds
    timesInt.at(5) = 0;
    for (int i = 0; i < 5; ++i) {
        if (timesInt.at(i) > 0) {
            ++timesInt.at(5);
        }
    }
    vector<string> timesString {" year", " day", " hour", " minute", " second"};
    string duration;
    if (timesInt.at(5) == 0) {
        duration = "now";
        return duration;
    } else if (timesInt.at(5) > 1) {
        for (int i = 0; i < 5 && timesInt.at(5) > 1; ++i) {
            if (timesInt.at(i) > 0) {
                duration += to_string(timesInt.at(i)) + timesString.at(i);
                if (timesInt.at(i) > 1) {
                    duration += "s";
                }
                if (timesInt.at(5) > 2) {
                    duration += ", ";
                }
                timesInt.at(i) = 0;
                --timesInt.at(5);
            }
        }
        duration += " and ";
    }
    for (int i = 0; i < 5; ++i) {
        if (timesInt.at(i) > 0) {
            duration += to_string(timesInt.at(i)) + timesString.at(i);
            if (timesInt.at(i) > 1) {
                duration += "s";
            }
        }
    }
    return duration;
}

int main(int argc, const char * argv[]) {
    cout << format_duration(999999999) << '\n';
    return 0;
}
