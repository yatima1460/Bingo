#include <Drum.hpp>
#include <iostream>


#include <cstdlib>

#include <limits>
#include <cassert>
#include <ctime>
#include <Player.hpp>
#include <BingoCLI.hpp>


int main(int argc, char* argv[])
{


    /*game = new Game(*player);
    game->SetCardsSize(5, 3);
    game->SetDrumSize(60);*/
    // game.SetCardsNumber(4);




    BingoCLI bingoCLI;
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"
    while (true)
    {
        BingoCLI::ClearScreen();
        BingoCLI::PrintLogo();
        bingoCLI.PrintMenu();

    }
#pragma clang diagnostic pop
}