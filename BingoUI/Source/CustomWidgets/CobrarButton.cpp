


#include <AssetsManager.hpp>
#include <Config.hpp>
#include "CustomWidgets/CobrarButton.hpp"


CobrarButton::CobrarButton(Player& player) : ButtonWidget(CHARGE_BUTTON_TEXT,
                                                          AssetsManager::Get<Texture>("botongrande01"),
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
    player.AddCredits(CHARGE_BUTTON_QUANTITY);
}

//callback
//