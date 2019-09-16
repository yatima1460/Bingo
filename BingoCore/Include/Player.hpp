

class Player
{

private:

    unsigned int credits;

public:


    unsigned int CreditsLeft();

    bool TryRemoveCredits(unsigned int Value);

    void AddCredits(unsigned int Value);

    unsigned int Collect();

};

