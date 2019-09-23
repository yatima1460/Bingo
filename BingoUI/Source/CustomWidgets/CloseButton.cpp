


#include <AssetsManager.hpp>
#include <cassert>
#include "CustomWidgets/CloseButton.hpp"
#include "Engine.hpp"

CloseButton::CloseButton() : ButtonWidget("", AssetsManager::Get<Texture>("x"),
                                          AssetsManager::Get<Texture>("x"))
{


    auto background = AssetsManager::Get<Texture>("Fondo_Juego");

    auto redX = AssetsManager::Get<Texture>("x");
    auto backgroundSize = background->GetSDLRect();

    auto redXSize = redX->GetSDLRect();

    SetPosition({backgroundSize.w - redXSize.w, 0});


}

void CloseButton::Update()
{
    ButtonWidget::Update();
}


void CloseButton::Pressed()
{
    Engine::Quit();
}

//callback
//PlayerRef.Collect();