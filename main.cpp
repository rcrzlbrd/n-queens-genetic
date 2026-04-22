#include <iostream>
#include <ostream>

#include "visualizer.h"

int main() {
    std::vector<int> board = { 0, 1, 2, 3, 4, 5, 6, 7 };
    visualizeBoard(board);
    return 0;
}