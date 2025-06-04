#ifndef MONTE_CARLO_H
#define MONTE_CARLO_H

#include <vector>

#include "evaluator.h"

int monte_carlo_simulation(const std::vector<card>& known_cards, int iterations);

#endif