


#include <AssetsManager.hpp>
#include "CustomWidgets/CobrarButton.hpp"


#define COBRAR_CHARGE 100


CobrarButton::CobrarButton(Player& player) : ButtonWidget("Cobrar", AssetsManager::Get<Texture>("botongrande01"),
                                                          AssetsManager::Get<Texture>("botongrande02")),
                                             player(player)
{

    auto background = AssetsManager::Get<Texture>("Fondo_Juego");
    auto backgroundSize = background->GetSDLRect();
    auto buttonBigNormal = AssetsManager::Get<Texture>("botongrande01");
    auto buttonBigNormalSize = buttonBigNormal->GetSDLRect();
    auto buttonSmallNormal = AssetsManager::Get<Texture>("botonpeque01");
    auto buttonSmallNormalSize = buttonSmallNormal->GetSDLRect();

    SetPosition({0, backgroundSize.h - buttonBigNormalSize.h});


}


void CobrarButton::Pressed()
{
    player.AddCredits(COBRAR_CHARGE);
}

//callback
//