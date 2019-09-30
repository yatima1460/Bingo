#include <Player.hpp>
#include <Settings.hpp>
#include "gtest/gtest.h"

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

