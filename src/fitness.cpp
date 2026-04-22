#include "fitness.h"
#include <cmath>

int maxFitness(const int n) {
    return n*(n-1)/2;
}

int fitness(const std::vector<int>& board) {
    int sum = 0;
    for (int i = 0; i < board.size(); i++) {
        for (int j = i + 1; j < board.size(); j++) {
            if (abs(i-j) != abs(board[i] - board[j])) {
                sum++;
            }
        }
    }
    return sum;
}