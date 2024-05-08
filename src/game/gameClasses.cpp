#include "game/gameClasses.hpp"

const Card* DeckOfCards::getTopCard()
{
    const Card* lastCard = (deck_.back()).get();
    deck_.pop_back();
    return lastCard;
}

void DeckOfCards::shuffleDeck(){
    std::random_device rd;
    std::shuffle(deck_.begin(), deck_.end(), rd);
}

DeckOfCards::DeckOfCards(std::size_t numOf52Decks)
{
    for(std::size_t i = 0; i < numOf52Decks ; i++)
    {
        for(const auto& c : all_colors)
        {
            for(const auto& v : all_values)
            {
                deck_.push_back(std::make_unique<Card>(c, v));
            }
        }
    }

}

int Card::getCardIntValue() const
{
    switch(card_.second)
    {
        case(Card_Value_t::ace): 
            return 1;
        case(Card_Value_t::two): 
            return 2;
        case(Card_Value_t::three): 
            return 3;
        case(Card_Value_t::four): 
            return 4;
        case(Card_Value_t::five): 
            return 5; 
        case(Card_Value_t::six): 
            return 6;
        case(Card_Value_t::seven): 
            return 7;
        case(Card_Value_t::eight): 
            return 8;
        case(Card_Value_t::nine): 
            return 9;
        case(Card_Value_t::ten): 
            return 10;
        case(Card_Value_t::jack):
            return 2;
        case(Card_Value_t::queen): 
            return 3;
        case(Card_Value_t::king): 
            return 4;
        default: 
            return 0;
    }

}