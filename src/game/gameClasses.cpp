#include "game\gameClasses.hpp"
#include <sstream>
#include <iostream>

std::string Hand::printHand() const{
    std::ostringstream oss;
    for(const auto& card_ptr: hand_){
        oss<< card_ptr->getCardValue() << " "<< card_ptr->getCardColor<< "\n";
    }
    return oss.str();
}

Hand::Hand(const std::vector<Card*>& list = {}){
    for(const auto& card_ptr: list){
        if(card_ptr->getCardIntValue == 1){
            ace_num += 1;
        }
    }
    int wynik = this->value_;
    value_ = wynik;

}

int Hand::handValue() const{
    int wynik;
    for(const auto& card_ptr: hand_){
        wynik += card_ptr->getCardValue();
    }
    if(wynik > 21){
        wynik -= 10*ace_num;
    }
    
    return wynik;
}

void Hand::add_card(const Card& card){
    hand_.push_back(&card);
    if(card.getCardValue == 1){
        ++ace_num;
        value_ += 1;
    } else{
        value_ += card.getCardValue;
    }
}

void Hand::add_card(const Card* card_ptr) {
    hand_.push_back(card_ptr);
    if(card_ptr->getCardValue == 1){
        ++ace_num;
        value_ += 1;
    } else{
        value_ += card_ptr->getCardValue;
    }
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

void Dealer::dealInitialHand(Hand& playerHand, Hand& dealerHand) {
    // Rozdaj dwie karty graczowi i jedną krupierowi (pierwsza karta krupiera zakryta)
    playerHand.add_card(deck_.getTopCard());
    dealerHand.add_card(deck_.getTopCard());
    playerHand.add_card(deck_.getTopCard());
    dealerHand.add_card(deck_.getTopCard());
}

void Dealer::playTurn(Hand& playerHand, Hand& dealerHand) {
    // Krupier dobiera karty dopóki suma punktów jego ręki jest mniejsza niż 17
    while (dealerHand.handValue() < 17) {
        dealerHand.add_card(deck_.getTopCard());
    }
}

void Dealer::revealHand() const {
    // Odsłonięcie kart krupiera
    std::cout << "Dealer's hand:\n";
    for (auto card : deck_) {
        std::cout << "Color: " << static_cast<int>(card->getCardColor()) << ", Value: " << static_cast<int>(card->getCardValue()) << "\n";
    }
}