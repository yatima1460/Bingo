


#pragma once


#include <Player.hpp>
#include <Game.hpp>

#include "CustomWidgets/DrumUI.hpp"
#include "CustomWidgets/CardUI.hpp"

class Bingo
{


    //DrumUI* drumUI;
    std::vector<CardUI*> cards;
    Player* player = nullptr;
    bool quit = false;
    Game* game = nullptr;
    //Event handler
    SDL_Event e{};

    std::vector<Widget*> widgets;


public:

    Bingo();

};