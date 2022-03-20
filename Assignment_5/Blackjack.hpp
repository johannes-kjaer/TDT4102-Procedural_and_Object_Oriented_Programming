#pragma once
#include "CardDeck.hpp"

class Hand {
    vector<Card> cards;
    int handValue = 0;
    void calculateHand(Card drawnCard);
public:
    Hand(CardDeck& deck);
    void viewHand();
    string viewDealerHand();
    void addCard(CardDeck& deck);
    int getHandValue();
    int handSize();
};

void playBlackjack();


