#ifndef UTILS_H
#define UTILS_H

#include <vector>
#include <array>
#include <stdexcept>

template <typename T, size_t K>
std::vector<std::array<T, K>> generate_combinations(const std::vector<T>& elements);

#endif