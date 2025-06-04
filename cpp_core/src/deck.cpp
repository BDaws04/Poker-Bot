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

Deck::Deck(const std::vector<card>& known_cards) {
    if (known_cards.size() > 52) {
        throw std::invalid_argument("Too many known cards");
    }
    char suits[] = {'H', 'D', 'C', 'S'};
    int index = 0;
    for (int i = 0; i < 52; ++i) {
        if (index < known_cards.size() && cards[i] == known_cards[index]) {
            cards[i] = known_cards[index++];
        } else {
            cards[i] = {suits[i / 13], static_cast<uint8_t>(i % 13 + 2)};
        }
    }
    front = index;
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

std::vector<card> Deck::draw(int n) {
    if (front + n > 52) {
        throw std::out_of_range("Not enough cards to draw");
    }
    std::vector<card> drawn_cards(cards + front, cards + front + n);
    front += n;
    return drawn_cards;
}

void Deck::reset() {
    front = 0;
    shuffle();
}

void Deck::shuffle_remaining() {
    for (int i = front; i < 52; ++i) {
        int j = rand() % (52 - front) + front;
        std::swap(cards[i], cards[j]);
    }
}