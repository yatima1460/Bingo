#include <Drum.hpp>
#include <iostream>

#include <Game.hpp>
#include <cstdlib>
#include <OutOfCreditsException.hpp>
#include <limits>
#include <cassert>
#include <ctime>

void ClearScreen()
{
    if (system("CLS")) system("clear");
}


Player *player;
Game *game;


void PrintCards(Player &player) {
    auto cards = player.GetCards();
    for (size_t i = 0; i < cards.size(); i++) {
        std::cout << std::endl << "Card #" << i + 1 << std::endl;
        Card *card = cards[i];
        assert(card != nullptr);
        for (size_t j = 0; j < card->Width * card->Height; j++) {
            unsigned int n = card[j];

            if (n >= 10)
                std::cout << n << " ";
            else
                std::cout << "0" << n << " ";
            if ((j + 1) % card->Width == 0) std::cout << std::endl;
        }

    }
}

void PrintMenu()
{


    const std::string logo = R"(______ _____ _   _ _____ _____
| ___ \_   _| \ | |  __ \  _  |
| |_/ / | | |  \| | |  \/ | | |
| ___ \ | | | . ` | | __| | | |
| |_/ /_| |_| |\  | |_\ \ \_/ /
\____/ \___/\_| \_/\____/\___/)";


    std::cout << logo << std::endl << std::endl;
    std::cout << "Current Credits: " << player->CreditsLeft() << "$" << std::endl << std::endl;
    std::cout << "1.Dynamic Bingo Settings" << std::endl;
    std::cout << "2.Insert Credits" << std::endl;
    std::cout << "3.Change the Card numbers" << std::endl;
    std::cout << "4.Show current Cards" << std::endl;
    std::cout << "5.Play One Game [ Cost: " << player->GetCards().size() << "$ ]" << std::endl;
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
            std::cout << "TODO" << std::endl;
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
            player->AddCredits(credits);
            std::cout << std::endl << "New credits: " << player->CreditsLeft() << std::endl;
            break;
        }
            // Change number of Cards
        case 3:
        {
            player->RerollCards();
            std::cout << std::endl << "New cards: " << std::endl;
            PrintCards(*player);
            /*std::cout << std::endl << "How many cards? ";
            int cards = -1;
            std::cin >> cards;
            game.SetCardsNumber(cards);*/
            break;
        }
            // Show Current Cards
        case 4: {
            assert(player != nullptr);
            PrintCards(*player);
            /*std::cout << std::endl << "How many cards? ";
            int cards = -1;
            std::cin >> cards;
            game.SetCardsNumber(cards);*/
            break;
        }
        // Play 1 Game
        case 5:
        {
            try
            {
                game->PlayOneGame();
            }
            catch (OutOfCreditsException &e)
            {

                std::cout << "ERROR: You don't have enough credits for cards" << std::endl;
                return;
            }


            auto balls = game->ExtractedBalls();

            std::cout << std::endl << balls.size() << " extracted balls: " << std::endl;

            for (size_t i = 0; i < balls.size(); i++)
            {
                if (balls[i] >= 10)
                    std::cout << "(" << balls[i] << ")";
                else
                    std::cout << "(0" << balls[i] << ")";
                if ((i + 1) % 10 == 0) std::cout << std::endl;
            }
            std::cout << std::endl << "Cards: " << std::endl;




            std::cout << std::endl;
            std::cout << "Remaining credits: " << player->CreditsLeft() << std::endl;



            break;
        }
        // Play X Games
        case 6:
        {

            std::cout << std::endl << "How many games? ";
            int games = -1;
            std::cin >> games;
            game->PlayNGames(games);
            break;
        }
        // Collect
        case 7:
        {
            unsigned int collected = player->Collect();
            std::cout << "Collected " << collected << " credits." << std::endl;
            break;
        }
            // Exit
        case 8:
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
    player = new Player();
    player->AddCredits(100);

    game = new Game(*player);
    game->SetCardsSize(5, 3);
    game->SetDrumSize(60);
    // game.SetCardsNumber(4);


#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"
    while (true)
    {
        PrintMenu();
        std::cout << std::endl;
        std::cout << "Press <Enter> to go back to the menu." << std::endl;
        std::cin.ignore().get();


    }

#pragma clang diagnostic pop
}