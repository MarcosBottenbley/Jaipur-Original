#include "Market.h"
#include "Game.h"
#include "Deck.h"

Market::Market(Game* g) {
    parent = g;
    for(int i = 2; i <= 4; i++)
    {
        mktCards[i] = new Card("Camel");
    }
}

Card* Market::getCard(int index) {
        return mktCards[index];
}

Card* Market::takeCard(int index) {
        Card* tempCard = mktCards[index];
        mktCards[index] = (parent->deck)->getCard();
        return tempCard;
}

Card* Market::swapCard(int index, Card* card) {
        Card* tempCard = mktCards[index];
        mktCards[index] = card;
        return tempCard;
}

void Market::addCard(int index, Card* card) {
        mktCards[index] = card;
}
