#pragma once
#include "Card.hpp"

class CardDeck {
    vector<Card> cards;
public:
    CardDeck();
    void swap(int a, int b);
    void print();
    void shuffle();
    Card drawCard();
};


