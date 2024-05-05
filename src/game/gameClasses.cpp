#include "game/gameClasses.hpp"

Card DeckOfCards::getTopCard()
{
    Card lastCard = deck_.back();
    deck_.pop_back();
    return lastCard;
}

void DeckOfCards::shuffleDeck(){
    std::random_device rd;
    std::shuffle(deck_.begin(), deck_.end(), rd);
}
