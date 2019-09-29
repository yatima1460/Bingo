#include <Graphics.hpp>
#include <sstream>
#include <BingoLevel.hpp>
#include <Engine.hpp>
#include "CustomWidgets/CreditosLabel.hpp"


void CreditosLabel::Update()
{
    Level& level = Engine::GetCurrentLevel();
    auto PlayerRef = dynamic_cast<BingoLevel&>(level).GetPlayer();

    std::stringstream player_credits;
    player_credits << "$ " << PlayerRef.creditsLeft();
    std::string creditsString = player_credits.str();
    SDL_Rect size = Graphics::MeasureText(creditsString);
    SetPosition({1120 - size.w / 2, 20});
    SetText(creditsString);
}