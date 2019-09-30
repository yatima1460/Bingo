
#include <Settings.hpp>
#include <Drum.hpp>
#include "gtest/gtest.h"


TEST(DrumTest, ZeroSizeAtCreation)
{
    ASSERT_THROW(Drum(0), std::invalid_argument);
}


TEST(DrumTest, BallsLeft)
{
    Drum drum(1000);
    EXPECT_EQ(drum.ballsLeft(), 1000);
    auto extracted = drum.extract(10);
    EXPECT_EQ(drum.ballsLeft(), 990);
    EXPECT_EQ(extracted.size(), 10);
}

TEST(DrumTest, AllNumbersInRange)
{


    for (int j = 0; j < 1000; j++)
    {
        Drum drum(1000);
        auto extracted = drum.extract(10);
        for (auto i: extracted)
        {
            EXPECT_GE(i, 1);
            EXPECT_LE(i, drum.NUMBER_OF_BALLS_AT_CREATION);
        }
    }

}


TEST(DrumTest, AllNumbersAreDifferent)
{
    const size_t testN = 1000;

    for (size_t j = 0; j < testN; j++)
    {
        Drum d(testN);
        std::vector<unsigned int> v(testN + 1);

        for (auto i : d.extract(j))
        {
            v[i]++;
        }

        for (auto i : v)
        {
            EXPECT_GE(i, 0);
            EXPECT_LE(i, 1);
        }
    }
}

