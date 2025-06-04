#include <cassert>

#include "../include/evaluator.h"

void test_encode_hand() {
    card hand[5] = {
        {'H', 2}, {'D', 3}, {'C', 4}, {'S', 5}, {'H', 6}
    };
    
    cs card_set = 0;
    ss suit_set = 0;

    encode_hand(hand, card_set, suit_set);
    assert(card_set == (1 << 3) | (1 << 4) | (1 << 5) | (1 << 6) | (1 << 7));
    assert(suit_set == (1 << 0) | (1 << 4) | (1 << 8) | (1 << 12) | (1 << 16));
}