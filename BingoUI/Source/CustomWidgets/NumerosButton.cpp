


#include <AssetsManager.hpp>
#include <CustomWidgets/CardUI.hpp>
#include <Config.hpp>
#include "CustomWidgets/NumerosButton.hpp"


#define COBRAR_CHARGE 100


NumerosButton::NumerosButton(Player& player, std::vector<CardUI*> cards, DrumUI& drumUI) : ButtonWidget(
        CARDS_BUTTON_TEXT,
        AssetsManager::Get<Texture>(
                                                                                                                "botonpeque01"),
        AssetsManager::Get<Texture>(
                                                                                                                "botonpeque02")),
                                                                                           player(player), cards(cards),
                                                                                           drumUI(drumUI)
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
    player.RerollCards();
    for (CardUI* card: cards)
    {
        card->SetExtractedNumbers(std::vector<unsigned int>());
    }
    drumUI.SetBalls(std::vector<unsigned int>());
}



//callback
//
