#include <iostream>
#include <cassert>
#include <unistd.h>

#include <Drum.hpp>

#include "BingoCLI.hpp"
#include <PrizeSystem.hpp>


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

/*
   */

    if (!Settings::load())
    {
        std::cout << "Could not load game settings from Settings.ini" << std::endl;
        std::cout << "Default settings will be loaded and written to file!" << std::endl;
        BingoCLI::Pause();
        Settings::set<unsigned int>("cards_number", 4);
        Settings::set<unsigned int>("card_width", 5);
        Settings::set<unsigned int>("card_height", 3);
        Settings::set<unsigned int>("drum_size", 60);
        Settings::set<unsigned int>("drum_extract", 30);
        Settings::set<std::string>("prizes", "1H0V8C,2H0V150C,B1500");
        if (!Settings::save())
        {
            std::cout << "Could not save default game settings to Settings.ini" << std::endl;
            BingoCLI::Pause();
        }

    }
    if (!PrizeSystem::load())
    {
        std::cout << "Could not load prize settings from Settings.ini" << std::endl;
        BingoCLI::Pause();
    }

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
    std::cout << "Game Settings:" << std::endl;
    std::cout << std::endl;
    std::cout << "1.Create prize pattern" << std::endl;
    // input number of rows matching
    // input number of columns matching
    // input VALUE of this prize
    std::cout << "2.Delete prize pattern" << std::endl;
    std::cout << "3.Set Game settings (drum, cards#, cards size)" << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "Debug Functions:" << std::endl;
    std::cout << std::endl;
    std::cout << "4.Print saved prize patterns in PrizeSystem" << std::endl;
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
        // Create prize pattern
        case 1:
        {
            std::string code;

            std::cout << "Prize code format:" << std::endl;
            std::cout << "HxVxCx or Bx" << std::endl;
            std::cout << "Hx = minimum number of horizontal lines to match" << std::endl;
            std::cout << "Vx = minimum number of vertical lines to match" << std::endl;
            std::cout << "Cx = credits value if won" << std::endl;
            std::cout << "Bx = special Bingo case credits value" << std::endl;
            std::cout << std::endl;
            std::cout << "Example: H1V0C8 = match only one line horizontally, 8 Credits value" << std::endl;
            std::cout << "Example: B1500 = match only Bingo, 1500 credits value" << std::endl;
            std::cout << std::endl;
            std::cout << "Insert prize code: ";
            std::cin >> code;

            // error another same code
            break;


        }
            // Delete prize pattern
        case 2:
        {
            std::cout << "Choose the prize pattern to delete: ";
            std::cout << std::endl;

            const auto prizes = PrizeSystem::getPrizes();
            size_t i = 0;
            for (; i < prizes.size(); i++)
            {
                const auto prize = prizes[i];
                std::cout << (i + 1) << ". " << prize.toString() << std::endl;

            }
            if (PrizeSystem::getBingoValue())
            {
                std::cout << (i + 1) << ". B" << PrizeSystem::getBingoValue() << std::endl;
            }

            unsigned int index;
            std::cout << "Insert index: ";
            std::cin >> index;


            if (index == i + 1)
            {
                PrizeSystem::setBingo(0);
                if (!PrizeSystem::save())
                {
                    std::cout << "Can't save prize to Settings.ini" << std::endl;
                    BingoCLI::Pause();
                }
            } else
            {
                if (index >= 1 && index <= i)
                {
                    PrizeSystem::removePrize(index - 1);
                } else
                {
                    std::cout << "Invalid index" << std::endl;
                    BingoCLI::ClearInputError();
                    BingoCLI::Pause();
                }
            }


            break;

        }
            // Print saved prize patterns
        case 4:
        {
            std::cout << PrizeSystem::toString() << std::endl;
            BingoCLI::Pause();
            break;
        }
            // Set Game settings
        case 3:
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
            Settings::set<int>("drum_size", drumBallsTotal);
            Settings::set<int>("drum_extract", drumBallsToExtract);
            Settings::set<int>("cards_number", cardsTotal);
            Settings::set<int>("card_width", cardWidth);
            Settings::set<int>("card_height", cardHeight);
            player.changeCards();

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
            // Print current settings .ini file
        case 5:
        {
            std::cout << Settings::toString() << std::endl;
            BingoCLI::Pause();
        }
        default:
            return;
    }
}

