#include "../include/monte_carlo.h"

std::pair<int, int> monte_carlo_simulation(const std::vector<card>& player_cards, std::vector<card>& river, int iterations) {
    int wins = 0, losses = 0, cards_required = 5 - river.size() + 2;
    std::vector<card> known_cards(player_cards.size() + river.size());

    int i = 0;
    for (const card& c : player_cards) {
        known_cards[i++] = c;
    }
    for (const card& c : river) {
        known_cards[i++] = c;
    }

    Deck deck(known_cards);

    for (int i = 0; i < iterations; ++i){
        std::vector<card> drawn_cards = deck.draw_and_reshuffle(cards_required);
        std::vector<card> player_hand = river, opponent_hand = river;
        player_hand.insert(player_hand.end(), player_cards.begin(), player_cards.end());

        int drawn_card_index = 0;

        for (int i = 0; i < 5 - river.size(); i++){
            player_hand.push_back(drawn_cards[drawn_card_index++]);
        }
        for (int i = drawn_card_index; i < drawn_cards.size(); i++){
            opponent_hand.push_back(drawn_cards[i]);
        }

        assert(player_hand.size() == 7);
        assert(opponent_hand.size() == 7);

        auto player_combinations = generate_combinations<card, 5>(player_hand);
        auto opponent_combinations = generate_combinations<card, 5>(opponent_hand);

        int player_sum = 0, opponent_sum = 0;
        for (int i = 0; i < player_combinations.size(); ++i) {
            player_sum += evaluate_hand(player_combinations[i].data());
            opponent_sum += evaluate_hand(opponent_combinations[i].data());
        }

        if (player_sum <= opponent_sum) {
            ++wins;
        } else {
            ++losses;
        }
    }

    return {wins, losses};
}