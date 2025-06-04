#ifndef MONTE_CARLO_H
#define MONTE_CARLO_H

#include <vector>
#include <assert.h>

#include "evaluator.h"
#include "utils.h"

// std::pair<wins, losses> 
std::pair<int, int> monte_carlo_simulation(const std::vector<card>& player_cards, std::vector<card>& river, int iterations);

#endif