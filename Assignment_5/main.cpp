#include "std_lib_facilities.h"
#include "Card.hpp"
#include "CardDeck.hpp"
#include "Blackjack.hpp"

int main() {
    srand(unsigned(time(nullptr)));
    //Rank r = Rank::king;
    //Suit s = Suit::hearts;
    //string rank = rankToString(r);
    //string suit = suitToString(s);
    //cout << "Rank: " << rank << " Suit: " << suit << '\n';
    
    //Card c{Suit::spades, Rank::ace};
    //cout << c.toString() << '\n';
    
    //CardDeck deck;
    //deck.swap(3,8);
    //deck.shuffle();
    //Card drawnCard = deck.drawCard();
    //deck.print();
    //cout << drawnCard.toString() << "\n";

    playBlackjack();
}