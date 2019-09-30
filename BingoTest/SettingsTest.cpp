#include <Player.hpp>
#include <Settings.hpp>
#include "gtest/gtest.h"


TEST(SettingsTest, GetWithInvalidKey)
{
    EXPECT_THROW(Settings::get<int>(std::string()), std::invalid_argument);
    EXPECT_THROW(Settings::get<std::string>(std::string()), std::invalid_argument);
    EXPECT_THROW(Settings::get<int>(""), std::invalid_argument);
    EXPECT_THROW(Settings::get<std::string>(""), std::invalid_argument);
}

TEST(SettingsTest, SetWithInvalidKey)
{
    EXPECT_THROW(Settings::set<int>(std::string(), 1234), std::invalid_argument);
    EXPECT_THROW(Settings::set<std::string>(std::string(), "1234"), std::invalid_argument);
    EXPECT_THROW(Settings::set<int>("", 1234), std::invalid_argument);
    EXPECT_THROW(Settings::set<std::string>("", "1234"), std::invalid_argument);
}

TEST(SettingsTest, SetAndGetSameKey)
{
    Settings::set<int>("test", 83721897);
    EXPECT_EQ(Settings::get<int>("test"), 83721897);
}

TEST(SettingsTest, LoadFromFile)
{
    EXPECT_EQ(Settings::load(), true);
}

TEST(SettingsTest, FileContentsAreMappedCorrectly)
{
    EXPECT_EQ(Settings::get<int>("card_height"), 3);
    EXPECT_EQ(Settings::get<std::string>("prizes"), "H1V0C8,H2V0C150,B1500");
}

