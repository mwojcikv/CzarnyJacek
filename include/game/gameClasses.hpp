#ifndef GAME_CLASSES_H_
#define GAME_CLASSES_H_

#include <string>
#include <utility>
#include <vector>
#include <algorithm>
#include <random>
#include <array>
#include <memory>
#include<cstdlib>

enum class Card_Color_t
{
    clover,
    pikes,
    hearts,
    diamonds
};

enum class Card_Value_t
{
    ace     = 11,
    two     = 2,
    three   = 3,
    four    = 4,
    five    = 5,
    six     = 6, 
    seven   = 7,
    eight   = 8, 
    nine    = 9,
    ten     = 10,
    jack,
    queen,
    king
};

const std::array<Card_Color_t, 4> all_colors = {Card_Color_t::clover, Card_Color_t::pikes, Card_Color_t::hearts, Card_Color_t::diamonds};
const std::array<Card_Value_t, 13> all_values = {Card_Value_t::ace, Card_Value_t::two, Card_Value_t::three, Card_Value_t::four, Card_Value_t::five, Card_Value_t::six, 
                                                Card_Value_t::seven, Card_Value_t::eight, Card_Value_t::nine, Card_Value_t::ten, Card_Value_t::jack, Card_Value_t::queen, Card_Value_t::king};

class Card
{
    public:
        using card_t = std::pair< Card_Color_t, Card_Value_t>;
    
        Card(Card_Color_t color = Card_Color_t::clover, Card_Value_t value = Card_Value_t::ace) : card_(color, value) {}

        Card(const Card&) = default;

        Card_Color_t getCardColor() const { return card_.first; }        
        Card_Value_t getCardValue() const { return card_.second; }
        card_t       getCard() const { return card_; }

        int getCardIntValue() const;
        
        ~Card() = default;
    private:
        card_t card_;
};

class DeckOfCards
{
    public:
    using card_t = std::pair< Card_Color_t, Card_Value_t>;

    DeckOfCards(std::size_t numOf52Decks = 1);

    DeckOfCards(const DeckOfCards&) = default;

    const Card* operator[](std::size_t n) const {return deck_[n].get();} 
    Card* operator[](std::size_t n)  {return deck_[n].get();}
    

    std::size_t numOfCards() const {return deck_.size();}
    const Card* getTopCard();
    void shuffleDeck();

    std::vector<std::unique_ptr<Card>>::iterator begin() {return deck_.begin();}
    std::vector<std::unique_ptr<Card>>::const_iterator begin() const {return deck_.cbegin();}
    std::vector<std::unique_ptr<Card>>::const_iterator cbegin() const {return deck_.cbegin();}
    
    std::vector<std::unique_ptr<Card>>::iterator end() {return deck_.end();}
    std::vector<std::unique_ptr<Card>>::const_iterator end() const {return deck_.cend();}
    std::vector<std::unique_ptr<Card>>::const_iterator cend() const {return deck_.cend();}


    ~DeckOfCards() = default;

    private:
        std::vector<std::unique_ptr<Card>> deck_;

};

#endif //GAME_CLASSES_H_