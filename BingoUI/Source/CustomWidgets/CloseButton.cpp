


#include <AssetsManager.hpp>
#include <cassert>
#include "CustomWidgets/CloseButton.hpp"


CloseButton::CloseButton(bool* quit) : ButtonWidget("", AssetsManager::Get<Texture>("x"),
                                                    AssetsManager::Get<Texture>("x")), quit(quit)
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
    assert(quit != nullptr);
    *quit = true;

}

//callback
//player.Collect();