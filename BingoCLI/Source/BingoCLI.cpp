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
    ClearScreen();
    std::cout << "What do you want to do?" << std::endl;
    std::cout << "0.Dynamic Bingo Settings" << std::endl;
    std::cout << "1.Insert Credits" << std::endl;
    std::cout << "2.Play 1 Game" << std::endl;
    std::cout << "3.Play X Games" << std::endl;
    std::cout << "4.Collect" << std::endl;

    std::cout << std::endl << "Insert number:";
    int command = -1;
    std::cin >> command;


    switch (command)
    {
        // Dynamic Bingo Settings
        case 0:
        {
            std::cout << "TODO" << std::endl;
            break;
        }
        // Insert Credits
        case 1:
        {
            std::cout << std::endl << "How many credits? ";
            int credits = -1;
            std::cin >> credits;
            game.InsertCredits(credits);
            break;
        }
        // Play 1 Game
        case 2:
        {
            game.PlayOneGame();
            break;
        }
        // Play X Games
        case 3:
        {

            std::cout << std::endl << "How many games? ";
            int games = -1;
            std::cin >> games;
            game.PlayNGames(games);
            break;
        }
        // Collect
        case 4:
        {
            game.Collect();
            break;
        }
        // Invalid Command
        default:
        {
            PrintMenu();
        }
    }

}

int main(int argc, char *argv[])
{

    PrintMenu();
/*
    Drum d(60);


    auto result = d.Extract(30);
    for ( int ball : result)
    {
        std::cout << ball << " ";
    }
*/






}