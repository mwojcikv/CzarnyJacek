#ifndef GAMECLASSES_H_
#define GAMECLASSES_H_

#include <vector>
#include <string>

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



#endif //GAMECLASSES_H_


