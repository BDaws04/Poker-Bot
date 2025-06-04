#include "../include/utils.h"

#include <vector>
#include <array>
#include <stdexcept>

template <typename T, size_t K>
std::vector<std::array<T, K>> generate_combinations(const std::vector<T>& elements) {
    int n = (int)elements.size();
    if (K > n || K == 0) {
        throw std::invalid_argument("Invalid combination length");
    }

    std::vector<std::array<T, K>> result;

    unsigned int bitmask = (1U << K) - 1;  // first bitmask with K ones

    while (bitmask < (1U << n)) {
        std::array<T, K> combo{};
        int idx = 0;
        for (int i = 0; i < n; ++i) {
            if (bitmask & (1U << i)) {
                combo[idx++] = elements[i];
            }
        }
        result.push_back(combo);

        unsigned int c = bitmask & -bitmask;
        unsigned int r = bitmask + c;
        bitmask = (((r ^ bitmask) >> 2) / c) | r;
    }

    return result;
}
