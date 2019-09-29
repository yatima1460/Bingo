


#include <AssetsManager.hpp>
#include <CustomWidgets/CardUI.hpp>
#include <Engine.hpp>
#include <BingoLevel.hpp>
#include <Prizes/DoubleLinePrize.hpp>
#include <cassert>
#include <Settings.hpp>
#include <PrizeSystem.hpp>
#include "CustomWidgets/JugarButton.hpp"


JugarButton::JugarButton() : ButtonWidget(Settings::get<std::string>("PLAY_BUTTON_TEXT"),
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
    SetEnabled(PlayerRef.creditsLeft() >= PlayerRef.getCards().size());

}

void JugarButton::Pressed()
{
    Level& level = Engine::GetCurrentLevel();

    auto& PlayerRef = dynamic_cast<BingoLevel&>(level).GetPlayer();
    auto& DrumUIRef = dynamic_cast<BingoLevel&>(level).GetDrumUI();
    auto cards = dynamic_cast<BingoLevel&>(level).GetCardsUI();

    // Remove cost of cards
    if (!PlayerRef.pay(static_cast<int>(PlayerRef.getCards().size())))
        throw std::runtime_error("Play button can be pressed when not enough money to play");

    // Update shown extracted numbers
    auto latestBalls = DrumUIRef.ExtractNewBalls();
    assert(!latestBalls.empty());
    for (CardUI* card: cards)
        card->SetExtractedNumbers(latestBalls);

    // Calculate prizes
    for (const std::shared_ptr<Card>& card: PlayerRef.getCards())
    {

        unsigned int prizeAmount = PrizeSystem::checkCard(*card, latestBalls);

        if (prizeAmount != 0)
        {
            PlayerRef.addCredits(prizeAmount);
            break;
        }


    }
}
