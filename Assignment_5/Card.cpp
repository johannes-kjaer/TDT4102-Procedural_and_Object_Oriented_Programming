#include "Card.hpp"

string suitToString(Suit someSuit) {
    map<Suit,string> mapSuitString{
        {Suit::hearts,"Hearts"},
        {Suit::spades,"Spades"},
        {Suit::diamonds,"Diamonds"},
        {Suit::clubs,"Clubs"}
    };
    return mapSuitString[someSuit];
}


string rankToString(Rank someRank) {
    map<Rank,string> mapRankString{
        {Rank::two,     "Two"},
        {Rank::three,   "Three"},
        {Rank::four,    "Four"},
        {Rank::five,    "Five"},
        {Rank::six,     "Six"},
        {Rank::seven,   "Seven"},
        {Rank::eight,   "Eight"},
        {Rank::nine,    "Nine"},
        {Rank::ten,     "Ten"},
        {Rank::jack,    "Jack"},
        {Rank::queen,   "Queen"},
        {Rank::king,    "King"},
        {Rank::ace,     "Ace"}
    };
    return mapRankString[someRank];
}

// Mer tydelig for brukere?

string Card::getSuit() {
    return suitToString(s);
}
string Card::getRank() {
    return rankToString(r);
}
string Card::toString() {
    return rankToString(r) + " of " + suitToString(s);
}
Rank Card::getRankRank() {
    return r;
}
