#include "genetic_v1.h"
#include "fitness.h"
#include <random>
#include <vector>
#include <algorithm>
#include <chrono>
#include <numeric>
#include <cmath>

double runGeneticV1(int n, int populationSize, int maxGenerations) {
    auto start = std::chrono::high_resolution_clock::now();
    std::vector<std::vector<int>> population;
    std::mt19937 rng(std::random_device{}());

    for (int i = 0; i < populationSize; i++) {
        std::vector<int> board(n);
        std::iota(board.begin(), board.end(), 0);
        std::shuffle(board.begin(), board.end(), rng);
        population.push_back(board);
    }

    for (int i = 0; i < maxGenerations; i++) {
        std::vector<int> fitnesses(populationSize);

        for (int j = 0; j < population.size(); j++) {
            fitnesses[j] = fitness(population[j]);
        }

        if (*(std::max_element(fitnesses.begin(), fitnesses.end())) == maxFitness(n)) {
            auto end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> elapsed = end - start;
            return elapsed.count();
        }

    }
}