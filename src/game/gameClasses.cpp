#include "game/gameClasses.hpp"
#include <sstream>
#include <iostream>
#include <ostream>
#include <chrono>
#include <random>
#include <algorithm>

std::string Hand::printHand() const{
    std::ostringstream oss;
    for(const auto& card: hand_){
        oss << Card_Value_to_string( card -> getCardValue())<< "_of_"<< Card_Color_to_string(card -> getCardColor())<<".png";
    }
    return oss.str();
}

std::string cardToString(const Card* card) {
    std::ostringstream oss;
    oss << Card_Value_to_string( card->getCardValue())<< "_of_"<< Card_Color_to_string(card->getCardColor())<<".png";
    return oss.str();
}

int Hand::handValue() const{
    int result = 0;

    for(const auto& card_ptr: hand_){
        result += int(card_ptr -> getCardIntValue());

    }
    if(result > 21){
        result -= 10*ace_num;
    }
    return result;
}

void Hand::add_card(std::unique_ptr<Card> card){
   
    if(card.get() -> getCardValue() == Card_Value_t::ace){
        ace_num ++;
    }

    value_ += int(card.get() -> getCardIntValue());
    hand_.emplace_back(std::move(card));

}


void Hand::clear_hand(){
    ace_num =0;
    hand_.clear();
    hand_.shrink_to_fit();
}


void DeckOfCards::getTopCard(Hand* hand)
{
    hand -> add_card(std::move(deck_.back()));
    deck_.pop_back();

}

void DeckOfCards::shuffleDeck()
{
    // Obtain a time-based seed
    unsigned seed = unsigned (std::chrono::system_clock::now().time_since_epoch().count());
    std::shuffle(deck_.begin(), deck_.end(), std::default_random_engine(seed));
}

DeckOfCards::DeckOfCards(std::size_t numOf52Decks)
{
    for(std::size_t i = 0; i < numOf52Decks ; i++)
    {
        for(const auto& c : all_colors)
        {
            for(const auto& v : all_values)
            {
                deck_.push_back(std::make_unique<Card>(c,v));
            }
        }
    }

}

int Card::getCardIntValue() const
{
    switch(card_.second)
    {
        case(Card_Value_t::ace): 
            return 11;
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
            return 10;
        case(Card_Value_t::queen): 
            return 10;
        case(Card_Value_t::king): 
            return 10;
        default: 
            return 0;
    }

}


std::string Card_Value_to_string(const Card_Value_t& cardValue )
{
    switch(cardValue) 
    {
        case Card_Value_t::ace:
            return "14";
        case Card_Value_t::two:
            return "2";
        case Card_Value_t::three:
            return "3";
        case Card_Value_t::four:
            return "4";
        case Card_Value_t::five:
            return "5";
        case Card_Value_t::six:
            return "6";
        case Card_Value_t::seven:
            return "7";
        case Card_Value_t::eight:
            return "8";
        case Card_Value_t::nine:
            return "9";
        case Card_Value_t::ten:
            return "10";
        case Card_Value_t::jack:
            return "11";
        case Card_Value_t::queen:
            return "12";
        case Card_Value_t::king:
            return "13";
        default:
            return "Unknown";
    }
}

std::string Card_Color_to_string(const Card_Color_t& cardColor ){
    switch (cardColor) {
        case Card_Color_t::pikes:
            return "spades";
        case Card_Color_t::hearts:
            return "hearts";
        case Card_Color_t::diamonds:
            return "diamonds";
        case Card_Color_t::clover:
            return "clubs";
        default:
            return "error";
    }
}


void Dealer::dealInitialHand(Gamer* gamer, DeckOfCards* deck) {
    
    for(std::size_t i = 0; i < 2; i++)
    {
        deck -> getTopCard(this);
        deck -> getTopCard(gamer);
    }
}

void Dealer::playTurn(DeckOfCards* deck) {
    // Krupier dobiera karty dopóki suma punktów jego ręki jest mniejsza niż 17
    if(this -> handValue() < 17)
    {
            deck -> getTopCard(this);
    }
}
void Dealer::revealHand() const {
    // Odsłonięcie kart krupiera
    std::cout << "Dealer's hand:\n";

    std::cout << this -> printHand();
}

