
#include "Player.hpp"

#include <stdexcept>
#include <Settings.hpp>

unsigned int Player::creditsLeft() const
{
    return credits;
}

bool Player::pay(const unsigned int value)
{
    if (value > credits)
        return false;
    credits -= value;
    return true;
}

unsigned int Player::collect()
{
    if (credits == 0)
        throw std::invalid_argument("Trying to collect credits");
    unsigned int win = credits;
    credits = 0;
    return win;
}

void Player::addCredits(unsigned int value)
{
    if (value == 0)
        throw std::invalid_argument("Trying to add 0 credits to a PlayerRef!");
    credits += value;
}

const std::vector<std::shared_ptr<Card>>& Player::getCards() const
{
    return cards;
}

Player::Player() : credits(0)
{


    //cards = std::vector<std::shared_ptr<Card>>(CARTON_NUMBER);


}

void
Player::changeCards()
{

    const auto n = Settings::get<unsigned int>("cards_number");
    const auto width = Settings::get<unsigned int>("card_width");
    const auto height = Settings::get<unsigned int>("card_height");
    const auto maxN = Settings::get<unsigned int>("drum_size");
    cards.clear();
    for (size_t i = 0; i < n; i++)
        cards.push_back(std::make_shared<Card>(width, height, maxN));
    /*for (auto& card : cards)
    {
        assert(card != nullptr);




        //auto newCard = new Card(CardInternal->WIDTH, CardInternal->HEIGHT, CardInternal->MAX_NUMBER);

        //delete CardInternal;

        //CardInternal = newCard;

        card->ReRoll();
    }*/

}
