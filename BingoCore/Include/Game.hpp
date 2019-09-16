


#include "Card.hpp"
#include "Player.hpp"
#include <vector>

class Game
{
private:

    int credits;
    std::vector<Card> cards;
    Player &player;


public:

    explicit Game(Player &player);

    void SetDrumSize(int N);

    void SetCardsNumber(int N);

    unsigned int GetCardsNumber();

    void SetCardsSize(int Width, int Height);

    void InsertCredits(int N);

    void PlayOneGame();

    void PlayNGames(int N);

    void ChangeCards(int N);

    /**
     * Collects all credits won, internal credits are reset to 0
     */
    //int Collect();

    //int CurrentCredits();

};


