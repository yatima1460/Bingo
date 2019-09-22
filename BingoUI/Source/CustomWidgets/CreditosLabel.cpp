//
// Created by yatima1460 on 23/09/2019.
//

#include <Graphics.hpp>
#include <sstream>
#include "CustomWidgets/CreditosLabel.hpp"


CreditosLabel::CreditosLabel(Player& player) : player(player)
{


}


void CreditosLabel::Update()
{
    std::stringstream player_credits;
    player_credits << "$ " << player.CreditsLeft();
    std::string creditsString = player_credits.str();
    SDL_Rect size = Graphics::MeasureText(creditsString);
    SetPosition({static_cast<int>(1120 - size.w / 2), 20});
    SetText(creditsString);
}