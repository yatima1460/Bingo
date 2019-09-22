

#include "CustomWidgets/DrumUI.hpp"

#include <utility>
#include <cassert>
#include <Graphics.hpp>
#include <sstream>
#include <AssetsManager.hpp>

#define OFFSET_X_ROW_0      438
#define OFFSET_Y_ROW_0      805
#define HORIZONTAL_PADDING  2
#define VERTICAL_PADDING    2
#define BALLS_N_ROW_0       13
#define BALLS_N_ROW_1       17

DrumUI::DrumUI()
{
    this->ball = AssetsManager::Get<Texture>("bola");
}

void DrumUI::SetBalls(std::vector<unsigned int> e)
{
    assert(e.size() == 30 || e.empty());
    this->extracted = std::move(e);
}

void DrumUI::Update()
{

}

void DrumUI::Draw()
{
    if (!extracted.empty())
    {
        for (int i = 0; i < BALLS_N_ROW_0; i++)
        {
            SDL_Point p;
            auto ballSize = ball->GetSDLRect();
            p.x = OFFSET_X_ROW_0 + i * (ballSize.w + HORIZONTAL_PADDING);
            p.y = OFFSET_Y_ROW_0;
            Graphics::DrawTexture(*ball, &p);


            std::stringstream ss;
            ss << extracted[i];
            p.x += ballSize.w / 2;
            p.y += ballSize.h / 2;
            SDL_Rect text_size = Graphics::MeasureText(ss.str());
            p.x -= text_size.w / 2;
            p.y -= text_size.h / 2;
            Graphics::DrawText(ss.str(), p, {0, 0, 0});
        }
        for (int i = 0; i < BALLS_N_ROW_1; i++)
        {
            SDL_Point p;
            auto ballSize = ball->GetSDLRect();
            p.x = OFFSET_X_ROW_0 + i * (ballSize.w + HORIZONTAL_PADDING) - ballSize.w * 2;
            p.y = VERTICAL_PADDING + OFFSET_Y_ROW_0 + ballSize.h;
            Graphics::DrawTexture(*ball, &p);

            std::stringstream ss;
            ss << extracted[i + BALLS_N_ROW_0];
            p.x += ballSize.w / 2;
            p.y += ballSize.h / 2;
            SDL_Rect text_size = Graphics::MeasureText(ss.str());
            p.x -= text_size.w / 2;
            p.y -= text_size.h / 2;
            Graphics::DrawText(ss.str(), p, {0, 0, 0});
        }
    }

}
