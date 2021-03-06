#pragma once

#include <Player.hpp>
#include <Settings.hpp>

class BingoCLI
{

    Player player;


public:

    BingoCLI();

    void PrintMenu();

    void PrintCards();

    /**
     * Plays a game
     * @param interactive pause to show all cards
     * @return true if the game was played, false if not enough money
     */
    bool TryPlayOneGame(bool interactive);

    void PlayNGames(unsigned int N);

    void PrintSettings();

    static const char* LOGO;

    static void PrintLogo();

    static void ClearScreen();

    static void Pause();

    static void ClearInputError();

};

