#include "gtest/gtest.h"
#include "PrizeSystem.hpp"

TEST(PrizeSystemTest, NotLoadedDefaultValues)
{
    PrizeSystem::clear();
    EXPECT_EQ(PrizeSystem::toString().empty(), true);
    EXPECT_EQ(PrizeSystem::getBingoValue(), 0);
    EXPECT_EQ(PrizeSystem::getPrizes().empty(), true);
}


TEST(PrizeSystemTest, toStringWhenBingo)
{
    PrizeSystem::clear();
    PrizeSystem::setBingo(100);
    EXPECT_EQ(PrizeSystem::toString(), "B100");
    EXPECT_EQ(PrizeSystem::getBingoValue(), 100);
    PrizeSystem::setBingo(0);
    EXPECT_EQ(PrizeSystem::toString().empty(), true);
    EXPECT_EQ(PrizeSystem::getBingoValue(), 0);
}


TEST(PrizeSystemTest, PrizeZeroWhenNoPrizesRegistered)
{
    PrizeSystem::clear();
    for (int i = 0; i < 100; i++)
    {
        Card c(5, 3, 60);
        const auto prize = PrizeSystem::checkCard(c, c.NUMBERS);
        EXPECT_EQ(prize, 0);
    }


}


TEST(PrizeSystemTest, BingoPrize)
{
    PrizeSystem::clear();
    PrizeSystem::setBingo(1234);
    for (int i = 0; i < 100; i++)
    {
        Card c(5, 3, 60);
        const auto prize = PrizeSystem::checkCard(c, c.NUMBERS);
        EXPECT_EQ(prize, PrizeSystem::getBingoValue());
    }

}


TEST(PrizeSystemTest, SingleLinePrize)
{
    PrizeSystem::clear();
    EXPECT_EQ(PrizeSystem::addPrize("H1V0C8"), true);
    EXPECT_EQ(PrizeSystem::getPrizes().size(), 1);
    for (int i = 0; i < 100; i++)
    {
        Card c(10, 1, 100);
        const auto prize = PrizeSystem::checkCard(c, c.NUMBERS);
        EXPECT_EQ(prize, c.HEIGHT * 8);
    }
    for (int i = 0; i < 100; i++)
    {
        Card c(1, 10, 100);
        const auto prize = PrizeSystem::checkCard(c, c.NUMBERS);
        EXPECT_EQ(prize, c.HEIGHT * 8);
    }
    for (int i = 0; i < 100; i++)
    {
        Card c(5, 3, 100);
        const auto prize = PrizeSystem::checkCard(c, c.NUMBERS);
        EXPECT_EQ(prize, c.HEIGHT * 8);
    }
}


TEST(PrizeSystemTest, DoubleLinePrize)
{
    PrizeSystem::clear();
    EXPECT_EQ(PrizeSystem::addPrize("H2V0C150"), true);
    EXPECT_EQ(PrizeSystem::getPrizes().size(), 1);
    for (int i = 0; i < 100; i++)
    {
        Card c(10, 1, 100);
        const auto prize = PrizeSystem::checkCard(c, c.NUMBERS);
        EXPECT_EQ(prize, 0);
    }
    for (int i = 0; i < 100; i++)
    {
        Card c(1, 10, 100);
        const auto prize = PrizeSystem::checkCard(c, c.NUMBERS);
        EXPECT_EQ(prize, c.HEIGHT * 150);
    }
    for (int i = 0; i < 100; i++)
    {
        Card c(5, 3, 100);
        const auto prize = PrizeSystem::checkCard(c, c.NUMBERS);
        EXPECT_EQ(prize, c.HEIGHT * 150);
    }
}




