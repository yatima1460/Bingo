#include <Player.hpp>
#include <Settings.hpp>
#include "gtest/gtest.h"


/*
// Simple test, does not use gmock
TEST(Dummy, foobar)
{
    EXPECT_EQ(1, 1);
}*/


/*// Real class we want to mock
class TeaBreak
{
public:
    virtual ~TeaBreak() {}

    // Return minutes taken to make the drinks
    int morningTea()
    {
        return makeCoffee(true,  1) +
               makeCoffee(false, 0.5) +
               makeHerbalTea();
    }

private:
    virtual int makeCoffee(bool milk, double sugars) = 0;
    virtual int makeHerbalTea() = 0;
};

// Mock class
class MockTeaBreak : public TeaBreak
{
public:
    MOCK_METHOD2(makeCoffee,    int(bool milk, double sugars));
    MOCK_METHOD0(makeHerbalTea, int());
};


using ::testing::Return;
using ::testing::_;*/

/*// Mocked test
TEST(TeaBreakTest, MorningTea)
{
    Player player;

    EXPECT_CALL(player, pay(10));

   *//* MockTeaBreak  teaBreak;
    EXPECT_CALL(teaBreak, makeCoffee(_,_))
        .WillOnce(Return(2))
        .WillOnce(Return(1));
    EXPECT_CALL(teaBreak, makeHerbalTea())
        .WillOnce(Return(3));

    EXPECT_LE(teaBreak.morningTea(), 6);*//*
}*/

/*class PlayerTest : public ::testing::Test {
protected:

    Player player;

    PlayerTest()
    {

    };
};*/

//region PlayerTest
TEST(PlayerTest, PayZero)
{
    Player player;
    EXPECT_EQ(player.pay(0), true);
}

TEST(PlayerTest, PayWhenNoCredits)
{
    Player player;
    EXPECT_EQ(player.pay(1), false);
}

TEST(PlayerTest, PayWithCredits)
{
    Player player;
    player.addCredits(10);
    EXPECT_EQ(player.pay(10), true);
    EXPECT_EQ(player.pay(10), false);
    EXPECT_EQ(player.pay(0), true);
}

TEST(PlayerTest, AddCredits)
{
    Player player;
    EXPECT_EQ(player.creditsLeft(), 0);
    player.addCredits(10);
    EXPECT_EQ(player.creditsLeft(), 10);
}

TEST(PlayerTest, CardInitializationOK)
{
    Player player;
    auto currentCards = player.getCards();
    EXPECT_EQ(currentCards.size(), 0);
    Settings::set("cards_number", 30);
    Settings::set("card_width", 5);
    Settings::set("card_height", 3);
    Settings::set("drum_size", 60);
    player.changeCards();
    currentCards = player.getCards();
    EXPECT_NE(currentCards.size(), 0);
    for (auto card: currentCards)
        EXPECT_NE(card, nullptr);

    /*
    EXPECT_NE(card->NUMBERS.size(),0);
   EXPECT_NE(card->HEIGHT, 0);
    EXPECT_NE(card->WIDTH, 0);
    EXPECT_NE(card->MAX_NUMBER, 0);
    EXPECT_GE(card->MAX_NUMBER,card->WIDTH*card->HEIGHT);*/

}

TEST(PlayerTest, ChangeCards)
{
    Player player;
    Settings::set("cards_number", 30);
    Settings::set("card_width", 5);
    Settings::set("card_height", 3);
    Settings::set("drum_size", 60);
    player.changeCards();
    auto oldCards = player.getCards();
    player.changeCards();
    EXPECT_EQ(oldCards.size(), player.getCards().size());
    EXPECT_EQ(oldCards != player.getCards(), true);
}

TEST(PlayerTest, Collect)
{
    Player player;
    const auto toCollect = 10;
    player.addCredits(toCollect);
    const auto collected = player.collect();
    EXPECT_EQ(player.creditsLeft(), 0);
    EXPECT_EQ(collected, toCollect);
}
//endregion PlayerTest

