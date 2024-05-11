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
#include <iostream>

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

        constexpr Card& operator = (const Card&);

        
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

    const Card operator[](std::size_t n) const {return deck_[n];} 
    Card operator[](std::size_t n) {return deck_[n];} 
   
    std::size_t numOfCards() const {return deck_.size();}
    Card& getTopCard();

    void shuffleDeck();

    std::vector<Card>::iterator begin() {return deck_.begin();}
    std::vector<Card>::const_iterator begin() const {return deck_.cbegin();}
    std::vector<Card>::const_iterator cbegin() const {return deck_.cbegin();}
    
    std::vector<Card>::iterator end() {return deck_.end();}
    std::vector<Card>::const_iterator end() const {return deck_.cend();}
    std::vector<Card>::const_iterator cend() const {return deck_.cend();}


    ~DeckOfCards() = default;

    private:
        std::vector<Card> deck_;

};


class Hand{
public:
    //kontruktory

    Hand(std::vector<Card> list = {});
    
    //destruktor

    Hand& operator = (const Hand& hand) = default;//kopiujący operator przypisania

    //metody
    std::string printHand() const;//zwraca reke jako stringa

    int handValue() const;//zwraca wartosc kart na rece

    void add_card(Card& card);//dodawanie karty do reki

    std::size_t numOfCards() const {return hand_.size();}   // zwraca ilość kart w ręce

    //przeciazony operator []
    const Card operator [](std::size_t pos) const {return hand_[pos];} 
    Card operator [](std::size_t pos) {return hand_[pos];}


    //iteratry dla  kontenera
    std::vector<Card>::const_iterator cbegin() const { return hand_.cbegin(); }
    std::vector<Card>::const_iterator begin() const { return hand_.begin(); }
    std::vector<Card>::iterator begin() { return hand_.begin(); }
    std::vector<Card>::const_iterator cend() const { return hand_.cend(); }
    std::vector<Card>::const_iterator end() const { return hand_.end(); }
    std::vector<Card>::iterator end() { return hand_.end(); }
  
    virtual ~Hand() = default;

private:
    //konterner któy zawiera ręke gracza
    std::vector<Card> hand_;
    inline static int ace_num =0;
    int value_;

};

class Gamer : public Hand
{
    public:
        Gamer(std::vector<Card> list = {}) : Hand(list) {}
        Gamer(const Gamer&) = default;

       
        void takeCard(Hand& playerHand, Hand& GamerHand); // pociągnij kartę
        void passGame() const; // poddaj się

        ~Gamer() = default; 
    private: 

};

class Dealer : public Hand
{
    public:
        Dealer(std::vector<Card> list = {}) : Hand(list) {}

        Dealer(const Dealer&) = default;

        void dealInitialHand(Gamer& gamer, DeckOfCards& deck);
        void showFirstCard();
        void playTurn(DeckOfCards& deck); // Obsługa ruchu krupiera
        void revealHand() const; // Odsłonięcie kart krupiera

        bool isGameLost() { return (handValue() > 21);}

        bool isGameWon(int gamerValue) { return (21 >= handValue() && handValue()> gamerValue) || (gamerValue > 21 && handValue()<= 21);}

        bool isDraw(int gamerValue) { return (handValue() == gamerValue);}

        ~Dealer() = default; 

};




std::string Card_Value_to_string(const Card_Value_t& cardValue );

std::string Card_Color_to_string(const Card_Color_t& cardColor );

#endif //GAME_CLASSES_H_
