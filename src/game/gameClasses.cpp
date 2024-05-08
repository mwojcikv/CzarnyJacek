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
