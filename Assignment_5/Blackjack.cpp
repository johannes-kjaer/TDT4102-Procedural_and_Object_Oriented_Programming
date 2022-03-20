#include "Blackjack.hpp"



Hand::Hand(CardDeck& deck) {
    for (int i = 0; i<2; i++) {
        addCard(deck);
    }
}

void Hand::viewHand() {
    for (int i = 0; i< size(cards); i++) {
        cout << cards[i].toString() << "\n";
    }
    cout << "The value of the hand is: " << handValue << "\n";
}

string Hand::viewDealerHand() {
    return cards[0].toString();
}

void Hand::addCard(CardDeck& deck) {
    Card drawnCard = deck.drawCard();
    cards.push_back(drawnCard);
    calculateHand(drawnCard);
}

void Hand::calculateHand(Card drawnCard) {
    if (int(drawnCard.getRankRank()) <= 10) {
        handValue += int(drawnCard.getRankRank());
    } else if (drawnCard.getRankRank() == Rank::ace) {
        if (handValue + 11 > 21) {
            handValue += 1;
        } else {
            handValue += 11;
        }
    } else {
        handValue += 10;
    }
}

int Hand::getHandValue() {
    return handValue;
}

int Hand::handSize() {
    return size(cards);
}

void playBlackjack() {
    // Setup of the game
    CardDeck deck;
    Hand playerHand{deck};
    Hand dealerHand{deck};

    // Initial info
    cout << "The first card of the dealers hand is: " << dealerHand.viewDealerHand() << "\nThe players hand is:\n";
    playerHand.viewHand();

    // The turn of the player
    bool hitting = true;
    while (hitting) {
        cout << "Do you want to [h]it or [s]tand?\n";
        string answer;
        cin >> answer;
        if (answer == string("h")) {
            playerHand.addCard(deck);
        } else if (answer == string("s")) {
                hitting = false;
        } else {
            cout << "Thats not a valid answer.\n";
        }
        if (playerHand.getHandValue() > 21) {
            hitting = false;
        }
        playerHand.viewHand();
    }

    // The turn of the dealer
    while (dealerHand.getHandValue() < 17) {
        dealerHand.addCard(deck);
    }
    // Show dealers hand
    //dealerHand.viewHand();

    // Check who wins
    if (playerHand.getHandValue() > 21) {
        cout << "Busted, you lose.\n";
    } else if (dealerHand.getHandValue() > 21) {
        cout << "The dealer busted, you won!";
    } else if (playerHand.getHandValue() < dealerHand.getHandValue()) {
        cout << "The dealer beat you, " << dealerHand.getHandValue() << " to " << playerHand.getHandValue() << ".\n";
    } else if (playerHand.getHandValue() > dealerHand.getHandValue()) {
        cout << "Congratulations, you won, " << playerHand.getHandValue() << " to " << dealerHand.getHandValue() << "\n";
    } else if (playerHand.getHandValue() == 21) {
        if (playerHand.handSize() == 2) {
            if (dealerHand.handSize() == 2) {
                cout << "You both got Blackjack, and tie.\n";
            } else {
                cout << "You beat the dealer with a Blackjack against 21.\n";
            }
        } else {
            cout << "You tie at 21.\n";
        }
    } else {
        cout << "You tie at " << playerHand.getHandValue() << "\n";
    }
}




