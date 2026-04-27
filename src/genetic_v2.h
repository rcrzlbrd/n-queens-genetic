#pragma once
#include <vector>
#include <utility>

std::pair<double, std::vector<int>> runGeneticV2(int n, int populationSize, int maxGenerations, int tournamentSize, double mutationRate);