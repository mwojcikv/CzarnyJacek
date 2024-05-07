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

std::size_t Hand::handValue() const{
    std::size_t wynik;
    for(const auto& card_ptr: hand_){
        wynik += card_ptr->getCardValue();
    }
    return wynik;
}

void Hand::add_card(const Card& card){
    hand_.push_back(&card);
}

void Hand::add_card(Card* card_ptr) {
    hand_.push_back(card_ptr);

}
