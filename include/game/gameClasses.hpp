#ifndef GAME_CLASSES_H_
#define GAME_CLASSES_H_

#include <string>
#include <utility>

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



class Card
{
    public:
        using card_t = std::pair< Card_Color_t, Card_Value_t>;
    
        Card(Card_Color_t color = Card_Color_t::clover, Card_Value_t value = Card_Value_t::ace) : card_(color, value) {}

        Card(const Card&) = default;

        Card_Color_t getCardColor() const { return card_.first; }        
        Card_Value_t getCardValue() const { return card_.second; }
        card_t       getCard() const { return card_; }

        ~Card() = default;
    private:
        card_t card_;
};

class DeckOfCards
{
    public:
    using card_t = std::pair< Card_Color_t, Card_Value_t>;

    DeckOfCards(std::size_t n = 52) : deck_(52) {} 

    DeckOfCards(const DeckOfCards&) = default;

    Card getTopCard();
    void shuffleDeck();


    ~DeckOfCards() = default;

    private:
        std::vector<card_t> deck_;

};

#endif //GAME_CLASSES_H_