#include <iostream>
#include "genetic_v1.h"
#include "genetic_v2.h"
#include "visualizer.h"

int main() {
    int n1 = 8;
    int populationSize1 = 100;
    int maxGenerations1 = 100000;
    double mutationRate1 = .3;

    int n2 = 8;
    int populationSize2 = 100;
    int maxGenerations2 = 100000;
    int tournamentSize = 3;
    double mutationRate2 = .5;

    std::pair<double, std::vector<int>> solution1 = runGeneticV1(n1, populationSize1, maxGenerations1, mutationRate1);
    if (solution1.first == -1) {
        std::cout << "\nThere was no solution found\n";
        visualizeBoard(solution1.second);
    } else {
        std::cout << "\nThe solution was found in " << solution1.first << "s\n";
        visualizeBoard(solution1.second);
    }

    std::pair<double, std::vector<int>> solution2 = runGeneticV2(n2, populationSize2, maxGenerations2, tournamentSize, mutationRate2);
    if (solution2.first == -1) {
        std::cout << "\nThere was no solution found\n";
        visualizeBoard(solution2.second);
    } else {
        std::cout << "\nThe solution was found in " << solution2.first << "s\n";
        visualizeBoard(solution2.second);
    }
    return 0;
}