


#include <AssetsManager.hpp>
#include "CustomWidgets/MonedasButton.hpp"


MonedasButton::MonedasButton(Player& player) : ButtonWidget("Monedas", AssetsManager::Get<Texture>("botongrande01"),
                                                            AssetsManager::Get<Texture>("botongrande02")),
                                               player(player)
{

    auto background = AssetsManager::Get<Texture>("Fondo_Juego");
    auto backgroundSize = background->GetSDLRect();
    auto buttonBigNormal = AssetsManager::Get<Texture>("botongrande01");
    auto buttonBigNormalSize = buttonBigNormal->GetSDLRect();
    auto buttonSmallNormal = AssetsManager::Get<Texture>("botonpeque01");
    auto buttonSmallNormalSize = buttonSmallNormal->GetSDLRect();

    SetPosition({backgroundSize.w - buttonBigNormalSize.w - buttonSmallNormalSize.w,
                 backgroundSize.h - buttonSmallNormalSize.h});


}


void MonedasButton::Update()
{
    SetEnabled(player.CreditsLeft() != 0);

}

void MonedasButton::Pressed()
{
    player.Collect();
}

//callback
//