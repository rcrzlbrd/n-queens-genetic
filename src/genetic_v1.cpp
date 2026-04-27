#include "genetic_v1.h"
#include "fitness.h"
#include <random>
#include <vector>
#include <algorithm>
#include <chrono>
#include <numeric>

int rouletteSelect(const std::vector<int>& fitnesses, std::mt19937& rng) {
    int sumFitnesses= 0;
    for (const int fitnesse : fitnesses) {
        sumFitnesses += fitnesse;
    }
    std::uniform_int_distribution<int> distrib(0, sumFitnesses);
    const int random = distrib(rng);
    int accumulatedFitness = 0;
    for (int i = 0; i < fitnesses.size(); i++) {
        accumulatedFitness += fitnesses[i];
        if (accumulatedFitness > random) {
            return i;
        }
    }
    return fitnesses.size() - 1;
}

std::vector<int> crossover0X1(const std::vector<int>& father1, const std::vector<int>& father2, std::mt19937& rng) {
    std::uniform_int_distribution<int> dist(0, father1.size() - 1);
    int startSegment = dist(rng);
    int endSegment = dist(rng);
    if (startSegment > endSegment) std::swap(startSegment, endSegment);
    std::vector<int> son(father1.size(), -1);
    for (int i = startSegment; i < endSegment; i++) {
        son[i] = father1[i];
    }

    for (int i = 0; i < father1.size(); i++) {
        for (int j : father2) {
            if (son[i] == -1 && std::find(son.begin(), son.end(), j) == son.end()) {
                son[i] = j;
                break;
            }
        }
    }
    return son;
}

std::pair<double, std::vector<int>> runGeneticV1(const int n, const int populationSize, const int maxGenerations, const double mutationRate) {
    auto start = std::chrono::high_resolution_clock::now();
    std::vector<std::vector<int>> population;
    std::mt19937 rng(std::random_device{}());

    for (int i = 0; i < populationSize; i++) {
        std::vector<int> board(n);
        std::iota(board.begin(), board.end(), 0);
        std::shuffle(board.begin(), board.end(), rng);
        population.push_back(board);
    }

    std::vector<int> fitnesses(populationSize);
    for (int i = 0; i < maxGenerations; i++) {

        for (int j = 0; j < population.size(); j++) {
            fitnesses[j] = fitness(population[j]);
        }

        if (*std::max_element(fitnesses.begin(), fitnesses.end()) == maxFitness(n)) {
            auto end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> const elapsed = end - start;
            return {elapsed.count(), population[std::max_element(fitnesses.begin(), fitnesses.end()) - fitnesses.begin()]};
        }

        std::vector<std::vector<int>> newPopulation;
        for (int k = 0; k < populationSize; k++) {
            const int index1 = rouletteSelect(fitnesses, rng);
            const int index2 = rouletteSelect(fitnesses, rng);
            std::vector<int>& father1 = population[index1];
            std::vector<int>& father2 = population[index2];
            std::vector<int> son = crossover0X1(father1, father2, rng);
            std::uniform_real_distribution mutation(0.0, 1.0);
            if (mutation(rng) < mutationRate) {
                std::uniform_int_distribution<int> mutationPos(0, n - 1);
                const int pos1 = mutationPos(rng);
                const int pos2 = mutationPos(rng);
                std::swap(son[pos1], son[pos2]);
            }
            newPopulation.push_back(son);
        }
        population = newPopulation;
    }
    return {-1.0, population[std::max_element(fitnesses.begin(), fitnesses.end()) - fitnesses.begin()]} ;
}