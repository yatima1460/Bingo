#include <Drum.hpp>
#include <iostream>

#include <Game.hpp>
#include <cstdlib>


void ClearScreen()
{
    if (system("CLS")) system("clear");
}

Game game;

void PrintMenu()
{
    const std::string logo = R"(______ _____ _   _ _____ _____
| ___ \_   _| \ | |  __ \  _  |
| |_/ / | | |  \| | |  \/ | | |
| ___ \ | | | . ` | | __| | | |
| |_/ /_| |_| |\  | |_\ \ \_/ /
\____/ \___/\_| \_/\____/\___/)";


    std::cout << logo << std::endl << std::endl;
    std::cout << "Current Credits: " << game.CurrentCredits() << std::endl << std::endl;
    std::cout << "1.Dynamic Bingo Settings" << std::endl;
    std::cout << "2.Insert Credits" << std::endl;
    std::cout << "3.Change number of Cards" << std::endl;
    std::cout << "4.Play 1 Game" << std::endl;
    std::cout << "5.Play X Games" << std::endl;
    std::cout << "6.Collect" << std::endl;
    std::cout << "7.Exit game" << std::endl;
    std::cout << std::endl;
    std::cout << "Insert number: ";
    int command = -1;
    std::cin >> command;


    switch (command)
    {
        // Dynamic Bingo Settings
        case 1:
        {
            std::cout << "TODO" << std::endl;
            break;
        }
        // Insert Credits
        case 2:
        {
            std::cout << std::endl << "How many credits? ";
            int credits = -1;
            std::cin >> credits;
            game.InsertCredits(credits);
            break;
        }
            // Change number of Cards
        case 3:
        {
            std::cout << std::endl << "How many cards? ";
            int cards = -1;
            std::cin >> cards;
            game.ChangeCards(cards);
            break;
        }
        // Play 1 Game
        case 4:
        {
            game.PlayOneGame();
            break;
        }
        // Play X Games
        case 5:
        {

            std::cout << std::endl << "How many games? ";
            int games = -1;
            std::cin >> games;
            game.PlayNGames(games);
            break;
        }
        // Collect
        case 6:
        {
            int collected = game.Collect();
            std::cout << "Collected " << collected << " credits." << std::endl;
            break;
        }
            // Exit
        case 7:
        {
            std::exit(EXIT_SUCCESS);
        }
        // Invalid Command
        default:
        {
            return;
        }
    }

}

int main(int argc, char *argv[])
{
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"
    while (true)
        PrintMenu();
#pragma clang diagnostic pop
}