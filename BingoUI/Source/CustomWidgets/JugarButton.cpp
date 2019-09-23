


#include <AssetsManager.hpp>
#include <CustomWidgets/CardUI.hpp>
#include <Config.hpp>
#include <Engine.hpp>
#include <BingoLevel.hpp>
#include "CustomWidgets/JugarButton.hpp"


JugarButton::JugarButton() : ButtonWidget(PLAY_BUTTON_TEXT,
                                          AssetsManager::Get<Texture>(
                                                  "botongrande01"),
                                          AssetsManager::Get<Texture>(
                                                  "botongrande02"))
{
    auto backgroundSize = AssetsManager::Get<Texture>("Fondo_Juego")->GetSDLRect();
    auto buttonBigNormalSize = AssetsManager::Get<Texture>("botongrande01")->GetSDLRect();
    SetPosition({backgroundSize.w - buttonBigNormalSize.w, backgroundSize.h - buttonBigNormalSize.h});
}


void JugarButton::Update()
{
    ButtonWidget::Update();

    Level& level = Engine::GetCurrentLevel();
    auto PlayerRef = dynamic_cast<BingoLevel&>(level).GetPlayer();
    SetEnabled(PlayerRef.CreditsLeft() >= PlayerRef.GetCards().size());

}

void JugarButton::Pressed()
{
    Level& level = Engine::GetCurrentLevel();
    auto& PlayerRef = dynamic_cast<BingoLevel&>(level).GetPlayer();
    auto& DrumUIRef = dynamic_cast<BingoLevel&>(level).GetDrumUI();
    auto cards = dynamic_cast<BingoLevel&>(level).GetCardsUI();

    // Remove cost of CardsUI
    if (!PlayerRef.TryRemoveCredits(PlayerRef.GetCards().size()))
        throw std::runtime_error("Play button can be pressed when not enough money to play");

    // Show extracted numbers
    auto latestBalls = DrumUIRef.ExtractNewBalls();
    for (CardUI* card: cards)
        card->SetExtractedNumbers(latestBalls);

    // Calculate prizes

}
