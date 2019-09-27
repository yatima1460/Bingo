
#include "Player.hpp"

#include <stdexcept>
#include <cassert>
#include <Settings.hpp>

unsigned int Player::CreditsLeft() const
{
    return Credits;
}

bool Player::TryRemoveCredits(const unsigned int Value)
{
    if (Value > Credits)
        return false;
    Credits -= Value;
    return true;
}

unsigned int Player::Collect()
{
    unsigned int win = Credits;
    Credits = 0;
    return win;
}

void Player::AddCredits(unsigned int Value)
{
    if (Value == 0)
    {
        throw std::invalid_argument("Trying to add 0 Credits to a PlayerRef!");
    }
    Credits += Value;
}

const std::vector<std::shared_ptr<Card>>& Player::GetCards() const
{
    return Cards;
}

Player::Player() : Credits(0)
{


    //Cards = std::vector<std::shared_ptr<Card>>(CARTON_NUMBER);


}

void
Player::changeCards()
{

    const auto n = Settings::get<unsigned int>("cards_number");
    const auto width = Settings::get<unsigned int>("card_width");
    const auto height = Settings::get<unsigned int>("card_height");
    const auto maxN = Settings::get<unsigned int>("drum_size");
    Cards.clear();
    for (size_t i = 0; i < n; i++)
        Cards.push_back(std::make_shared<Card>(width, height, maxN));
    /*for (auto& card : Cards)
    {
        assert(card != nullptr);




        //auto newCard = new Card(CardInternal->Width, CardInternal->Height, CardInternal->MaxNumber);

        //delete CardInternal;

        //CardInternal = newCard;

        card->ReRoll();
    }*/

}
