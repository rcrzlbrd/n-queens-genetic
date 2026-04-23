#pragma once
#include <vector>
#include <utility>

std::pair<double, std::vector<int>> runGeneticV1(int n, int populationSize, int maxGenerations, double mutationRate);