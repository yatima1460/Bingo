


#include <AssetsManager.hpp>
#include <CustomWidgets/CardUI.hpp>
#include "CustomWidgets/JugarButton.hpp"


JugarButton::JugarButton(Game& game, std::vector<CardUI*> cards, DrumUI& drumUI) : ButtonWidget("JUGAR",
                                                                                                AssetsManager::Get<Texture>(
                                                                                                        "botongrande01"),
                                                                                                AssetsManager::Get<Texture>(
                                                                                                        "botongrande02")),
                                                                                   game(game), cards(cards),
                                                                                   drumUI(drumUI)
{

    auto background = AssetsManager::Get<Texture>("Fondo_Juego");
    auto backgroundSize = background->GetSDLRect();
    auto buttonBigNormal = AssetsManager::Get<Texture>("botongrande01");
    auto buttonBigNormalSize = buttonBigNormal->GetSDLRect();
    auto buttonSmallNormal = AssetsManager::Get<Texture>("botonpeque01");
    auto buttonSmallNormalSize = buttonSmallNormal->GetSDLRect();
    SetPosition({backgroundSize.w - buttonBigNormalSize.w, backgroundSize.h - buttonBigNormalSize.h});


}


void JugarButton::Update()
{
    ButtonWidget::Update();

    //SetEnabled(player.CreditsLeft() > game.GetCardsCount());

}

void JugarButton::Pressed()
{
    game.PlayOneGame();
    auto latestBalls = game.ExtractedBalls();
    drumUI.SetBalls(latestBalls);
    for (CardUI* card: cards)
    {
        card->SetExtractedNumbers(latestBalls);
    }
}

//callback
//