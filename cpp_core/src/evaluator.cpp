#include <cstdint>

#include "../include/evaluator.h"

using cs = uint16_t;
using ss = uint64_t;

int evaluate_hand(const card hand[5]){
    cs card_set = 0;
    ss suit_set = 0;

    encode_hand(hand, card_set, suit_set);
}

void encode_hand(const card hand[5], cs& card_set, ss& suit_set) {

}

