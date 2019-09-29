


#include <AssetsManager.hpp>
#include <CustomWidgets/CardUI.hpp>
#include <Config.hpp.old>
#include <BingoLevel.hpp>
#include <Engine.hpp>
#include <cassert>
#include <Settings.hpp>
#include "CustomWidgets/NumerosButton.hpp"


#define COBRAR_CHARGE 100


NumerosButton::NumerosButton() : ButtonWidget(
        Settings::get<std::string>("CARDS_BUTTON_TEXT"),
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
    auto cardsUI = dynamic_cast<BingoLevel&>(level).GetCardsUI();
    auto& DrumUIRef = dynamic_cast<BingoLevel&>(level).GetDrumUI();

    PlayerRef.changeCards(/*CARTON_NUMBER, CARTON_WIDTH, CARTON_HEIGHT, DRUM_SIZE*/);

    auto cards = PlayerRef.getCards();
    for (size_t i = 0; i < cards.size(); i++)
    {
        assert(cardsUI[i] != nullptr);
        cardsUI[i]->ChangeCard(cards[i]);
        cardsUI[i]->SetExtractedNumbers(std::vector<unsigned int>());
    }

    DrumUIRef.Clear();
    //DrumUIRef.SetBalls(std::vector<unsigned int>());
}



//callback
//
