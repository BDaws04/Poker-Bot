#include <cstdint>
#include <cassert>

#include "../include/evaluator.h"

int evaluate_hand(const card hand[5]){
    cs card_set = 0;
    ss suit_set = 0;

    encode_hand(hand, card_set, suit_set);
}

void encode_hand(const card hand[5], cs& card_set, ss& suit_set) {
    for (int i = 0; i < 5; ++i) {
        char suit = hand[i].first;
        uint8_t rank = hand[i].second;

        assert(rank >= 2 && rank <= 14); 
        assert(suit == 'H' || suit == 'D' || suit == 'C' || suit == 'S'); 

        card_set |= (1 << (rank + 1));

        int offset = (rank - 2) * 4;
        uint64_t count = (suit_set >> offset) & 0xF;
        count = (count < 4) ? count + 1 : 4;
        suit_set &= ~(0xFULL << offset);
        suit_set |= (count << offset);

    }
}

