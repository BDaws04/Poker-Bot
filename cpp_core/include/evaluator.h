#ifndef EVALUATOR_H
#define EVALUATOR_H

#include "deck.h"

using cs = uint16_t;
using ss = uint64_t;

int evaluate_hand(const card hand[5]);
void encode_hand(const card hand[5], cs& card_set, ss& suit_set);

#endif