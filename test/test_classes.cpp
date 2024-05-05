#include "gtest/gtest.h"

#include "game/gameClasses.hpp"

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

TEST(DeckOfCardsTest, constructor)
{
    DeckOfCards basic;

    EXPECT_EQ(basic.numOfCards(), 52);
}

