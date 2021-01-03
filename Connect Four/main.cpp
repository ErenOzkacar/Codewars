//
//  main.cpp
//  Connect Four
//
//  Created by Eren Özkacar on 03.01.21.
//
//  Challenge: The grid is 6 row by 7 columns, those being named from A to G. You will receive a list of strings showing the order of the pieces which dropped in columns: std::vector<std::string> pieces_position_list {"A_Red", "B_Yellow", "A_Red", "B_Yellow", "A_Red", "B_Yellow", "G_Red", "B_Yellow"} The list may contain up to 42 moves and shows the order the players are playing. The first player who connects four items of the same color is the winner. You should return "Yellow", "Red" or "Draw" accordingly.

#include <iostream>
#include <vector>
#include <string>
using namespace std;

string winner(vector<vector<string>> grid) {
    int counter;
    // Horizontal
    for (int y = 0; y < 6; ++y) {
        for (int x1 = 0; x1 <= 3; ++x1) {
            counter = 0;
            for (int i = 0; i <= 3; ++i) {
                if (grid[x1][y] == grid[x1 + i][y]) {
                    ++counter;
                }
            }
            if (counter == 4 && grid[x1][y] != "Free") {
                return grid[x1][y];
            }
        }
    }
    // Vertical
    for (int x = 0; x < 7; ++x) {
        for (int y1 = 0; y1 <= 2; ++y1) {
            counter = 0;
            for (int i = 0; i <= 3; ++i) {
                if (grid[x][y1] == grid[x][y1 + i]) {
                    ++counter;
                }
            }
            if (counter == 4 && grid[x][y1] != "Free") {
                return grid[x][y1];
            }
        }
    }
    // Diagonal - Up
    for (int x = 0; x <= 3; ++x) {
        for (int y = 0; y <= 2; ++y) {
            counter = 0;
            for (int x1 = 0, y1 = 0; x1 <= 3; ++x1, ++y1) {
                if (grid[x][y] == grid[x + x1][y + y1]) {
                    ++counter;
                }
            }
            if (counter == 4 && grid[x][y] != "Free") {
                return grid[x][y];
            }
        }
    }
    // Diagonal - Down
    for (int x = 0; x <= 3; ++x) {
        for (int y = 5; y >= 3; --y) {
            counter = 0;
            for (int x1 = 0, y1 = 0; x1 <= 3; ++x1, ++y1) {
                if (grid[x][y] == grid[x + x1][y - y1]) {
                    ++counter;
                }
            }
            if (counter == 4 && grid[x][y] != "Free") {
                return grid[x][y];
            }
        }
    }
    return "Draw";
}

string game(vector<string> dropOrder) {
    vector<vector<string>> grid (7, vector<string>(6));
    // Initializing grid with "Free"
    for (int i = 0; i < 7 ; ++i) {
        for (int j = 0; j < 6; ++j) {
            grid[i][j] = "Free";
        }
    }
    // Put pieces in grid and check if one won already
    string win;
    for (int i = 0; i < dropOrder.size(); ++i) {
        int column = dropOrder.at(i)[0] - 65;
        for (int j = 0; j < 6; ++j) {
            if (grid[column][j] == "Free") {
                grid[column][j] = dropOrder.at(i).substr(2, dropOrder.at(i).size() - 2);
                break;
            }
        }
        win = winner(grid);
        if (win != "Draw") {
            break;
        }
    }
    return win;
}

int main(int argc, const char * argv[]) {
    cout << game({"A_Red", "B_Yellow", "A_Red", "B_Yellow", "A_Red", "B_Yellow", "G_Red", "B_Yellow"}) << '\n';
    return 0;
}