void BingoCLI::PrintMenu()
{
    std::cout << "Current credits: " << player.creditsLeft() << "$" << std::endl << std::endl;
    std::cout << "1.Dynamic Bingo Settings" << std::endl;
    std::cout << "2.Insert credits" << std::endl;
    std::cout << "3.Change the numbers on the cards" << std::endl;
    std::cout << "4.Show current cards" << std::endl;
    std::cout << "5.Play One Game [ Cost: " << Settings::get<unsigned int>("cards_number") << "$ ]" << std::endl;
    std::cout << "6.Play X Games" << std::endl;
    std::cout << "7.collect" << std::endl;
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

            // Insert credits
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
            player.addCredits(credits);

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

            // Show Current cards
        case 4:
        {
            PrintCards();
            BingoCLI::Pause();
            break;
        }

            // Play 1 Game
        case 5:
        {
            if (!TryPlayOneGame(true))
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
                std::cout << "Invalid VALUE" << std::endl;
                BingoCLI::ClearInputError();
                return;
            }
            PlayNGames(games);
            break;
        }

            // collect
        case 7:
        {
            unsigned int collected = player.collect();
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
    const auto cards = player.getCards();
    for (size_t i = 0; i < cards.size(); i++)
    {
        std::cout << "Card #" << i + 1 << std::endl;
        const auto card = cards[i];
        assert(card != nullptr);
        for (size_t j = 0; j < card->WIDTH * card->HEIGHT; j++)
        {
            unsigned int n = (*card)[j];

            if (n >= 10)
                std::cout << n << " ";
            else
                std::cout << "0" << n << " ";
            if ((j + 1) % card->WIDTH == 0) std::cout << std::endl;
        }
        std::cout << std::endl;
        if ((i + 1) % 4 == 0) BingoCLI::Pause();

    }
}

bool BingoCLI::TryPlayOneGame(const bool interactive)
{
    // Try remove credits for cards
    if (!player.pay(Settings::get<unsigned int>("cards_number")))
        return false;

    // extract numbers
    Drum drum(Settings::get<unsigned int>("drum_size"));
    const auto extractedBalls = drum.extract(Settings::get<unsigned int>("drum_extract"));

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

    if (interactive)
        BingoCLI::Pause();


    // Create a lookup table for faster checks
    std::vector<unsigned int> lookup(Settings::get<unsigned int>("drum_size") + 1);
    for (unsigned int j : extractedBalls)
        lookup[j] = 1;


    unsigned int wonRound = 0;

    // Show marked cards
    const auto cards = player.getCards();
    for (size_t i = 0; i < cards.size(); i++)
    {


        std::cout << "Card #" << i + 1 << std::endl;
        const auto card = cards[i];
        assert(card != nullptr);


        for (size_t j = 0; j < card->WIDTH * card->HEIGHT; j++)
        {
            unsigned int n = (*card)[j];

            if (lookup[n] == 1)
            {
                std::cout << "\tX";

            } else
            {

                std::cout << "\t" << n;

            }

            if ((j + 1) % card->WIDTH == 0) std::cout << std::endl;
        }


        unsigned int prize = PrizeSystem::checkCard(*card, extractedBalls);
        std::cout << "Prize amount: " << prize << " credits" << std::endl << std::endl;

        if (prize != 0)
        {
            player.addCredits(prize);

        }
        wonRound += prize;

    }

    // Show remaining credits
    std::cout << std::endl;
    std::cout << "Total won this round:" << wonRound << std::endl;
    std::cout << "Remaining credits: " << player.creditsLeft() << std::endl;

    return true;
}


void BingoCLI::PlayNGames(unsigned int N)
{

    unsigned int i = 0;

    const auto playerCreditsOld = player.creditsLeft();
    while (i++ < N)
    {
        std::cout << "Game " << i << "/" << N << std::endl;

        auto flag = TryPlayOneGame(false);

        if (!flag) break;
    }
    std::cout << std::endl;
    std::cout << "Total number of games played: " << (i - 1) << std::endl;
    std::cout << "Difference in credits: " << ((long) player.creditsLeft() - (long) playerCreditsOld) << std::endl;
    BingoCLI::Pause();

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
