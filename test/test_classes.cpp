#include "gtest/gtest.h"

#include "game/gameClasses.hpp"
#include <iostream>

TEST(CardTest, constructor)
{
    Card card(Card_Color_t::hearts, Card_Value_t::ten);

    EXPECT_EQ(Card_Color_t::hearts, card.getCardColor());
    EXPECT_EQ(Card_Value_t::ten, card.getCardValue());
}

TEST(CardTest, copy_constructor)
{
    Card card1(Card_Color_t::hearts, Card_Value_t::ten);
    Card card2(Card_Color_t::hearts, Card_Value_t::ten);


    EXPECT_EQ(Card_Color_t::hearts, card2.getCardColor());
    EXPECT_EQ(Card_Value_t::ten, card2.getCardValue());
    EXPECT_EQ(card1.getCard(), card2.getCard());    
}

TEST(CardTest, getIntValue)
{
    Card card1(Card_Color_t::hearts, Card_Value_t::five);
    Card card2(Card_Color_t::hearts, Card_Value_t::ten);

    EXPECT_EQ(5, card1.getCardIntValue());
    EXPECT_EQ(10, card2.getCardIntValue());
}


TEST(DeckOfCardsTest, constructor)
{
    DeckOfCards basic;
    Card card(Card_Color_t::clover, Card_Value_t::ace);
    EXPECT_EQ(basic.numOfCards(), 52);
    EXPECT_EQ(basic[0] -> getCardColor(), card.getCardColor());
    EXPECT_EQ(basic[0] -> getCardValue(), card.getCardValue());

}


TEST(DeckOfCardsTest, shuffle)
{
    srand(11);

    DeckOfCards basic;
    Card card(Card_Color_t::clover, Card_Value_t::ace);
    EXPECT_EQ(basic.numOfCards(), 52);
    EXPECT_EQ(basic[0] -> getCardColor(), card.getCardColor());
    EXPECT_EQ(Card_Value_to_string(basic[0] -> getCardValue()), Card_Value_to_string(card.getCardValue()));

    basic.shuffleDeck();
    
    EXPECT_NE(basic[0] -> getCard(), card.getCard());


    Card_Color_t color_2 = basic[0] -> getCardColor();
    Card_Value_t value_2 = basic[0] -> getCardValue();
    Card card2(color_2, value_2);

    basic.shuffleDeck();
    EXPECT_NE(basic[0] -> getCard(), card2.getCard());
}



TEST(HandTest, printHand) {
    Hand hand;
    hand.add_card(std::make_unique<Card>(Card_Color_t::hearts, Card_Value_t::five));
    hand.add_card(std::make_unique<Card>(Card_Color_t::pikes, Card_Value_t::ten));

    Hand hand1;
    EXPECT_EQ(hand.printHand(), "5_of_hearts.png\n10_of_spades.png\n");
    EXPECT_EQ(hand1.printHand(), "");
}

TEST(test_game_classes_hand,  assigment_operator){
    Hand hand;
    hand.add_card(std::make_unique<Card>(Card_Color_t::hearts, Card_Value_t::five));
    hand.add_card(std::make_unique<Card>(Card_Color_t::pikes, Card_Value_t::ten));

    EXPECT_EQ(hand.get_card(1) -> getCardColor(),Card_Color_t::pikes);
    EXPECT_EQ(hand.get_card(1) -> getCardValue(), Card_Value_t::ten);

}

TEST(test_game_classes_hand,  handValue_test){

    Hand hand;
    hand.add_card(std::make_unique<Card>(Card_Color_t::hearts, Card_Value_t::five));
    hand.add_card(std::make_unique<Card>(Card_Color_t::pikes, Card_Value_t::ten));

    ASSERT_EQ(hand.handValue(), 15);

    hand.add_card(std::make_unique<Card>(Card_Color_t::hearts, Card_Value_t::ace));

    EXPECT_EQ(hand.handValue(), 16);
}

TEST(test_game_classes_hand,  add_card_test){
    Hand hand;

    hand.add_card(std::make_unique<Card>(Card_Color_t::hearts, Card_Value_t::nine));
    hand.add_card(std::make_unique<Card>(Card_Color_t::hearts, Card_Value_t::nine));
    hand.add_card(std::make_unique<Card>(Card_Color_t::hearts, Card_Value_t::nine));
    EXPECT_EQ(hand.get_card(1) -> getCardValue(), Card_Value_t::nine);
    EXPECT_EQ(hand.get_card(1) -> getCardColor(), Card_Color_t::hearts);
}

TEST(test_game_classes_hand, clear_hand){
    
    Hand hand;
    hand.add_card(std::make_unique<Card>(Card_Color_t::hearts, Card_Value_t::five));
    hand.add_card(std::make_unique<Card>(Card_Color_t::pikes, Card_Value_t::ten));

    EXPECT_EQ(hand.get_card(1) -> getCardValue(), Card_Value_t::ten);

    hand.clear_hand();

    EXPECT_EQ(hand.handValue(), 0);


}

TEST(DealerTest, dealInitialHand)
{
    Dealer deal;
    Gamer gam;
    DeckOfCards deck;

    deal.dealInitialHand(&gam, &deck);
    
    EXPECT_EQ(gam.numOfCards(), 2);
    EXPECT_EQ(deal.numOfCards(), 2);
    EXPECT_EQ(deck.numOfCards(), 48);
}


TEST(DealerTest, playTurn)
{
    Dealer deal;

    DeckOfCards deck;

    deck.shuffleDeck();
    
    deck.shuffleDeck();
    deal.playTurn(&deck);
    
    EXPECT_EQ(deal.numOfCards(), 1);

    int n_1 = 0;
    int n = 1;
    while(n_1 != n )
    {
        n_1 = n;
        deal.playTurn(&deck);
        n = deal.handValue(); 
    
    }

   deal.revealHand();
}

TEST(test_game_classes_deck, shuffle_deck){
    DeckOfCards deckOfCards;
    //UWAGA TODO test czasami się nie wychodzi bo karta moze się przetasować na dokładnie taką samą
    Card* card_ptr_1 = deckOfCards.get_Card(0);
    Card* card_ptr_2 = deckOfCards.get_Card(1);
    Card* card_ptr_3 = deckOfCards.get_Card(2);

    deckOfCards.shuffleDeck();
    Card* card_ptr_4 = deckOfCards.get_Card(0);
    Card* card_ptr_5 = deckOfCards.get_Card(1);
    Card* card_ptr_6 = deckOfCards.get_Card(2);
    EXPECT_NE(card_ptr_4->getCardIntValue(), card_ptr_1->getCardIntValue());
    EXPECT_NE(card_ptr_5->getCardIntValue(), card_ptr_2->getCardIntValue());
    EXPECT_NE(card_ptr_6->getCardIntValue(), card_ptr_3->getCardIntValue());
}
