


#include <AssetsManager.hpp>
#include <BingoLevel.hpp>
#include <Engine.hpp>
#include <Settings.hpp>
#include "CustomWidgets/MonedasButton.hpp"


MonedasButton::MonedasButton() : ButtonWidget(Settings::get<std::string>("MONEY_BUTTON_TEXT"),
                                              AssetsManager::Get<Texture>("botonpeque01"),
                                              AssetsManager::Get<Texture>("botonpeque02"))
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
    ButtonWidget::Update();

    Level& level = Engine::GetCurrentLevel();
    auto& PlayerRef = dynamic_cast<BingoLevel&>(level).GetPlayer();

    SetEnabled(PlayerRef.creditsLeft() != 0);

}

void MonedasButton::Pressed()
{
    Level& level = Engine::GetCurrentLevel();
    auto& PlayerRef = dynamic_cast<BingoLevel&>(level).GetPlayer();
    [[maybe_unused]] const auto collected = PlayerRef.collect();
}
