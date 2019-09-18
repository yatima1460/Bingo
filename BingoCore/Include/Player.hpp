

#include <vector>
#include "Card.hpp"

class Player
{

private:

    unsigned int credits;
    std::vector<Card *> cards;

public:


    unsigned int CreditsLeft();

    bool TryRemoveCredits(unsigned int Value);

    void AddCredits(unsigned int Value);

    unsigned int Collect();

    std::vector<Card *> GetCards();

};

