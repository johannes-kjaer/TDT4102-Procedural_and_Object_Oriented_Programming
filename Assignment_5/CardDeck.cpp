#include "CardDeck.hpp"

CardDeck::CardDeck() {
    for (int i = 0; i<4; i++) {
        for (int j = 2; j<=14; j++) {
            cards.push_back(Card{static_cast<Suit>(i),static_cast<Rank>(j)});
        }
    }
    shuffle();
}
void CardDeck::swap(int a, int b) {
    Card temporary = cards[a];
    cards[a] = cards[b];
    cards[b] = temporary;
}
void CardDeck::print() {
    for (int i = 0; i<size(cards); i++) {
        cout << cards[i].toString() << " , ";
    }
    cout << "\n";
}
void CardDeck::shuffle() {
    for (int i = 0; i < 1000; i++) {
        int c = rand() % size(cards);
        int d = rand() % size(cards);
        swap(c,d);
    }
}
Card CardDeck::drawCard() {
    Card drawnCard = cards[size(cards)-1];
    cards.pop_back();
    return drawnCard;
}

