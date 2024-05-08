
#ifndef GAMECLASSES_H_
#define GAMECLASSES_H_

#include <vector>
#include <string>
#include <utility>
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
    ace,     
    two,     
    three,   
    four,    
    five,    
    six,      
    seven,   
    eight,    
    nine,    
    ten,    
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


class Hand{
public:
    //kontruktory
    Hand(const Hand& ) = default; //kopiujący

    Hand(const std::vector<Card*>& list = {}): hand_(list);

    //destruktor
    ~Hand() = default;

    Hand& operator = (const Hand& hand){ return hand_};//kopiujący operator przypisania

    //metody
    std::string printHand() const;//zwraca reke jako stringa

    int handValue() const;//zwraca wartosc kart na rece

    void add_card(const Card& card);//dodawanie karty do reki
    void add_card(const Card* card_ptr);// dodawawanie karty do reki


    //przeciązony operator []
    Hand& operator [](std::size_t pos) {return hand_[pos]};//operator przypisania
    const Hand& operator [](std::size_t pos) const {return hand_[pos]}; //inspektor

    //iteratry dla  kontenera
    std::vector<Card*>::const_iterator cbegin() const { return hand_.cbegin(); }
    std::vector<Card*>::const_iterator begin() const { return hand_.begin(); }
    std::vector<Card*>::iterator begin() { return hand_.begin(); }
    std::vector<Card*>::const_iterator cend() const { return hand_.cend(); }
    std::vector<Card*>::const_iterator end() const { return hand_.end(); }
    std::vector<Card*>::iterator end() { return hand_.end(); }

private:
    //konterner któy zawiera ręke gracza
    //TODO zastanowic się nad rodzajem relacji miedzy klasami czy na pewno kompozycja
    std::vector<Card*> hand_;
    inline static int ace_num =0;
    int value_;

};





#endif //GAME_CLASSES_H_

