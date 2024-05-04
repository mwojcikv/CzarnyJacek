#include "game\gameClasses.hpp"
#include <sstream>
#include <iostream>

std::string Hand::printHand() const{
    std::ostringstream oss;
    for(const auto& card: hand_){
        oss<< card.getCardValue() << " "<< card.getCardColor<< "\n";
    }
    return oss.str();
}

std::size_t Hand::handValue() const{
    std::size_t wynik;
    for(const auto& card: hand_){
        wynik += card.getCardValue();
    }
    return wynik;
}
