#include "game\gameClasses.hpp"
#include <sstream>
#include <iostream>
#include <ostream>


Hand::Hand(const std::vector<Card*>& list): hand_(list){
    {
        for(const auto& card_ptr: list){
            if(card_ptr->getCardIntValue() == 1){
                ace_num += 1;
            }
        }
        int result = this->value_;
        value_ = result;
    }
};


std::string Hand::printHand() const{
    std::ostringstream oss;
    for(const auto& card_ptr: hand_){
        oss<< Card_Value_to_string( card_ptr->getCardValue())<< " of "<< Card_Color_to_string(card_ptr->getCardColor())<< "\n";
    }
    return oss.str();
}

int Hand::handValue() const{
    int result;
    for(const auto& card_ptr: hand_){
        result += int(card_ptr->getCardValue());
    }
    if(result > 21){
        result -= 10*ace_num;
    }
    return result;
}

void Hand::add_card(Card& card){
    hand_.push_back(&card);
    if(card.getCardValue() == Card_Value_t::ace){
        ++ace_num;
    }
    value_ += int(card.getCardValue());
}

void Hand::add_card(Card* card_ptr) {
    hand_.push_back(card_ptr);
    if(card_ptr->getCardValue() == Card_Value_t::ace){
        ++ace_num;
    }
    value_ += int(card_ptr->getCardValue());
}


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


std::string Card_Value_to_string(const Card_Value_t& cardValue ){
    switch(cardValue) {
        case Card_Value_t::ace:
            return "Ace";
        case Card_Value_t::two:
            return "Two";
        case Card_Value_t::three:
            return "Three";
        case Card_Value_t::four:
            return "Four";
        case Card_Value_t::five:
            return "Five";
        case Card_Value_t::six:
            return "Six";
        case Card_Value_t::seven:
            return "Seven";
        case Card_Value_t::eight:
            return "Eight";
        case Card_Value_t::nine:
            return "Nine";
        case Card_Value_t::ten:
            return "Ten";
        case Card_Value_t::jack:
            return "Jack";
        case Card_Value_t::queen:
            return "Queen";
        case Card_Value_t::king:
            return "King";
        default:
            return "Unknown";
    }
}

std::string Card_Color_to_string(const Card_Color_t& cardColor ){
    switch (cardColor) {
        case Card_Color_t::pikes:
            return "Pikes";
        case Card_Color_t::hearts:
            return "Hearts";
        case Card_Color_t::diamonds:
            return "Diamonds";
        case Card_Color_t::clover:
            return "Clover";
    }
}
