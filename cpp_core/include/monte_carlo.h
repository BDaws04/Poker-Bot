#ifndef MONTE_CARLO_H
#define MONTE_CARLO_H

#include <vector>

#include "evaluator.h"

int monte_carlo_simulation(const std::vector<card>& player_hand, const std::vector<card>& river, int iterations);

#endif