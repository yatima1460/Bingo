

#include "CustomWidgets/DrumUI.hpp"

#include <utility>
#include <cassert>
#include <Graphics.hpp>
#include <sstream>
#include <AssetsManager.hpp>
#include <Drum.hpp>
#include <Settings.hpp>
#include "Config.hpp.old"


void DrumUI::Update()
{


}

void DrumUI::Draw()
{


    if (!ExtractedBalls.empty())
    {
        auto ball = AssetsManager::Get<Texture>("bola");
        for (int i = 0; i < Settings::get<int>("BALLS_N_ROW_0"); i++)
        {
            SDL_Point p;
            auto ballSize = ball->GetSDLRect();
            p.x = Settings::get<int>("OFFSET_X_ROW_0") + i * (ballSize.w + Settings::get<int>("HORIZONTAL_PADDING"));
            p.y = Settings::get<int>("OFFSET_Y_ROW_0");
            Graphics::DrawTexture(*ball, p);


            std::stringstream ss;
            ss << ExtractedBalls[i];
            p.x += ballSize.w / 2;
            p.y += ballSize.h / 2;
            SDL_Rect text_size = Graphics::MeasureText(ss.str());
            p.x -= text_size.w / 2;
            p.y -= text_size.h / 2;
            Graphics::DrawText(ss.str(), p, {0, 0, 0, 0});
        }
        for (int i = 0; i < Settings::get<int>("BALLS_N_ROW_1"); i++)
        {
            SDL_Point p;
            auto ballSize = ball->GetSDLRect();
            p.x = Settings::get<int>("OFFSET_X_ROW_0") + i * (ballSize.w + Settings::get<int>("HORIZONTAL_PADDING")) -
                  ballSize.w * 2;
            p.y = Settings::get<int>("VERTICAL_PADDING") + Settings::get<int>("OFFSET_Y_ROW_0") + ballSize.h;
            Graphics::DrawTexture(*ball, p);

            std::stringstream ss;
            ss << ExtractedBalls[i + Settings::get<int>("BALLS_N_ROW_0")];
            p.x += ballSize.w / 2;
            p.y += ballSize.h / 2;
            SDL_Rect text_size = Graphics::MeasureText(ss.str());
            p.x -= text_size.w / 2;
            p.y -= text_size.h / 2;
            Graphics::DrawText(ss.str(), p, {0, 0, 0, 0});
        }
    }

}

std::vector<unsigned int> DrumUI::ExtractNewBalls()
{
    Drum d(Settings::get<unsigned int>("drum_size"));
    ExtractedBalls = d.extract(Settings::get<unsigned int>("DRUM_BALLS_TO_EXTRACT"));
    return ExtractedBalls;
}

void DrumUI::Clear()
{
    ExtractedBalls.clear();
}
