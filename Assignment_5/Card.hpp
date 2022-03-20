#pragma once

#include "std_lib_facilities.h"


enum class Suit {clubs, diamonds, hearts, spades};

enum class Rank {two=2, three, four, five, six, seven, eight, nine, ten, jack, queen, king, ace};

string suitToString(Suit someSuit);

string rankToString(Rank someRank);

class Card {
    Suit s;
    Rank r;
public:
    Card(Suit suit, Rank rank) : s{suit}, r{rank} {};
    string getSuit();
    string getRank();
    string toString();
    Rank getRankRank();
};