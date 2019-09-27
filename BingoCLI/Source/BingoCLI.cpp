//
// Created by yatima1460 on 27/09/2019.
//


#include <iostream>
#include <cassert>
#include <Drum.hpp>
#include "BingoCLI.hpp"


#include <unistd.h>
#include <algorithm>


void BingoCLI::ClearScreen()
{
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
    system("CLS");
#else
    printf("\033[H\033[J");
#endif
}


const char* BingoCLI::LOGO = R"(______ _____ _   _ _____ _____
| ___ \_   _| \ | |  __ \  _  |
| |_/ / | | |  \| | |  \/ | | |
| ___ \ | | | . ` | | __| | | |
| |_/ /_| |_| |\  | |_\ \ \_/ /
\____/ \___/\_| \_/\____/\___/)";

void BingoCLI::PrintLogo()
{
    std::cout << BingoCLI::LOGO << std::endl << std::endl;
}

void BingoCLI::PrintMenu()
{
    std::cout << "Current Credits: " << player.CreditsLeft() << "$" << std::endl << std::endl;
    std::cout << "1.Dynamic Bingo Settings" << std::endl;
    std::cout << "2.Insert Credits" << std::endl;
    std::cout << "3.Change the Card numbers" << std::endl;
    std::cout << "4.Show current Cards" << std::endl;
    std::cout << "5.Play One Game [ Cost: " << player.GetCards().size() << "$ ]" << std::endl;
    std::cout << "6.Play X Games" << std::endl;
    std::cout << "7.Collect" << std::endl;
    std::cout << "8.Exit game" << std::endl;
    std::cout << std::endl;
    std::cout << "Insert number: ";
    int command = -1;
    std::cin >> command;


    switch (command)
    {

        // Dynamic Bingo Settings
        case 1:
        {
            std::cout << "Game Settings" << std::endl;
            std::cout << std::endl;
            std::cout << "1.Set Prize patterns" << std::endl;
            // input number of rows matching
            // input number of columns matching
            // input value of this prize
            std::cout << "2.Set Drum balls" << std::endl;
            std::cout << "3.Set Cards number" << std::endl;
            std::cout << "4.Set Cards size" << std::endl;
            std::cout << std::endl;
            std::cout << "Insert number: ";

            int settingsCommand = -1;
            std::cin >> settingsCommand;


            switch (settingsCommand)
            {

            }
            break;
        }

            // Insert Credits
        case 2:
        {
            std::cout << std::endl << "How many credits? ";
            int credits = 0;
            std::cin >> credits;
            if (credits <= 0)
            {
                std::cout << "ERROR: Invalid credits value" << std::endl;
                std::cin.clear();
                return;
            }
            player.AddCredits(credits);

            break;
        }

            // Change the Card numbers
        case 3:
        {
            player.ChangeCards(4, 5, 3, 60);
            PrintCards();
            BingoCLI::Pause();
            break;
        }

            // Show Current Cards
        case 4:
        {
            PrintCards();
            BingoCLI::Pause();
            break;
        }

            // Play 1 Game
        case 5:
        {
            if (!TryPlayOneGame())
            {
                std::cout << std::endl << "You don't have enough money!" << std::endl << std::endl;
                //BingoCLI::Pause();
            }
            BingoCLI::Pause();
            break;
        }

            // Play X Games
        case 6:
        {
            std::cout << std::endl << "How many games? ";
            int games = -1;
            std::cin >> games;
            if (games <= 0)
            {
                std::cout << "ERROR: Invalid games value" << std::endl;
                std::cin.clear();
                return;
            }
            PlayNGames(games);
            break;
        }

            // Collect
        case 7:
        {
            unsigned int collected = player.Collect();
            std::cout << "Collected " << collected << " credits." << std::endl;
            break;
        }

            // Exit
        case 8:
        {
            BingoCLI::ClearScreen();
            std::exit(EXIT_SUCCESS);
        }

            // Invalid Command
        default:
        {
            return;
        }
    }
}


void BingoCLI::PrintCards()
{
    BingoCLI::ClearScreen();
    const auto cards = player.GetCards();
    for (size_t i = 0; i < cards.size(); i++)
    {
        std::cout << "Card #" << i + 1 << std::endl;
        const auto card = cards[i];
        assert(card != nullptr);
        for (size_t j = 0; j < card->Width * card->Height; j++)
        {
            unsigned int n = (*card)[j];

            if (n >= 10)
                std::cout << n << " ";
            else
                std::cout << "0" << n << " ";
            if ((j + 1) % card->Width == 0) std::cout << std::endl;
        }
        std::cout << std::endl;

    }
}

bool BingoCLI::TryPlayOneGame()
{
    // Try remove credits for cards
    if (!player.TryRemoveCredits(4))
        return false;

    // Extract numbers
    Drum drum(60);
    const auto extractedBalls = drum.Extract(30);

    // Show extracted numbers
    std::cout << std::endl << extractedBalls.size() << " extracted balls: " << std::endl;
    for (size_t i = 0; i < extractedBalls.size(); i++)
    {
        if (extractedBalls[i] >= 10)
            std::cout << "(" << extractedBalls[i] << ")";
        else
            std::cout << "(0" << extractedBalls[i] << ")";
        if ((i + 1) % 10 == 0) std::cout << std::endl;
    }


    std::vector<unsigned int> lookup(60 + 1);
    for (unsigned int j : extractedBalls)
        lookup[j] = 1;

    // Show marked cards
    const auto cards = player.GetCards();
    for (size_t i = 0; i < cards.size(); i++)
    {


        std::cout << "Card #" << i + 1 << std::endl;
        const auto card = cards[i];
        assert(card != nullptr);


        for (size_t j = 0; j < card->Width * card->Height; j++)
        {
            unsigned int n = (*card)[j];

            if (lookup[n] == 1)
            {
                std::cout << "\tX";

            } else
            {

                std::cout << "\t" << n;

            }

            if ((j + 1) % card->Width == 0) std::cout << std::endl;
        }
        std::cout << std::endl;

    }

    // Show remaining credits
    std::cout << std::endl;
    std::cout << "Remaining credits: " << player.CreditsLeft() << std::endl;

    return true;
}


void BingoCLI::PlayNGames(unsigned int N)
{

    unsigned int i = 1;
    while (true)
    {
        std::cout << "Game #" << i++ << std::endl;
        if (!TryPlayOneGame()) return;
    }

}

void BingoCLI::Pause()
{
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
    system("pause");
#else
    system("read -rsp $'Press any key to continue...\\n' -n 1 key");
#endif
}

BingoCLI::BingoCLI()
{
    player.ChangeCards(4, 5, 3, 60);
}
