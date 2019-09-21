#include <SDL_rect.h>
#include <Graphics.hpp>
#include <Card.hpp>
#include <sstream>
#include "CustomWidgets/CardUI.hpp"

#define DRAW_CELL_OFFSET_X 19
#define DRAW_CELL_OFFSET_Y 44
#define PADDING 1

void CardUI::Draw()
{


    Graphics::DrawTexture(background, &location);


    if (card != nullptr)
    {
        for (int x = 0; x < card->Width; x++)
        {
            for (int y = 0; y < card->Height; y++)
            {
                auto n = card->operator[](y * card->Height + x);

                std::stringstream ss;
                ss << n;


                SDL_Rect cellSize = cell->GetSDLRect();

                SDL_Point p = location;
                p.x += DRAW_CELL_OFFSET_X + (cellSize.w + PADDING) * x;
                p.y += DRAW_CELL_OFFSET_Y + (cellSize.h + PADDING) * y;
                Graphics::DrawTexture(cell, &p);

                SDL_Point cellTextLoc = p;
                SDL_Rect r = Graphics::MeasureText(ss.str());
                cellTextLoc.x += cellSize.w / 2;
                cellTextLoc.y += cellSize.h / 2;
                cellTextLoc.x -= r.w / 2;
                cellTextLoc.y -= r.h / 2;

                Graphics::DrawText(ss.str(), cellTextLoc, {0, 0, 0});
            }
        }
    }


}

CardUI::CardUI(Texture* background, Texture* cell)
{
    this->background = background;
    this->cell = cell;
}

void CardUI::Update()
{

}


void CardUI::SetCard(Card* card)
{
    this->card = card;
}

