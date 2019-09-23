


#include <AssetsManager.hpp>
#include <CustomWidgets/CardUI.hpp>
#include <Config.hpp>
#include <BingoLevel.hpp>
#include <Engine.hpp>
#include "CustomWidgets/NumerosButton.hpp"


#define COBRAR_CHARGE 100


NumerosButton::NumerosButton() : ButtonWidget(
        CARDS_BUTTON_TEXT,
        AssetsManager::Get<Texture>(
                                                                                                                "botonpeque01"),
        AssetsManager::Get<Texture>(
                "botonpeque02"))
{

    auto background = AssetsManager::Get<Texture>("Fondo_Juego");
    auto backgroundSize = background->GetSDLRect();
    auto buttonBigNormal = AssetsManager::Get<Texture>("botongrande01");
    auto buttonBigNormalSize = buttonBigNormal->GetSDLRect();
    auto buttonSmallNormal = AssetsManager::Get<Texture>("botonpeque01");
    auto buttonSmallNormalSize = buttonSmallNormal->GetSDLRect();

    SetPosition({buttonBigNormalSize.w, backgroundSize.h - buttonSmallNormalSize.h});


}


void NumerosButton::Pressed()
{
    Level& level = Engine::GetCurrentLevel();
    auto& PlayerRef = dynamic_cast<BingoLevel&>(level).GetPlayer();
    auto cards = dynamic_cast<BingoLevel&>(level).GetCardsUI();

    PlayerRef.RerollCards();
    for (CardUI* card: cards)
    {
        card->SetExtractedNumbers(std::vector<unsigned int>());
    }
    //DrumUIRef.SetBalls(std::vector<unsigned int>());
}



//callback
//
