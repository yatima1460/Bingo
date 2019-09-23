


#include <AssetsManager.hpp>
#include <CustomWidgets/CardUI.hpp>
#include <Config.hpp>
#include <Engine.hpp>
#include <BingoLevel.hpp>
#include <Prizes/LinePrize.hpp>
#include <Prizes/DoubleLinePrize.hpp>
#include <Prizes/BingoPrize.hpp>
#include <cassert>
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

    // Remove cost of cards
    if (!PlayerRef.TryRemoveCredits(PlayerRef.GetCards().size()))
        throw std::runtime_error("Play button can be pressed when not enough money to play");

    // Update shown extracted numbers
    auto latestBalls = DrumUIRef.ExtractNewBalls();
    assert(!latestBalls.empty());
    for (CardUI* card: cards)
        card->SetExtractedNumbers(latestBalls);

    // Calculate prizes
    Prize* prizes[] = {new BingoPrize(BINGO_PRIZE), new DoubleLinePrize(DOUBLELINE_PRIZE), new LinePrize(LINE_PRIZE)};
    for (const std::shared_ptr<Card>& card: PlayerRef.GetCards())
    {

        for (Prize* p : prizes)
        {
            assert(card != nullptr);
            auto prizeAmount = p->Check(*card, latestBalls);

            if (prizeAmount != 0)
            {
                PlayerRef.AddCredits(prizeAmount);

                // A prize overrides the lower value ones
                break;
            }

        }

    }

    // TODO: destructor
    for (auto& prize : prizes)
        delete prize;
}
