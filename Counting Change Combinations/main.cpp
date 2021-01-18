//
//  main.cpp
//  Counting Change Combinations
//
//  Created by Eren Özkacar on 13.01.21.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<vector<unsigned long>> rightChangeCombinations(const unsigned int money, const vector<unsigned int>& coins);
vector<string> format(vector<vector<unsigned long>> combinations, const vector<unsigned int>& coins);

int main(int argc, const char * argv[]) {
    unsigned int money {15};
    vector<unsigned int> coins {5, 2, 3};
    vector<vector<unsigned long>> combinations = rightChangeCombinations(money, coins);
    vector<string> combinationsString = format(combinations, coins);
    cout << "Combinations to get " << money << " with the coins " << coins.at(0);
    for (int i = 1; i < coins.size(); ++i) {
        cout << ", " << coins.at(i);
    }
    cout << " are:\n";
    for (int i = 0; i < combinationsString.size(); ++i) {
        cout << combinationsString.at(i) << '\n';
    }
    return 0;
}

vector<vector<unsigned long>> allChangeCombinations(const unsigned int money, const vector<unsigned int>& coins) {
    unsigned long amountOfCoins {coins.size()};
    vector<vector<unsigned long>> coinsSum(amountOfCoins, vector<unsigned long>());
    unsigned long i, j, k, l;
    for (i = 0; i < amountOfCoins; ++i) { // All possible sums of one coin
        coinsSum[i].push_back(0);
        for (j = 1; j <= money / coins.at(i); ++j) {
            coinsSum[i].push_back(coins.at(i) * j);
        }
    }
    vector<unsigned int> cycleLength(amountOfCoins); // e.g. last coin has a cycle length of 1
    for (i = 0; i < amountOfCoins; ++i) {
        cycleLength.at(i) = 1;
        for (j = i + 1; j < amountOfCoins; ++j) {
            cycleLength.at(i) *= coinsSum[j].size();
        }
    }
    unsigned long maxAmountOfCombinations {1};
    for (i = 0; i < amountOfCoins; ++i) {
        maxAmountOfCombinations *= coinsSum[i].size();
    }
    vector<vector<unsigned long>> allCombinations(maxAmountOfCombinations, vector<unsigned long>(amountOfCoins + 1));
    for (i = 0; i < amountOfCoins; ++i) {
        for (j = 0, k = 0, l = 0; j < maxAmountOfCombinations; ++j) {
            if (k == cycleLength.at(i)) {
                k = 0;
                ++l;
            }
            if (l == coinsSum[i].size()) {
                l = 0;
            }
            allCombinations[j][i] = coinsSum[i][l];
            ++k;
        }
    }
    for (i = 0; i < maxAmountOfCombinations; ++i) { // Calculate sum of the combination
        allCombinations[i][amountOfCoins] = 0; // Field where the sum of the combination wil be
        for (j = 0; j < amountOfCoins; ++j) {
            allCombinations[i][amountOfCoins] += allCombinations[i][j];
        }
    }
    return allCombinations;
}

unsigned long amountOfRightChangeCombinations(vector<vector<unsigned long>> allCombinations, const unsigned int money) {
    unsigned long rightCombinations {0};
    for (unsigned long i = 0; i < allCombinations.size(); ++i) {
        if (allCombinations[i][allCombinations[0].size() - 1] == money) {
            ++rightCombinations;
        }
    }
    return rightCombinations;
}

vector<vector<unsigned long>> rightChangeCombinations(const unsigned int money, const vector<unsigned int>& coins) {
    vector<vector<unsigned long>> allCombinations = allChangeCombinations(money, coins);
    unsigned long amountRightCombinations = amountOfRightChangeCombinations(allCombinations, money);
    vector<vector<unsigned long>> rightCombinations(amountRightCombinations, vector<unsigned long>(allCombinations[0].size()));
    unsigned long counter {0};
    for (int i = 0; counter < amountRightCombinations && i < allCombinations.size(); ++i) {
        if (allCombinations[i][allCombinations[0].size() - 1] == money) {
            rightCombinations[counter] = allCombinations[i];
            ++counter;
        }
    }
    return rightCombinations;
}

vector<string> format(vector<vector<unsigned long>> combinations, const vector<unsigned int>& coins) {
    vector<string> formatted(combinations.size());
    unsigned long i, j, multiple, fixedMultiple, nextMultiple, count;
    for (i = 0; i < coins.size(); ++i) {
        for (j = 0; j < combinations.size(); ++j) {
            multiple = combinations[j][i] / coins.at(i);
            fixedMultiple = multiple;
            while (multiple >= 1) {
                formatted.at(j) += to_string(coins.at(i));
                if (multiple > 1) {
                    formatted.at(j) += " + ";
                }
                --multiple;
            }
            for (count = i + 1; count < coins.size(); ++count) {
                nextMultiple = combinations[j][count] / coins.at(i + 1);
                if (nextMultiple > 0 && fixedMultiple > 0) {
                    formatted.at(j) += " + ";
                    break;
                }
            }
        }
    }
    return formatted;
}
