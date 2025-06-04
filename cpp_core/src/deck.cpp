#include <cstdint>
#include <stdexcept>
#include "../include/deck.h"

Deck::Deck() {
    char suits[] = {'H', 'D', 'C', 'S'};
    for (int i = 0; i < 52; ++i) {
        cards[i] = {suits[i / 13], static_cast<uint8_t>(i % 13 + 2)};
    }
    shuffle();
}

void Deck::shuffle() {
    for (int i = 51; i > 0; --i) {
        int j = rand() % (i + 1);
        std::swap(cards[i], cards[j]);
    }
}

card Deck::draw() {
    if (front >= 52) {
        throw std::out_of_range("No more cards to draw");
    }
    return cards[front++];
}

void Deck::reset() {
    front = 0;
    shuffle();
}