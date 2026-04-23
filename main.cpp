#include <iostream>
#include "genetic_v1.h"
#include "visualizer.h"

int main() {
    int n = 16;
    int populationSize = 100;
    int maxGenerations = 10000;
    double mutationRate = .5;
    std::pair<double, std::vector<int>> solution = runGeneticV1(n, populationSize, maxGenerations, mutationRate);
    if (solution.first == -1) {
        std::cout << "There was no solution found\n";
        visualizeBoard(solution.second);
    } else {
        std::cout << "The solution was found in " << solution.first << "s\n";
        visualizeBoard(solution.second);
    }
    return 0;
}