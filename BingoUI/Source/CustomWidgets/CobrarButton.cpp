


#include <AssetsManager.hpp>
#include <Level.hpp>
#include <Engine.hpp>
#include <BingoLevel.hpp>
#include <Settings.hpp>
#include "CustomWidgets/CobrarButton.hpp"


CobrarButton::CobrarButton() : ButtonWidget(Settings::get<std::string>("charge_button_text"),
                                            AssetsManager::Get<Texture>("botongrande01"),
                                            AssetsManager::Get<Texture>("botongrande02"))
{
    auto backgroundSize = AssetsManager::Get<Texture>("Fondo_Juego")->GetSDLRect();
    auto buttonBigNormalSize = AssetsManager::Get<Texture>("botongrande01")->GetSDLRect();

    SetPosition({0, backgroundSize.h - buttonBigNormalSize.h});
}


void CobrarButton::Pressed()
{
    Level& level = Engine::GetCurrentLevel();
    auto& PlayerRef = dynamic_cast<BingoLevel&>(level).GetPlayer();
    PlayerRef.addCredits(Settings::get<unsigned int>("charge_button_quantity"));
}
