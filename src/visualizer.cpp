#include "visualizer.h"
#include <iostream>

void visualizeBoard(const std::vector<int>& board) {
    bool sw = true;
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board.size(); j++) {
            if (j == board[i]) {
                std::cout << "♛";
            } else if (sw) {
                std::cout << "■";
            } else {
                std::cout << "□";
            }
            sw = !sw;
        }
        std::cout << "\n";
        sw = !sw;
    }
}