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

BingoCLI::BingoCLI()
{


    Settings::set<unsigned int>("cards_number", 4);
    Settings::set<unsigned int>("card_width", 5);
    Settings::set<unsigned int>("card_height", 3);
    Settings::set<unsigned int>("drum_size", 60);
    Settings::set<unsigned int>("drum_extract", 30);
    Settings::set<std::string>("prizes", "1H0V8C,2H0V150C,B1500");

    player.changeCards();
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


void BingoCLI::PrintSettings()
{
    std::cout << "Game Settings" << std::endl;
    std::cout << std::endl;
    std::cout << "1.Create prize pattern" << std::endl;
    // input number of rows matching
    // input number of columns matching
    // input value of this prize
    std::cout << "2.Delete prize pattern" << std::endl;
    std::cout << "3.Show saved prize patterns" << std::endl;
    std::cout << "4.Set Game settings" << std::endl;
    //drum balls, cards number, size
    std::cout << "5.Print current settings .ini file" << std::endl;
    std::cout << "6.Back to Main Menu" << std::endl;
    std::cout << std::endl;
    std::cout << "Insert number: ";

    int settingsCommand = -1;
    std::cin >> settingsCommand;
    if (settingsCommand <= 0 || settingsCommand >= 6)
    {
        BingoCLI::ClearInputError();
        return;
    }


    switch (settingsCommand)
    {
        //Create prize pattern
        case 1:
        {
            break;
        }
        case 2:
        {
            break;
        }
        case 3:
        {
            break;
        }
            // Set Game settings
        case 4:
        {
            int drumBallsTotal = -1;
            std::cout << "Set total Drum balls: ";
            std::cin >> drumBallsTotal;
            if (drumBallsTotal <= 0)
            {
                std::cout << "Wrong number of balls" << std::endl;
                BingoCLI::Pause();
                return;
            }


            int drumBallsToExtract = -1;
            std::cout << "Set Drum balls to extract: ";
            std::cin >> drumBallsToExtract;
            if (drumBallsToExtract <= 0)
            {
                std::cout << "Invalid balls to extract" << std::endl;
                BingoCLI::Pause();
                return;
            }
            if (drumBallsToExtract > drumBallsTotal)
            {
                std::cout << "Number of balls can't exceed Drum size" << std::endl;
                BingoCLI::Pause();
                return;
            }

            int cardsTotal = -1;
            std::cout << "Set total number of cards: ";
            std::cin >> cardsTotal;
            if (cardsTotal <= 0)
            {
                std::cout << "Wrong cards number" << std::endl;
                BingoCLI::Pause();
                return;
            }

            int cardWidth = -1;
            std::cout << "Set card columns count: ";
            std::cin >> cardWidth;
            if (cardWidth <= 0)
            {
                std::cout << "Wrong cards columns count" << std::endl;
                BingoCLI::Pause();
                return;
            }
            if (cardWidth > drumBallsTotal)
            {
                std::cout << "Area exceeding Drum total size" << std::endl;
                BingoCLI::Pause();
                return;
            }

            int cardHeight = -1;
            std::cout << "Set card rows count: ";
            std::cin >> cardHeight;
            if (cardHeight <= 0)
            {
                std::cout << "Wrong cards rows count" << std::endl;
                BingoCLI::Pause();
                return;
            }
            if (cardHeight > drumBallsTotal || cardHeight * cardWidth > drumBallsTotal)
            {
                std::cout << "Area exceeding Drum total size" << std::endl;
                BingoCLI::Pause();
                return;
            }

            // Save settings
            Settings::set<int>("drum_total", drumBallsTotal);
            Settings::set<int>("drum_extract", drumBallsToExtract);
            Settings::set<int>("cards_number", cardsTotal);
            Settings::set<int>("card_width", cardWidth);
            Settings::set<int>("card_height", cardHeight);
            if (Settings::save())
            {
                std::cout << "Settings OK" << std::endl;
            } else
            {
                std::cout << "Can't save settings to file" << std::endl;
            }

            BingoCLI::Pause();
            break;
        }
        case 5:
        {
            std::cout << Settings::toString();
            BingoCLI::Pause();
        }
        default:
            return;
    }
}

void BingoCLI::PrintMenu()
{
    std::cout << "Current Credits: " << player.CreditsLeft() << "$" << std::endl << std::endl;
    std::cout << "1.Dynamic Bingo Settings" << std::endl;
    std::cout << "2.Insert Credits" << std::endl;
    std::cout << "3.Change the numbers on the Cards" << std::endl;
    std::cout << "4.Show current Cards" << std::endl;
    std::cout << "5.Play One Game [ Cost: " << Settings::get<unsigned int>("cards_number") << "$ ]" << std::endl;
    std::cout << "6.Play X Games" << std::endl;
    std::cout << "7.Collect" << std::endl;
    std::cout << "8.Exit game" << std::endl;
    std::cout << std::endl;
    std::cout << "Insert number: ";
    int command = -1;
    std::cin >> command;
    if (command <= 0 || command >= 9)
    {
        BingoCLI::ClearInputError();
        return;
    }


    switch (command) // NOLINT(hicpp-multiway-paths-covered)
    {

        // Dynamic Bingo Settings
        case 1:
        {
            PrintSettings();
            break;
        }

            // Insert Credits
        case 2:
        {
            std::cout << std::endl << "How many credits? ";
            int credits = -1;
            std::cin >> credits;
            if (credits <= 0)
            {
                std::cout << "Invalid credits" << std::endl;
                BingoCLI::ClearInputError();
                BingoCLI::Pause();
                return;
            }
            player.AddCredits(credits);

            break;
        }

            // Change the Card numbers
        case 3:
        {
            player.changeCards();
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
                std::cout << "Invalid value" << std::endl;
                BingoCLI::ClearInputError();
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
    if (!player.TryRemoveCredits(Settings::get<unsigned int>("cards_number")))
        return false;

    // Extract numbers
    Drum drum(Settings::get<unsigned int>("drum_size"));
    const auto extractedBalls = drum.Extract(Settings::get<unsigned int>("drum_extract"));

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

    BingoCLI::Pause();


    std::vector<unsigned int> lookup(Settings::get<unsigned int>("drum_size") + 1);
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


void BingoCLI::ClearInputError()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
