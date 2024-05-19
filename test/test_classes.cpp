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
    EXPECT_EQ(basic[0].getCardColor(), card.getCardColor());
    EXPECT_EQ(basic[0].getCardValue(), card.getCardValue());

}


TEST(DeckOfCardsTest, shuffle)
{
    srand(11);

    DeckOfCards basic;
    Card card(Card_Color_t::clover, Card_Value_t::ace);
    EXPECT_EQ(basic.numOfCards(), 52);
    EXPECT_EQ(basic[0].getCardColor(), card.getCardColor());
    EXPECT_EQ(basic[0].getCardValue(), card.getCardValue());

    basic.shuffleDeck();
    
    EXPECT_NE(basic[0].getCard(), card.getCard());


    Card_Color_t color_2 = basic[0].getCardColor();
    Card_Value_t value_2 = basic[0].getCardValue();
    Card card2(color_2, value_2);

    basic.shuffleDeck();
    EXPECT_NE(basic[0].getCard(), card2.getCard());
}



TEST(HandTest, printHand) {
    Card card1(Card_Color_t::hearts, Card_Value_t::five);
    Card card2(Card_Color_t::pikes, Card_Value_t::ten);

    Hand hand({card1, card2});
    Hand hand1;
    EXPECT_EQ(hand.printHand(), "Five of Hearts\nTen of Pikes\n");
    EXPECT_EQ(hand1.printHand(), "");
}

TEST(test_game_classes_hand,  assigment_operator){
    Card card1(Card_Color_t::hearts, Card_Value_t::five);
    Card card2(Card_Color_t::pikes, Card_Value_t::ten);
    Card card3(Card_Color_t::hearts, Card_Value_t::nine);
    Hand hand({card1, card2});

    hand.set_card(card3, 1);

    EXPECT_EQ(hand.get_card(1).getCardColor(),Card_Color_t::hearts);
    EXPECT_EQ(hand.get_card(1).getCardValue(), Card_Value_t::nine);

}

//TODO napraw = operator dla karty...
//TEST(test_game_classes_hand,  equality_operator){
//    Card card1(Card_Color_t::hearts, Card_Value_t::five);
//    Card card2(Card_Color_t::pikes, Card_Value_t::ten);
//    Card card3(Card_Color_t::hearts, Card_Value_t::nine);
//    Hand hand({card1, card2});
//
//    hand.get_card(1) = card3;
//    EXPECT_EQ(hand.get_card(1).getCardColor(),Card_Color_t::hearts);
//    EXPECT_EQ(hand.get_card(1).getCardValue(), Card_Value_t::nine);
//}

TEST(test_game_classes_hand,  handValue_test){
    Card card1(Card_Color_t::hearts, Card_Value_t::five);
    Card card2(Card_Color_t::pikes, Card_Value_t::ten);
    Card card3(Card_Color_t::hearts, Card_Value_t::ace);

    Hand hand({card1, card2});

    ASSERT_EQ(hand.handValue(), 15);

    hand.add_card(card3);

    EXPECT_EQ(hand.handValue(), 16);
}

TEST(test_game_classes_hand,  add_card_test){
    Card card1(Card_Color_t::hearts, Card_Value_t::five);
    Card card2(Card_Color_t::pikes, Card_Value_t::ten);
    Card card3(Card_Color_t::hearts, Card_Value_t::nine);
    Hand hand({card1, card2});
    hand.add_card(card3);
    EXPECT_EQ(hand.get_card(2).getCardValue(), Card_Value_t::nine);
    EXPECT_EQ(hand.get_card(2).getCardColor(), Card_Color_t::hearts);
}

TEST(test_game_classes_hand, clear_hand){
    Card card1(Card_Color_t::hearts, Card_Value_t::five);
    Card card2(Card_Color_t::pikes, Card_Value_t::ten);

    Hand hand({card1, card2});

    EXPECT_EQ(hand.get_card(1).getCardValue(), Card_Value_t::ten);

    hand.clear_hand();

    EXPECT_EQ(hand.handValue(), 0);


}


// //TODO dopisz test
//TEST(DealerTest, dealInitialHand)
//{
//    Dealer deal;
//    Gamer gam;
//    DeckOfCards deck;
//
//    deal.dealInitialHand(gam, deck);
//
//    EXPECT_EQ(gam.numOfCards(), 2);
//    EXPECT_EQ(deal.numOfCards(), 2);
//    EXPECT_EQ(deck.numOfCards(), 48);
//}

