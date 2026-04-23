#include "visualizer.h"
#include <iostream>

void visualizeBoard(const std::vector<int>& board) {
    const std::string RESET = "\033[0m";
    const std::string WHITE = "\033[48;2;240;217;181m\033[38;2;0;0;0m";
    const std::string BLACK = "\033[48;2;181;136;99m\033[38;2;0;0;0m";
    const std::string QUEEN = "\033[48;2;150;200;150m\033[38;2;0;0;0m ♕ \033[0m";

    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board.size(); j++) {
            bool isWhite = (i + j) % 2 == 0;
            std::string bg = isWhite ? WHITE : BLACK;
            if (j == board[i]) {
                std::cout << QUEEN;
            } else std::cout << bg << "   " << RESET;
        }
        std::cout << "\n";
    }
}