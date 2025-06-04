#include <cstdint>
#include <cassert>

#include "../include/evaluator.h"

int evaluate_hand(const card hand[5]){
    cs card_set = 0;
    ss suit_set = 0;

    encode_hand(hand, card_set, suit_set);

    int s = 0;
    for (int i = 0; i < 5; ++i) {
        s |= (1 << hand[i].second);
    }

    int v = 0;
    for (int i = 0; i < 5; ++i) {
        int rank = hand[i].second;
        int offset = (rank - 2) * 4;
        uint64_t count = (suit_set >> offset) & 0xF;

        int power = 1 << (rank * 4);
        v += power * ((v / power & 15) + 1);
    }

    bool isStraight = (s / (s & -s)) == 31;  
    bool isAceLowStraight = s == 0x403c;     

    v = v % 15 - ((isStraight || isAceLowStraight) ? 3 : 1);

    bool isFlush = (hand[0].first == hand[1].first) &&
                   (hand[0].first == hand[2].first) &&
                   (hand[0].first == hand[3].first) &&
                   (hand[0].first == hand[4].first);

    if (isFlush) {
        if (s == 0x7c00)  
            v -= -5;     
        else
            v -= 1;
    }
    
    return v;
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

