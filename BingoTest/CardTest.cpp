
#include <Settings.hpp>
#include <Card.hpp>
#include "gtest/gtest.h"


TEST(CardTest, CardCreationWithInvalidValues)
{
    EXPECT_THROW(Card(0, 0, 0), std::invalid_argument);
    EXPECT_THROW(Card(0, 0, 1), std::invalid_argument);
    EXPECT_THROW(Card(0, 1, 0), std::invalid_argument);
    EXPECT_THROW(Card(0, 1, 1), std::invalid_argument);
    EXPECT_THROW(Card(1, 0, 0), std::invalid_argument);
    EXPECT_THROW(Card(1, 0, 1), std::invalid_argument);
    EXPECT_THROW(Card(1, 1, 0), std::invalid_argument);
    EXPECT_NO_THROW(Card(1, 1, 1));
}

TEST(CardTest, BigCardCreation)
{
    for (int x = 1; x < 50; x++)
    {
        for (int y = 1; y < 50; y++)
        {
            Card c(x, y, x * y);
            EXPECT_EQ(c.MAX_NUMBER, x * y);
            EXPECT_EQ(c.NUMBERS.size(), x * y);
        }
    }
}

TEST(CardTest, CardValuesRangeMinAndMax)
{
    for (int x = 1; x < 10; x++)
    {
        for (int y = 1; y < 10; y++)
        {
            Card c(x, y, x * y);

            auto maxit = *std::max_element(std::begin(c.NUMBERS), std::end(c.NUMBERS));
            auto minit = *std::min_element(std::begin(c.NUMBERS), std::end(c.NUMBERS));

            EXPECT_GE(minit, 1);
            EXPECT_LE(maxit, x * y);
        }
    }
}


