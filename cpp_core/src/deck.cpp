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

    std::vector<card> all_cards;
    char suits[] = {'H', 'D', 'C', 'S'};
    for (int i = 0; i < 52; ++i) {
        all_cards.push_back({suits[i / 13], static_cast<uint8_t>(i % 13 + 2)});
    }

    for (const auto& kc : known_cards) {
        auto it = std::find(all_cards.begin(), all_cards.end(), kc);
        if (it != all_cards.end()) {
            all_cards.erase(it);
        } else {
            throw std::invalid_argument("Known card not found in deck");
        }
    }

    int idx = 0;
    for (const auto& kc : known_cards) {
        cards[idx++] = kc;
    }
    for (const auto& c : all_cards) {
        cards[idx++] = c;
    }

    front = known_cards.size(); 
    shuffle_remaining();  
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

std::vector<card> Deck::draw_and_reshuffle(int n) {
    std::vector<card> result(n);
    if (front + n > 52) {
        throw std::out_of_range("Not enough cards to draw");
    }
    for (int i = 0; i < n; ++i){
        result[i] = cards[front + i];
    }
    shuffle_remaining();
    return result;
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