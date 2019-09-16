




class Game
{
private:

    int credits;


public:

    void InsertCredits(int N);

    void PlayOneGame();

    void PlayNGames(int N);

    void ChangeCards(int N);

    /**
     * Collects all credits won, internal credits are reset to 0
     */
    int Collect();

    int CurrentCredits();

};


