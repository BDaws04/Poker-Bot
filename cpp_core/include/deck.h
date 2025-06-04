#ifndef DECK_H
#define DECK_H

#include <cstdint>
#include <utility>
#include <vector>

using card = std::pair<char, uint8_t>;


struct Deck {
    public:
        Deck();
        ~Deck() = default;
        card draw();
        void reset();
        void shuffle_remaining();
    private:
        card cards[52];
        int front = 0;
        void shuffle();
};
#endif