#ifndef DECK_H
#define DECK_H

#include <cstdint>
#include <vector>

using card = std::pair<char, uint8_t>;


struct Deck {
    public:
        Deck();
        Deck(const std::vector<card>& known_cards);
        ~Deck() = default;

        card draw();
        std::vector<card> draw(int n);
        std::vector<card> draw_and_reshuffle(int n);
        
        void reset();
        void shuffle_remaining();
    private:
        card cards[52];
        int front = 0;
        void shuffle();
};
#endif