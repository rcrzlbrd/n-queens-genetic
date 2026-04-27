#include "genetic_v2.h"
#include "fitness.h"
#include <random>
#include <vector>
#include <algorithm>
#include <chrono>
#include <numeric>

int tournamentSelect(const std::vector<std::vector<int>>& population, const std::vector<int>& fitnesses, std::mt19937& rng, int tournamentSize) {
    std::uniform_int_distribution<int> dist(0, population.size() - 1);
    int maxFitness = 0, maxFitnessIndex = 0;
    for (int i = 0; i < tournamentSize; i++) {
        int randomIndex = dist(rng);
        if (fitnesses[randomIndex] > maxFitness) {
            maxFitness = fitnesses[randomIndex];
            maxFitnessIndex = randomIndex;
        }
    }
    return maxFitnessIndex;
}

std::vector<int> crossoverPMX(const std::vector<int>& father1, const std::vector<int>& father2, std::mt19937& rng) {
    std::uniform_int_distribution<int> dist(0, father1.size() - 1);
    int startSegment = dist(rng);
    int endSegment = dist(rng);
    if (startSegment > endSegment) {
        std::swap(startSegment, endSegment);
    }
    std::vector<int> son(father1.size(), -1);
    for (int i = startSegment; i <= endSegment; i++) {
        son[i] = father1[i];
    }
    for (int i = startSegment; i <= endSegment; i++) {
        if (std::find(son.begin(), son.end(), father2[i]) == son.end()) {
            int pos = i;
            int safety = 0;
            while (son[pos] != -1 && safety < (int)father1.size()) {
                int val = father2[pos];
                pos = std::find(father1.begin(), father1.end(), val) - father1.begin();
                safety++;
            }
            if (pos < (int)son.size() && son[pos] == -1) {
                son[pos] = father2[i];
            }
        }
    }
    for (int i = 0; i < (int)father2.size(); i++) {
        if (son[i] == -1 && std::find(son.begin(), son.end(), father2[i]) == son.end()) {
            son[i] = father2[i];
        }
    }
    for (int i = 0; i < (int)son.size(); i++) {
        if (son[i] == -1) {
            for (int val = 0; val < (int)father1.size(); val++) {
                if (std::find(son.begin(), son.end(), val) == son.end()) {
                    son[i] = val;
                    break;
                }
            }
        }
    }
    return son;
}

void mutationInversion(std::vector<int>& board, std::mt19937& rng) {
    std::uniform_int_distribution<int> dist(0, board.size() - 1);
    int startSegment = dist(rng);
    int endSegment = dist(rng);
    if (startSegment > endSegment) { std::swap(startSegment, endSegment); }
    std::reverse(board.begin() + startSegment, board.begin() + endSegment);
}

std::pair<double, std::vector<int>> runGeneticV2(const int n, const int populationSize, const int maxGenerations, const int tournamentSize, const double mutationRate) {
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

        const int bestIndex = std::max_element(fitnesses.begin(), fitnesses.end()) - fitnesses.begin();
        std::vector<std::vector<int> > newPopulation = {population[bestIndex]};

        for (int k = 0; k < populationSize - 1; k++) {
            const int index1 = tournamentSelect(population, fitnesses, rng, tournamentSize);
            const int index2 = tournamentSelect(population, fitnesses, rng, tournamentSize);
            std::vector<int>& father1 = population[index1];
            std::vector<int>& father2 = population[index2];
            std::vector<int> son = crossoverPMX(father1, father2, rng);
            std::uniform_real_distribution<double> dist(0.0, 1.0);
            if (dist(rng) < mutationRate) { mutationInversion(son, rng); }
            newPopulation.push_back(son);
        }
        population = newPopulation;
    }
    return {-1.0, population[std::max_element(fitnesses.begin(), fitnesses.end()) - fitnesses.begin()]} ;
}
