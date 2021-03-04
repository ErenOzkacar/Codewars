//
//  main.cpp
//  Matrix Determinant
//
//  Created by Eren Özkacar on 04.03.21.
//
//  Challenge: Write a function that accepts a square matrix (N x N 2D array) and returns the determinant of the matrix.

#include <iostream>
#include <vector>
#include <math.h>

long long determinant(std::vector<std::vector<long long>> matrix) {
    if (matrix.size() == 1) {
        return matrix[0][0];
    } else if (matrix.size() == 2) {
        return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    } else {
        long long det {0};
        for (size_t i = 0; i < matrix[0].size(); ++i) {
            std::vector<std::vector<long long>> minor(matrix.size() - 1, std::vector<long long>(matrix[0].size() - 1));
            for (size_t j = 1; j < matrix.size(); ++j) {
                for (size_t k = 0, l = 0; k < matrix[0].size(); ++k) {
                    if (k != i) {
                        minor[j - 1][l] = matrix[j][k];
                        ++l;
                    }
                }
            }
            det += pow(-1, i) * matrix[0][i] * determinant(minor);
        }
        return det;
    }
}

int main(int argc, const char * argv[]) {
    std::vector<std::vector<long long>> matrix1 {{1}};
    std::vector<std::vector<long long>> matrix2 {{2, 5}, {1, -2}};
    std::vector<std::vector<long long>> matrix3 {{2, 5, 3}, {1, -2, -1}, {1, 3, 4}};
    std::cout << determinant(matrix3);
    return 0;
}
