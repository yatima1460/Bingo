#include <SDL_rect.h>
#include <Graphics.hpp>
#include <Card.hpp>
#include <sstream>
#include "CustomWidgets/CardUI.hpp"
#include <algorithm>
#include <utility>


#define DRAW_CELL_OFFSET_X 19
#define DRAW_CELL_OFFSET_Y 44
#define PADDING 1

void CardUI::Draw()
{


    Graphics::DrawTexture(background, location);


    for (size_t x = 0; x < card->WIDTH; x++)
    {
        for (size_t y = 0; y < card->HEIGHT; y++)
        {
            unsigned int n = (*card)[y * card->WIDTH + x];

            std::stringstream ss;
            ss << n;


            SDL_Rect cellSize = cell->GetSDLRect();

            SDL_Point p = location;
            p.x += DRAW_CELL_OFFSET_X + (cellSize.w + PADDING) * x;
            p.y += DRAW_CELL_OFFSET_Y + (cellSize.h + PADDING) * y;
            Graphics::DrawTexture(*cell, p);

            // TODO: use a lookup table
            if (std::find(extracted.begin(), extracted.end(), n) != extracted.end())
            {
                Graphics::DrawTexture(*marked, p);
            }


            SDL_Point cellTextLoc = p;
            SDL_Rect r = Graphics::MeasureText(ss.str(), Graphics::GetBigFont());
            cellTextLoc.x += cellSize.w / 2;
            cellTextLoc.y += cellSize.h / 2;
            cellTextLoc.x -= r.w / 2;
            cellTextLoc.y -= r.h / 2;

            Graphics::DrawText(ss.str(), cellTextLoc, {0, 0, 0, 0}, Graphics::GetBigFont());
        }
    }


}

CardUI::CardUI(std::shared_ptr<Card> card, Texture& background, Texture* cell, Texture* marked) : background(
        background), card(std::move(card))
{

    this->cell = cell;
    this->marked = marked;
}

void CardUI::Update()
{

}


void CardUI::SetExtractedNumbers(std::vector<unsigned int> e)
{
    this->extracted = std::move(e);
}

void CardUI::ChangeCard(std::shared_ptr<Card> c)
{
    this->card = std::move(c);
}

