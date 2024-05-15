#include "game/gameClasses.hpp"
#include <sstream>
#include <iostream>
#include <ostream>

void swapping(Card& card1, Card& card2)
{
    Card& temp = card1;
    card1 = card2;
    card1 = temp;
}


constexpr Card& Card::operator=(const Card& other) {
    if (this != &other) { // Check for self-assignment
        card_ = other.getCard(); // Assign the card pair from the other Card object
    }
    return *this; // Return a reference to the modified object
}

Hand::Hand(std::vector<std::unique_ptr<Card>> list) : hand_(list)
    {
        value_ = 0;
        for(const auto& card : list)
        {
            if(card -> getCardValue() == Card_Value_t::ace)
            {
                ace_num += 1;
            }
            value_ += card -> getCardIntValue();
        }
    }



std::string Hand::printHand() const{
    std::ostringstream oss;
    for(const auto& card: hand_){
        oss << Card_Value_to_string( card -> getCardValue())<< " of "<< Card_Color_to_string(card -> getCardColor())<< "\n";
    }
    return oss.str();
}

int Hand::handValue() const{
    int result;
    for(const auto& card_ptr: hand_){
        result += int(card_ptr -> getCardValue());
    }
    if(result > 21){
        result -= 10*ace_num;
    }
    return result;
}

void Hand::add_card(std::unique_ptr<Card> card){
    hand_.push_back(std::move(card));
    if(card -> getCardValue() == Card_Value_t::ace){
        ++ace_num;
    }
    value_ += int(card -> getCardValue());
}



void DeckOfCards::getTopCard(Hand* hand)
{
    hand -> add_card(std::move(deck_.back()));
    deck_.pop_back();

}

void DeckOfCards::shuffleDeck(){

     std::random_shuffle(deck_.begin(), deck_.end());

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
        default:
            return "Error";
    }
}


void Dealer::dealInitialHand(Gamer* gamer, DeckOfCards* deck) {
    
    for(std::size_t i = 0; i < 2; i++)
    {
        deck -> getTopCard(this);
        deck -> getTopCard(gamer);
    }
}

void Dealer::playTurn(DeckOfCards& deck) {
    // Krupier dobiera karty dopóki suma punktów jego ręki jest mniejsza niż 17
    while (this -> handValue() < 17) {
            deck.getTopCard(this);
    }
}
void Dealer::revealHand() const {
    // Odsłonięcie kart krupiera
    std::cout << "Dealer's hand:\n";
    printHand();
}